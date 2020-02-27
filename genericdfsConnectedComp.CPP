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
	void addEdge(T u1,T v1,bool bidir=true){
		u[u1].pb(v1);
		if(bidir){
			u[v1].pb(u1);
		}
	}
	void dfshelp(T src,map<T,bool> &visited){
		visited[src]=true;
		cout<<src<<" ";
		for(auto t:u[src]){
			if(!visited[t]){
				dfshelp(t,visited);
			}
		}
	}
	void dfs(T src){
		map<T,bool> visit;
		dfshelp(src,visit);
		cout<<endl;
		int comp=1;
		for(auto i:u){
			T city=i.first;
			if(!visit[city]){
				dfshelp(city,visit);
				comp++;
			}
		}
		cout<<endl;
		cout<<"THE NUMBER OF COMPONENTS IN THE CURRENT GRAPH ARE: "<<comp;
	}
};
void solve(){
	graph<string> g;
	g.addEdge("Amritsar","Jaipur");
	g.addEdge("Amritsar","Delhi");
	g.addEdge("Delhi","Jaipur");
	g.addEdge("Mumbai","Jaipur");
	g.addEdge("Mumbai","Bhopal");
	g.addEdge("Delhi","Bhopal");
	g.addEdge("Mumbai","Bangalore");
	g.addEdge("Agra","Delhi");
	g.addEdge("Andaman","Nicobar");
	g.dfs("Amritsar");
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
