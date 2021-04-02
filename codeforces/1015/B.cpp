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

const int N = 1e4;

void solve()
{
	int n;
	string s, t;
	cin >> n >> s >> t;

	string temp1 = s, temp2 = t;
	sort(all(temp1)), sort(all(temp2));
	if (temp1 != temp2) {
		cout << -1 << '\n';
		return;
	}

	vi v;

	for (int i = 0; i < n; ) {
		if (s[i] == t[i]) i++;
		else {
			char c = t[i];

			rep(j, i, n) {
				if (s[j] == c) {
					v.pb(j);
					swap(s[j - 1], s[j]);
					break;
				}
			}
		}
	}

	if (sz(v) <= N) {
		cout << sz(v) << '\n';

		for (auto x : v) cout << x << " ";
		cout << '\n';
	}
	else {
		cout << -1 << '\n';
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
	//cin >> t;
	while (t--) solve();

	return 0;
}