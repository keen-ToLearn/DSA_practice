#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    string x,y;
    getline(cin,x);//ABCBABC
    getline(cin,y);//BABDCBA
    int n,m;
    n=x.length();//vertical rows
    m=y.length();//horizontal column
    cout<<x<<" "<<n<<"\n";
    cout<<y<<" "<<m<<"\n";
    int lcs[n+1][m+1];
    //creating lookup table
    for(int i=0; i<n+1; i++)
        lcs[i][0]=0;
    for(int i=0; i<m+1; i++)
        lcs[0][i]=0;
    for(int i=1; i<n+1; i++)
        for(int j=1; j<m+1; j++)
            if(x[i-1] == y[j-1])
                lcs[i][j]=lcs[i-1][j-1]+1;
            else
                lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
    //printing lookup table
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            cout<<lcs[i][j]<<" ";
        }
        cout<<"\n";
    }
    //finding lcs
    cout<<"length of lcs: "<<lcs[n][m]<<"\n";
    stack<char> seq;
    int i=n,j=m;
    while(lcs[i][j]){
        if(lcs[i-1][j-1] == lcs[i][j-1] && lcs[i][j-1] == lcs[i-1][j]){
            if(lcs[i][j] == lcs[i-1][j-1])
                j--;
            else{
                seq.push(x[i-1]);
                i--;
                j--;
            }
        }
        else if(lcs[i][j-1] > lcs[i-1][j] && lcs[i][j-1] > lcs[i-1][j-1])
            j--;
        else if(lcs[i-1][j] > lcs[i][j-1] && lcs[i-1][j] > lcs[i-1][j-1])
            i--;
        else{
            seq.push(x[i-1]);
            i--;
            j--;
        }
    }
    cout<<"lcs: ";
    while(!seq.empty()){
        cout<<seq.top();
        seq.pop();
    }
    cout<<"\n";
    return 0;
}