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
#define all v.begin(),v.end()
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
		int x, y;
		cin >> x >> y;

		if (x == y)
			cout << x * 2 << '\n';
		else
		{
			int a = min(x, y); // Now we can reach to (a,a) in a*2 steps
			int b = max(x, y);

			cout << (a * 2) + 1 + ((b - a - 1) * 2) << '\n';
		}
	}

	return 0;
}