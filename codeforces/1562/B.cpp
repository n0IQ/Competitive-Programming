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

set<char> p = {'1', '4', '6', '8', '9'};

bool check(int n)
{
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}

	return true;
}

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	map<int, int> cnt;
	rep(i, 0, n) {
		cnt[s[i] - '0']++;

		if (p.count(s[i])) {
			cout << 1 << '\n';
			cout << s[i] << '\n';
			return;
		}
	}

	for (auto it : cnt) {
		if (it.ss >= 2) {
			cout << 2 << '\n';
			cout << it.ff << it.ff << '\n';
			return;
		}
	}

	rep(i, 0, n) {
		rep(j, i + 1, n) {
			int num = ((s[i] - '0') * 10) + (s[j] - '0');
			if (!check(num)) {
				cout << 2 << '\n';
				cout << num << '\n';
				return;
			}
		}
	}

	cout << n << '\n';
	cout << s << '\n';
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