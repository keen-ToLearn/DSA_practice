//right rotate K times, reversal algorithm
#include <bits/stdc++.h>
using namespace std;

void revarr(int a[50], int s, int e){
    while(s<e){
        swap(a[s],a[e]);
        s++;
        e--;
    }
}
void printarr(int a[50], int n){
    for(int i=0; i<n; i++)
        cout<<"->"<<a[i];
}
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int k=3,n=10;
    printarr(a,n);
    cout<<"\n";
    revarr(a,0,n-1);
    revarr(a,0,k-1);
    revarr(a,k,n-1);
    printarr(a,n);
    return 0;
}