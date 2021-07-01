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

ll a[10];
set<ll> s;

void getsum(int i, ll sum)
{
	if (i == 10) return;
	s.insert(sum);

	getsum(i + 1, sum + a[i]);
	getsum(i + 1, sum);
}

void init()
{
	a[0] = 1;
	s.insert(1);

	ll t = 1LL;
	rep(i, 1, 10) {
		t *= 3LL;
		a[i] = t;
		s.insert(a[i]);
	}

	getsum(0, 0);
}

void solve()
{
	ll n;
	cin >> n;

	auto it = s.lb(n);
	cout << *it << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	init();
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}