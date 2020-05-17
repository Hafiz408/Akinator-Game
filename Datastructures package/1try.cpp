#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<stdlib.h>

fstream fio;

struct trienode
{
    string ans;
    string ques;
    struct trienode* next[20];
}*root;

struct trienode* createnode()
{
    int i;
    struct trienode *node=new trienode;
    for(i=0;i<20;i++)
    {
        node->next[i]=NULL;
    }
    return node;
}

void inserttrie(struct trienode* temp,string domain,string ques)
{
    int i=0;
    string key;
    while(temp->next[i]!=NULL&&domain!=temp->next[i]->ans)
    {
        i++;
    }
    if(temp->next[i]==NULL)
    {
        temp->next[i]=createnode();
        temp=temp->next[i];
        temp->ques=ques;
        temp->ans=domain;
        while(fio)
        {
            getline(fio,key);
            if(key!="-1")
            {
            getline(fio,ques);
            inserttrie(temp,key,ques);
            }
            else
            break;
        }
    }
    else if(domain==temp->next[i]->ans)
    {
        temp=temp->next[i];
        while(fio)
        {
            getline(fio,key);
            if(key!="-1")
            {
            getline(fio,ques);
            inserttrie(temp,key,ques);
            }
            else
            break;
        }
    fio.close();
    }
}

void insert(struct trienode* temp1,char filename[])
{
    string domain,ques;
    fio.open(filename,ios::in);
    getline(fio,domain);
    getline(fio,ques);
    inserttrie(root,domain,ques);
}

void akinator(struct trienode* temp1)
{
    struct trienode *temp=temp1;
    int i;
    char c;
    for(i=0;i<20;i++)
    {
        system("CLS");
        cout<<"\n\t\t\t\t\tAKINATOR\n\n\n";
        if(temp->next[i]!=NULL)
        {
            cout<<"\n\t\t\t"<<temp->next[i]->ques;
            cin>>c;
            if(c=='y')
            {
                temp=temp->next[i];
                if(temp->next[0]!=NULL)
                akinator(temp);
                else
                cout<<"\n\t\t\tI guess you thought of "<<temp->ans;
                return;
            }
            if(c=='n')
            {
                continue;
            }
        }
         else
        {
            cout<<"\n\t\t\tIts out of my guesses";
            return;
        }
    }
}

int main()
{
    root=createnode();
    insert(root,"D:/package/package/tamilactors/rajini.txt");
    insert(root,"D:/package/package/tamilactors/ajith.txt");
    insert(root,"D:/package/package/tamilactors/vijay.txt");
    insert(root,"D:/package/package/tamilactors/vijaysethupathi.txt");
    insert(root,"D:/package/package/tamilactors/madhavan.txt");
    insert(root,"D:/package/package/tamilactors/arjun.txt");
    insert(root,"D:/package/package/tamilactors/harishkalyan.txt");
    insert(root,"D:/package/package/tamilactors/kamal.txt");
    insert(root,"D:/package/package/tamilactors/vijaykanth.txt");
    insert(root,"D:/package/package/tamilactors/dhanush.txt");
    insert(root,"D:/package/package/tamilactors/suriya.txt");
    insert(root,"D:/package/package/tamilactors/vikram.txt");
    insert(root,"D:/package/package/tamilactors/vishnuvishal.txt");
    insert(root,"D:/package/package/tamilactors/sarathkumar.txt");
    insert(root,"D:/package/package/tamilactors/vishal.txt");
    insert(root,"D:/package/package/animals/cat.txt");
    insert(root,"D:/package/package/animals/cheetah.txt");
    insert(root,"D:/package/package/animals/cow.txt");
    insert(root,"D:/package/package/animals/dog.txt");
    insert(root,"D:/package/package/animals/elephant.txt");
    insert(root,"D:/package/package/animals/giraffe.txt");
    insert(root,"D:/package/package/animals/horse.txt");
    insert(root,"D:/package/package/animals/lion.txt");
    insert(root,"D:/package/package/animals/tiger.txt");
    insert(root,"D:/package/package/animals/zebra.txt");
    akinator(root);
    cout<<"\n\n\n\n";
}
