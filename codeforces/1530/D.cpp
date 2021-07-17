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
	cin >> n;

	vi a(n), b(n, -1);
	set<int> s, temp;

	rep(i, 0, n) {
		cin >> a[i];
		--a[i];
		temp.insert(a[i]);
	}

	rep(i, 0, n) {
		if (!temp.count(i)) {
			s.insert(i);
		}
	}

	set<int> mark, idx;

	for (auto x : s) {
		if (!mark.count(a[x])) {
			b[x] = a[x];
			mark.insert(a[x]);
		}
	}

	rep(i, 0, n) {
		if (b[i] != -1) continue;
		if (!mark.count(a[i])) {
			b[i] = a[i];
			mark.insert(a[i]);
		}
		else {
			idx.insert(i);
		}
	}


	for (auto x : idx) {
		if (s.count(x)) {
			auto it = s.lb(x);

			if (it != s.begin()) it--;
			b[x] = *it;
			s.erase(it);
		}
	}

	rep(i, 0, n) {
		if (b[i] == -1) {
			b[i] = *(s.begin());
			s.erase(s.begin());
		}
	}


	int ans = 0;
	rep(i, 0, n) {
		if (a[i] == b[i]) ans++;
	}
	cout << ans << '\n';
	rep(i, 0, n) cout << b[i] + 1 << " ";
	cout << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}