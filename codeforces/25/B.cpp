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

	if (n == 2) cout << s << '\n';
	else if (n == 3) cout << s << '\n';
	else if (n % 2 == 0) {
		string ans;
		ans.pb(s[0]); ans.pb(s[1]); ans.pb('-');
		int k = 0;

		rep(i, 2, n) {
			if (k == 2) {
				ans.pb('-');
				ans.pb(s[i]);
				k = 1;
			}
			else {
				ans.pb(s[i]);
				k++;
			}
		}

		cout << ans << '\n';
	}
	else {
		string ans;
		ans.pb(s[0]); ans.pb(s[1]); ans.pb(s[2]); ans.pb('-');
		int k = 0;

		rep(i, 3, n) {
			if (k == 2) {
				ans.pb('-');
				ans.pb(s[i]);
				k = 1;
			}
			else {
				ans.pb(s[i]);
				k++;
			}
		}

		cout << ans << '\n';
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