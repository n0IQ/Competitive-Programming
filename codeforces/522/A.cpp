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

vvi adj;
int ans;

void dfs(int s, int tweets)
{
	for (auto v : adj[s]) {
		dfs(v, tweets + 1);
	}

	ans = max(ans, tweets);
}

void solve()
{
	int n, j = 1;
	cin >> n;
	ans = 1;

	adj.resize(1000);
	unordered_map<string, int> mp;
	rep(i, 0, n) {
		string s1, s2, s3; cin >> s1 >> s2 >> s3;
		transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
		transform(s3.begin(), s3.end(), s3.begin(), ::tolower);
		if (mp.find(s3) == mp.end()) mp[s3] = j++;
		if (mp.find(s1) == mp.end()) mp[s1] = j++;

		adj[mp[s3]].pb(mp[s1]);
	}

	/*rep(i, 1, n + 1) {
		cout << i << "-> ";

		for (auto v : adj[i]) {
			cout << v << " ";
		}

		cout << '\n';
	}*/

	dfs(1, 1);
	cout << ans << '\n';
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