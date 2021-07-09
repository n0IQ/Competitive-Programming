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

set<int> Primefactor(int n)
{
	set<int> pf;
	while (n % 2 == 0)
	{
		pf.insert(2);
		n = n / 2;
	}

	for (int i = 3; i * i <= n; i += 2)
	{
		while (n % i == 0)
		{
			pf.insert(i);
			n = n / i;
		}
	}


	if (n > 2) pf.insert(n);
	return pf;
}

void solve()
{
	int n;
	cin >> n;

	vpii a(n);
	for (auto &[x, y] : a) {
		cin >> x >> y;
	}

	sort(all(a));
	int x = a[0].ff, y = a[0].ss;
	set<int> pfact1 = Primefactor(x);
	set<int> pfact2 = Primefactor(y);
	set<int> pfact;
	vi pf;

	for (auto it : pfact1) pfact.insert(it);
	for (auto it : pfact2) pfact.insert(it);

	for (auto it : pfact) {
		bool ok = 1;

		for (auto &[x, y] : a) {
			if (x % it != 0 && y % it != 0) {
				ok = 0;
				break;
			}
		}

		if (ok) {
			cout << it << '\n';
			return;
		}
	}

	cout << -1 << '\n';
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