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
	ll n, m;
	cin >> n >> m;

	ll t1 = (n - m + 1), t2 = 0LL;
	ll mx = (t1 * 1LL * (t1 - 1)) / 2, mn = 0LL;

	if (n % m == 0) {
		t1 = n / m;
		t1 = (t1 * 1LL * (t1 - 1)) / 2;
		mn = t1 * m;
	}
	else {
		t1 = (n / m) + 1;
		t2 = n % m;
		ll left = m - t2;

		ll temp = n - (t1 * 1LL * t2);
		temp = temp / left;

		t1 = (t1 * 1LL * (t1 - 1)) / 2;
		t2 = (temp * 1LL * (temp - 1)) / 2;
		mn = (t1 * (m - left)) + (t2 * left);
	}

	cout << mn << " " << mx << '\n';
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