#include <bits/stdc++.h>
using namespace std;

void permute(string a, int l, int r){
    if(l == r)
        cout<<a<<"\n";
    else
        for(int i=l; i<=r; i++){
            swap(a[l],a[i]);
            permute(a,l+1,r);
            //backtrack - again swapping ith and lth characters
            swap(a[l],a[i]);
        }
}

int main()
{
    string s="ABCD";
    permute(s,0,3);
    return 0;
}