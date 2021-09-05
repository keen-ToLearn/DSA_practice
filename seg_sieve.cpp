/*
1. store all primes upto sqrt of n, keep count of primes upto sqrt of n
2. set low = limit, high = 2*limit
3. while low < n, also set high to n if high > n
4. for all stored primes, starting with first multiple of prime in range
   mark all multiples false
   create marking array with size limit
   and set value false for mark[j-low]
   where low is lower limit
5. store all primes into map
*/
#include <bits/stdc++.h>
using namespace std;

void simplesieve(int lim, map<int, bool> &m, int *r){
    vector<bool> id(lim+1,true);
    id.at(0)=id.at(1)=false;
    for(long long i=2; i*i<=lim; i++)
        if(id.at(i))
            for(long long j=i*i; j<=lim; j+=i)
                id.at(j)=false;
    for(int i=2; i<=lim; i++)
        if(id.at(i)){
            m[i]=true;
            (*r)++;
        }
}

void segmentedsieve(int l, map<int, bool> &id){
    int c=0,limit=sqrt(l);
    map<int, bool> tmp;
    simplesieve(limit,tmp,&c);
    id=tmp;
    int low=limit,high=2*limit;
    while(low<l){
        int tc=c;
        if(high>l)
            high=l;
        vector<bool> prm(limit+1,true);
        map<int, bool>::iterator it;
        it = id.begin();
        while(tc--){
            int lowmul=floor((float)low/(it->first))*(it->first);
            while(lowmul < low)
                lowmul+=(it->first);
            for(int i=lowmul; i<high; i+=(it->first))
                prm.at(i-low)=false;
            it++;
        }
        for(int i=low; i<high; i++)
            if(prm.at(i-low))
                id[i]=true;
        low+=limit;
        high+=limit;
    }
}

int main(){
    //int l=1000000007;
    int l=100;
    map<int, bool> id;
    segmentedsieve(l,id);
    for(auto it: id){
        cout<<it.first<<"_";
    }
    return 0;
}