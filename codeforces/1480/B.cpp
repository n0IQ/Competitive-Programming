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

	int T;
	cin >> T;

	while (T-- > 0)
	{
		ll A, B;
		int n;
		cin >> A >> B >> n;

		vll v1(n), v2(n);

		rep(i, n) {
			cin >> v1[i];
		}

		rep(i, n) {
			cin >> v2[i];
		}

		vector<pll> m;

		rep(i, n) {
			m.pb({v1[i], v2[i]});
		}

		sort(m.begin(), m.end());

		bool flag = true;

		rep(i, n) {
			int x = m[i].ff, y = m[i].ss;
			ll count = (y + A - 1) / A;
			ll damage = count * x;

			B -= damage;

			if (B <= 0 && i < n - 1) {
				flag = false;
				break;
			}

			if (i == n - 1 && B < 0) {
				B += x;

				if (B <= 0) {
					flag = false;
				}
			}
		}

		if (flag) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}