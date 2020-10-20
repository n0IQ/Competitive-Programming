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

int Solve()
{
	int n;
	cin >> n;

	std::vector<int> v;
	int ones = 0, zeros = 0;

	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		v.pb(num);

		if (num == 1)
			ones++;
	}

	if (ones <= 1)
		return 0;

	int shifts = 0;

	int l = 0, r = v.size() - 1;

	for (int i = 0; i < n; i++)
	{
		if (v[i] == 1 && v[i + 1] != 1)
		{
			l = i;
			break;
		}
	}

	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] == 1 && v[i - 1] != 1)
		{
			r = i;
			break;
		}
	}
	l++;
	r--;

	while (l <= r)
	{
		if (v[l] == 0)
		{
			zeros++;
		}
		l++;
	}

	shifts = zeros;

	return shifts;
}

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
		int shifts = Solve();

		cout << shifts << endl;
	}

	return 0;
}