#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, r, minDiff;
int dp[20][2][2]; // index, greater than left, smaller than right

ll helper(int idx, int greaterThanLeft, int smallerThanRight, int n, int maxVal, int minVal, string &curr, string &left, string &right, bool &found)
{
	if (idx == n) {
		found = true;
		return true;
	}

	if (dp[idx][greaterThanLeft][smallerThanRight] != -1) {
		return dp[idx][greaterThanLeft][smallerThanRight];
	}

	for (int i = minVal; i <= maxVal; i++) {
		if ((greaterThanLeft || i >= left[idx] - '0') && (smallerThanRight || i <= right[idx] - '0')) {
			curr.push_back(char('0' + i));
			helper(idx + 1, greaterThanLeft || i > left[idx] - '0', smallerThanRight || i < right[idx] - '0', n, maxVal, minVal, curr, left, right, found);
			if (found) return true;
			curr.pop_back();
		}
	}

	return dp[idx][greaterThanLeft][smallerThanRight] = false;
}

void solve()
{
	cin >> l >> r;

	string left = to_string(l),  right = to_string(r);
	if ((int)left.size() != (int)right.size()) {
		string ans((int)left.size(), '9');
		cout << ans << '\n';
		return;
	}

	string ans = left;
	minDiff = 100;

	for (int maxVal = 1; maxVal <= 9; maxVal++) {
		for (int minVal = 0; minVal <= maxVal; minVal++) {
			if (maxVal - minVal > minDiff) continue;

			memset(dp, -1, sizeof(dp));
			string curr;
			bool found = false;
			helper(0, 0, 0, (int)left.size(), maxVal, minVal, curr, left, right, found);

			if (found) {
				ans = curr;
				minDiff = maxVal - minVal;
			}
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