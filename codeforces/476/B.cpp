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

int sum = 0;
vi cases;

void wifi(string s, int i, int n, int total)
{
	if (i == n) {
		cases.pb(total);
		return;
	}

	if (s[i] == '+') {
		wifi(s, i + 1, n, total + 1);
	}
	else if (s[i] == '-') {
		wifi(s, i + 1, n, total - 1);
	}
	else {
		wifi(s, i + 1, n, total + 1);
		wifi(s, i + 1, n, total - 1);
	}
}

void solve()
{
	string s1, s2;
	cin >> s1 >> s2;

	rep(i, 0, sz(s1)) {
		if (s1[i] == '+') sum += 1;
		else sum -= 1;
	}

	wifi(s2, 0, sz(s2), 0);

	int cnt = 0;
	for (auto it : cases) {
		if (it == sum) cnt++;
	}

	double ans = cnt / (sz(cases) * 1.0);

	cout << ps(ans, 12) << '\n';
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