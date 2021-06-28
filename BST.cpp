#include<iostream>
using namespace std;
class node
{
public:
int data;
node *Lchild;
node *Rchild;
};
class BST
{
private:
node *root;
public:
BST()
{
    root=nullptr;
}
node* get_root()
{
    return root;
}
void insert(int x);
void inorder_display(node *t);
int search(int key);
node* Delete(node*p,int key);
node* inaccs(node *q);
node* inpre(node *q);
int height(node *p);
};
void BST::insert(int x)
{
   node *t=root,*p=nullptr,*s;
   s=new node;
   s->data=x;
   s->Lchild=s->Rchild=nullptr;
   if(t==nullptr)
   {
      root=s;
      return;
   }
   while(t)
   {
   p=t;
   if(x<t->data)
   t=t->Lchild;
   else if(x>t->data)
   t=t->Rchild;
   else
   return;
   }
   if(s->data>p->data)
   p->Rchild=s;
   else
   p->Lchild=s;
}
void BST::inorder_display(node *t)
{
    if(t)
    {
        inorder_display(t->Lchild);
        cout<<t->data<<" ";
        inorder_display(t->Rchild);
    }
}
int BST::search(int key)
{
    node* t=root;
    while(t)
    {
    if(key==t->data)
    return 1;
    else if(key>t->data)
    t=t->Rchild;
    else
    t=t->Lchild;
    }
    return 0;
}
node* BST::Delete(node *p, int key) {
    node* q;
 
    if (p == nullptr){
        return nullptr;
    }
 
    if (p->Lchild == nullptr && p->Rchild == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
 
    if (key < p->data){
        p->Lchild = Delete(p->Lchild, key);
    } else if (key > p->data){
        p->Rchild = Delete(p->Rchild, key);
    } else {
        if (height(p->Lchild) > height(p->Rchild)){
            q = inpre(p->Lchild);
            p->data = q->data;
            p->Lchild = Delete(p->Lchild, q->data);
        } else {
            q = inaccs(p->Rchild);
            p->data = q->data;
            p->Rchild = Delete(p->Rchild, q->data);
        }
    }
    return p;
}
 
int BST::height(node *p) {
    int x;
    int y;
    if (p == nullptr){
        return 0;
    }
    x = height(p->Lchild);
    y = height(p->Rchild);
    return x > y ? x + 1 : y + 1;
}
 
node* BST::inpre(node *p) {
    while (p->Rchild != nullptr){
        p = p->Rchild;
    }
    return p;
}
 
node* BST::inaccs(node *p) {
    while (p->Lchild != nullptr){
        p = p->Lchild;
    }
    return p;
}
int main()
{
    BST *p=new BST();
    int data,ch,key,a;
    while(1)
    {
    cout<<endl<<"Press 1 for Insert: "<<endl;
    cout<<"Press 2 for Display: "<<endl;
    cout<<"Press 3 for Search: "<<endl;
    cout<<"Press 4 for Delete: "<<endl;
    cout<<"Press 5 for Exit: "<<endl;
    cout<<"Enter Your Choice: "<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1: cout<<"Enter The Value: ";
                cin>>data;
                p->insert(data);
                break;
        case 2: p->inorder_display(p->get_root());
                break;
        case 3: cout<<"Enter The Key: ";
                cin>>key;
                a=p->search(key);
                if(a)
                cout<<endl<<"Found and the key is: "<<key<<endl;
                else
                cout<<endl<<"Not Found"<<endl;
                break;
        case 4: cout<<"Enter The Key: ";
                cin>>key;
                p->Delete(p->get_root(),key);
                break;
        case 5: exit(0);
    }
    }
}