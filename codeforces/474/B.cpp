#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repR(i, n) for (int i = n-1; i >= 0; --i)
#define repA(i, a, n) for (int i = a; i <= n; ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vd vector<double>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>
#define vpdd vector<pdd>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int search(int v[], int n, int x)
{
	int l = 1, r = n, mid = 0;

	while (l <= r) {
		mid = l + (r - l) / 2;

		if (x > v[mid - 1] && x <= v[mid]) {
			return mid;
		}
		else if (x <= v[mid - 1]) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	return -1;
}

void solve()
{
	int n, m;
	cin >> n;

	int a[n], v[n + 1];
	rep(i, n) {
		cin >> a[i];
	}

	int temp = 0;
	v[0] = 0;
	repA(i, 1, n) {
		v[i] = (temp + a[i - 1]);
		temp += a[i - 1];
	}

	cin >> m;

	rep(i, m) {
		int x; cin >> x;
		int ans = search(v, n, x);

		cout << ans << '\n';
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}