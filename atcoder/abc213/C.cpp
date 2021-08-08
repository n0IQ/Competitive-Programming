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
	int h, w, n;
	cin >> h >> w >> n;

	map<int, int> row, col;
	set<int> temp1, temp2;
	vector<pii> q;

	rep(i, 0, n) {
		int x, y; cin >> x >> y;
		temp1.insert(x), temp2.insert(y);
		q.pb({x, y});
	}

	vector<int> a, b;
	for (auto x : temp1) a.pb(x);
	for (auto x : temp2) b.pb(x);

	int cnt = 0, prev = 0;
	rep(i, 0, sz(a)) {
		int back = a[i] - prev - 1;
		row[a[i]] = a[i] - back - cnt;
		prev = a[i];
		cnt += back;
	}

	cnt = 0, prev = 0;
	rep(i, 0, sz(b)) {
		int back = b[i] - prev - 1;
		col[b[i]] = b[i] - back - cnt;
		prev = b[i];
		cnt += back;
	}

	rep(i, 0, n) {
		int x = q[i].ff, y = q[i].ss;
		cout << row[x] << " " << col[y] << '\n';
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