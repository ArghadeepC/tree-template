#include <iostream>
#include<conio.h>
#include "Queue.h"
using namespace std;
node *root=nullptr;
void Tcreate()
{
node *t,*p;
int x;
root=new node;
cout<<endl<<"Enter The Root Value: ";
cin>>x;
root->data=x;
root->LChild=root->RChild=0;
enqueue(root);
while(!isEmpty())
{
   p=dequeue();
   cout<<endl<<"Enter Value Of Left Child of "<<p->data<<": ";
   cin>>x;
   if(x!=-1)
   {
       t=new node;
       t->data=x;
       t->LChild=t->RChild=nullptr;
       p->LChild=t;
       enqueue(t);
   }
   cout<<endl<<"Enter Value Of Right Child of "<<p->data<<": ";
   cin>>x;
   if(x!=-1)
   {
       t=new node;
       t->data=x;
       t->LChild=t->RChild=nullptr;
       p->RChild=t;
       enqueue(t);
   }
}
}
void inorder(node *p)
{
    if(p)
    {
        inorder(p->LChild);
        cout<<p->data<<" ";
        inorder(p->RChild);
    }
}
void postorder(node *p)
{
    if(p)
    {
        postorder(p->LChild);
        postorder(p->RChild);
        cout<<p->data<<" ";
    }
}
int main()
{
    Tcreate();
    inorder(root);
    cout<<endl;
    postorder(root);
    getch();
}
