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

int n, m;
char a[2001][2001];

void solve()
{
	cin >> n >> m;
	rep(i, 1, n + 1) {
		rep(j, 1, m + 1) {
			cin >> a[i][j];
		}
	}

	map<int, int> mp;

	rep(i, 1, n + 1) {
		rep(j, 1, m + 1) {
			if (a[i][j] == '1') mp[j]++;
		}
	}

	rep(i, 1, n + 1) {
		bool ok = true;

		rep(j, 1, m + 1) {
			if (a[i][j] == '1') {
				if (mp[j] < 2) ok = false;
			}
		}

		if (ok) {
			cout << "YES" << '\n';
			return;
		}
	}

	cout << "NO" << '\n';
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