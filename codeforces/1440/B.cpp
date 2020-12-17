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
		int n, k;
		cin >> n >> k;

		vi v(n * k + 1);

		for (int i = 1; i <= n * k; i++) {
			cin >> v[i];
		}

		ll sum = 0, skip = n / 2;

		for (int i = n * k - skip, j = 0; i >= 1 && j < k;) {
			sum += v[i];
			i -= skip;
			i--;
			j++;
		}

		cout << sum << '\n';
	}

	return 0;
}