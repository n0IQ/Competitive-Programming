#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
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

	while (T-- > 0)
	{
		ll n;
		cin >> n;

		vi v;

		int flag = 0;
		string s = to_string(n);

		for (int i = 0; i < s.length(); i++) {
			if (s[i] - '0' != 0) {
				v.pb(s[i] - '0');
			}
		}

		ll i;

		for (i = n; ; ) {
			flag = 0;

			for (auto x : v) {
				if (i % x != 0) {
					flag = 1;
					v.clear();
					break;
				}
			}

			if (flag == 1) {
				i++;
				s = "";
				s = to_string(i);

				for (int j = 0; j < s.length(); j++) {
					if (s[j] - '0' != 0) {
						v.pb(s[j] - '0');
					}
				}
			}
			else {
				break;
			}
		}

		cout << i << '\n';
	}

	return 0;
}