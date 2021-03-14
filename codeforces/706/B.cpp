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

const int N = 1e7;
ll dp[N];

void solve()
{
	int n, q;
	cin >> n;

	vi v(n + 1);
	unordered_map<int, int> mp;
	rep(i, 1, n + 1) {
		cin >> v[i];
		mp[v[i]]++;
	}

	sort(all(v));
	int j = 1;

	rep(i, 1, 1000000) {
		if (j <= n && i == v[j]) {
			dp[i] = mp[i] + dp[i - 1];
			j += mp[i];
		}
		else {
			dp[i] = dp[i - 1];
		}
	}

	int largest = v[n];

	cin >> q;
	rep(i, 0, q) {
		int x; cin >> x;

		if (x > largest) {
			cout << dp[largest] << '\n';
		}
		else {
			cout << dp[x] << '\n';
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