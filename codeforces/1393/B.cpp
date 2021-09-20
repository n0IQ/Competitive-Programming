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

	map<int, int> m;
	rep(i, 0, n) {
		int x; cin >> x;
		m[x]++;
	}

	multiset<pii, greater<pii>> s;
	for (auto it : m) s.insert({it.ss, it.ff});

	int q;
	cin >> q;
	while (q--) {
		char c;
		int x, num = 0;
		cin >> c >> x;

		if (m.find(x) != m.end()) {
			auto it = s.find({ m[x], x});
			num = it->ff;
			s.erase(it);
			m.erase(x);
		}

		if (c == '+') {
			s.insert({num + 1, x});
			m[x] = num + 1;
		}
		else {
			if (num > 1) {
				s.insert({num - 1, x});
				m[x] = num - 1;
			}
		}

		bool ok = false;

		if (s.empty() || s.begin()->ff < 4) ok = false;
		else if (s.begin()->ff >= 8) ok = true;
		else {
			int t = s.begin()->ff - 4;
			auto it1 = s.begin(); it1++;
			auto it2 = it1; it2++;

			if (it1 != s.end() && (t >= 2 && it1->ff >= 2) || (it1->ff >= 4)) ok = true;
			else if ((it1 != s.end() && it2 != s.end()) && (it1->ff >= 2 && it2->ff >= 2)) ok = true;
		}

		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}