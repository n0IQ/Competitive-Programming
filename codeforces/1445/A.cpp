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

bool Solve(vi v1, vi v2, int x)
{
	if (v1[0] + v2[0] > x)
		return false;

	int flag = 0;
	int n = (int)v1.size();

	for (int i = n - 1; i >= 0 ; i--)
	{
		if (v1[i] + v2[i] <= x)
			continue;

		if (v1[i] + v2[i] > x)
		{
			swap(v2[flag], v2[i]);

			if (v2[flag] + v1[flag] > x || v1[i] + v2[i] > x)
				return false;

			flag++;
		}
	}

	return true;
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
		int n, x;
		cin >> n >> x;

		vi v1;
		vi v2;

		for (int i = 0; i < n; i++)
		{
			int num; cin >> num;
			v1.pb(num);
		}

		for (int i = 0; i < n; i++)
		{
			int num; cin >> num;
			v2.pb(num);
		}

		if (Solve(v1, v2, x))
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}

	return 0;
}