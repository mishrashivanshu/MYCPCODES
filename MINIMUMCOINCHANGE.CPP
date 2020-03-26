//.......................SHIVANSHU MISHRA.................................
//.................MINIMUM COIN CHANGE PROBLEM............................
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005;
void solve(){
	int t;// for possible number of denominations...
	cin>>t;
	int n;
	cin>>n;
	int arr[10];// for storing the possible denominations...
	for(int i=0;i<t;i++){
		cin>>arr[i];
	}
	int dp[1000]={0};
	for(int i=1;i<=n;i++){
        dp[i]=INT_MAX;
		for(int j=0;j<t;j++){
			if(i-arr[j]>=0){
				int x=dp[n-arr[j]];
				dp[i]=min(dp[i],x+1);
			}
		}
	}
	cout<<dp[n]<<endl;
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
