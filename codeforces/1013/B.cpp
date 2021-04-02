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
	int n, x;
	cin >> n >> x;

	int a[n];
	unordered_set<int> s;
	unordered_set<int>::iterator it1;
	map<int, int> mp;
	rep(i, 0, n) {
		int x; cin >> x;

		if (mp.find(x) != mp.end()) {
			cout << 0 << '\n';
			return;
		}

		a[i] = x;
		s.insert(x);
		mp[x]++;
	}

	int ans = 0, b[n];

	rep(i, 0, n) {
		b[i] = a[i] & x;
	}

	bool ok = false;
	sort(b, b + n);

	rep(i, 1, n) {
		if (b[i] == b[i - 1]) {
			ok = true;
			break;
		}
	}

	if (!ok) {
		cout << -1 << '\n';
		return;
	}

	for (it1 = s.begin(); it1 != s.end(); it1++) {
		int temp = *it1;
		int num = temp & x;

		auto it2 = s.find(num);
		if (it2 != s.end() && it2 != it1) {
			cout << 1 << '\n';
			return;
		}
	}

	cout << 2 << '\n';
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