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
	ll n, k;
	cin >> n >> k;

	multiset<ll, greater<ll>> s;

	for (int j = 30; j >= 0 && k > 0; j--) {
		if (1 << j <= n) {
			k--;
			n -= (1 << j);
			s.insert(1 << j);
		}
	}

	if (n != 0) {
		cout << "NO" << '\n';
		return;
	}

	while (k > 0) {
		int x = *(s.begin());
		if (x == 1) break;
		s.erase(s.begin());
		s.insert(x / 2), s.insert(x / 2);
		k--;
	}

	if (k != 0) cout << "NO" << '\n';
	else {
		cout << "YES" << '\n';
		for (auto x : s) cout << x << " ";
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