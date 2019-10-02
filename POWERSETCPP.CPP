#include<bits/stdc++.h>
using namespace std;
void powerset(int arr[],int size){
    cout<<"NULL"<<endl;
    for(int i=1;i<pow(2,size);i++){
        for(int j=0;j<size;j++){
            if(i&(1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
    return ;
}
int main(){
    int n;
    cin>>n;
    int arr[1000000];
    for(int t=0;t<n;t++){
        cin>>arr[t];
    }
    powerset(arr,n);
    cout<<endl;
    return 0;
}
