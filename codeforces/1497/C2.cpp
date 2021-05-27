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

vi get(int n)
{
	vi v;

	if (n % 2 == 1) v.pb(n / 2), v.pb(n / 2), v.pb(1);
	else if (n % 4 == 0) v.pb(n / 2), v.pb(n / 4), v.pb(n / 4);
	else {
		int temp = (n / 2) - 1;
		v.pb(temp), v.pb(temp), v.pb(2);
	}

	return v;
}

void solve()
{
	int n, k;
	cin >> n >> k;

	vi v = get(n - k + 3);
	rep(i, 0, k - 3) {
		v.pb(1);
	}

	sort(all(v));
	for (int x : v) cout << x << " ";
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