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

	int n = sz(s);
	s.pb('0');

	vector<int> posAB, posBA;

	rep(i, 0, n) {
		if (s[i] == 'A' && s[i + 1] == 'B') posAB.pb(i);
		if (s[i] == 'B' && s[i + 1] == 'A') posBA.pb(i);
	}

	rep(i, 0, sz(posAB)) {
		auto it = lb(all(posBA), posAB[i] + 2);
		if (it != posBA.end()) {
			cout << "YES" << '\n';
			return;
		}
	}

	rep(i, 0, sz(posBA)) {
		auto it = lb(all(posAB), posBA[i] + 2);
		if (it != posAB.end()) {
			cout << "YES" << '\n';
			return;
		}
	}

	cout << "NO" << '\n';
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