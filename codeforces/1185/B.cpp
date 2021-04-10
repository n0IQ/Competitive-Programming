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

vector<pair<char, int>> split(string s)
{
	vector<pair<char, int>> ans;
	s.pb('0');
	char c = s[0];
	int cnt = 1;

	rep(i, 1, sz(s) + 1) {
		if (c != s[i]) {
			ans.pb({c, cnt});
			c = s[i];
			cnt = 1;
		}
		else cnt++;
	}

	return ans;
}

void solve()
{
	int n;
	cin >> n;

	rep(i, 0, n) {
		string s, t;
		cin >> s >> t;

		auto sa(split(s)), ta(split(t));
		bool ok = (sz(sa) == sz(ta));

		if (ok) {
			rep(i, 0, sz(sa)) {
				if (sa[i].ff != ta[i].ff || sa[i].ss > ta[i].ss) ok = false;
			}
		}

		if (ok) cout << "YES" << '\n';
		else cout << "NO" << '\n';
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
	//cin>>t;
	while (t--) solve();

	return 0;
}