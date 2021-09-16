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

const int MaxN = 5e5 + 10;
ll alp[MaxN], als[MaxN], bobp[MaxN], bobs[MaxN];

void solve()
{
	int n;
	cin >> n;

	int a[n], b[n];
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) {
		char c; cin >> c;
		if (c == 'A') b[i] = 0;
		else b[i] = 1;
	}

	rep(i, 1, n + 1) {
		if (b[i - 1] == 1) {
			bobp[i] = a[i - 1] + bobp[i - 1];
			alp[i] = alp[i - 1];
		}
		else {
			alp[i] = a[i - 1] + alp[i - 1];
			bobp[i] = bobp[i - 1];
		}
	}

	repR(i, n, 1) {
		if (b[i - 1] == 1) {
			bobs[i] = a[i - 1] + bobs[i + 1];
			als[i] = als[i + 1];
		}
		else {
			als[i] = a[i - 1] + als[i + 1];
			bobs[i] = bobs[i + 1];
		}
	}

	ll res1 = 0, res2 = 0;
	rep(i, 1, n + 1) {
		res1 = max(res1, alp[i] + bobs[i]);
		res2 = max(res2, als[i] + bobp[i]);
	}

	cout << max({res1, res2}) << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}