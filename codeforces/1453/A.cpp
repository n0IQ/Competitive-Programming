#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define all v.begin(),v.end()
#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

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
		int n, m;
		cin >> n >> m;

		vi t1;
		vi t2;

		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			t1.pb(num);
		}

		for (int i = 0; i < m; i++) {
			int num; cin >> num;
			t2.pb(num);
		}

		//set<int> s;
		ll crash = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (t1[i] == t2[j])
					crash++;
			}
		}

		cout << crash << '\n';
	}

	return 0;
}