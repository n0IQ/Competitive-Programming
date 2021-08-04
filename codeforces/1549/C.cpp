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

const int N = 2e5 + 10;
int in[N], out[N];
set<int> s;

void solve()
{
	int n, m;
	cin >> n >> m;

	rep(i, 0, m) {
		int x, y; cin >> x >> y;
		--x, --y;
		if (x > y) swap(x, y);
		in[x]++, out[x]++;
	}

	rep(i, 0, n) {
		if (in[i]) s.insert(i);
	}

	int q;
	cin >> q;

	while (q--) {
		int type; cin >> type;

		if (type == 1) {
			int x, y; cin >> x >> y;
			--x, --y;
			if (x > y) swap(x, y);
			in[x]++, out[y]++;
			s.insert(x);
		}
		else if (type == 2) {
			int x, y; cin >> x >> y;
			--x, --y;
			if (x > y) swap(x, y);
			in[x]--, out[y]--;

			if (in[x] == 0) s.erase(x);
		}
		else {
			cout << n - sz(s) << '\n';
		}
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