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

bool Odd()
{
	int n;
	cin >> n;

	std::vector<int> v;
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		v.pb(num);
		sum += num;
	}

	if (sum % 2 != 0)
		return true;

	int odd_no = 0, even_no = 0;

	for (int x : v)
	{
		if (x % 2 != 0)
			odd_no++;
		else
			even_no++;
	}

	if (odd_no == 0 || even_no == 0)
		return false;

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
		if (Odd())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}