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

bool check(string s, int n)
{
	rep(i, 1, n) {
		if (s[i] == s[i - 1]) return false;
	}

	return true;
}

void solve()
{
	string s;
	cin >> s;

	int n = sz(s);

	if (n == 1) {
		cout << 'a' << '\n';
		return;
	}

	rep(i, 0, n) {
		vb v(3, 0);

		if (s[i] == '?') {
			if (i == 0) {
				if (s[i + 1] == '?') s[i] = 'a';
				else {
					int t = s[i + 1] - 'a' + 1;
					s[i] = 'a' + t % 3;
				}
			}
			else if (i == n - 1) {
				int t = s[i - 1] - 'a' + 1;
				s[i] = 'a' + t % 3;
			}
			else {
				v[s[i - 1] - 'a'] = 1;
				if (s[i + 1] != '?') v[s[i + 1] - 'a'] = 1;

				rep(j, 0, 3) {
					if (v[j] == 0) {
						s[i] = 'a' + j;
						break;
					}
				}
			}
		}
	}

	if (check(s, n)) cout << s << '\n';
	else cout << -1 << '\n';
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