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
		string s;
		cin >> s;

		int i = n - 1;
		ll count = 0;

		for (; i >= 0; i--) {
			if (s[i] != ')') {
				break;
			}
			else {
				count++;
			}
		}

		int rem;

		if (i != 0) {
			rem = i + 1;
		}
		else {
			rem = i;
		}

		if (count > rem) {
			cout << "Yes" << '\n';
		}
		else {
			cout << "No" << '\n';
		}
	}

	return 0;
}