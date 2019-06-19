#pragma once
#include <string>
#include <set>
using namespace std;

class Folder
{
public: 
    Folder();
    ~Folder();
    Folder& operator= (const Folder&);
    Folder(const Folder&);

    void addMsg(Message *m3)
    {
        messages.insert(m3);
    }
    void remMsg(Message *m4)
    {
        messages.erase(m4);
    }
private:
    set<Message> messages;
};

class Message
{
    friend class Folder;
public:
    Message(const Message& m):contents(m.contents),folders(m.folders)
    {
        add_to_Folders(m);
    }

    Message& operator= (const Message& mm)
    {
        remove_from_Folders();
        contents = mm.contents;
        folders = mm.folders;
        add_to_Folders(mm);
        
        return *this;
    }

    Message(const string &str = ""):contents(str) { }
    void swap(Message& m1, Message& m2)
    {
        using std::swap;

        for(auto f : m1.folders)
        {
            f->remMsg(this);
        }
        for(auto f : m2.folders)
        {
            f->remMsg(this);
        }
        swap(m1.folders, m2.folders);
        swap(m1.contents, m2.contents);
        for(auto f : m1.folders)
        {
            f->addMsg(this);
        }
        for(auto f : m2.folders)
        {
            f->addMsg(this);
        }
    }

    ~Message()
    {
        remove_from_Folders();
    }

    void save(Folder&);
    void remove(Folder&);

private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

void Message::save(Folder& f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message& m)
{
    for(aut0 f : m.folders)
    {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders()
{
    for(auto f : folders)
    {
        f->remMsg(this);
    }
}