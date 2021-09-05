//agenda: dfs, bfs, both using array implementation
#include <stdio.h>
int n,adjacencyMatrix[20][20],visited[20]={0};
void dfs(int r){
    int i;
    visited[r]=1;
    printf("-> %d ",r+1);
    for(i=0; i < n; i++)
        if(adjacencyMatrix[r][i] == 1 && visited[i] == 0)
            dfs(i);
    return;
}
void bfs(int r){
    int queue[40],front=0,rear=-1,i,node;
    queue[++rear]=r;
    visited[r]=1;
    while(front != rear+1){
        node=queue[front++];
        printf("-> %d ",node+1);
        for(i=0; i < n; i++)
            if(adjacencyMatrix[node][i] == 1 && visited[i] == 0){
                visited[i]=1;
                queue[++rear]=i;
            }
    }
    return;
}
int main(){
    char opt,opt1;
    int r,i,j;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0; i < n; i++)
        for(j=i; j < n; j++)
            adjacencyMatrix[i][j]=adjacencyMatrix[j][i]=(i == j)?0:999;
    printf("Specify edges...\n");
    do{
        scanf("%d%d",&i,&j);
        adjacencyMatrix[i-1][j-1]=adjacencyMatrix[j-1][i-1]=1;
        printf("More?(Y/N) ");
        scanf("\n%c",&opt);
    }while(opt == 'Y');
    printf("Enter start node: ");
    scanf("%d",&r);
    printf("Graph traversal: D - DFS, B - BFS :- ");
    scanf("\n%c",&opt1);
    if(opt1 == 'D')
        dfs(r-1);
    if(opt1 == 'B')
        bfs(r-1);
    return 0;
}