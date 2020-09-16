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
	
	ll n, k, w, cost = 0;
	cin >> k >> n >> w;

	for (int i = 1; i <= w; ++i)
	{
		cost += k*i;
	}

	if(cost > n)
	{
		cout << cost - n << endl;
	}
	else
	{
		cout << 0 << endl;
	}

	
	
	return 0;
}