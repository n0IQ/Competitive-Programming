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
		ll n, c0, c1, h;
		cin >> n >> c0 >> c1 >> h;

		string s;
		cin >> s;
		//cout << s << '\n';

		ll original_cost = 0, total_cost = 0, count = 0, count0 = 0, count1 = 0;

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0')
				count0++;
			else
				count1++;
		}

		original_cost = (count0 * c0) + (count1 * c1);

		//cout << original_cost << '\n';

		if (c0 == c1)
		{
			total_cost = (n * c0);
		}
		else if (c0 <= c1 )
		{
			for (int i = 0; i < n; i++)
			{
				if (s[i] == '1')
				{
					count++;
				}
			}

			total_cost = (c0 * n) + (h * count);

		}
		else if (c1 < c0)
		{
			for (int i = 0; i < n; i++)
			{
				if (s[i] == '0')
				{
					count++;
				}
			}

			total_cost = (c1 * n) + (h * count);
		}

		if (original_cost <= total_cost)
		{
			cout << original_cost << '\n';
		}
		else
		{
			cout << total_cost << '\n';
		}

	}

	return 0;
}
