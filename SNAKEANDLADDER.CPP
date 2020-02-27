#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int N = 100005;
struct graph{
	int V;
	vector<int> *u;
	graph(int d){
		V=d;
		u=new vector<int>[V];
	}
	void addEdge(int u1,int v1,bool bidir=true){
		u[u1].pb(v1);
		if(bidir){
			u[v1].pb(u1);
		}
	}
	int bfs(int src,int dest){
		queue<int> q;
		map<int,int> dist;
		for(int i=0;i<V;i++){
			dist[i]=INT_MAX;
		}
		q.push(src);
		dist[src]=0;
		while(!q.empty()){
			int node=q.front();
			//cout<<node<<" ";
			q.pop();
			for(int ver:u[node]){
				if(dist[ver]==INT_MAX){
					q.push(ver);
					dist[ver]=dist[node]+1;
				}
			}
		}
		//cout<<endl;
		//cout<<endl;
		/*for(int i=0;i<V;i++){
			int node=i;
			cout<<"THE SHORTEST DISTANCE OF "<<node<<" is "<<dist[node]<<endl;
		}*/
		return dist[dest];
	}

};
void solve(){
	graph g(37);
	int board[50]={0};
	board[2]=13;
	board[5]=2;
	board[9]=18;
	board[18]=11;
	board[17]=-13;
	board[20]=-14;
	board[24]=-8;
	board[25]=-10;
	board[32]=-2;
	board[34]=-22;
	for(int i=0;i<=36;i++){
		for(int j=1;j<=6;j++){
			int v=j+i+board[j+i];
			g.addEdge(i,v,false);
		}
	}
	cout<<"THE SHORTEST DISTANCE IS: "<<g.bfs(0,36);
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
