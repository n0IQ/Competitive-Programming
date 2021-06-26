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

ll countoccurences(string s, string t = "wow")
{
	int n = sz(s), m = sz(t);
	ll dp[n + 1][m + 1];

	rep(i, 0, m + 1) {
		dp[0][i] = 0;
	}

	rep(i, 0, n + 1) {
		dp[i][0] = 1;
	}

	rep(i, 1, n + 1) {
		rep(j, 1, m + 1) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][m];
}

void solve()
{
	string s;
	cin >> s;
	int n = sz(s);

	string res;

	rep(i, 0, n) {
		if (s[i] == 'o') res.pb('o');
		else {
			int cnt = 0;
			while (i < n && s[i] == 'v') cnt++, i++;

			if (cnt > 1) {
				string t(cnt - 1, 'w');
				res += t;
			}
			else res.pb('v');
			i--;
		}
	}

	cout << countoccurences(res) << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}