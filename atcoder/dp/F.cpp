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

string PrintLCS(string s1, string s2, int n, int m)
{
	int dp[n + 1][m + 1];

	rep(i, 0, n + 1) {
		rep(j, 0, m + 1) {
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	int i = n, j = m;
	string lcs;

	while (i > 0 && j > 0) {
		if (s1[i - 1] == s2[j - 1]) {
			lcs.pb(s1[i - 1]);
			i--, j--;
		}
		else {
			if (dp[i][j - 1] >= dp[i - 1][j]) j--;
			else i--;
		}
	}

	reverse(all(lcs));

	return lcs;
}

void solve()
{
	string s1, s2;
	cin >> s1 >> s2;

	int n = s1.length(), m = s2.length();

	cout << PrintLCS(s1, s2, n, m) << '\n';
}

int main()
{
	fastio;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}