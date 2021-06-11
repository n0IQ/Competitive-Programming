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

	vi a(n), b(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];

	vi pos, neg;
	rep(i, 0, n) {
		if (b[i] == 0) {
			if (a[i] >= 0) pos.pb(a[i]);
			else if (a[i] < 0)neg.pb(a[i]);
		}
	}

	sort(all(pos), greater<int>()), sort(all(neg), greater<int>());
	int i = 0, j = 0;

	while (j < sz(pos)) {
		if (b[i] == 0) a[i] = pos[j++];
		i++;
	}

	j = 0;
	while (j < sz(neg)) {
		if (b[i] == 0) a[i] = neg[j++];
		i++;
	}

	rep(i, 0, n) cout << a[i] << " ";
	cout << '\n';
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