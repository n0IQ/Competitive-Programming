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
#define all(x) x.begin(),x.end()
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

		vi v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		ll evensum = 0, oddsum = 0;
		vector<int> ans(n, 0);

		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				evensum += v[i];
			}
			else {
				oddsum += v[i];
			}
		}

		if (evensum < oddsum) {
			for (int i = 0; i < n; i += 2) {
				v[i] = 1;
			}
		}
		else {
			for (int i = 1; i < n; i += 2) {
				v[i] = 1;
			}
		}

		for (auto x : v) {
			cout << x << " ";
		}

		cout << '\n';
	}

	return 0;
}