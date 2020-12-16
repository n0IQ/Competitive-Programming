#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define all v.begin(),v.end()
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
		int n;
		cin >> n;

		vector<ll> v;

		for (int i = 0; i < n; i++) {
			ll num; cin >> num;
			v.pb(num);
		}

		ll operations = 0;

		for (int i = 1; i < n; i++) {
			operations += abs(v[i] - v[i - 1]);
		}

		ll opt1 = 0, opt2 = 0, opt3 = -1;

		opt1 = abs(v[1] - v[0]);
		opt2 = abs(v[n - 1] - v[n - 2]);

		for (int i = 1; i < n - 1; i++) {
			opt3 = max(opt3, abs(abs(v[i + 1] - v[i]) + abs(v[i] - v[i - 1]) - abs(v[i + 1] - v[i - 1])));
		}

		ll opt_chc = max({opt1, opt2, opt3});

		cout << operations - opt_chc << '\n';
	}

	return 0;
}