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

vi ans;

void divide(vi a, int d)
{
	int n = sz(a);
	if (n < 1) return;

	int mx = 0, idx = 0, j = 0;
	rep(i, 0, n) {
		if (a[i] > mx) mx = a[i], idx = i;
	}

	ans[mx] = d;

	vi b(idx), c(n - idx - 1);
	rep(i, 0, idx) b[i] = a[i];
	rep(i, idx + 1, n) c[j++] = a[i];

	divide(b, d + 1);
	divide(c, d + 1);
}

void solve()
{
	ans.clear(); ans.resize(101, 0);

	int n;
	cin >> n;

	vi a(n);
	rep(i, 0, n) cin >> a[i];

	divide(a, 0);

	rep(i, 0, n) cout << ans[a[i]] << " ";
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