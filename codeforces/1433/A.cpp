#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vsort sort(v.begin(),v.end())
#define mod 1000000007
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
		int x;
		cin >> x;

		ll digits = 0;
		int ap_no = 1, rem = 1, count = 1;

		while (ap_no <= 10000)
		{
			if (ap_no == x)
			{
				digits += count % 5;
				break;
			}

			digits += count % 5;
			rem = ap_no % 10;
			ap_no = (ap_no * 10) + rem;
			count++;

			if (ap_no > 10000)
			{
				ap_no = rem;
				ap_no++;
				count = 1;
			}
		}

		cout << digits << endl;
	}

	return 0;
}