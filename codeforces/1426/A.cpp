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
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif
	
	int T;
	cin >> T;
	
	while (T-- > 0)
	{
	    int n, x;
	    cin >> n >> x;

	    int floor = 1, apt_range1 = 1, apt_range2 = 2, i = 0, j =1;

	    while(1)
	    {
	    	if((apt_range1 <= n) && (n <= apt_range2))
	    	{
	    		break;
	    	}
	    	else
	    	{
	    		apt_range1 = (i*x + 3); 
	    		apt_range2 = (j*x+2); 
	    		i++; 
	    		j++; 
	    		floor++; 
	    	}
	    }

	    cout << floor << endl;
	}
	
	return 0;
}