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

ll dp[101][100001];

ll Knapsack(int val[], int wt[], int n, int weight)
{
	if (n == 0 || weight == 0) {
		return 0;
	}

	if (dp[n][weight] != -1) {
		return dp[n][weight];
	}

	if (wt[n - 1] <= weight) {
		return dp[n][weight] = max(val[n - 1] + Knapsack(val, wt, n - 1, weight - wt[n - 1]), Knapsack(val, wt, n - 1, weight));
	}
	else {
		return dp[n][weight] = Knapsack(val, wt, n - 1, weight);
	}
}

void solve()
{
	int n, W;
	cin >> n >> W;

	int wt[n], val[n];
	rep(i, n) {
		cin >> wt[i], cin >> val[i];
	}

	mem1(dp);

	cout << Knapsack(val, wt, n, W) << '\n';
}

int main()
{
	fastio;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}