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
	string s;
	cin >> n >> s;

	int cntm = 0;
	rep(i, 0, n) {
		if (s[i] == 'M') cntm++;
	}

	if (cntm != (n / 3)) {
		cout << "NO" << '\n';
		return;
	}

	int pref[n] = {0}, suff[n] = {0}, cnt = 0;
	bool ok = true;
	rep(i, 0, n) {
		if (s[i] == 'T') cnt++;
		else if (ok) {
			pref[i] = cnt;
			ok = false;
		}
		else pref[i] = --cnt;
	}

	cnt = 0;
	ok = true;

	repR(i, n - 1, 0) {
		if (s[i] == 'T') cnt++;
		else if (ok) {
			suff[i] = cnt;
			ok = false;
		}
		else suff[i] = --cnt;
	}

	rep(i, 0, n) {
		if (s[i] == 'M' && (pref[i] <= 0 || suff[i] <= 0)) {
			cout << "NO" << '\n';
			return;
		}
	}

	cout << "YES" << '\n';
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