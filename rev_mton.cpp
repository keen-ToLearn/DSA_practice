#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node(){
            
        }
        Node(int x){
            val = x;
        }
        Node *next;
};

class LL{
    public:
        Node *start;
};

void insert(LL *l, int ele){
    Node *tmp=new Node(ele);
    tmp->next=l->start;
    l->start=tmp;
}

int count(LL l){
    int c=0;
    Node *p = new Node();
    p=l.start;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

void reverse(LL *l, int m, int n){
    Node *q,*p,*r,*t1,*t2;
    q=new Node();
    p=new Node();
    r=new Node();
    t1=new Node();
    t2=new Node();
    q=NULL;
    p=l->start;
    cout<<"sp "<<p->val<<"\n";
    int c=0;
    while(c != m){
        if(c == m-1)
            t1=q;
        c++;
        q=p;
        p=p->next;
        cout<<"ip "<<p->val<<" ";
    }
    cout<<"\n";
    t2=q;
    
    while(p!=NULL && c != n){
        c++;
        r=p->next;
        p->next=q;
        cout<<"rp "<<p->val<<" ";
        q=p;
        p=r;
    }
    
    if(m<=1){
        l->start=q;
        if(m == 1)
            t2->next=NULL;
    }
    else{
        t1->next=q;
        t2->next=p;
    }
}

void display(LL l){
    Node *p = new Node();
    p=l.start;
    while(p != NULL){
        cout<<"->"<<p->val;
        p=p->next;
    }
}

int main(){
    LL l;
    l.start=NULL;
    insert(&l,5);
    insert(&l,4);
    insert(&l,3);
    insert(&l,2);
    insert(&l,1);
    display(l);
    cout<<"\n";
    reverse(&l,0,count(l));
    //reverse(&l,1,count(l));
    //reverse(&l,2,4);
    cout<<"\n";
    display(l);
    return 0;
}