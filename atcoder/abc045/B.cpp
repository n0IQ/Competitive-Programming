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
	string a, b, c;
	cin >> a >> b >> c;

	int sa = sz(a), sb = sz(b), sc = sz(c);

	char x = a[0];
	sa--;
	a.erase(a.begin());

	while (1) {
		if (x == 'a') {
			if (sa == 0) {
				cout << 'A' << '\n';
				return;
			}

			sa--;
			x = a[0];
			a.erase(a.begin());
		}
		else if (x == 'b') {
			if (sb == 0) {
				cout << 'B' << '\n';
				return;
			}

			sb--;
			x = b[0];
			b.erase(b.begin());
		}
		else {
			if (sc == 0) {
				cout << 'C' << '\n';
				return;
			}

			sc--;
			x = c[0];
			c.erase(c.begin());
		}
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
	//cin >> t;
	while (t--) solve();

	return 0;
}