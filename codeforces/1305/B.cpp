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
	string s;
	cin >> s;

	int n = sz(s), ans = 0;
	vi v;

	while (1) {
		int pref[n] = {0}, suff[n] = {0}, cnt = 0;
		rep(i, 0, n) {
			if (s[i] == '(') pref[i] = ++cnt;
		}
		cnt = 0;
		repR(i, n - 1 , 0) {
			if (s[i] == ')') suff[i] = ++cnt;
		}

		int x1 = -1, x2 = -1;

		repR(i, n - 1, 0) {
			if (pref[i] == 0) continue;

			if (pref[i] > 0) {
				x1 = i;
				int num = pref[i];

				rep(j, 0, n) {
					if (suff[j] == num) x2 = j;
				}
			}

			if (x1 < x2) break;
			else x1 = x2 = -1;
		}

		if (x1 == -1 || x2 == -1) {
			cout << 0 << '\n';
			return;
		}

		rep(i, 0, x1 + 1) {
			if (pref[i] > 0) v.pb(i);
		}

		repR(i, n - 1, x2) {
			if (suff[i] > 0)v.pb(i);
		}

		sort(all(v));

		ans++;
		break;
	}

	cout << ans << '\n';
	cout << sz(v) << '\n';
	for (auto x : v) cout << x + 1 << " ";
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
	//cin >> t;
	while (t--) solve();

	return 0;
}