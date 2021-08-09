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

	map<char, bool> col;
	col['R'] = 0, col['G'] = 0, col['B'] = 0;

	s.pb('0');
	int cnt = 0;
	rep(i, 1, n) {
		if (s[i] == s[i - 1]) {
			cnt++;

			if (s[i] == s[i + 1]) {
				if (s[i] == 'R') s[i] = 'B';
				else if (s[i] == 'B') s[i] = 'G';
				else s[i] = 'R';
			}
			else {
				col[s[i]] = 1; col[s[i + 1]] = 1;
				for (auto it : col) {
					if (it.ss == 0) s[i] = it.ff;
				}

				col['R'] = 0, col['G'] = 0, col['B'] = 0;
			}
		}
	}

	s.pop_back();
	cout << cnt << '\n';
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
	//cin>>t;
	while (t--) solve();

	return 0;
}