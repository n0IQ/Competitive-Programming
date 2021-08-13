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
	int n, s, k;
	cin >> n >> s >> k;

	set<int> closed;
	rep(i, 0, k) {
		int x; cin >> x;
		closed.insert(x);
	}

	int ans = n - 1, step = 0;
	bool ok = false;
	for (int i = s; i <= min(s + k + 10, n); i++) {
		if (!closed.count(i)) {
		    ok = true;
		    break;
		}
		
		step++;
	}
	
	if(ok) ans = step;
	step = 0;
	ok = false;
	

	for (int i = s; i >= max(1, s - k); i--) {
		if (!closed.count(i)) {
		    ok = true;
		    break;
		}
		
		step++;
	}
	
	if(ok) ans = min(ans, step);
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
	cin >> t;
	while (t--) solve();

	return 0;
}