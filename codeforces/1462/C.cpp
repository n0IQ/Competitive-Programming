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

void solve(int x)
{
	vi ans;

	int sum = 0, last = 9;

	while (sum < x && last > 0) {
		ans.pb(min(x - sum, last));
		sum += last;
		last--;
	}

	if (sum < x) {
		cout << -1 << '\n';
	}
	else {
		sort(all(ans));
		for (auto i : ans) {
			cout << i;
		}

		cout << '\n';
	}
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
		int x;
		cin >> x;

		solve(x);
	}

	return 0;
}