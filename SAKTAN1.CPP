#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,q;
        cin>>n>>m>>q;
        int arr1[n+1]={0};
        int arr2[m+1]={0};
        while(q--){
            int x,y;
            cin>>x>>y;
            arr1[x]++;
            arr2[y]++;
        }
        int e=0;
        int f=0;
        for(int i=1;i<=n;i++){
            if(arr1[i]%2==1){
                e++;
            }
        }
        for(int t=1;t<=m;t++){
            if(arr2[t]%2==1){
                f++;
            }
        }
        cout<<e*(m-f)+f*(n-e)<<endl;
    }
    return 0;
}
