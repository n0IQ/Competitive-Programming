#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 2000000000000000

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int i = 0, cnt = 0;
	ll ans = 0, sum = 0;
	priority_queue<ll> q;

	while (i < n && s[i] == '1') ans += a[i++];

	while (i < n) {
		while (i + 1 < n && s[i + 1] == '0') {
			i++;
		}

		q.push(a[i++]);
		cnt = 0;

		while (i < n && s[i] == '1') {
			q.push(a[i++]);
			cnt++;
		}

		while (!q.empty()) {
			if (cnt > 0) {
				ans += q.top();
				cnt--;
			}
			q.pop();
		}
	}

	cout << ans << '\n';
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