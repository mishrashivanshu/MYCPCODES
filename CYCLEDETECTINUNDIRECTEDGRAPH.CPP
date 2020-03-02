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
class graph{
	map<T,list<T>> u;
public:
	graph(){

	}
	void addEdge(T u1,T v1,bool bidir=true){
		u[u1].pb(v1);
		if(bidir){
			u[v1].pb(u1);
		}
	}
	bool cycledetect(T src){
		map<T,bool> visited;
		queue<T> q;
		map<T,T> parent;
		q.push(src);
		parent[src]=src;
		visited[src]=true;
		while(!q.empty()){
			T node=q.front();
			q.pop();
			for(auto neighbor:u[node]){
				if(visited[neighbor]==true&&parent[node]!=neighbor){
					return true;
				}
				else if(visited[neighbor]==false){
					q.push(neighbor);
					visited[neighbor]=true;
					parent[neighbor]=node;
				}
			}
		}
		return false;
	}
};
void solve(){
	graph<int> g;
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(4,3);
	if(g.cycledetect(1)){
		cout<<"THE GRAPH HAS A CYCLE"<<endl;
	}
	else{
		cout<<"THE GRAPH DOES NOT POSESS A CYCLE."<<endl;
	}
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
