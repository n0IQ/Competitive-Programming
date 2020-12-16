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
		ll x;
		cin >> x;

		ll start = 0, count = 0, i = 1;

		while (1) {
			if (start >= x) {
				break;
			}

			start += i;
			i++;
			count++;
		}

		if (start == x) {
			cout << count << '\n';
			continue;
		}
		else if (start - 1 == x) {
			cout << count + 1 << '\n';
		}
		else if (start > x) {
			cout << count << '\n';
		}
	}

	return 0;
}