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
	string s;
	cin >> n >> s;

	int open = 0, closed = 0, cnt = 0;

	rep(i, 0, n) {
		if (s[i] == '(') open++;
		else closed++;
	}

	if (open != closed || n == 1) {
		cout << "No" << '\n';
		return;
	}

	stack<char> stk;

	rep(i, 0, n) {
		if (stk.empty()) stk.push(s[i]);
		else if (s[i] == ')' && stk.top() == '(') stk.pop();
		else stk.push(s[i]);
	}

	while (!stk.empty()) {
		if (stk.top() == ')')cnt++;
		stk.pop();
	}

	if (cnt > 1) cout << "No" << '\n';
	else cout << "Yes" << '\n';
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