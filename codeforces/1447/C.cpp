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

void solve()
{
	int n;
	ll W;
	cin >> n >> W;

	ll a[n];
	multimap<ll, ll> mp;
	rep(i, 0, n) {
		cin >> a[i];
		mp.insert({a[i], i});
	}

	ll least = (W + 2 - 1) / 2LL;
	sort(a, a + n, greater<ll>());

	vll v;
	ll wt = 0LL;

	rep(i, 0, n) {
		if (a[i] <= W) {
			auto it = mp.find(a[i]);
			v.pb(it->ss);
			mp.erase(it);
			W -= a[i];
			wt += a[i];
		}
	}

	if (wt < least) {
		cout << -1 << '\n';
		return;
	}

	sort(all(v));
	cout << sz(v) << '\n';
	rep(i, 0, sz(v)) cout << v[i] + 1 << " ";
	cout << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}