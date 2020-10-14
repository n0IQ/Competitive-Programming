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

	std::vector<int> v;

	for (int i = 0; i < n; ++i)
	{
		int num; cin >> num;
		v.pb(num);
	}

	int sub = 0, max_sub = -1, flag = 0;

	for (int i = 0; i < n; i++)
	{
		if ((i == 0) || (v[i]) >= v[i - 1])
			sub++;
		else
		{
			flag = 1;
			if (max_sub < sub)
				max_sub = sub;

			sub = 1;
		}
	}

	if (max_sub < sub)
		max_sub = sub;

	cout << max_sub << '\n';

	return 0;
}