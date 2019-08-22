#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr1[100],arr2[100],arr3[700];
    int n1,n2;
    cin>>n1>>n2;
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    int s;
for(s=0;s<n1;s++){
    arr3[s]=arr1[s];
}
for(int r=0;r<n2;r++){
    arr3[s]=arr2[r];
    s++;
}
sort(arr3,arr3+n1+n2);
for(int i=0;i<n1+n2;i++){
    if(arr3[i]==arr3[i+1]){
        cout<<arr3[i]<<" ";
        i++;
    }
    else{
        cout<<arr3[i]<<" ";
    }
}

    return 0;
}
