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

	map<int, int> cnt;
	rep(i, 0, n) {
		int x; cin >> x;
		cnt[x]++;
	}

	vi b, c;
	for (auto it : cnt) {
		if (it.ss >= 2) {
			b.pb(it.ff); c.pb(it.ff);
		}
		else b.pb(it.ff);
	}

	sort(all(b)), sort(all(c));
	int mex1 = 0, mex2 = 0;
	rep(i, 0, sz(b)) {
		if (b[i] != mex1) {
			break;
		}
		else mex1++;
	}

	rep(i, 0, sz(c)) {
		if (c[i] != mex2) {
			break;
		}
		else mex2++;
	}

	cout << mex1 + mex2 << '\n';
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