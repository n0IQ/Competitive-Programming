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

bool check(string s)
{
	stack<char> stk;

	rep(i, 0, sz(s)) {
		if (stk.empty() || s[i] == '(' || (s[i] == ')' && stk.top() != '(')) {
			stk.push(s[i]);
		}
		else {
			stk.pop();
		}
	}

	if (stk.empty()) return true;
	return false;
}

void solve()
{
	string s;
	cin >> s;

	int n = sz(s);

	if (s[0] == s[n - 1]) {
		cout << "NO" << '\n';
		return;
	}

	char c1 = s[0], c2 = s[n - 1];
	for (auto &it : s) {
		if (it == c1) it = '(';
		if (it == c2) it = ')';
	}

	string t1 = s, t2 = s;
	rep(i, 0, n) {
		if (t1[i] >= 'A' && t1[i] <= 'C') t1[i] = '(';
		if (t2[i] >= 'A' && t2[i] <= 'C') t2[i] = ')';
	}

	if (check(t1) || check(t2)) cout << "YES" << '\n';
	else cout << "NO" << '\n';
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