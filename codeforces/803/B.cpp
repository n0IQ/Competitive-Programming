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

	int a[n];
	rep(i, 0, n) cin >> a[i];

	int p[n], s[n];

	if (a[0] == 0) p[0] = 0;
	else p[0] = 1e9 + 1;

	rep(i, 1, n) {
		if (a[i] == 0) p[i] = 0;
		else p[i] = p[i - 1] + 1;
	}

	if (a[n - 1] == 0) s[n - 1] = 0;
	else s[n - 1] = 1e9 + 1;

	repR(i, n - 2, 0) {
		if (a[i] == 0) s[i] = 0;
		else s[i] = s[i + 1] + 1;
	}

	rep(i, 0, n) {
		cout << min(p[i], s[i]) << " ";
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
	//cin >> t;
	while (t--) solve();

	return 0;
}