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

	int n, m;
	cin >> n >> m;

	std::vector<int> v;

	for (int i = 0; i < m; i++)
	{
		int num; cin >> num;
		v.pb(num);
	}

	sort(v.begin(), v.end(), greater<>());

	int i = 0, j = n - 1, diff = 0, min_diff = INT_MAX;

	while (i < m && j < m)
	{
		int diff = v[i] - v[j];

		if (diff < min_diff)
		{
			min_diff = diff;
		}

		i++;
		j++;
	}

	cout << min_diff << '\n';

	return 0;
}