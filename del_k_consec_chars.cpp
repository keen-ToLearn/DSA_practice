#include <iostream>
#include <string>

using namespace std;

int main(){
    string s("geeksforgeeks"),ans;
    //string s("abbbajabbbadabbba"),ans;
    //string s("bbbbbbbbbbbbbbbbb"),ans;
    //string s("qddxxxd"),ans;
    int k=2;
    int l=s.length();
    cout<<l<<"\n";
    string prev;
    do{
        prev=s;
        ans="";
        for(int i=0; i<l-1;i++){
            if(s[i] == s[i+1]){
                string tmp(k,s[i]);
                if(!tmp.compare(s.substr(i,k))){
                    if(i+k > l-2)
                        ans+=s.substr(i+k);
                    i=i+k-1;
                }
                else{
                    if(i==l-2)
                        ans+=s.substr(i);
                    else
                        ans+=s[i];
                }
            }
            else{
                if(i == l-2)
                    ans+=s.substr(i);
                else
                    ans+=s[i];
            }
        }
        l=ans.length();
        s=ans;
    }while(prev.compare(s) && l>1);
    cout<<s;
    return 0;
}