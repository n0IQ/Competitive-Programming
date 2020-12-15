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

int main()
{
	fastio

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;

	/*string s = "19";

	s[0] = s[0] + 1;
	cout << s;*/

	while (T-- > 0)
	{
		int x;
		cin >> x;

		if (x > 45) {
			cout << -1 << '\n';
			continue;
		}

		if (x <= 9) {
			cout << x << '\n';
			continue;
		}

		if (x >= 10 && x <= 17) {
			string s = "19";
			int diff = x - 10;

			for (int j = 0; j < diff; j++) {
				s[0] = s[0] + 1;
			}

			cout << s << '\n';
			continue;
		}

		if (x >= 18 && x <= 24) {
			string s = "189";
			int diff = x - 18;

			for (int j = 0; j < diff; j++) {
				s[0] = s[0] + 1;
			}

			cout << s << '\n';
			continue;
		}

		if (x >= 25 && x <= 30) {
			string s = "1789";
			int diff = x - 25;

			for (int j = 0; j < diff; j++) {
				s[0] = s[0] + 1;
			}

			cout << s << '\n';
			continue;
		}

		if (x >= 31 && x <= 35) {
			string s = "16789";
			int diff = x - 31;

			for (int j = 0; j < diff; j++) {
				s[0] = s[0] + 1;
			}

			cout << s << '\n';
			continue;
		}

		if (x >= 36 && x <= 39) {
			string s = "156789";
			int diff = x - 36;

			for (int j = 0; j < diff; j++) {
				s[0] = s[0] + 1;
			}

			cout << s << '\n';
			continue;
		}

		if (x >= 40 && x <= 42) {
			string s = "1456789";
			int diff = x - 40;

			for (int j = 0; j < diff; j++) {
				s[0] = s[0] + 1;
			}

			cout << s << '\n';
			continue;
		}

		if (x >= 43 && x <= 44) {
			string s = "13456789";
			int diff = x - 43;

			for (int j = 0; j < diff; j++) {
				s[0] = s[0] + 1;
			}

			cout << s << '\n';
			continue;
		}

		if (x == 45) {
			string s = "123456789";
			cout << s << '\n';
			continue;
		}

	}

	return 0;
}