#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define vsort sort(v.begin(),v.end())
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int Perfect_Team(int c, int m, int x)
{
	int left = 0, mid = 0, right = 0;
	int ans = 0;

	right = min(c, m);

	while(left <= right)
	{
		mid = left + (right - left) / 2;

		if((c-mid)+(m-mid)+x >= mid)
		{
			ans = mid;
			left = mid+1;
		}
		else
		{
			right = mid-1;
		}
	}

	return ans;
}


int main()
{
	fastio

	#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif
	
	int q;
	cin >> q;
	
	while (q-- > 0)
	{
		int c, m, x;
		cin >> c >> m >> x;

	    int ans = Perfect_Team(c, m, x);

	    cout << ans << endl;
	}
	
	return 0;
}