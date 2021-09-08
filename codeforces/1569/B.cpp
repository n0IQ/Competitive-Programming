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
	int n;
	string s;
	cin >> n >> s;

	int twos = 0;
	rep(i, 0, n) {
		if (s[i] == '2') twos++;
	}

	if (twos == 1 || twos == 2) {
		cout << "NO\n";
		return;
	}

	char a[n][n];
	rep(i, 0, n) {
		rep(j, 0, n) {
			if (i == j) a[i][j] = 'X';
			else a[i][j] = '?';
		}
	}

	rep(i, 0, n) {
		bool ok = true;

		rep(j, 0, n) {
			if (a[i][j] == '?') {
				if (s[i] == '1') {
					a[i][j] = '=';
					a[j][i] = '=';
				}
				else {
					if (s[j] == '1') {
						a[i][j] = '=';
						a[j][i] = '=';
					}
					else {
						if (ok) {
							a[i][j] = '+';
							a[j][i] = '-';
							ok = false;
						}
						else {
							a[i][j] = '-';
							a[j][i] = '+';
						}
					}
				}
			}

		}
	}

	cout << "YES\n";
	rep(i, 0, n) {
		rep(j, 0, n) {
			cout << a[i][j];
		}

		cout << '\n';
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}