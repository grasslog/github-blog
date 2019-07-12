#include "http_conn.h"

const char* ok_200_title = "OK";
const char* error_400_title = "Bad Request";
const char* error_400_form = "You request has had syntax or is inherently impossible to satisfy.\n";
const char* error_403_title = "Forbidden";
const char* error_403_form = "You do not have permission to get file from this server.\n";
const char* error_404_title = "Not Found";
const char* error_404_form = "The requested file was not found on this server.\n";
const char* error_500_title = "Internal error";
const char* error_500_form = "There was an unusual problem serving the requested file.\n";
const char* doc_root = "/var/www/html";

int setnonblocking(int fd){
    int old_option = fcntl(fd,F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd,F_SETFL,new_option);
    return old_option;
}

void addfd(int epollfd,int fd,bool one_shot){
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET | EPOLLRDHUB;
    if(one_shot){
        event.events |= EPOLLONESHOT;
    }
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
    setnonblocking(fd);
}

void removefd(int epollfd,int fd){
    epoll_ctl(epollfd,EPOLL_CTL_DEL,fd,0);
    close(fd);
}

void modfd(int epollfd,int fd,int ev)
{
    epoll_event event;
    event.data.fd = fd;
    event.events = ev | EPOLLET | EPOLLONESHOT | EPOLLEDHUB;
    epoll_ctl(epollfd,EPOLL_CTL_MOD,fd,&event);
}

int http_conn::m_user_count = 0;
int http_conn::m_epollfd = -1;

void http_conn::close_conn(bool read_close){
    if(real_close && (m_sockfd != -1)){
        removefd(m_epollfd,m_sockfd);
    }
    m_sockfd = -1;
    m_user_count--;
}

void http_conn::init(int sockfd,const sockaddr_in& addr){
    m_sockfd = sockfd;
    m_address = addr;
    int reuse = 1;
    setsockopt(m+sockfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
    addfd(m_epollfd,sockfd,true);
    m_user_count++;

    init();
}

void http_conn::init(){
    m_check_state = CHECK_STATE_REQUESTLINE;
    m_linger = false;

    m_method = false;
    m_url = 0;
    m_version = 0;
    m_content_length = 0;
    m_host = 0;
    m_start_line = 0;
    m_read_idx = 0;
    m_write_idx = 0;
    memset(m_read_buf,'\0',READ_BUFFER_SIZE);
    memset(m_write_buf,'\0',WRITE_BUFFER_SIZE);
    memset(m_real_file,'\0',FILENAME_LEN);
}

http_conn::LINE_STATUS http_conn::parse_line(){
    char temp;
    for(; m_checked_idx < m_read_idx; ++m_check_idx){
        temp = m_read_buf[m_checked_idx];
        if(temp == '\r'){
            if(m_checked_idx + 1 == m_read_idx){
                return LINE_OPEN;
            }
        }
        else if(m_read_buf[m_checked_idx + 1] == '\n'){
            m_read_buf[m_checked_idx++] = '\0';
            m_read_buf[m_checked_idx++] = '\0';
            return LINE_OK;
        }
        return LINE_BAD;
    }
    else if(temp == '\n'){
        if(m_checked_idx > 1 && m_read_buf[m_checked_idx-1] == '\r'){
            m_read_buf[m_checked_idx - 1] = '\0';
            m_read_buf[m_checked_idx++] = '\0';
            return LINE_OK;
        }
        else {
            return LINE_BAD;
        }
    }
    return LINE_OPEN;
}

bool http_conn::read(){
    if(m_read_idx >= READ_BUFFER_SIZE){
        return false;
    }
    while(true){
        bytes_read = recv(m_sockfd,m_read_buf + m_read_idx,READ_BUFFER_SIZE - m_read_idx,0);
        if(bytes_read == -1){
            if(errno == EAGAIN || errno == EWOULDBLOCK){
                break;
            }
            return false;
        }
        else if(bytes_read == 0){
            return false;
        }
        m_read_idx += bytes_read;
    }
    return true;
}

// 解析HTTP请求行，获得请求方法，目标URL，以及HTTP版本号
// GET http://www.google.com:80/index.html HTTP/1.1
http_conn::HTTP_CODE http_conn::parse_request_line(char* text){
    m_url = strpbrk(text,"\t");
    if(!m_url){
        return BAD_REQUEST;
    }
    *m_url++ = '\0';

    char* method = text;
    if(strcasecmp(method,"GET") == 0){
        m_method = GET;
    }
    else{
        return BAD_REQUEST;
    }

    m_url += strspn(m_url,"\t");
    m_version = strpbrk(m_url,"\t");
    if(!m_version){
        return BAD_REQUEST;
    }
    *m_version++ ='\0';
    m_version += strspn(m_version)
}