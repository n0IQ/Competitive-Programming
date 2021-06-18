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

	vll a(n);
	map<ll, ll> cnt;
	rep(i, 0, n) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	sort(all(a));

	bool ok = 0;
	ll num = 0;
	for (auto &it : cnt) {
		if (it.ss > 1) {
			ok = 1;
			num = it.ff;
			it.ss -= 2;
			break;
		}
	}

	vll res(n);
	if (ok) {
		res[0] = res[n - 1] = num;
	}
	else {
		ll mn = INT_MAX, num1 = 0, num2 = 0;

		rep(i, 0, n - 1) {
			ll t = abs(a[i] - a[i + 1]);

			if (t < mn) {
				mn = t;
				num1 = a[i], num2 = a[i + 1];
			}
		}

		res[0] = num1, res[n - 1] = num2;
		cnt[num1]--;
		cnt[num2]--;
	}

	multiset<ll> s;
	for (auto &it : cnt) {
		while (it.ss > 0) {
			s.insert(it.ff);
			it.ss--;
		}
	}

	rep(i, 1, n - 1) {
		auto it = s.lb(res[i - 1]);
		if (it == s.end()) {
			it = s.begin();
		}
		ll x = *it;
		s.erase(it);
		res[i] = x;
	}

	rep(i, 0, n) cout << res[i] << " ";
	cout << '\n';
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