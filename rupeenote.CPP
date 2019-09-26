#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[10]={2000,500,200,100,50,20,10,5,2,1};
    int n1[10]={0};
    for(int i=0;i<10;i++){
        if(n>=arr[i]){
            n1[i]=n/arr[i];
            n=n-arr[i]*n1[i];
        }
    }
    for(int i=0;i<10;i++){
        if(n1[i]!=0){
            cout<<n1[i]<<" "<<"no of"<<" "<<arr[i]<<" "<<"rupee notes are required"<<endl;
        }
    }
    return 0;
}
