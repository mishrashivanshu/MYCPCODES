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
  vector<int> v;
  for(int i=0;i<n;i++){
      if(s[i]=='2') v.pb(i);
  }
  if(v.size()>0 && v.size()<3) {
      cout<<"NO\n";
      return;
  }
  else cout<<"YES\n";
  vector<vector<char>> a(n,vector<char>(n,'='));
  for(int i=0;i<n;i++){
        a[i][i]='X';
  }
  for(int i=1;i<v.size();i++){
      a[v[i-1]][v[i]]='+';
      a[v[i]][v[i-1]]='-';
  }
  if(!v.empty()){
      a[v[0]][v.back()]='-';
      a[v.back()][v[0]]='+';
  }
  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
        cout<<a[i][j];
      cout<<"\n";
  }
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
