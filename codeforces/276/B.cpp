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
	string s;
	cin >> s;

	map<char, int> m;
	for (auto c : s) m[c]++;
	bool first = true;

	while (1) {
		bool ok = false, play = false;

		for (auto it : m) {
			if (it.ss % 2 == 1) {
				if (!ok) ok = true;
				else {
					play = true;
					break;
				}
			}
		}

		if (play) {
			ok = false;
			for (auto &it : m) {
				if (it.ss > 0 && it.ss % 2 == 0) {
					ok = true;
					it.ss--;
					break;
				}
			}

			if (!ok) {
				for (auto &it : m) {
					if (it.ss > 0) {
						it.ss--;
						break;
					}
				}
			}

			if (first) first = false;
			else first = true;
		}
		else {
			if (first) cout << "First\n";
			else cout << "Second\n";
			return;
		}
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
	// cin >> t;
	while (t--) solve();

	return 0;
}