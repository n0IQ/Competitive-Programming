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
	int n, k;
	string s;
	cin >> n >> k >> s;

	int wins = 0, loss = 0, ls = 0, ans = 0;
	bool ok = false;
	vector<int> dist;

	for (auto c : s) {
		if (c == 'W') {
			if (ls) {
				dist.pb(ls);
				ls = 0;
			}

			wins++;
			ans++;

			if (ok) ans++;
			ok = true;
		}
		else {
			loss++;
			ok = false;
			if (wins) ls++;
		}
	}

	if (k >= loss) {
		cout << 2 * n - 1 << '\n';
		return;
	}

	if (wins == 0) {
		cout << max(2 * k - 1, 0) << '\n';
		return;
	}

	sort(all(dist));
	ans += 2 * k;

	for (auto x : dist) {
		if (x <= k) {
			ans++;
			k -= x;
		}
	}

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
	cin >> t;
	while (t--) solve();

	return 0;
}