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
vll a(N + 1);

void precalc()
{
	a[1] = 2;

	rep(i, 2, N + 1) {
		a[i] = a[i - 1] + (2 * 1LL * i) + i - 1;
	}
}

void solve()
{
	ll n, ans = 0;
	cin >> n;

	while (n > 1) {
		auto it1 = lb(all(a), n);

		if (*it1 == n) {
			n -= *it1;
			ans++;
		}
		else {
			it1--;
			n -= *it1;
			ans++;
		}
	}

	cout << ans << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	precalc();

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}