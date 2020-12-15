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

		vi v;

		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			v.pb(num);
		}

		int l = 0, r = n - 1;
		vi ans;

		if (n == 1) {
			cout << v[0] << '\n';
			continue;
		}

		while (l <= r && l < n && r > 0) {
			if (l == r) {
				ans.pb(v[l]);
			}
			else {
				ans.pb(v[l]);
				ans.pb(v[r]);
			}
			l++;
			r--;
		}

		for (auto x : ans) {
			cout << x << " ";
		}

		cout << '\n';
	}

	return 0;
}