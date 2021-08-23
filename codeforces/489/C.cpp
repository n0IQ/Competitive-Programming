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
	int m, s;
	cin >> m >> s;

	if (m == 1) {
		if (s >= 0 && s <= 9) cout << s << " " << s << '\n';
		else cout << "-1 -1" << '\n';
		return;
	}

	if (s == 0 || 9 * m < s) {
		cout << "-1 -1" << '\n';
		return;
	}

	string small, big;
	int l = m, sum = s;

	while (l > 0) {
		rep(i, l == m ? 1 : 0, 10) {
			if (sum - i <= (l - 1) * 9) {
				small += ('0' + i);
				sum -= i;
				l--;
				break;
			}
		}
	}

	l = m, sum = s;
	while (l > 0) {
		big += ('0' + min(9, sum));
		sum -= min(9, sum);
		l--;
	}

	cout << small << " " << big << '\n';
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