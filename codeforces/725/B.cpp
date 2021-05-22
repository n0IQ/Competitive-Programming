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
	string s, t;
	cin >> s;

	t = s.substr(0, sz(s) - 1);
	ll n = stoll(t), seat = 0LL;
	char c = s[sz(s) - 1];

	if (((n - 1) % 4 == 0) || ((n - 2) % 4 == 0)) {
		seat = (6 * 1LL * (n / 2)) + (n - 1);
		if (c == 'f') seat += 1;
		else if (c == 'e') seat += 2;
		else if (c == 'd') seat += 3;
		else if (c == 'a') seat += 4;
		else if (c == 'b') seat += 5;
		else if (c == 'c') seat += 6;
	}
	else {
		seat = (6 * 1LL * (n / 2)) + (n - 3);
		if (c == 'f') seat -= 5;
		else if (c == 'e') seat -= 4;
		else if (c == 'd') seat -= 3;
		else if (c == 'a') seat -= 2;
		else if (c == 'b') seat -= 1;
	}

	cout << seat << '\n';
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