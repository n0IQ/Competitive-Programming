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

const int N = 1e5;
ll dp1[N + 1], dp2[N + 1];

void solve()
{
	int n, m;
	cin >> n;

	int a[n + 1], b[n + 1];
	b[0] = 0;
	rep(i, 1, n + 1) cin >> a[i], b[i] = a[i];

	sort(b, b + n + 1);
	rep(i, 1, n + 1) {
		dp1[i] = dp1[i - 1] + a[i];
		dp2[i] = dp2[i - 1] + b[i];
	}

	cin >> m;

	rep(i, 0, m) {
		int type; cin >> type;

		if (type == 1) {
			int l, r; cin >> l >> r;
			cout << dp1[r] - dp1[l - 1] << '\n';
		}
		else {
			int l, r; cin >> l >> r;
			cout << dp2[r] - dp2[l - 1] << '\n';
		}
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