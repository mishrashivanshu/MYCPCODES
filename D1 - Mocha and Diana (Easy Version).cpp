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

int root(vector<int> &g,int i){
  while(g[i]!=i){
    i=g[i];
  }
  return i;
}

void solve() {
  int n,m1,m2;
  cin>>n>>m1>>m2;
  vector<int> g1(n),g2(n);
  for(int i=0;i<n;i++){
    g1[i]=g2[i]=i;
  }
  for(int i=0;i<m1;i++){
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    int l=root(g1,x);
    int r=root(g1,y);
    g1[max(l,r)]=min(l,r);
  }
  for(int i=0;i<m2;i++){
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    int l=root(g2,x);
    int r=root(g2,y);
    g2[max(l,r)]=min(l,r);
  }
  vector<int> v1,v2;
  for(int i=0;i<n;i++){
    if(g1[i]==i){
      v1.push_back(i);
    }
    if(g2[i]==i){
      v2.push_back(i);
    }
  }
  
  vector<pair<int,int>> a; 
  for(int i=0;i<v1.size();i++){
    // if(g1[v1[i]]==v1[i])
    for(int j=0;j<v2.size();j++){
      // if(v2[j]!=g2[v2[j]]) continue;
      int x=root(g1,v1[i]);
      int y=root(g2,v2[j]);
      int r1=root(g1,y);
      int r2=root(g2,x);
      if(r1!=x && r2!=y){
        a.push_back({v1[i],v2[j]});
        g1[max(r1,x)]=min(x,r1);
        g2[max(r2,y)]=min(y,r2);
      }
    }
  }
  cout<<a.size()<<"\n";
  for(int i=0;i<a.size();i++){
    cout<<a[i].fi+1<<" "<<a[i].se+1<<"\n";
  }
}


int32_t main(){
	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	solve();

	return 0;
}
