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
	int n, m, j = 0;
	string s, t, temp;
	cin >> n >> m >> s >> t;
	bool ok = false;

	rep(i, 0, n) {
		if (s[i] != '*') temp.pb(s[i]);
		else j = i, ok = true;
	}

	if (!ok && s != t) {
		cout << "NO" << '\n';
		return;
	}

	if (temp == t) {
		cout << "YES" << '\n';
		return;
	}

	if (n > m) {
		cout << "NO" << '\n';
		return;
	}

	int index1 = 0, index2 = 0, k = m - 1;

	temp = "";
	ok = false;

	rep(i, 0, j) {
		if (s[i] != t[i]) {
			index1 = i;
			ok = true;
			break;
		}
	}

	if (!ok) {
		index1 = j;
	}

	for (int i = n - 1; i > j; i--, k--) {
		if (s[i] != t[k]) {
			cout << "NO" << '\n';
			return;
		}
	}

	rep(i, index1, k + 1) {
		temp.pb(t[i]);
	}

	string ans;
	rep(i, 0, j)ans.pb(s[i]);
	ans += temp;
	rep(i, j + 1, n)ans.pb(s[i]);

	if (ans == t)cout << "YES" << '\n';
	else cout << "NO" << '\n';
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