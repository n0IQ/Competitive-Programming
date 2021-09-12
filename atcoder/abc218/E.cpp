#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, a, b) for(int i = a; i < b; i++)
#define repR(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int MaxN = 2e5 + 10;
int n, m;

struct Edge {
	int u, v, w;
};

Edge edges[MaxN];
int p[MaxN], r[MaxN];

void init()
{
	rep(i, 0, MaxN) {
		p[i] = i;
		r[i] = 1;
	}
}

int find_set(int x)
{
	if (p[x] == x) {
		return x;
	}

	return p[x] = find_set(p[x]);
}

void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);

	if (a != b) {
		if (r[a] < r[b])
			swap(a, b);
	}

	p[b] = p[a];
	r[a] += r[b];
}

void addEdge(Edge &e, int u, int v, int w)
{
	e.u = u, e.v = v, e.w = w;
}

bool comp(Edge &e1, Edge &e2)
{
	return e1.w < e2.w;
}

ll KruskalMST()
{
	sort(edges, edges + m, comp);
	ll reward = 0;

	rep(i, 0, m) {
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		u = find_set(u);
		v = find_set(v);

		if (u != v) {
			union_set(u, v);
		}
		else if (w > 0) {
			reward += w;
		}
	}

	return reward;
}

void solve()
{
	cin >> n >> m;
	rep(i, 0, m) {
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(edges[i], u, v, w);
	}

	cout << KruskalMST() << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	init();
	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}