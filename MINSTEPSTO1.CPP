//...............SHIVANSHU MISHRA.................
//...............MINIMUM STEPS TO ONE.............
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define inf INT_MAX
const int N = 100005;
int fun(int n,int dp[]){
	dp[0]=0;
	dp[1]=0;
	for(int i=2;i<=n;i++){
		int x=inf,y=inf,z=inf;
		if(i%3==0){
			x=dp[i/3];
		}
		if(i%2==0){
			y=dp[i/2];
		}
		z=dp[i-1];
		dp[i]=min(min(x,y),z)+1;
		
	}
	return dp[n];
}
void solve(){
	int t;
	cin>>t;
    int dp[100000]={0};
	while(t--){
		int n;
		cin>>n;
		cout<<fun(n,dp)<<endl;;
	}
	return;
}
int32_t main()
{	
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif*/
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
