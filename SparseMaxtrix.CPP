#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[5][5],arr1[5][5],count1=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
            if(arr[i][j]==0){
                count1++;
            }
        }
    }
    int l=1;
    if(count1<(3*3)/2){
        cout<<"The Matrix is Not Sparse"<<endl;
    }
    else{
        cout<<"The Matrix is Sparse"<<endl;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(arr[i][j]!=0){
                    arr1[0][0]=3;
                    arr1[0][1]=3;
                    arr1[0][2]=9-count1;
                    for(int k=0;k<3;k++){
                        if(k==0){
                            arr1[l][k]=i;
                        }
                        else if(k==1){
                            arr1[l][k]=j;
                        }
                        else{
                            arr1[l][k]=arr[i][j];
                        }
                    }
                    l++;
                }
            }
        }
        for(int o=0;o<=9-count1;o++){
            for(int y=0;y<3;y++){
                cout<<arr1[o][y]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
