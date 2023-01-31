#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<ll> b(a);
	sort(b.begin(), b.end(), greater<>());

	ll sum = 0;
	multiset<ll> s;
	for (int i = 0; i < m * k; i++) {
		sum += b[i];
		s.insert(b[i]);
	}

	vector<int> seq;
	int cnt = 0;

	for (int i = 0; i < n && (int)seq.size() < k - 1; i++) {
		auto it = s.find(a[i]);
		if (it != s.end()) {
			cnt++;
			s.erase(it);
		}

		if (cnt == m) {
			seq.push_back(i);
			cnt = 0;
		}
	}

	cout << sum << '\n';
	for (auto &x : seq) {
		cout << x + 1 << ' ';
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
	// cin >> t;
	while (t--) solve();

	return 0;
}