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
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int rook = 0, bishop = 0, king = 0;

	if (x1 == x2 || y1 == y2) rook = 1;
	else rook = 2;

	king = max(abs(x1 - x2), abs(y1 - y2));

	if ((x1 + y1) % 2 != (x2 + y2) % 2) {
		cout << rook << " " << bishop << " " << king << '\n';
		return;
	}
	else {
		for (int i = x1, j = y1; i >= 1 && j <= 8; i--, j++) {
			if (i == x2 && j == y2) {
				bishop = 1;
				cout << rook << " " << bishop << " " << king << '\n';
				return;
			}
		}

		for (int i = x1, j = y1; i <= 8 && j <= 8; i++, j++) {
			if (i == x2 && j == y2) {
				bishop = 1;
				cout << rook << " " << bishop << " " << king << '\n';
				return;
			}
		}

		for (int i = x1, j = y1; i >= 1 && j >= 1; i--, j--) {
			if (i == x2 && j == y2) {
				bishop = 1;
				cout << rook << " " << bishop << " " << king << '\n';
				return;
			}
		}

		for (int i = x1, j = y1; i <= 8 && j >= 1; i++, j--) {
			if (i == x2 && j == y2) {
				bishop = 1;
				cout << rook << " " << bishop << " " << king << '\n';
				return;
			}
		}

		bishop = 2;
	}

	cout << rook << " " << bishop << " " << king << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}