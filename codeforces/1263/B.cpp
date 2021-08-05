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

map<string, int> m;

string getCode(string s)
{
	m[s]--;
	rep(i, 0, 4) {
		for (char c = '0'; c <= '9'; c++) {
			s[i] = c;

			if (!m.count(s)) {
				m[s]++;
				return s;
			}
		}
	}

	return s;
}

void solve()
{
	int n;
	cin >> n;

	vector<string> a(n);
	m.clear();
	rep(i, 0, n) {
		cin >> a[i];
		m[a[i]]++;
	}

	int cnt = 0;
	for (auto it : m) cnt += (it.ss - 1);

	cout << cnt << '\n';

	rep(i, 0, n) {
		string s = a[i];

		if (m[s] > 1) {
			s = getCode(s);
		}

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