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

	vi v(n + 2);
	rep(i, 0, n + 2) cin >> v[i];
	sort(all(v));

	ll sum = accumulate(all(v), 0LL);

	if ((sum - v[n] - v[n + 1] == v[n]) || (sum - v[n] - v[n + 1] == v[n + 1])) {
		rep(i, 0, n) cout << v[i] << " ";
		cout << '\n';
		return;
	}
	else {
		int indx = -1;
		sum -= v[n + 1];

		rep(i, 0, n + 1) {
			if (sum - v[i] == v[n + 1]) {
				indx = i;
				break;
			}
		}

		if (indx >= 0) {
			rep(i, 0, n + 1) {
				if (i == indx) continue;
				cout << v[i] << " ";
			}

			cout << '\n';
			return;
		}
	}

	cout << -1 << '\n';
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