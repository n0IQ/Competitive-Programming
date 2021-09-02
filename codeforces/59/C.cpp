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

bool check(string s, int n)
{
	rep(i, 0, n / 2) {
		if (s[i] != s[n - i - 1]) return false;
	}

	return true;
}

void solve()
{
	int k;
	string s;
	cin >> k >> s;

	int n = sz(s);
	int f[26] = {0};
	rep(i, 0, n / 2) {
		if (s[i] == '?' || s[n - i - 1] == '?') {
			if (s[i] == '?' && s[n - i - 1] == '?') continue;
			if (s[i] == '?') s[i] = s[n - i - 1];
			else s[n - i - 1] = s[i];
		}
	}

	rep(i, 0, n) {
		if (s[i] != '?') f[s[i] - 'a']++;
	}

	set<char, greater<char>> a;
	vector<int> idx;
	rep(i, 0, k) {
		if (f[i] == 0) {
			a.insert('a' + i);
		}
	}

	rep(i, 0, n / 2) {
		if (s[i] == '?') idx.pb(i);
	}
	if (n % 2 == 1 && s[n / 2] == '?') idx.pb(n / 2);

	repR(i, sz(idx) - 1, 0) {
		int x = idx[i];
		char c = 'a';

		if (!a.empty()) {
			c = *a.begin();
			a.erase(a.begin());
		}

		s[x] = c;
		s[n - x - 1] = c;
	}

	if (!a.empty() || !check(s, n)) cout << "IMPOSSIBLE" << '\n';
	else cout << s << '\n';
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