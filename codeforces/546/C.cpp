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

	vector<int> a, b;

	int x; cin >> x;
	rep(i, 0, x) {
		int num; cin >> num;
		a.pb(num);
	}

	int y; cin >> y;
	rep(i, 0, y) {
		int num; cin >> num;
		b.pb(num);
	}

	int l = 0;
	while (1) {
		if (sz(a) == 0 || sz(b) == 0 || l == 2e6) break;
		int num1 = a[0], num2 = b[0];
		a.erase(a.begin()), b.erase(b.begin());

		if (num1 > num2) a.pb(num2), a.pb(num1);
		else b.pb(num1), b.pb(num2);

		l++;
	}

	if (sz(a) == 0) cout << l << " " << 2 << '\n';
	else if (sz(b) == 0) cout << l << " " << 1 << '\n';
	else cout << -1 << '\n';
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