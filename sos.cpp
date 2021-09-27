#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;

void sos(vector<int> w, vector<int> X, int M, int k, int sum, int rem){
    //checking if adding current item to sum gives required ans
    if(sum+w[k] == M){
        X.at(k)=1;
        for(int i=0; i<X.size(); i++)
            if(X.at(i))
                cout<<w[i]<<" ";
        cout<<"\n";
    }
    //selecting current element; if current and next item when added to sum is smaller or equal to required ans
    else if(sum+w[k]+w[k+1] <= M){
        X.at(k)=1;
        sos(w,X,M,k+1,sum+w[k],rem-w[k]);
    }
    //not selecting current element & going ahead with next element; if remaining sum & current sum are sufficient to get required ans only then go ahead
    if(sum+rem-w[k] >= M && sum+w[k+1] <= M){
        X.at(k)=0;
        sos(w,X,M,k+1,sum,rem-w[k]);
    }
}

int main(){
    vector<int> w({1,1,2,3,4,6,7});//for sorted weights
    vector<int> X(7,0);
    int M=7;
    int rem=accumulate(w.begin(), w.end(), 0);
    sos(w,X,M,0,0,rem);
    return 0;
}