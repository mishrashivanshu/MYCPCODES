#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr1[100],arr2[100];
    vector<int> v;
    int n1,n2;
    cin>>n1>>n2;
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(arr1[i]==arr2[2]){
                cout<<arr1[i]<<" ";
                break;
            }
        }
    }
    cout<<endl;
    for(int o=0;o<n1;o++){
        v.push_back(arr1[o]);
        for(int y=0;y<n2;y++){
            if(arr1[o]!=arr2[y]){
                if(o<n2){
                v.push_back(arr2[o]);
                break;}
            }
        }
    }
    int q=0;
    for(int u=0;u<v.size();u++){
        for(int t=0;t<v.size();t++){
            if(u!=t){
            if(v[u]==v[t]){
                q=v[u];
            }
        }
    }}
    for(int s=0;s<v.size();s++){
        if(v[s]!=q){
            cout<<v[s]<<" ";
        }
    }
    cout<<q;
    return 0;
}
