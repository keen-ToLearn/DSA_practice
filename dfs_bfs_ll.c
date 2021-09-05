//agenda: dfs, bfs, both using linked list
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int val,visit;
    struct node *next;
    struct node *prev;
}node;

typedef struct{
    node *start;
}list;

void initialiser(int n, list ll[20]){
    node *new;
    int i;
    for(i=0; i < n; i++){
        new=(node*)malloc(sizeof(node));
        new->val=i+1;
        new->visit=0;
        new->next=NULL;
        new->prev=NULL;
        ll[i].start=new;
    }
    return;
}

void addedge(int u, int v, list ll[20]){
    node *p,*q,*new;
    p=ll[u-1].start;
    q=ll[v-1].start;
    while(p->next != NULL){
        p=p->next;
    }
    while(q->next != NULL){
        q=q->next;
    }
    new=(node*)malloc(sizeof(node));
    new->val=v;
    new->visit=0;
    p->next=new;
    new->next=NULL;
    new->prev=p;
    new=(node*)malloc(sizeof(node));
    new->val=u;
    new->visit=0;
    q->next=new;
    new->next=NULL;
    new->prev=q;
    return;
}

void display(int n, list ll[20]){
    int i;
    node *p;
    for(i=0; i < n; i++){
        printf("\nList %d: ",i+1);
        p=ll[i].start;
        while(p != NULL){
            printf("%d ",p->val);
            p=p->next;
        }
        printf("\n");
    }
    return;
}

void visitor(int ele, list ll[20], int n){
    node *p;
    int i;
    for(i=0; i < n; i++){
        p=ll[i].start;
        while(p != NULL){
            if(p->val == ele){
                p->visit=1;
                break;
            }
            p=p->next;
        }
    }
    return;
}

void devisitor(int n, list ll[20]){
    int i;
    node *p;
    for(i=0; i < n; i++){
        p=ll[i].start;
        while(p != NULL){
            p->visit=0;
            p=p->next;
        }
    }
    return;
}

void bfs(int s, list ll[10], int n){
    int queue[40],front=0,rear=-1,i,temp;
    node *p;
    queue[++rear]=s;
    visitor(s+1,ll,n);
    while(front != rear+1){
        temp=queue[front++];
        printf("-> %d ",temp+1);
        p=ll[temp].start;
        while(p != NULL){
            if(p->visit == 0){
                visitor(p->val,ll,n);
                queue[++rear]=(p->val)-1;
            }
            p=p->next;
        }
    }
    return;
}

void dfs(int s, list ll[20], int n){
    node *p;
    p=ll[s].start;
    visitor(p->val,ll,n);
    printf("-> %d ",p->val);
    while(p != NULL){
        if(p->visit == 0)
            dfs((p->val)-1,ll,n);
        p=p->next;
    }
    return;
}

int main()
{
    list ll[20];
    int n,i,e,u,v,s;
    for(i=0; i < 20; i++)
        ll[i].start=NULL;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    initialiser(n,ll);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    printf("Enter edges:\n");
    for(i=0; i < e; i++){
        scanf("%d%d",&u,&v);
        addedge(u,v,ll);
        printf("Done\n");
    }
    display(n,ll);
    printf("Enter start node: ");
    scanf("%d",&s);
    printf("DFS:\n");
    dfs(s-1,ll,n);
    devisitor(n,ll);
    printf("\nBFS:\n");
    bfs(s-1,ll,n);
    return 0;
}