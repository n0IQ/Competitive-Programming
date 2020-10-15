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

	while (T-- > 0) // 5
	{
		int a, b;
		cin >> a >> b;

		int d = abs(a - b);

		if ((d % 10) == 0)
			cout << d / 10 << '\n';
		else
			cout << (d / 10) + 1 << '\n';

	}
	return 0;
}