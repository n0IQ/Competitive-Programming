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
	int a, b;
	string s;
	cin >> a >> b >> s;

	int n = sz(s);

	rep(i, 0, n / 2) {
		if (s[i] != '?' && s[n - i - 1] != '?') {
			if (s[i] != s[n - i - 1]) {
				cout << -1 << '\n';
				return;
			}
		}

		if (s[i] != '?' || s[n - i - 1] != '?') {
			if (s[i] != '?') s[n - i - 1] = s[i];
			else s[i] = s[n - i - 1];

			if (s[i] == '0') a -= 2;
			else b -= 2;
		}
	}

	rep(i, 0, n / 2) {
		if (a > 1 && s[i] == '?') {
			s[i] = '0';
			s[n - i - 1] = '0';
			a -= 2;
		}
		else if (b > 1 && s[i] == '?') {
			s[i] = '1';
			s[n - i - 1] = '1';
			b -= 2;
		}
	}

	if (n % 2 == 1) {
		if (s[n / 2] == '?') {
			if (a == 1) {
				s[n / 2] = '0';
				a--;
			}
			else  {
				s[n / 2] = '1';
				b--;
			}
		}
		else {
			if (s[n / 2] == '0') a--;
			else b--;
		}
	}

	if (a > 0 || b > 0) {
		cout << -1 << '\n';
	}
	else {
		cout << s << '\n';
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