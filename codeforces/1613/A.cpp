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
	int x1, x2, p1, p2;
	cin >> x1 >> p1 >> x2 >> p2;

	int n1 = x1, n2 = x2, cnt1 = 0, cnt2 = 0;
	while (n1 > 0) {
		n1 /= 10;
		cnt1++;
	}
	while (n2 > 0) {
		n2 /= 10;
		cnt2++;
	}

	cnt1 += p1;
	cnt2 += p2;

	if (cnt1 > cnt2) cout << ">\n";
	else if (cnt1 < cnt2) cout << "<\n";
	else {
		string s1 = to_string(x1), s2 = to_string(x2);
		while (sz(s1) < sz(s2)) s1.pb('0');
		while (sz(s2) < sz(s1)) s2.pb('0');

		int ok = -1;
		rep(i, 0, min(sz(s1), sz(s2))) {
			if (s1[i] > s2[i]) {
				ok = 0;
				break;
			}
			else if (s1[i] < s2[i]) {
				ok = 1;
				break;
			}
		}

		if (ok == 0) cout << ">\n";
		else if (ok == 1) cout << "<\n";
		else if (ok == -1) cout << "=\n";
	}
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