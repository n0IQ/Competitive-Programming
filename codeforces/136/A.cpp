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

	int arr[n];

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	std::map<int, int> m;
	std::map<int, int>::iterator it;

	for (int i = 1; i <= n; i++)
	{
		m[arr[i]] += i;
	}

	for (it = m.begin(); it != m.end(); it++)
	{
		cout << it->ss << " ";
	}

	return 0;
}