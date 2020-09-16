#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define vsort sort(v.begin(),v.end())
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

void Remove_Smallest()
{
	int n;
    cin >> n;

	std::vector<int> v;

	for (int i = 0; i < n; ++i)
	{
	    int num;
	    cin >> num;
	    v.pb(num);
	}

	vsort;
	int flag = 0;

	for (int i = 1; i <n; ++i)
	{
		if(v[i] - v[i-1] <= 1)
		{
			continue;
		}
		else
		{
			flag = 1;
			break;
		}
	}

	if(flag == 0)
	{
	    cout << "YES" << endl;
	}
	else
	{
	    cout << "NO" << endl;
	}

	return;
}

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
	    Remove_Smallest();
	}
	
	return 0;
}