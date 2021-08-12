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
	int a, b, c, m;
	cin >> a >> b >> c >> m;

	vector<ll> usb, ps2, both;
	rep(i, 0, m) {
		ll cost;
		string t;
		cin >> cost >> t;

		if (t == "USB") usb.pb(cost);
		else ps2.pb(cost);
	}

	ll totalCost = 0, comps = 0;
	sort(all(usb)), sort(all(ps2));
	int i = 0;

	while (i < sz(usb) && a) {
		totalCost += usb[i];
		comps++, i++, a--;
	}

	rep(j, i, sz(usb)) both.pb(usb[j]);

	i = 0;
	while (i < sz(ps2) && b) {
		totalCost += ps2[i];
		comps++, i++, b--;
	}

	rep(j, i, sz(ps2)) both.pb(ps2[j]);
	sort(all(both));

	i = 0;
	while (i < sz(both) && c) {
		totalCost += both[i];
		comps++, i++, c--;
	}

	cout << comps << " " << totalCost << '\n';
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