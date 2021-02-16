#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repR(i, n) for (int i = n-1; i >= 0; --i)
#define repA(i, a, n) for (int i = a; i <= n; ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vd vector<double>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>
#define vpdd vector<pdd>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

vi v, rem;
int n;
vpii ans;
vb visited;

void dfs(int s)
{
	visited[s] = true;

	repA(i, 1, n) {
		if (s == i) {
			continue;
		}

		if (v[s] != v[i]) {
			ans.pb({s, i});
			visited[i] = true;
		}
		else {
			rem.pb(i);
		}
	}
}

void Solve()
{
	bool ok = true;
	vi temp = v;
	sort(all(temp));

	repA(i, 2, n) {
		if (v[i] != v[i - 1]) {
			ok = false;
			break;
		}
	}

	if (ok) {
		cout << "NO" << '\n';
		return;
	}

	cout << "YES" << '\n';

	visited.assign(n + 1, false);

	dfs(1);
	int val = v[1], index = 1;

	repA(i, 2, n) {
		if (val != v[i]) {
			index = i;
		}
	}

	for (auto x : rem) {
		ans.pb({index, x});
	}

	for (auto p : ans) {
		cout << p.ff << " " << p.ss << '\n';
	}
}

int main()
{
	fastio

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;

	while (T-- > 0)
	{
		v.clear();
		rem.clear();
		ans.clear();
		visited.clear();

		cin >> n;
		v.resize(n + 1);

		repA(i, 1, n) {
			cin >> v[i];
		}

		Solve();
	}

	return 0;
}