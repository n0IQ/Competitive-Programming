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
	int n, k;
	cin >> n >> k;

	vi a(k), t(k);
	rep(i, 0, k) cin >> a[i];
	rep(i, 0, k) cin >> t[i];

	vll c(n, INT_MAX);
	rep(i, 0, k) {
		c[--a[i]] = t[i];
	}

	vll l(n, INT_MAX), r(n, INT_MAX);
	ll temp = INT_MAX;
	rep(i, 0, n) {
		temp = min(temp + 1, c[i]);
		l[i] = temp;
	}

	temp = INT_MAX;
	repR(i, n - 1, 0) {
		temp = min(temp + 1, c[i]);
		r[i] = temp;
	}

	rep(i, 0, n) {
		cout << min(l[i], r[i]) << " ";
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