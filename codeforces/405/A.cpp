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

vector<int> Gravity(std::vector<int> v, int n)
{

	// 3 2 1 2
	// i
	// 2 3 1 2
	for (int i = 0; i < n; i++)
	{
		int flag = 0;

		for (int j = 0; j < n - i - 1; j++)
		{
			if (v[j] >= v[j + 1])
			{
				swap(v[j], v[j + 1]);
				flag = 1;
			}
		}

		if (flag == 0)
			break;
	}

	return v;
}

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

	vector<int> ans = Gravity(v, n);

	for (int x : ans)
		cout << x << " ";

	cout << endl;

	return 0;
}