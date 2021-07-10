#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, a, b) for(int i = a; i < b; i++)
#define repR(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

void solve()
{
	int x1, y1, x2, y2, f1, f2;
	cin >> x1 >> y1 >> x2 >> y2 >> f1 >> f2;

	if (x1 == x2) {
		if (x1 == f1 && ((f2 >= y1 && f2 <= y2) || (f2 >= y2 && f2 <= y1))) {
			cout << abs(y2 - y1) + 2 << '\n';
		}
		else {
			cout << abs(y2 - y1) << '\n';
		}
	}
	else if (y1 == y2) {
		if (y1 == f2 && ((f1 >= x1 && f1 <= x2) || (f1 >= x2 && f1 <= x1))) {
			cout << abs(x2 - x1) + 2 << '\n';
		}
		else {
			cout << abs(x2 - x1) << '\n';
		}
	}
	else {
		cout << abs(x1 - x2) + abs(y1 - y2) << '\n';
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}