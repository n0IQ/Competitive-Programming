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
	cin >> n;

	vi a(n);
	set<pii> s1, s2;

	rep(i, 1, n + 1) {
		int x; cin >> x;
		s1.insert({x, i});
	}

	rep(i, 1, n + 1) {
		int x; cin >> x;
		s2.insert({x, i});
	}

	map<int, int> cnt;
	auto it1 = s1.begin(), it2 = s2.begin();

	for ( ; it1 != s1.end() && it2 != s2.end(); it1++, it2++) {
		int x = it1->ss, y = it2->ss;

		int t = ((x % n) - (y % n) + n) % n;
		cnt[t]++;
	}

	int ans = 0;
	for (auto it : cnt) ans = max(ans, it.ss);

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
	//cin >> t;
	while (t--) solve();

	return 0;
}