#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define fi first
#define se second
#define pb push_back
#define mod 998244353
#define inf (int)1e9
#define fo(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef pair<int, int> pii; 
typedef vector<int> vii;
typedef vector<bool> vbb;
typedef vector<pair<int,int>> vpii;

int fact[1000001];

int powe(int a,int n){
    if(n==0) return 1;
    int x=powe(a,n/2);
    x=(x*x)%mod;
    if(n&1) x=(x*a)%mod;
    return x;
}

int ncr(int n,int r){
    int u=fact[n];
    int d=(fact[r]*fact[n-r])%mod;
    return (u*(powe(d,mod-2)%mod))%mod;
}

void solve() {
  int n;
  cin>>n;
  vii a(n);
  for(int i=0;i<n;i++){
      cin>>a[i];
  }
  sort(a.begin(),a.end());
  if(a[n-1]-a[n-2]>1) {
      cout<<0<<"\n";
      return;
  }
  if(a.back()-a[n-2]==0){
      cout<<fact[n]<<"\n";
  }
  else{
      int c=0;
      for(int i=n-2;i>=0;i--){
          if(a.back()-a[i]==1) c++;
          else break;
      }
      int ans=fact[n];
      int p=n-c-1;
      for(int i=c;i<n;i++){
          ans=(ans-(fact[n-i-1]*((ncr(p,i-c)*fact[i])%mod)%mod)+mod)%mod;
      }
      cout<<ans<<"\n";
  }
}


int32_t main(){
	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    fact[0]=fact[1]=1;
    for(int i=2;i<1000001;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
