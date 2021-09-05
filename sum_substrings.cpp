#include <iostream>
#include <string>
using namespace std;

int main(){
    string s="1984";
    //sum of all substrings of a number string
    //end1 = 1
    //end9 = 9 + 19 = 9*2 + 10*(1)
    //end8 = 8 + 98 + 198 = 8*3 + 10*(9+19)
    //end4 = 4 + 84 + 984 + 1984 = 4 + 80+4 + 980+4 + 1980+4 = 4*4 + 10*(8+98+198)
    int prev=0,cur=0,sum=0;
    for(int i=0; i<s.size(); i++){
        string tmp="";
        tmp+=s[i];
        cur=(stoi(tmp)*(i+1))+(10*prev);
        sum+=cur;
        prev=cur;
        cout<<prev<<" "<<sum<<"\n";
    }
    cout<<sum;
    return 0;
}