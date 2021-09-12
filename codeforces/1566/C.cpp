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
	string s, t;
	cin >> n >> s >> t;

	s.pb('?'), t.pb('?');
	int i = 0;
	bool ok1 = false, ok2 = false;
	ll ans = 0LL;

	while (i < n) {
		if ((s[i] == '1' && t[i] == '0') || (s[i] == '0' && t[i] == '1')) {
			ans += 2;
			i++;
			ok1 = true, ok2 = true;
		}
		else if (s[i] == '0' && t[i] == '0') {
			ok1 = true;
			if (s[i + 1] == '1' && t[i + 1] == '1') {
				ans += 2;
				i += 2;
			}
			else {
				ans++;
				i++;
			}
		}
		else {
			ok2 = true;
			while (i < n) {
				if (s[i] == '0' || t[i] == '0') {
					ans += 2;
					i++;
					break;
				}
				else i++;
			}
		}
	}

	if (ok1 && ok2) ans = max(2LL, ans);
	cout << ans << '\n';
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