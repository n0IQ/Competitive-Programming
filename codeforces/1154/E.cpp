#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, a, b) for(int i = a; i < b; i++)
#define repR(i, a, b) for(int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MOD1 1000000007
#define MOD2 998244353
#define INF  2000000000000000000
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

void solve()
{
	int n, k;
	cin >> n >> k;

	int a[n];
	map<int, int, greater<int>> m;
	set<pii> s;

	rep(i, 0, n) {
		cin >> a[i];
		m[a[i]] = i;
		s.insert({i, a[i]});
	}

	int t1 = 0;
	while (!s.empty()) {
		t1 = 1 - t1;
		int x = m.begin()->ff, idx = m.begin()->ss;

		if (t1) a[idx] = 1;
		else a[idx] = 2;

		int temp = k;
		auto it = s.find({idx, x});

		while (temp-- && !s.empty()) {
			auto it1 = it;
			it1++;

			if (it1 == s.end()) break;
			x = it1->ss, idx = it1->ff;

			if (t1) a[idx] = 1;
			else a[idx] = 2;

			m.erase(x);
			s.erase(it1);
		}

		temp = k;
		while (temp-- && !s.empty()) {
			auto it1 = it;

			if (it1 == s.begin()) break;
			else it1--;

			x = it1->ss, idx = it1->ff;

			if (t1) a[idx] = 1;
			else a[idx] = 2;

			m.erase(x);
			s.erase(it1);
		}

		s.erase(it);
		m.erase(m.begin());
	}

	rep(i, 0, n) cout << a[i];
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
	//cin >> t;
	while (t--) solve();

	return 0;
}