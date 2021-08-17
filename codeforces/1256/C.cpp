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
	int n, m, d;
	cin >> n >> m >> d;

	vector<int> a(m + 1), res(n + 1, 0);
	int sum = 0;
	rep(i, 1, m + 1)  {
		cin >> a[i];
		sum += a[i];
	}

	int curr = 0;
	rep(i, 1, m + 1) {
		if (curr + d + sum > n + 1) {
			rep(j, curr + 1, curr + 1 + a[i]) res[j] = i;
			curr = curr + a[i];
		}
		else {
			rep(j, curr + d, curr + d + a[i]) res[j] = i;
			curr = curr + d + a[i] - 1;
		}

		sum -= a[i];
	}

	if (curr + d < n + 1) {
		cout << "NO" << '\n';
		return;
	}

	cout << "YES" << '\n';
	rep(i, 1, n + 1) cout << res[i] << " ";
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
	//cin>>t;
	while (t--) solve();

	return 0;
}