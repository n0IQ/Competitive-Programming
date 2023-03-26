#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n), pos, neg;
	for (auto &x : a) {
		cin >> x;
		if (x >= 0) pos.push_back(x);
		else neg.push_back(x);
	}

	sort(pos.begin(), pos.end(), greater<>());
	sort(neg.begin(), neg.end(), greater<>());

	ll maxLimit = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());

	vector<ll> ans(n);
	ll sum = 0;

	for (int i = 0; i < n; i++) {
		if (!pos.empty()) {
			if (pos.back() >= maxLimit) {
				cout << "No\n";
				return;
			}

			if (abs(sum + pos.back()) < maxLimit) {
				ans[i] = pos.back();
				sum += pos.back();
				pos.pop_back();
			}
			else {
				if (neg.empty()) {
					cout << "No\n";
					return;
				}
				else {
					ans[i] = neg.back();
					sum += neg.back();
					neg.pop_back();
				}
			}
		}
		else {
			if (abs(neg.back()) >= maxLimit) {
				cout << "No\n";
				return;
			}

			if (abs(sum + neg.back()) < maxLimit) {
				ans[i] = neg.back();
				sum += neg.back();
				neg.pop_back();
			}
			else {
				cout << "No\n";
				return;
			}
		}
	}

	cout << "Yes\n";
	for (auto &x : ans) {
		cout << x << ' ';
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
	cin >> t;
	while (t--) solve();

	return 0;
}