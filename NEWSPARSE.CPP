#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[100][100],count1=0,arr1[100][100];
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>arr[i][j];
			if(arr[i][j]!=0){
				count1++;
			}
		}
	}
	int u;
	if((25-count1)>25/2){
		cout<<"The Matrix is SPARSE"<<endl;
		u=1;	
	}
	else{
		cout<<"The Matrix is NOT SPARSE"<<endl;
		u=0;
	}
	if(u==1){
	int l=1;
	for(int i=0;i<5;i++,l++){
		for(int j=0;j<5;j++){
			if(arr[i][j]!=0){
				arr1[0][0]=5;
				arr1[0][1]=5;
				arr1[0][2]=count1;
				arr1[l][0]=i;
				arr1[l][1]=j;
				arr1[l][2]=arr[i][j];				
			}						
		}
		
	}
	for(int o=0;o<=count1;o++){
		for(int p=0;p<3;p++){
			cout<<arr1[o][p]<<" ";
		}
		cout<<endl;
	}}
	else{
		return 0;
	}
	return 0;
}
