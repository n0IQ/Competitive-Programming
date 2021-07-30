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
	ll W, H, x1, y1, x2, y2, tw, th;
	cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> tw >> th;

	ll tw2 = x2 - x1, th2 = y2 - y1;

	if (tw + tw2 > W && th + th2 > H) {
		cout << -1 << '\n';
		return;
	}

	if (tw <= x1 || tw <= W - x2 ||  th <= y1 || th <= H - y2) {
		cout << ps(0, 9) << '\n';
		return;
	}

	ll ans = 1e12;

	if (th + th2 <= H) {
		ans = min({ans, th - y1, th - (H - y2)});
	}

	if (tw + tw2 <= W) {
		ans = min({ans, tw - x1, tw - (W - x2)});
	}

	cout << ps(ans, 9) << '\n';
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