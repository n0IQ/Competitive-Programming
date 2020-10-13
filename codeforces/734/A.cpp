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
	string s;
	cin >> s;
	//cout << s << '\n';

	ll anton_wins = 0, danik_wins = 0;

	for (int x : s)
	{
		if (x == 'A')
			anton_wins++;
		else
			danik_wins++;
	}

	if (anton_wins > danik_wins)
		cout << "Anton" << '\n';
	else if (danik_wins > anton_wins)
		cout << "Danik" << '\n';
	else
		cout << "Friendship" << '\n';

	return 0;
}