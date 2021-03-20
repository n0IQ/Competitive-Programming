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

ll mult(ll a, ll b)
{
	ll res = (a * 1LL * b);
	return res;
}

ll power(ll a, ll b)
{
	ll res = 1;

	while (b) {
		if (b % 2 == 1) {
			res = mult(a, res);
		}

		a = mult(a, a);
		b /= 2LL;
	}

	return res;
}

void solve()
{
	ll n;
	cin >> n;

	if (n < 11) {
		cout << 0 << '\n';
		return;
	}

	string s = to_string(n);

	if (s.length() % 2 == 0) {
		ll l = s.length() / 2;
		string s1, s2;

		rep(i, 0, l) s1.pb(s[i]);
		rep(i, l, s.length()) s2.pb(s[i]);

		if (s1 > s2) {
			ll ans = (stoi(s1) * 1LL) - 1;
			cout << ans << '\n';
		}
		else cout << s1 << '\n';
	}
	else {
		ll l = s.length();
		ll x = power(10, l - 1) - 1;
		string s1, s2, s3;
		s1 = to_string(x);

		l = s1.length() / 2;

		rep(i, 0, l) s2.pb(s1[i]);
		rep(i, l, s1.length()) s3.pb(s1[i]);

		if (s2 > s3) {
			ll ans = (stoi(s2) * 1LL) - 1;
			cout << ans << '\n';
		}
		else cout << s2 << '\n';
	}
}

int main()
{
	fastio;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}