#include<bits/stdc++.h>
using namespace std;
void check(int x,int y,int arr[10000][10000],int sizerow,int sizecol){
    for(int i=0;i<sizecol;i++){
        arr[x-1][i]+=1;
    }
    for(int t=0;t<sizerow;t++){
        arr[t][y-1]+=1;
    }
}
int countodd(int arr[10000][10000],int sizerow,int sizecol){
    int countx=0;
    for(int t=0;t<sizerow;t++){
        for(int n=0;n<sizecol;n++){
            if(arr[t][n]%2!=0){
                countx++;
            }
        }
    }
    return countx;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,q;
        cin>>n>>m>>q;
        int arr[10000][10000];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=0;
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            check(x,y,arr,n,m);
        }
        cout<<countodd(arr,n,m)<<endl;
    }
    return 0;
}
