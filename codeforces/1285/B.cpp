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

	vll v(n);
	rep(i, 0, n) cin >> v[i];

	ll yasser = accumulate(all(v), 0LL);

	vll a(v), b(v);
	a.pop_back();
	b.erase(b.begin());

	ll dp1[n], dp2[n];
	ll sum1 = INT_MIN, sum2 = INT_MIN;
	dp1[0] = 0, dp2[0] = 0;

	rep(i, 1, n) {
		dp1[i] = max(dp1[i - 1] + a[i - 1], a[i - 1]);
		sum1 = max(sum1, dp1[i]);
	}

	rep(i, 1, n) {
		dp2[i] = max(dp2[i - 1] + b[i - 1], b[i - 1]);
		sum2 = max(sum2, dp2[i]);
	}

	ll adele = max(sum1, sum2);

	if (yasser > adele) cout << "YES" << '\n';
	else cout << "NO" << '\n';
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