#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll> &a, int n, ll h, ll k, int op)
{
	ll cnt = 0, green = 2, blue = 1, x = h, ok = 1;

	for (int i = 0; i < n; ) {
		if (h > a[i]) {
			h += (a[i] / 2);
			i++, cnt++;
		}
		else {
			if (op == 1) { // bgg
				if (blue > 0) {
					h *= 3LL;
					blue--;
				}
				else if (green > 0) {
					h *= 2LL;
					green--;
				}
				else break;
			}
			else if (op == 2) { //gbg
				if (ok) {
					if (green > 0) {
						h *= 2LL;
						green--;
						ok = 0;
					}
					else break;
				}
				else {
					if (blue > 0) {
						h *= 3LL;
						blue--;
					}
					else if (green > 0) {
						h *= 2LL;
						green--;
					}
					else break;
				}
			}
			else { //ggb
				if (green > 0) {
					h *= 2LL;
					green--;
				}
				else if (blue > 0) {
					h *= 3LL;
					blue--;
				}
				else break;
			}
		}
	}

	return cnt >= k;
}

void solve()
{
	int n;
	ll h;
	cin >> n >> h;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());

	ll l = 1, r = n, ans = 0;
	while (l <= r) {
		ll mid = l + (r - l) / 2;

		if (check(a, n, h, mid, 1) || check(a, n, h, mid, 2) || check(a, n, h, mid, 3)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
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