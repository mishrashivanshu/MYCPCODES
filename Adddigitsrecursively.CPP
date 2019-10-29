#include<bits/stdc++.h>
using namespace std;
int adddigits(int n){
    if(n<10){
        return n;
    }
    return adddigits(n/10)+n%10;
}
int main(){
    int n;
    cin>>n;
    cout<<adddigits(n)<<endl;
    return 0;
}
