#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans;
bool isPossible;

void merge(vector<int> l, vector<int> r, vector<int> &a)
{
	int n = l.size(), m = r.size(), i = 0, j = 0, k = 0;
	bool ok = 0;

	while (i < n && j < m) {
		if (l[i] <= r[j]) {
			a[k++] = l[i++];
		}
		else {
			a[k++] = r[j++];
			ok = 1;
		}
	}

	while (i < n) {
		a[k++] = l[i++];
	}

	while (j < m) {
		a[k++] = r[j++];
	}

	if (ok) ans++;
}

void MergeSort(vector<int> &a, int n)
{
	if (n < 2) return;

	int mid = n / 2;
	vector<int> l(mid), r(n - mid);

	for (int i = 0; i < mid; i++) l[i] = a[i];
	for (int i = mid; i < n; i++) r[i - mid] = a[i];

	MergeSort(l, mid);
	MergeSort(r, n - mid);
	merge(l, r, a);
}

bool check(vector<int> &a, int l, int r, int sr, int er)
{
	for (int i = l; i < r; i++) {
		if (a[i] >= sr && a[i] <= er) continue;
		else return false;
	}
	return true;
}

void helper(vector<int> &a, int n, int l, int r, int sr, int er)
{
	if (n == 0) return;
	if (check(a, l, r, sr, sr + n - 1)) {
		helper(a, n / 2, l, l + n / 2, sr, sr + n - 1);
		helper(a, n / 2, l + n / 2, r, sr, sr + n - 1);
	}
	else if (check(a, l, r, sr + n, er)) {
		helper(a, n / 2, l, l + n / 2, sr + n, er);
		helper(a, n / 2, l + n / 2, r, sr + n, er);
	}
	else isPossible = 0;
}

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	if (n == 1) {
		cout << "0\n";
		return;
	}

	isPossible = 1;
	helper(a, n / 2, 0, n / 2, 1, n);
	helper(a, n / 2, n / 2, n, 1, n);

	if (isPossible == 0) {
		cout << "-1\n";
		return;
	}

	ans = 0;
	MergeSort(a, n);

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