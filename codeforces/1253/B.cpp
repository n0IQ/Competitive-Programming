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

	vector<int> a(n), res;
	rep(i, 0, n) cin >> a[i];

	set<int> s;
	map<int, int> m;
	int cnt = 0;

	rep(i, 0, n) {
		if (a[i] > 0) {
			if (s.count(a[i]) || m[a[i]] >= 2) {
				cout << -1 << '\n';
				return;
			}

			s.insert(a[i]);
			m[a[i]]++;
			cnt++;
		}
		else {
			a[i] = abs(a[i]);
			if (!s.count(a[i])) {
				cout << -1 << '\n';
				return;
			}

			s.erase(a[i]);
			m[a[i]]++;
			cnt++;

			if (s.empty()) {
				m.clear();
				res.pb(cnt);
				cnt = 0;
			}
		}
	}

	if (!s.empty()) cout << -1 << '\n';
	else {
		cout << sz(res) << '\n';
		for (auto x : res) cout << x << " ";
		cout << '\n';
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