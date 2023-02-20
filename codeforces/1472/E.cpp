#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> adj[200010];

int helper(vector<ll> &v, ll val1, ll val2, int currentIdx)
{
	auto it = lower_bound(v.begin(), v.end(), val1);
	--it;
	int idx = (int)(it - v.begin()), validIdx = -1;

	if (idx != -1) {
		for (auto &it : adj[idx]) {
			if (it.first < val2 && it.second != currentIdx) {
				validIdx = it.second;
				break;
			}
		}
	}

	return validIdx;
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		adj[i].clear();
	}

	vector<pair<ll, ll>> a(n);
	vector<pair<pair<ll, ll>, ll>> arr(n); // h, w, idx

	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		arr[i] = {{a[i].first, a[i].second}, i};
	}
	sort(arr.begin(), arr.end());

	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = arr[i].first.first;
	}

	priority_queue<pair<ll, ll>> pq; // store min W with indexes
	for (int i = 0; i < n; i++) {
		pq.push({arr[i].first.second, arr[i].second}); // W, idx
		while ((int)pq.size() > 2) pq.pop();

		auto q = pq;
		while (!q.empty()) {
			adj[i].push_back({q.top()});
			q.pop();
		}
	}

	vector<ll> ans(n, -1);
	for (int i = 0; i < n; i++) {
		// check first contition
		int validIdx = helper(v, a[i].first, a[i].second, i);
		if (validIdx != -1) {
			ans[i] = validIdx;
			continue;
		}
		// check second contition
		ans[i] = helper(v, a[i].second, a[i].first, i);
	}

	for (int i = 0; i < n; i++) {
		if (ans[i] == -1) cout << "-1 ";
		else cout << ans[i] + 1 << ' ';
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