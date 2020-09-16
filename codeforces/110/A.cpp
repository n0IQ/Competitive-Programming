#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pb push_back
#define mp make_pair
#define vsort sort(v.begin(),v.end())
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int main()
{
	fastio

	#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif
	
	ll n, rem, nearly_lucky = 0, flag = 0;
	cin >> n;
	
	while(n > 0)
	{
		rem = n % 10;

		if (rem == 4 || rem == 7)
		{
			nearly_lucky++;
		}

		n = n / 10;
	}

	if (nearly_lucky == 7 || nearly_lucky == 4)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}