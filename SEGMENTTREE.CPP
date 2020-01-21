#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
#define p pair
#define ld long double
#define N 1000000
using namespace std;
void buildtree(int arr[],int start,int end,int *tree,int index){
	if(start==end){
		tree[index]=arr[end];
		return;
	}
	int mid=(start+end)/2;
	buildtree(arr,start,mid,tree,2*index);
	buildtree(arr,mid+1,end,tree,2*index+1);
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
}
void solve(){
	int n;
	cin>>n;
	int arr[N];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int *tree=new int[4*n+1];
	buildtree(arr,0,n-1,tree,1);
	for(int i=1;i<=13;i++){
		cout<<tree[i]<<" ";
	}

	return;
}
int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve();
return 0;
}