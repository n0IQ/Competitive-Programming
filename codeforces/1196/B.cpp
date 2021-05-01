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

	int a[n], even = 0, odd = 0;
	rep(i, 0, n) {
		cin >> a[i];
		if (a[i] % 2 == 0) even++;
		else odd++;
	}

	if (odd < k) {
		cout << "NO" << '\n';
		return;
	}

	if (k == 1) {
		ll sum = accumulate(a, a + n, 0LL);
		if (sum % 2 == 0) cout << "NO" << '\n';
		else cout << "YES\n" << n << '\n';
		return;
	}

	vi v;
	int i;
	ll sum = 0LL;
	for (i = 0; i < n && k > 1; i++) {
		sum += a[i];
		if (sum % 2 == 1) {
			v.pb(i + 1);
			sum = 0LL;
			k--;
		}
	}

	if (k > 1) {
		cout << "NO" << '\n';
		return;
	}

	sum = 0LL;
	for (; i < n; i++) {
		sum += a[i];
	}

	if (sum % 2 == 0) {
		cout << "NO" << '\n';
		return;
	}

	v.pb(n);
	cout << "YES" << '\n';
	for (auto x : v) cout << x << " ";
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