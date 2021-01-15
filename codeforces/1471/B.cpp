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

int Get_Count(int n, int x)
{
	int count = 0;

	while (n % x == 0) {
		count++;
		n /= x;
	}

	return count;
}

int main()
{
	fastio

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;

	while (T-- > 0)
	{
		int n, x;
		cin >> n >> x;

		vi v(n);
		ll sum = 0;

		rep(i, n) {
			cin >> v[i];
		}

		vi count;

		rep(i, n) {
			count.pb(Get_Count(v[i], x));
		}

		int min = INT_MAX, min_index = 0;

		rep(i, sz(count)) {
			if (count[i] < min) {
				min = count[i];
				min_index = i;
			}
		}

		rep(i, min_index) {
			sum += (v[i] * 1LL * (min + 2));
		}

		repA(i, min_index, n - 1) {
			sum += (v[i] * 1LL * (min + 1));
		}

		cout << sum << '\n';
	}

	return 0;
}
