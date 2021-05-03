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

	if (n < 3 || n == 4) cout << -1 << '\n';
	else if (n % 3 == 0) cout << n / 3 << " " << 0 << " " << 0 << '\n';
	else if (n % 5 == 0) cout << 0 << " " << n / 5 << " " << 0 << '\n';
	else if (n % 7 == 0) cout << 0 << " " << 0 << " " << n / 7 << '\n';
	else {
		int t1 = n - 3, t2 = n - 5, t3 = n - 7;
		if (t1 % 5 == 0 || t1 % 7 == 0) {
			if (t1 % 5 == 0) cout << 1 << " " << t1 / 5 << " " << 0 << '\n';
			else cout << 1 << " " << 0 << " " << t1 / 7 << '\n';
		}
		else if (t2 % 3 == 0 || t2 % 7 == 0) {
			if (t2 % 3 == 0) cout << t2 / 3 << " " << 1 << " " << 0 << '\n';
			else cout << 0 << " " << 1 << " " << t2 / 7 << '\n';
		}
		else if (t3 % 3 == 0 || t3 % 5 == 0) {
			if (t3 % 3 == 0) cout << t3 / 3 << " " << 0 << " " << 1 << '\n';
			else cout << 0 << " " << t3 / 5 << " " << 1 << '\n';
		}
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
	cin >> t;
	while (t--) solve();

	return 0;
}