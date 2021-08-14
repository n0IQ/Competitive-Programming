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

int getK(int n, int distinct, int maxSpace)
{
	while (1) {
		int j = 0;
		while (distinct > (1 << j)) j++;
		if (n * 1LL * j <= maxSpace) return distinct;
		distinct--;
	}
}

void solve()
{
	int n, I;
	cin >> n >> I;

	vector<int> a(n);
	map<int, int> m;

	rep(i, 0, n) {
		cin >> a[i];
		m[a[i]]++;
	}

	int maxSpace = I * 8,  distinct = sz(m);
	int k = getK(n, distinct, maxSpace);

	if (k >= distinct) {
		cout << 0 << '\n';
		return;
	}

	sort(all(a));
	vector<int> b, sum(n + 10, 0);
	int ans = INT_MAX;

	rep(i, 0, n) {
		if (m[a[i]] > 0) {
			b.pb(m[a[i]]);
			m[a[i]] = 0;
		}
	}

	rep(i, 1, distinct + 1) sum[i] = sum[i - 1] + b[i - 1];
	rep(i, k, distinct + 1) {
		ans = min(ans, n - (sum[i] - sum[i - k]));
	}

	cout << ans << '\n';
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