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

vector<int> adj[26];
bool visited[26], present[26];

void dfs(int s)
{
	visited[s] = true;

	for (auto it : adj[s]) {
		if (!visited[it]) {
			dfs(it);
		}
	}
}

void solve()
{
	int n;
	cin >> n;

	rep(i, 0, n) {
		string s; cin >> s;

		rep(j, 0, sz(s)) {
			int u = s[j] - 'a';
			present[u] = true;

			rep(k, j + 1, sz(s)) {
				int v = s[k] - 'a';
				adj[u].pb(v);
				adj[v].pb(u);
			}
		}
	}

	int cnt = 0;

	rep(i, 0, 26) {
		if (!visited[i] && present[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}