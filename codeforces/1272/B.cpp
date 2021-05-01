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

	int n = sz(s);
	int l = 0, r = 0, u = 0, d = 0;
	rep(i, 0, n) {
		if (s[i] == 'L') l++;
		if (s[i] == 'R') r++;
		if (s[i] == 'D') d++;
		if (s[i] == 'U') u++;
	}

	if (((l > 0 && r == 0) || (l == 0 && r > 0)) && (u == 0 || d == 0)) {
		cout << 0 << '\n';
		return;
	}

	if (((u > 0 && d == 0) || (u == 0 && d > 0)) && (l == 0 || r == 0)) {
		cout << 0 << '\n';
		return;
	}

	if (u == 0 || d == 0) {
		cout << 2 << '\n' << "LR\n";
		return;
	}
	if (l == 0 || r == 0) {
		cout << 2 << '\n' << "UD\n";
		return;
	}

	int ans = (min(l, r) * 2) + (min(u, d) * 2);
	l = r = min(l, r);
	u = d = min(u, d);

	cout << ans << '\n';

	cout << "U"; u--;
	cout << "L"; l--;

	while (d > 0) {
		cout << "D"; d--;
	}
	while (r > 0) {
		cout << "R"; r--;
	}
	while (u > 0) {
		cout << "U"; u--;
	}
	while (l > 0) {
		cout << "L"; l--;
	}

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