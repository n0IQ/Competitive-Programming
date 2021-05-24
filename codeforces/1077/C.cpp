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

	vi a(n);
	multimap<int, int> pos;
	rep(i, 0, n) {
		cin >> a[i];
		pos.insert({a[i], i});
	}

	vi b(a);
	sort(all(b));
	ll sum1 = accumulate(b.begin(), b.end() - 1, 0LL);
	ll sum2 = accumulate(b.begin(), b.end() - 2, 0LL);

	vi ans;

	if (sum2 == b[n - 2]) {
		int t = b[n - 1];
		rep(i, 0, n) {
			if (a[i] == t) ans.pb(i);
		}
	}

	rep(i, 0, n) {
		int t = b[n - 1];
		if (t != a[i] && abs(sum1 - a[i]) == b[n - 1]) ans.pb(i);
	}

	sort(all(ans));
	cout << sz(ans) << '\n';
	for (auto x : ans) cout << x + 1 << " ";
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