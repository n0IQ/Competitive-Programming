#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void divide(vector<ll> &a, int n, vector<ll> &possibleSums)
{
	possibleSums.push_back(accumulate(a.begin(), a.end(), 0LL));
	if (n <= 1 || a[0] == a[n - 1]) {
		return;
	}

	ll mid = (a[0] + a[n - 1]) / 2;
	vector<ll> left, right;
	for (int i = 0; i < n; i++) {
		if (a[i] <= mid) left.push_back(a[i]);
		else right.push_back(a[i]);
	}

	divide(left, (int)left.size(), possibleSums);
	divide(right, (int)right.size(), possibleSums);
}

void solve()
{
	int n, q;
	cin >> n >> q;

	vector<ll> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end());

	vector<ll> possibleSums;
	divide(a, n, possibleSums);
	sort(possibleSums.begin(), possibleSums.end());

	for (int i = 0; i < q; i++) {
		ll sum;
		cin >> sum;
		auto it = lower_bound(possibleSums.begin(), possibleSums.end(), sum);
		if (it != possibleSums.end() && *it == sum) cout << "Yes\n";
		else cout << "No\n";
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("Error.txt", "w", stderr);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}