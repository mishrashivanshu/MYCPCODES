#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
#define p pair
#define ld long double
#define N 1000000
using namespace std;
struct segment{
	void buildtree(int arr[],int start,int end,int *tree,int index){
	if(start==end){
		tree[index]=arr[start];
		return;
	}
	int mid=(start+end)/2;
	buildtree(arr,start,mid,tree,2*index);
	buildtree(arr,mid+1,end,tree,2*index+1);
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
	}
	int query(int *tree,int qs,int qe,int start,int end,int index){
	//Complete Overlap
		if(start>=qs&&end<=qe){
			return tree[index];
		}
	//NO OVERLAP
		if(qe<start||qs>end){
			return INT_MAX;
		}
		int mid=(start+end)/2;
		int left=query(tree,qs,qe,start,mid,2*index);
		int right=query(tree,qs,qe,mid+1,end,2*index+1);
		return min(left,right);
	}
	void update(int *tree,int start,int end,int i,int inc,int index){
		if(i>end||i<start){
			return;
		}
		if(start==end){
			tree[index]+=inc;
			return;
		}
		int mid=(start+end)/2;
		update(tree,start,mid,i,inc,2*index);
		update(tree,mid+1,end,i,inc,2*index+1);
		tree[index]=min(tree[2*index],tree[2*index+1]);
	}
	void update(int *tree,int start,int end,int l,int r,int inc,int index){
		if(l>end||r<start){
			return;
		}
		if(start==end){
			tree[index]+=inc;
			return;
		}
		int mid=(start+end)/2;
		update(tree,start,mid,l,r,inc,2*index);
		update(tree,mid+1,end,l,r,inc,2*index+1);
		tree[index]=min(tree[2*index],tree[2*index+1]);
	}
};

void solve(){
	segment s;
	int n;
	cin>>n;
	int arr[N];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int *tree=new int[4*n+1];
	s.buildtree(arr,0,n-1,tree,1);
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		cout<<s.query(tree,l,r,0,n-1,1)<<endl;
	}
	s.update(tree,0,n-1,1,14,1);
	cout<<s.query(tree,1,2,0,n-1,1)<<endl;
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