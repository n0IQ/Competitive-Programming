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

	std::vector<int> v;
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		v.pb(num);
		sum += num;
	}

	sort(v.begin(), v.end(), greater<>());

	int twin1 = 0, twin2 = sum, coins = 0;

	for (int i = 0; i < n; i++)
	{
		twin1 += v[i];
		twin2 -= v[i];
		coins++;

		if (twin1 > twin2)
			break;
	}

	cout << coins << endl;


	return 0;
}