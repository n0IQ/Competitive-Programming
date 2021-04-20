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
	int n, m;
	cin >> n >> m;

	int a[n + m], b[n + m];
	rep(i, 0, n + m) cin >> a[i];
	rep(i, 0, n + m) cin >> b[i];

	map<int, int> mp;
	int p[n + m], s[n + m];
	rep(i, 0, n + m) {
		p[i] = INT_MAX;
		s[i] = INT_MAX;
	}

	rep(i, 0, n + m) {
		mp[a[i]] = b[i];
	}

	/*for (auto it : mp) {
		cout << it.ff << " " << it.ss << '\n';
	}*/

	int i = 0;
	map<int, int> ans;

	for (auto it : mp) {
		if (it.ss == 1) {
			ans[it.ff] = 0;
			p[i] = it.ff;
		}
		else if (i > 0) p[i] = p[i - 1];
		i++;
	}

	map<int, int>::iterator it;
	i = n + m;

	for (it = mp.end(); it != mp.begin(); ) {
		--it; --i;
		if (it->ss == 1) s[i] = it->ff;
		else if (i < n + m - 1) s[i] = s[i + 1];
	}

	/*for (auto x : p) cout << x << " ";
	cout << '\n';
	for (auto x : s) cout << x << " ";
	cout << '\n';*/

	i = 0;
	for (auto it : mp) {
		if (it.ss == 0) {
			int diff1 = abs(it.ff - p[i]), diff2 = abs(it.ff - s[i]);

			if (diff1 <= diff2) ans[p[i]]++;
			else ans[s[i]]++;
		}

		i++;
	}

	for (auto it : mp) {
		if (it.ss == 1) {
			cout << ans[it.ff] << " ";
		}
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
	//cin >> t;
	while (t--) solve();

	return 0;
}