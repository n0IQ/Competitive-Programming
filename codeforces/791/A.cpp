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
	
	ll a, b, years = 0;
	cin >> a >> b;

	while(a <= b)
	{
		a = a * 3;
		b = b * 2;
		years++;
	}

	cout << years << endl;
	
	return 0;
}