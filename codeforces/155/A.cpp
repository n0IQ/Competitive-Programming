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

	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int min_score = a[0], max_score = a[0], amazing_contests = 0;

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			continue;
		if (a[i] < min_score)
		{
			amazing_contests++;
			min_score = a[i];
		}
		else if (a[i] > max_score)
		{
			amazing_contests++;
			max_score = a[i];
		}
	}

	cout << amazing_contests << '\n';

	return 0;
}