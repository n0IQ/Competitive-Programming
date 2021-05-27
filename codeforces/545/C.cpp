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

const int maxn = 1e5;
ll a[maxn + 10], h[maxn + 10];

void solve()
{
	int n;
	cin >> n;
	rep(i, 0, n) cin >> a[i] >> h[i];

	if (n == 1) {
		cout << 1 << " ";
		return;
	}

	int cnt = 1;
	rep(i, 1, n - 1) {
		if ((a[i] - h[i]) > a[i - 1]) {
			cnt++;
			a[i] = max(a[i], a[i] - h[i]);
		}
		else if ((a[i] + 0LL + h[i]) < a[i + 1]) {
			cnt++;
			a[i] = max(a[i], a[i] + h[i]);
		}
	}

	cout << cnt + 1 << '\n';
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