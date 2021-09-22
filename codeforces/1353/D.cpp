#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
	int n;
	cin >> n;

	int a[n + 1] = {0};
	multiset<int, greater<int>> s;
	vector<set<pii>> adj(n + 1);

	s.insert(n);
	adj[n].insert({1, n});
	int cnt = 1;

	while (cnt <= n) {
		int x = *s.begin();
		s.erase(s.begin());

		auto it = adj[x].begin();
		int l = it->ff, r = it->ss, t, newl, newr;
		adj[x].erase(adj[x].begin());

		if ((r - l + 1) % 2 == 1) {
			t = (l + r) / 2, newl = t - 1, newr = t + 1;
			a[t] = cnt++;
		}
		else {
			t = (l + r - 1) / 2, newl = t - 1, newr = t + 1;
			a[t] = cnt++;
		}

		if (l <= newl) {
			s.insert(newl - l + 1);
			adj[newl - l + 1].insert({l, newl});
		}
		if (r >= newr) {
			s.insert(r - newr + 1);
			adj[r - newr + 1].insert({newr, r});
		}
	}

	rep(i, 1, n + 1) cout << a[i] << ' ';
	cout << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}