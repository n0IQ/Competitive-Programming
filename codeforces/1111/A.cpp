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

bool isvowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;
}

void solve()
{
	string s, t;
	cin >> s >> t;

	if (sz(s) != sz(t)) {
		cout << "No" << '\n';
		return;
	}

	bool ok = true;
	rep(i, 0, sz(s)) {
		if (s[i] != t[i]) {
			if (isvowel(s[i])) {
				if (!isvowel(t[i])) ok = false;
			}
			else {
				if (isvowel(t[i])) ok = false;
			}
		}
	}

	if (ok) cout << "Yes" << '\n';
	else cout << "No" << '\n';
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