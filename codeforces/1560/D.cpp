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

int getans(string s1, string s2, int n, int m)
{
	int i = 0, j = 0, cnt = 0, d = 0;

	while (i < n && j < m) {
		if (s1[i] == s2[j]) {
			i++, j++;
			d++;
		}
		else cnt++, i++;
	}

	int l = n - cnt;
	int total = cnt + abs(m - l);

	return total;
}

void solve()
{
	ll n;
	cin >> n;

	vector<string> a;

	for (ll i = 0; i <= 62; i++) {
		ll num = (1LL << i);
		string s = to_string(num);
		a.pb(s);
	}

	string t = to_string(n);
	int ans = INT_MAX;
	for (auto s : a) {
		ans = min(ans, getans(t, s, sz(t), sz(s)));
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