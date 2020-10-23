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

	int flag1 = 0, flag2 = 1;

	while (n > 0 && m > 0)
	{
		if (flag1 == 0)
		{
			n--;
			m--;
			flag1 = 1;
			flag2 = 0;
		}
		else if (flag2 == 0)
		{
			n--;
			m--;
			flag1 = 0;
			flag2 = 1;
		}
	}

	if (flag1 == 1)
		cout << "Akshat" << '\n';
	else
		cout << "Malvika" << '\n';


	return 0;
}