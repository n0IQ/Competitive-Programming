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
	int n, a, b, c, wins = 0;
	string s;
	cin >> n >> a >> b >> c >> s;

	char arr[n];
	rep(i, 0, n) arr[i] = 'A';

	rep(i, 0, n) {
		if (s[i] == 'R') {
			if (b > 0) {
				arr[i] = 'P';
				b--;
				wins++;
			}
		}
		else if (s[i] == 'P') {
			if (c > 0) {
				arr[i] = 'S';
				c--;
				wins++;
			}
		}
		else if (s[i] == 'S') {
			if (a > 0) {
				arr[i] = 'R';
				a--;
				wins++;
			}
		}
	}

	int req = 0;
	(n % 2 == 0 ? req = n / 2 : req = (n / 2) + 1);

	if (wins < req) {
		cout << "NO" << '\n';
		return;
	}

	rep(i, 0, n) {
		if (arr[i] == 'A') {
			if (a > 0) {
				arr[i] = 'R';
				a--;
			}
			else if (b > 0) {
				arr[i] = 'P';
				b--;
			}
			else if (c > 0) {
				arr[i] = 'S';
				c--;
			}
		}
	}

	string ans;
	rep(i, 0, n) ans.pb(arr[i]);

	cout << "YES\n" << ans << '\n';
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