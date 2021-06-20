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
	int n, l, r;
	cin >> n >> l >> r;

	vll a(n);
	rep(i, 0, n) cin >> a[i];

	sort(all(a));
	ll res1, res2, t1 = 0, t2 = 0;
	int i = 0, j = n - 1;

	while (i < j) {
		if (a[i] + a[j] < l) {
			t1 += j - i;
			i++;
		}
		else j--;
	}

	i = 0, j = n - 1;

	while (i < j) {
		if (a[i] + a[j] <= r) {
			t2 += j - i;
			i++;
		}
		else j--;
	}

	res1 = (n * 1LL * (n - 1) / 2) - t1;
	res2 = (n * 1LL * (n - 1) / 2) - t2;

	cout << abs(res1 - res2) << '\n';
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