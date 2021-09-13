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

	vector<int> a(n);
	map<int, int> m;
	rep(i, 0, n) {
		cin >> a[i];
		m[a[i]]++;
	}

	int g = m[a[0]], s = 0, b = 0, medals = g, i = g;

	while (i < n && g >= s) {
		s += m[a[i]];
		i += m[a[i]];
	}

	medals += s;
	while (i < n) {
		int t = m[a[i]];
		if (medals + t > n / 2) break;
		else {
			b += t;
			medals += t;
			i += t;
		}
	}

	if (g == 0 || s == 0 || b == 0 || g >= s || g >= b) cout << "0 0 0\n";
	else cout << g << ' ' << s << ' ' << b << '\n';
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