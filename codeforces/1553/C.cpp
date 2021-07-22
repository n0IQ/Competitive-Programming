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

int ans;

void minKicks(string s)
{
	int n = sz(s), ptsA = 0, kickA = 5, ptsB = 0, kickB = 5, mn = 10;

	rep(i, 0, n) {
		if (i % 2 == 0) {
			if (s[i] == '1') ptsA++;
			kickA--;

			if (ptsA - ptsB > kickB) {
				mn = i + 1;
				break;
			}

			if (ptsB - ptsA > kickA) {
				mn = i + 1;
				break;
			}
		}
		else {
			if (s[i] == '1') ptsB++;
			kickB--;

			if (ptsB - ptsA > kickA) {
				mn = i + 1;
				break;
			}

			if (ptsA - ptsB > kickB) {
				mn = i + 1;
				break;
			}
		}
	}

	ans = min(ans, mn);
}


void getstring (string s, int i, int n)
{
	if (i == n) {
		minKicks(s);
		return;
	}

	if (s[i] == '?') {
		s[i] = '1';
		getstring(s, i + 1, n);

		s[i] = '0';
		getstring(s, i + 1, n);
	}
	else getstring(s, i + 1, n);
}

void solve()
{
	string s;
	cin >> s;

	int n = sz(s);
	ans = 10;

	getstring(s, 0, n);

	cout << ans << '\n';
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