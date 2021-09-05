#include <bits/stdc++.h>
using namespace std;

int arrangement(int n){
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    int n1=0,n2=1,ans=0;
    for(int i=3; i<=n; i++){
        ans=(i-1)*(n1+n2);
        n1=n2;
        n2=ans;
    }
    return ans;
}

int main(){
    cout<<arrangement(7);
    return 0;
}