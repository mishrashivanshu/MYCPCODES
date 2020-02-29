#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005;
template<typename T>
struct graph{
	map<T,list<T>> u;
	graph(){

	}
	void addEdge(T u1,T v1, bool bidir=true){
		u[u1].pb(v1);
		if(bidir){
			u[v1].pb(u1);
		}
	}
	void dfshelp(T src,map<T,bool> &visited){
		cout<<src<<" ";
		visited[src]=true;
		for(auto a: u[src]){
			if(!visited[a]){
				dfshelp(a,visited);
			}
		}
	}
	void dfs(T src){
		map<T,bool> visited;
		dfshelp(src,visited);
	}
	void bfs(T src){
		map<T,bool> visit;
		queue<T> q;
		q.push(src);
		visit[src]=true;
		while(!q.empty()){
			T n=q.front();
			cout<<n<<" ";
			q.pop();
			for(auto a:u[n]){
				if(!visit[a]){
					q.push(a);
					visit[a]=true;
				}
			}
		}
	}
};
void solve(){
	graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(1,3);
	g.dfs(0);
	cout<<endl;
	g.bfs(0);
	return;
}
int32_t main()
{	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
