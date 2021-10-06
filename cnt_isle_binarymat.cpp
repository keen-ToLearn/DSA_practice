//count islands in binary matrix
//IMP: recursive solution causes the function call stack to collapse
#include <bits/stdc++.h>
using namespace std;

void visitor(int i, int j, vector<vector<int>>& visited, vector<vector<char>> grid){
    int r,c;
    r=grid.size();
    c=grid[0].size();
    visited[i][j] = 1;
    //top row
    if(i-1 >= 0){
        if(j-1 >= 0 && (grid[i-1][j-1] == '1' && visited[i-1][j-1] == 0)){//i-1, j-1
            visitor(i-1,j-1,visited,grid);
        }
        else if(j+1 < c && (grid[i-1][j+1] == '1' && visited[i-1][j+1] == 0)){//i-1, j+1
            visitor(i-1,j+1,visited,grid);
        }
        else{//i-1, j
            if(grid[i-1][j] == '1' && visited[i-1][j] == 0)
                visitor(i-1,j,visited,grid);
        }
    }
    //right column
    if(j+1 < c){
        if(i+1 < r && (grid[i+1][j+1] == '1' && visited[i+1][j+1] == 0)){//i+1, j+1
            visitor(i+1,j+1,visited,grid);
        }
        else{//i, j+1
            if(grid[i][j+1] == '1' && visited[i][j+1] == 0)
                visitor(i,j+1,visited,grid);
        }
    }
    //bottom row
    if(i+1 < r){
        if(j-1 >= 0 && (grid[i+1][j-1] == '1' && visited[i+1][j-1] == 0)){//i+1, j-1
            visitor(i+1,j-1,visited,grid);
        }
        else{//i+1, j
            if(grid[i+1][j] == '1' && visited[i+1][j] == 0)
                visitor(i+1,j,visited,grid);
        }
    }
    //left column
    if(j-1 >= 0){//i, j-1
        if(grid[i][j-1] == '1' && visited[i][j-1] == 0)
                visitor(i,j-1,visited,grid);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int r,c;
    r=grid.size();
    c=grid[0].size();
    vector<vector<int>> visited;
    vector<int> tmp(c,0);
    for(int i=0; i<r; i++){//initialising visited with all 0s
        visited.push_back(tmp);
    }
    int island=0;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            if(grid[i][j] == '0' || visited[i][j] == 1)
                continue;
            else{
                visitor(i,j,visited,grid);
                island++;
            }
        }
    return island;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m,'#'));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>grid[i][j];
    int ans = numIslands(grid);
    cout<<ans;
    return 0;
}