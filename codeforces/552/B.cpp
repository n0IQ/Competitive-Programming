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

ll mult(ll a, ll b)
{
	ll res = (a * 1LL * b);

	return res;
}

ll power(ll a, ll b)
{
	ll res = 1;

	while (b) {
		if (b % 2 == 1) {
			res = mult(a, res);
		}

		a = mult(a, a);
		b /= 2;
	}

	return res;
}

int getsize(ll n)
{
	int cnt = 0;
	while (n != 0) {
		n /= 10;
		cnt++;
	}

	return cnt;
}

void solve()
{
	ll n, cnt = 0;
	cin >> n;

	if (n < 10) {
		cout << n << '\n';
		return;
	}
	else cnt += 9;

	int i = 2, l = getsize(n);

	while (i < l) {
		ll num = 9 * 1LL * power(10, i - 1);
		cnt += i * 1LL * num;
		i++;
	}

	ll num = power(10, i - 1);
	cnt += i * (n - num + 1);
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
	//cin >> t;
	while (t--) solve();

	return 0;
}