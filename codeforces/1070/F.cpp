#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define ppb pop_back
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
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
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

/*---------------------------------------------------------Debugging----------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------------------------------------------*/

void solve()
{
	int n;
	cin >> n;

	vector<ll> a, b, none;

	ll ans = 0, alice_pts = 0, bob_pts = 0, cnt = 0;
	rep(i, 0, n) {
		string s;
		ll p;
		cin >> s >> p;

		if (s == "11") {
			ans += p;
			alice_pts++;
			bob_pts++;
			cnt++;
		}
		else if (s == "10") a.pb(p);
		else if (s == "01") b.pb(p);
		else none.pb(p);
	}

	sort(all(a));
	sort(all(b));
	sort(all(none));
	debug(ans)

	while (sz(a) > 0 && sz(b) > 0 && alice_pts * 2 >= cnt && bob_pts * 2 >= cnt) {
		ans += a.back();
		ans += b.back();
		a.ppb();
		b.ppb();
		alice_pts++, bob_pts++, cnt += 2;
	}

	vector<pair<ll, pair<bool, bool>>> temp;
	for (auto x : a) temp.pb({x, {1, 0}});
	for (auto x : b) temp.pb({x, {0, 1}});
	for (auto x : none) temp.pb({x, {0, 0}});

	sort(all(temp));
	debug(ans)
	debug(temp)

	while (!temp.empty()) {
		ans += temp.back().ff;
		if (temp.back().ss.ff == 1) alice_pts++;
		else if (temp.back().ss.ss == 1) bob_pts++;
		cnt++;
		if (alice_pts * 2 < cnt || bob_pts * 2 < cnt) {
			ans -= temp.back().ff;
			if (temp.back().ss.ff == 1) alice_pts--;
			else if (temp.back().ss.ss == 1) bob_pts--;
			cnt--;
		}
		temp.ppb();
	}

	debug(ans)

	cout << ans << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("Error.txt", "w", stderr);
#endif

	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}