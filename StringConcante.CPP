#include<bits/stdc++.h>
using namespace std;
int counta(string s,long int n){
    long int j,i,l=0;
    for(j=0;s[j]!=0;j++);
    long int k=0,count1=0;
    while(true){
        for(i=0;i<j;i++,l++){
            if(s[i]=='a'){
                count1++;
            }
            if(l==n-1){
                return count1;
            }
        }
    }
}
int main(){
    string s;
    cin>>s;
    long int n;
    cin>>n;
    cout<<counta(s,n);
    return 0;
}
