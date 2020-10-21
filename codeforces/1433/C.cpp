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
		int n;
		cin >> n;

		std::vector<int> v;
		int max_size = 0;

		for (int i = 0; i < n; i++)
		{
			int num; cin >> num;
			v.pb(num);
			max_size = max(max_size, num);
		}

		int index = -1;

		for (int i = 0; i < n; i++)
		{
			if (v[i] != max_size) continue;
			if (i > 0 && v[i - 1] != max_size)
			{
				index = i + 1;
			}
			if (i < n - 1 && v[i + 1] != max_size)
			{
				index = i + 1;
			}
		}

		cout << index << '\n';
	}

	return 0;
}