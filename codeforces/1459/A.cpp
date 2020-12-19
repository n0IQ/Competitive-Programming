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

	while (T-- > 0)
	{
		int n;
		cin >> n;

		string s1;
		string s2;
		cin >> s1 >> s2;

		vi v1;
		vi v2;

		for (int i = 0; i < n; i++) {
			v1.pb(s1[i] - '0');
		}

		for (int i = 0; i < n; i++) {
			v2.pb(s2[i] - '0');
		}

		ll red = 0, blue = 0;
		//int Redzeros = 0, BlueZeros = 0;

		/*for (int i = 0; i < n; i++) {
			if (v1[i] == 0) {
				Redzeros++;
			}
		}

		for (int i = 0; i < n; i++) {
			if (v2[i] == 0) {
				BlueZeros++;
			}
		}*/

		for (int i = 0; i < n; i++) {
			if (v1[i] > v2[i]) {
				red++;
			}
			else if (v2[i] > v1[i]) {
				blue++;
			}
		}

		if (red > blue) {
			cout << "RED" << '\n';
		}
		else if (blue > red) {
			cout << "BLUE" << '\n';
		}
		else if (red == blue) {
			cout << "EQUAL" << '\n';
		}
	}

	return 0;
}