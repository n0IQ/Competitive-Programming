#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repR(i, n) for (int i = n-1; i >= 0; --i)
#define repA(i, a, n) for (int i = a; i <= n; ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vd vector<double>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>
#define vpdd vector<pdd>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int main()
{
	fastio

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	map<int, int> m1;
	map<int, int> m2;
	map<int, int> m3;

	rep(i, n) {
		int num; cin >> num;
		m1[num]++;
	}

	rep(i, n - 1) {
		int num; cin >> num;
		m2[num]++;
	}

	rep(i, n - 2) {
		int num; cin >> num;
		m3[num]++;
	}

	int ans = 0;

	for (auto x : m1) {
		if (m2[x.ff] != x.ss) {
			ans = x.ff;
			break;
		}
	}

	cout << ans << '\n';

	for (auto x : m2) {
		if (m3[x.ff] != x.ss) {
			ans = x.ff;
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}