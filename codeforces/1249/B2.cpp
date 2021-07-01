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

const int MaxN = 3e5;
int p[MaxN], r[MaxN];

void init()
{
	rep(i, 0, MaxN) {
		p[i] = i;
		r[i] = 1;
	}
}

int get_set(int x)
{
	if (x == p[x])
		return x;

	return p[x] = get_set(p[x]);
}

void union_set(int a, int b)
{
	if (r[a] < r[b])
		swap(a, b);

	p[b] = p[a];
	r[a] += r[b];
}

void solve()
{
	init();

	int n;
	cin >> n;

	rep(i, 1, n + 1) {
		int a = i, b; cin >> b;

		a = get_set(a);
		b = get_set(b);

		if (a != b) {
			union_set(a, b);
		}
	}

	rep(i, 1, n + 1) {
		int x = get_set(i);
		cout << r[x] << " ";
	}

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