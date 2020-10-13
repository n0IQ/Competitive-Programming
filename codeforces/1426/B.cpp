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

bool Solve()
{
	int n, m;
	cin >> n >> m;

	std::vector<pair<int, int>> v;
	std::vector<pair<int, int>>::iterator it;
	std::vector<pair<int, int>>::iterator it1;

	for (int i = 0; i < 2 * n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.pb(mp(x, y));
	}

	if (m % 2 != 0)
		return false;


	for (it = v.begin(); it != v.end(); it++)
	{
		it1 = it;
		it1++;

		if ((it1 != v.end()) && (it->ss == it1->ff))
		{
			return true;
		}

		it++;
	}

	/*for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << it->ff << " " << it->ss << endl;
	}*/

	return false;
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
		if (Solve())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}