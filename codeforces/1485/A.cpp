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

int Solve(int a, int b)
{
	int ans = 0;

	while (a >= b) {
		a /= b;
		ans++;
	}

	return ans + 1;
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
		int a, b;
		cin >> a >> b;

		int op1 = 0, ans = INT_MAX;
		bool flag = false;

		for (int i = 0; i <= 30; i++) {
			op1 = 0;

			if (b == 1) {
				flag = true;
				op1++;
				b++;
				op1 += Solve(a, b);
			}
			else {
				op1 = Solve(a, b + i);
				op1 += i;

				if (flag) {
					op1++;
				}
			}

			if (op1 < ans) {
				ans = op1;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}