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
	int n;
	cin >> n;

	int a[n];
	map<int, int> m;
	rep(i, 0, n) {
		cin >> a[i];
		m[a[i]]++;
	}

	set<pii, greater<pii>> s;
	for (auto it : m) {
		s.insert({it.ss, it.ff});
	}

	if (s.begin()->ff == 1) {
		cout << 0 << '\n';
		return;
	}

	int ans = 1e9;
	rep(l, 0, n) {
		set<pii, greater<pii>> t = s;
		map<int, int> cnt = m;

		rep(r, l, n) {
			auto it = t.find({cnt[a[r]], a[r]});
			int occ = it->ff - 1;
			t.erase(it);
			if (occ) t.insert({occ, a[r]});
			cnt[a[r]] = occ;

			if (t.begin()->ff == 1) {
				ans = min(ans, r - l + 1);
			}
		}
	}

	cout << ans << '\n';
}

int main()
{
	fastio;

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}