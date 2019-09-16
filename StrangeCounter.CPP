#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long int t;
    cin>>t;
    unsigned long long int j=3;
    while(t>j){
        t=t-j;
        j*=2;
    }
    cout<<j-t+1<<endl;
    return 0;
}
