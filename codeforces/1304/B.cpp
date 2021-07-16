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
	int n, m;
	cin >> n >> m;

	vector<string> a(n);
	rep(i, 0, n) cin >> a[i];

	vector<string> p1, p2, p3;

	for (int i = 0; i < sz(a); ) {
		string s = a[i];
		reverse(all(s));

		auto it = find(all(a), s);
		int j = it - a.begin();

		if (i != j && it != a.end()) {
			p1.pb(a[i]);
			p3.pb(s);

			a.erase(a.begin() + i);

			if (i < j) --j;
			a.erase(a.begin() + j);
		}
		else i++;
	}

	for (int i = 0; i < sz(a); ) {
		string s = a[i];
		reverse(all(s));

		if (a[i] == s) {
			p2.pb(a[i]);
			a.erase(a.begin() + i);
			break;
		}
		else i++;
	}

	reverse(all(p3));
	string res;
	for (auto s : p1) res += s;
	for (auto s : p2) res += s;
	for (auto s : p3) res += s;

	cout << sz(res) << '\n';
	cout << res << '\n';
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