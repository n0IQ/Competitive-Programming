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

	int f[2] = {0};
	rep(i, 0, n) {
		f[s[i] - 'a']++;
		f[t[i] - 'a']++;
	}

	if (f[0] % 2 == 1 || f[1] % 2 == 1) {
		cout << -1 << '\n';
		return;
	}

	set<pair<char, int>> p;
	rep(i, 0, n) {
		if (s[i] == t[i]) continue;
		p.insert({t[i], i});
	}

	vector<pii> ans;

	rep(i, 0, n) {
		if (s[i] == t[i]) continue;
		auto it = p.ub({t[i], i});
		if (it == p.end() || it->ff != t[i]) {
			it = p.lb({t[i], i});
			p.erase(it);
			p.insert({s[i], i});
			swap(s[i], t[i]);
			ans.pb({i, i});
			i--;
		}
		else {
			int j = it->ss;
			swap(s[i], t[j]);
			p.erase(it);
			if (s[j] != t[j]) p.insert({t[j], j});
			ans.pb({i, j});
		}
	}

	cout << sz(ans) << '\n';
	for (auto [a, b] : ans) {
		cout << a + 1 << " " << b + 1 << '\n';
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}