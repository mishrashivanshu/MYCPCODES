//..........................SHIVANSHU MISHRA............................
//..............CODED WITH LOVE.........................................
// 1. GRAPH TRAVERSALS (DFS AND BFS)
// 2. SINGLE SOURCE SHORTEST PATH (DIJKSTRA, BELLMANFORD)
// 3. All pair shortest path (Floyd Warshall Algorithm)
// 4. DISJOINT SET UNION AND KRUSKAL's Algorithm (FINDING MINIMUM cosT SPANNING TREE)
// GRAPH USED : A directed graph with cycles.
// 0->1, 2
// 0->3, 1
// 1->2, 3
// 2->6, 4
// 6->0, 3
// 2->3, 1
// 3->4, 0
// 4->5, 2
// 5->4, 0

//INPUT
/*
7 9
0 1 2
0 3 1
1 2 3
2 6 4
6 0 3
2 3 1
3 4 0
4 5 2
5 4 0
*/



// OUTPUT:
/*
Printing the DFS:
0 1 2 6 3 4 5
Printing the BFS:
0 1 3 2 4 6 5
Printing the distance array:
0 1 2 1 2 3 3

DIJKSTRA's OUTPUT:
0 2 5 1 1 3 9

BELLMAN's OUTPUT:
0 2 5 1 1 3 9

FLOYD WARSHALL's OUTPUT:
0 2 5 1 1 3 9
10 0 3 4 4 6 7
7 9 0 1 1 3 4
-1 -1 -1 0 0 2 -1
-1 -1 -1 -1 0 2 -1
-1 -1 -1 -1 0 0 -1
3 5 8 4 4 6 0
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl           '\n'
#define F              first
#define S              second
#define int             long long int
#define pb              push_back
#define mp              make_pair
#define P             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define N 				100005
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
}
vector<pair<int, int>> v[N];
// Makes a directed graph.
void make_graph(int a, int b, int w, bool dir = true) {
	v[a].pb({b, w});
	if (dir) return;
	v[b].pb({a, w});
}
// DFS
void dfs_help(int src, int visited[]) {
	visited[src] = 1;
	cout << src << " ";
	for (auto a : v[src]) {
		if (visited[a.F]) continue;
		dfs_help(a.F, visited);
	}
}
void dfs(int n, int src) {
	int visited[N];
	memset(visited, 0, n);
	dfs_help(src, visited);
}

//BFS
void bfs(int n, int src) {
	int dist[N];
	memset(dist, 0, n);
	int visit[N];
	for (int i = 0; i < n; i++) {
		visit[i] = 0;
	}
	queue<int> q;
	q.push(src);
	visit[src] = 1;
	cout << src << " ";
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		for (auto a : v[s]) {
			if (visit[a.F] == 1) continue;
			q.push(a.F);
			cout << a.F << " ";
			visit[a.F] = 1;
			dist[a.F] = dist[s] + 1;
		}

	}
	cout << endl;
	cout << "Printing the distance array:\n";
	for (int i = 0; i < n; i++) {
		cout << dist[i] << " ";
	}
	cout << endl;
}

// DIJKSTRA's ALGORITHM
void dijkstra(int src, int n) {
	priority_queue<pair<int, int>> pq;
	int distance[N];
	distance[src] = 0;
	bool relaxed[N] = {false};
	for (int i = 1; i < n; i++) {
		distance[i] = inf;
	}
	pq.push({distance[src], src});
	relaxed[src] = true;
	while (!pq.empty()) {
		int s = pq.top().S;
		pq.pop();
		relaxed[s] = true;
		for (auto a : v[s]) {
			if (relaxed[a.F])continue;
			if (distance[a.F] > distance[s] + a.S) {
				distance[a.F] = distance[s] + a.S;
			}
			pq.push({ -1 * distance[a.F], a.F});
		}
	}
	for (int i = 0; i < n; i++) {
		cout << distance[i] << " ";
	}
	cout << endl;
}

//BELLMAN FORD ALGORITHM

void bellmanford(int src, int n, int m) {
	int distance[N];
	for (int i = 0; i < n; i++) {
		distance[i] = inf;
	}
	distance[src] = 0;
	//making an edge list.
	vector<pair<int, pair<int, int>>> ve;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			ve.pb({i, {v[i][j].F, v[i][j].S}});
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < ve.size(); j++) {
			if (distance[ve[j].F] + ve[j].S.S < distance[ve[j].S.F]) {
				distance[ve[j].S.F] = distance[ve[j].F] + ve[j].S.S;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << distance[i] << " ";
	}
	cout << endl;
}

// FLOYD WARSHALL ALGORITHM

void warshall(int src, int n) {
	int dis[n + 1][n + 1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dis[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			dis[i][v[i][j].F] = v[i][j].S;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				dis[i][j] = 0;
			}
			else if (dis[i][j] == -1) {
				dis[i][j] = inf;
			}
		}
	}


	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dis[i][j] != inf)
				cout << dis[i][j] << "  ";
			else {
				cout << -1 << "  ";
			}
		}
		cout << endl;
	}
}
// IMPLEMENTING DISJOINT SET UNION FROM HERE ON.

int find(int x, vector<int> link) {
	while (x != link[x]) {
		x = link[x];
	}
	return x;
}

bool same(int a, int b, vector<int> &link) {
	return find(a, link) == find(b, link);
}

void unite(int a, int b, vector<int> &link, vector<int> &size) {
	a = find(a, link);
	b = find(b, link);
	if (size[a] < size[b]) {
		swap(a, b);
	}
	size[a] += size[b];
	link[b] = a;
}
// IMPLEMENTED DSU

//IMPLEMENTING Kruskal's Algorithm'

vector<pair<int, pair<int, int>>> ve;
void makeedgelist(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			ve.pb({v[i][j].S, {i, v[i][j].F}});
		}
	}
	sort(ve.begin(), ve.end());
}

int findminspanningdist(vector<int> &link, vector<int> &size) {
	vector<pair<int, pair<int, int>>> kruskalvector;
	for (int i = 0; i < ve.size(); i++) {
		if (!same(ve[i].S.F, ve[i].S.S, link)) {
			kruskalvector.pb(ve[i]);
			unite(ve[i].S.F, ve[i].S.S, link, size);
		}
	}
	int wt = 0;
	for (int i = 0; i < kruskalvector.size(); i++) {
		wt += kruskalvector[i].F;
	}
	return wt;
}


//IMPLEMENTED KRUSKAL's Algorithm
int32_t main() {
	c_p_c();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		make_graph(a, b, w, false);
	}

	// DOING THIS FOR DSU
	vector<int> link(n);
	for (int i = 0; i < n; i++) {
		link[i] = i;
	}
	vector<int> size(n);
	for (int i = 0; i < n; i++) {
		size[i] = 1;
	}
	// DSU WORK ENDS HERE
	//KRUSKAL'S CALL;
	cout << "THE MINIMUM SPANNNG DISTANCE IS:\n";
	makeedgelist(n);
	cout << findminspanningdist(link, size) << endl << endl;
	//KRUSKAL's CALL ENDS
	cout << "Printing the DFS:\n";
	dfs(n, 0);
	cout << endl << endl;
	cout << "Printing the BFS:\n";
	bfs(n, 0);
	cout << endl << endl;
	cout << "DIJKSTRA's OUTPUT:\n";
	dijkstra(0, n);
	cout << endl << endl;
	cout << "BELLMAN's OUTPUT:\n";
	bellmanford(0, n, m);
	cout << endl << endl;
	cout << "FLOYD WARSHALL's OUTPUT:\n";
	warshall(0, n);// -1 in output denotes infinite distance between two nodes.
	return 0;
}
