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
	string s, ans;
	cin >> s;

	int n = sz(s);
	if (n < 26) {
		cout << -1 << '\n';
		return;
	}

	rep(i, 0, n - 25) {
		string t = s.substr(i, 26);
		vi cnt(26, 0);
		bool ok = true;

		rep(j, 0, sz(t)) if (t[j] != '?') cnt[t[j] - 'A']++;
		rep(j, 0, sz(cnt)) if (cnt[j] > 1) ok = false;

		if (ok) {
			vector<char> v;
			rep(j, 0, sz(cnt)) if (cnt[j] == 0) v.pb(char('A' + j));
			int k = 0;

			rep(j, 0, sz(t)) {
				if (t[j] == '?') {
					t[j] = v[k];
					k++;
				}
			}

			string ans = s.substr(0, i);
			ans += t;
			ans += s.substr(i + 26, n);

			rep(j, 0, sz(ans)) {
				if (ans[j] == '?') ans[j] = 'A';
			}

			cout << ans << '\n';
			return;
		}
	}

	cout << -1 << '\n';
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