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
	int n, t;
	cin >> n >> t;

	vector<int> a(n), res(n, 0);
	rep(i, 0, n) cin >> a[i];

	if (t % 2 == 1) {
		rep(i, 0, n) {
			if (a[i] % 2 == 0) res[i] = 0;
			else res[i] = 1;
		}
	}
	else {
		int num = t / 2, cnt = 0;
		rep(i, 0, n) {
			if (a[i] < num) res[i] = 0;
			else if (a[i] >= num) res[i] = 1;
			if (a[i] == num) cnt++;
		}

		cnt = cnt / 2;
		for (int i = 0; i < n && cnt > 0; i++) {
			if (a[i] == num) {
				res[i] = 0;
				cnt--;
			}
		}
	}

	rep(i, 0, n) {
		cout << res[i] << ' ';
	}

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