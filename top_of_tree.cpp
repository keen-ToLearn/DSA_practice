#include <iostream>
using namespace std;

struct node{
    node *left,*right;
    int data,hd,depth;
};
struct tree{
    node *root;
};

void insert(tree *t, int ele){
    node *tmp=new node;
    node *p=new node;
    tmp->data=ele;
    tmp->left=tmp->right=NULL;
    if(t->root == NULL){
        t->root=tmp;
        tmp->hd=0;
        tmp->depth=0;
        return;
    }
    p=t->root;
    int c,d;
    c=d=0;
    while(p != NULL){
        if(tmp->data < p->data){
            if(p->left == NULL){
                p->left=tmp;
                c--;
                d++;
                tmp->hd=c;
                tmp->depth=d;
                return;
            }
            p=p->left;
            c--;
            d++;
        }
        else{
            if(p->right == NULL){
                p->right=tmp;
                c++;
                d++;
                tmp->hd=c;
                tmp->depth=d;
                return;
            }
            p=p->right;
            c++;
            d++;
        }
    }
}

void inorder(node *n){
    if(n!=NULL){
        inorder(n->left);
        cout<<"val= "<<n->data<<" hd= "<<n->hd<<" depth= "<<n->depth<<"\n";
        inorder(n->right);
    }
}

node* findmin(tree *t){
    if(t->root == NULL)
        return NULL;
    node *p=new node;
    p=t->root;
    while(p->left != NULL){
        p=p->left;
        cout<<"val= "<<p->data<<" hd= "<<p->hd<<" depth= "<<p->depth<<"\n";
    }
    return p;
}

node* findmax(tree *t){
    if(t->root == NULL)
        return NULL;
    node *p=new node;
    p=t->root;
    while(p->right != NULL){
        p=p->right;
        cout<<"val= "<<p->data<<" hd= "<<p->hd<<" depth= "<<p->depth<<"\n";
    }
    return p;
}

void finorder(node *n, int min, int max){
    if(n!=NULL){
        finorder(n->left, min, max);
        if(n->hd > max || n->hd < min){
            cout<<"val= "<<n->data<<" hd= "<<n->hd<<" depth= "<<n->depth<<"\n";
        }
        finorder(n->right, min, max);
    }
}

int main(){
    tree t;
    t.root=NULL;
    int n;
    cout<<"n=";
    cin>>n;
    int ele;
    for(int i=0; i<n; i++){
        cin>>ele;
        insert(&t,ele);
        inorder(t.root);
    }
    node *r;
    r=t.root;
    cout<<"Answer\n";
    cout<<"root= "<<r->data<<" hd= "<<r->hd<<" depth= "<<r->depth<<"\n";
    node *p,*q;
    p=findmin(&t);
    q=findmax(&t);
    cout<<"min_val= "<<p->data<<" min_hd= "<<p->hd<<" min_depth= "<<p->depth<<"\n";
    cout<<"max_val= "<<q->data<<" max_hd= "<<q->hd<<" max_depth= "<<q->depth<<"\n";
    if(p->right){
        finorder(p->right,p->hd,q->hd);
        cout<<"ONE\n";
    }
    if(q->left){
        finorder(q->left,p->hd,q->hd);
        cout<<"TWO\n";
    }
    return 0;
}