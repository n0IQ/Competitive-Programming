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
	int n, k, d;
	cin >> n >> k >> d;

	vi a(n);
	rep(i, 0, n) cin >> a[i];

	int cnt[1000010] = {0};
	int i = 0, j = 0, days = 0, total = 0;

	while (j < n && days < d) {
		if (cnt[a[j]] == 0) total++;

		cnt[a[j]]++;
		j++, days++;
	}

	int	res = total;

	while (j < n) {
		cnt[a[i]]--;
		if (cnt[a[i]] == 0) total--;
		cnt[a[j]]++;
		if (cnt[a[j]] == 1) total++;
		i++, j++;

		res = min(res, total);
	}

	cout << res << '\n';
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