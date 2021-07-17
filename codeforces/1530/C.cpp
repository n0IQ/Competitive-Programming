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

	sort(all(a)), sort(all(b));

	ll sum1 = accumulate(all(a), 0);
	ll sum2 = accumulate(all(b), 0);
	int k = n - (n - (n / 4)), cnt = 0;
	int l1 = 0, l2 = 0;

	while (l1 < k) sum1 -= a[l1++];
	while (l2 < k) sum2 -= b[l2++];
	l2--;

	int rounds = n, t;
	while (sum1 < sum2) {
		cnt++;
		sum1 += 100;
		rounds++;

		t = rounds - (rounds - (rounds / 4));
		if (t != k) {
			sum1 -= a[l1];
			l1++;
			k = t;

			continue;
		}

		if (l2 >= 0) {
			sum2 += b[l2];
			l2--;
		}
	}

	cout << cnt << '\n';
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