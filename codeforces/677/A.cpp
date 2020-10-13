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

	int n, h;
	cin >> n >> h;

	int width = 0;

	for (int i = 0; i < n; ++i)
	{
		int num; cin >> num;

		if (num > h)
			width += 2;
		else
			width += 1;
	}

	cout << width << '\n';

	return 0;
}