#include <stdio.h>
#include <pthread.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

//文件拷贝函数
int mycopy(string src,string des)
{
    try
    {
        ifstream file(src.c_str(),ios::in);
        if(!file.is_open()) 
        {
            cout << "open src error \n";
            return 1;
        }
        std::istreambuf_iterator<char> beg(file),end;
        string strdata(beg,end);
        file.close();

        std::ofstream fout(des.c_str(),ios::out);
        if (!fout.is_open())
        {
            cout <<"create "<<des<<" error.\n";
            return 1;
        }
        fout<<strdata.c_str();
        fout<<std::flush;
        fout.close();
    }
    catch(exception e)
    {
        return 1;
    }
    return 0;
}
//任务信息
typedef struct TASK_INFO
{
    string src;
    string des;
}Info;

//获取目录下所有文件
int GetFileName(string strpath,vector<string>& vec)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp=opendir(strpath.c_str()))==NULL)
    {
        cout <<"Get File Name error.\n";
        return 1;
    }
    while((dirp=readdir(dp))!=NULL)
    {
        if( (strcmp(dirp->d_name,".")==0) || (strcmp(dirp->d_name,"..")==0))
            continue;
        vec.push_back(dirp->d_name);
        //cout << dirp->d_name<<endl;
    }
    return 0;
}
//组合src des路径名
int GetTaskInfo(vector<string>& vecfilename,string src,string des,vector<Info>& vecInfo)
{
    for(int i=0;i<vecfilename.size();i++)
    {
        Info info1;
        info1.src=src+vecfilename.at(i);
        info1.des=des+vecfilename.at(i);
        vecInfo.push_back(info1);
        //cout <<"src:"<<info1.src<<endl;
        //cout <<"des:"<<info1.des<<endl;
    }
    return 0;
}
int npos=0;
pthread_mutex_t mut;//线程锁
//线程工作函数
void* task_cp(void *param)
{
    vector<Info> vec = *((vector<Info>*)param);
    for(;npos<vec.size();)
    {
        Info info1;
        pthread_mutex_lock(&mut);
        info1 = vec.at(npos);
        npos++;
        pthread_mutex_unlock(&mut);

        if(mycopy(info1.src,info1.des))
        {
            cout<<info1.src<<" : copy error.\n";
        }
        else
        {
            cout<<info1.src<<" : copy success.\n";
        }
        usleep(1);
    }

}
int main(int argc,char* argv[])
{
    //读取参数
    if(argc==2&&!strcmp(argv[1],"-h"))
    {
        cout<<"usage : mycp src des num\n";
        cout <<"src:"<<"源目录路径 /结尾";
        cout <<"des:"<<"目标路径 /结尾";
        cout <<"num:"<<"线程数量";
        return 0;
    }
    if(argc<4)
    {
        cout <<"paramer error\n";
        return 0;
    }
    int num_pthread=atoi(argv[3]);
    string src=argv[1];
    string des=argv[2];

    //获取文件名
    vector<string> vec;
    GetFileName(src,vec);

    //生成任务信息
    vector<Info> vecInfo;
    GetTaskInfo(vec,src,des,vecInfo);

    if(num_pthread>vecInfo.size())
        num_pthread=vecInfo.size();

    pthread_t pid[num_pthread];

    //开启多个线程
    for(int k=0;k<num_pthread;k++)
    {
        pthread_create(&pid[k],NULL,task_cp,(void*)&vecInfo);
    }
    //等待所有线程工作结束退出
    for(int j=0;j<num_pthread;j++)
    {
        pthread_join(pid[j],NULL);
    }
    return 0;
}