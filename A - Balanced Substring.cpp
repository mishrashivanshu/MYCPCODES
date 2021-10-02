#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define inf (int)1e9
#define fo(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef pair<int, int> pii; 
typedef vector<int> vii;
typedef vector<bool> vbb;
typedef vector<pair<int,int>> vpii;

void solve() {
  int n;
  cin>>n;
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++){
      int a=0,b=0;
      for(int j=i;j<s.size();j++){
          if(s[j]=='a') a++;
          else b++;
          if(a==b){
              cout<<i+1<<" "<<j+1<<"\n";
              return;
          }
      }
  }
  cout<<-1<<" "<<-1<<"\n";
}


int32_t main(){
	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
