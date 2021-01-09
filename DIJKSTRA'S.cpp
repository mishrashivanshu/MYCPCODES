//..........................SHIVANSHU MISHRA............................
//..............CODED WITH LOVE.........................................
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
vector<P> V[N];
void mg(int a, int b, int w) {
	V[a].pb({b, w});
	V[b].pb({a, w});
}
void dijkstra(int src, vector<int> &distances) {
	bool visited[N] = {false};
	distances[src] = 0;
	priority_queue<P> pq;
	pq.push({0, src});
	while (!pq.empty()) {
		int a = pq.top().S;
		pq.pop();
		if (visited[a]) {
			continue;
		}
		visited[a] = true;
		for (auto u : V[a]) {
			int b = u.F, w = u.S;
			if (distances[a] + w < distances[b]) {
				distances[b] = distances[a] + w;
				pq.push({ -1 * distances[b], b});
			}
		}
	}
}
int32_t main() {
	c_p_c();
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		mg(a, b, w);
	}
	int src = 0;
	vector<int> distances(n);
	for (int i = 0; i < n; i++) {
		distances[i] = INT_MAX;
	}
	dijkstra(src, distances);
	for (int i = 0; i < distances.size(); i++) {
		cout << distances[i] << " ";
	}
	cout << endl;
	return 0;
}
