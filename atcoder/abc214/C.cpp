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
	cin >> n;

	vector<int> s(n), t(n);
	int idx = 0, mn = INT_MAX;

	rep(i, 0, n) cin >> s[i];
	rep(i, 0, n) {
		cin >> t[i];
		if (mn > t[i]) {
			mn = t[i];
			idx = i;
		}
	}

	vector<int> ans(n);
	ans[idx] = t[idx];
	int time = t[idx], i = idx + 1, l;
	if (i == n) i = 0;

	while (i != idx) {
		(i == 0 ? l = n - 1 : l = i - 1);
		time = min(t[i], time + s[l]);
		ans[i] = time;
		i++;
		if (i == n) i = 0;
	}

	for (auto x : ans) cout << x << '\n';
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