#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int check(vector<ll> &a, vector<ll> &b, int n)
{
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += a[i] == b[i];
	}
	return cnt;
}

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());

	if (a.back() - a[0] <= 1) {
		cout << n << '\n';
		for (auto &x : a) cout << x << ' ';
		return;
	}

	ll sum = accumulate(a.begin(), a.end(), 0LL);
	ll minVal = a[0], maxVal = a.back();
	vector<ll> b(a);

	// change a-1 and a+1 with 2a
	for (int i = 0, j = n - 1; i < j; i++, j--) {
		if (b[i] == minVal && b[j] == maxVal) {
			b[i] = b[j] = minVal + 1;
		}
	}

	int ans1 = check(a, b, n);
	vector<ll> c(a);

	// change 2a with a-1 and a+1
	for (int i = 0, j = n - 1; i < j; i++, j--) {
		while (i < j && c[i] == minVal) i++;
		while (i < j && c[j] == maxVal) j--;
		if (i >= j) break;
		if (c[i] == minVal + 1 && c[j] == minVal + 1) {
			c[i] = minVal;
			c[j] = maxVal;
		}
	}

	int ans2 = check(a, c, n);

	if (ans1 <= ans2) {
		cout << ans1 << '\n';
		for (auto &x : b) cout << x << ' ';
	}
	else {
		cout << ans2 << '\n';
		for (auto &x : c) cout << x << ' ';
	}

	cout << '\n';
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
	// cin >> t;
	while (t--) solve();

	return 0;
}