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

vector<string> names, res;

void getnames()
{
	rep(i, 0, 2) {
		string s;
		i == 0 ? s = "A" : s = "B";

		for (char c = 'a'; c <= 'z'; c++) {
			s.pb(c);
			names.pb(s);
			s.pop_back();
		}
	}
}

void solve()
{
	int n, k;
	cin >> n >> k;

	getnames();

	int l = 0;
	rep(i, 0, k - 1) res.pb(names[l++]);

	rep(i, k - 1, n) {
		string s; cin >> s;
		if (s == "YES") res.pb(names[l++]);
		else res.pb(res[i - (k - 1)]);
	}

	for (auto x : res) cout << x << " ";
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