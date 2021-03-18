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
	int n, m;
	cin >> n >> m;

	unordered_map<int, int> mp;
	rep(i, 0, m) {
		int u, v; cin >> u >> v;
		mp[u]++, mp[v]++;
	}

	int count1 = 0, count2 = 0, count3 = 0;

	for (auto p : mp) {
		if (p.ss == 1)count1++;
		if (p.ss == 2)count2++;
		if (p.ss > 2) count3++;;
	}

	if (count1 == 2 && count2 == n - 2 && count3 == 0) cout << "bus topology" << '\n';
	else if (count1 == 0 && count2 == n && count3 == 0 ) cout << "ring topology" << '\n';
	else if (count1 == n - 1 && count2 == 0 && count3 == 1) cout << "star topology" << '\n';
	else cout << "unknown topology" << '\n';
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