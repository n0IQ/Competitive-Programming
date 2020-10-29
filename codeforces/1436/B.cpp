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

	const int N = 1e5 + 5;
	static bool prime[N];

	for (int i = 0; i < N; i++)
	{
		prime[i] = true;
	}

	prime[0] = prime[1] = false;

	for (int i = 2; i * i < N; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j < N; j += i)
			{
				prime[j] = false;
			}
		}
	}

	int T;
	cin >> T;

	while (T-- > 0)
	{
		int n;
		cin >> n;

		int num = 1;

		while (num <= 1e5)
		{
			if (prime[num] == false )
			{
				if (prime[num + (n - 1)])
				{
					break;
				}
			}

			num++;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
					cout << num << " ";
				}
				else
				{
					cout << 1 << " ";
				}
			}

			cout << '\n';
		}

	}

	return 0;
}