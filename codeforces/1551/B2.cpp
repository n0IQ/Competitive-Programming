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
	cin >> n >> k;

	vi a(n), ans(n, 0);
	map<int, int> cnt;

	rep(i, 0, n) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	multimap<int, int> color;
	multiset<int> fill;

	for (auto &it : cnt) {
		if (it.ss >= k) {
			it.ss = k;

			rep(i, 0, it.ss) fill.insert(it.ff);
		}
		else {
			rep(i, 0, it.ss) {
				color.insert({it.ff, 0});
			}
		}
	}

	rep(i, 0, n) {
		auto it = fill.find(a[i]);
		if (it != fill.end()) {
			ans[i] = cnt[a[i]]--;
			fill.erase(it);
		}
	}

	rep(i, 0, sz(fill)) {
		ans[i] = cnt[a[i]]--;
	}

	int t = sz(color);
	int times = (t / k) * k;
	int count = k;

	for (auto &it : color) {
		if (times == 0) break;
		if (count == 0) count = k;
		it.ss = count--;
		times--;
	}

	rep(i, 0, n) {
		if (ans[i] == 0) {
			auto it = color.find(a[i]);

			if (it != color.end()) {
				ans[i] = it->ss;
				color.erase(it);
			}
		}
	}

	rep(i, 0, n) cout << ans[i] << " ";
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