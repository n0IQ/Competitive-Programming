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
	int k, n, m;
	cin >> k >> n >> m;

	vi a(n), b(m);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];

	int i = 0, j = 0;
	vi res;

	while (i < n && j < m) {
		if (a[i] > k && b[j] > k) {
			cout << -1 << '\n';
			return;
		}

		if (a[i] <= b[j]) {
			if (a[i] == 0) {
				res.pb(a[i]);
				k++;
			}
			else if (a[i] > k) {
				cout << -1 << '\n';
				return;
			}
			else {
				res.pb(a[i]);
			}

			i++;
		}
		else {
			if (b[j] == 0) {
				k++;
				res.pb(b[j]);
			}
			else if (b[j] > k) {
				cout << -1 << '\n';
				return;
			}
			else {
				res.pb(b[j]);
			}

			j++;
		}
	}

	while (i < n) {
		if (a[i] == 0) {
			k++;
			res.pb(a[i]);
		}
		else if (a[i] > k) {
			cout << -1 << '\n';
			return;
		}
		else {
			res.pb(a[i]);
		}


		i++;
	}

	while (j < m) {
		if (b[j] == 0) {
			k++;
			res.pb(b[j]);
		}
		else if (b[j] > k) {
			cout << -1 << '\n';
			return;
		}
		else {
			res.pb(b[j]);
		}


		j++;
	}

	for (auto x : res) cout << x << " ";
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