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

bool check(string s, int n, int pos)
{
	if (s[pos] == 'a' && pos < n - 2) {
		if (s[pos + 1] == 'b' && s[pos + 2] == 'c') return true;
		return false;
	}
	else if (s[pos] == 'b' && pos > 0 && pos < n - 1) {
		if (s[pos + 1] == 'c' && s[pos - 1] == 'a') return true;
		return false;
	}
	else if (s[pos] == 'c' && pos >= 2) {
		if (s[pos - 1] == 'b' && s[pos - 2] == 'a') return true;
		return false;
	}

	return false;
}

void solve()
{
	int n, q;
	string s;
	cin >> n >> q >> s;

	int subs = 0;
	rep(i, 0, n - 2) {
		if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
			subs++;
		}
	}

	while (q--) {
		int pos;
		char ch;
		cin >> pos >> ch;
		pos--;

		int ok1 = check(s, n, pos);
		s[pos] = ch;
		int ok2 = check(s, n, pos);

		if (ok1 == 1 && ok2 == 0) subs--;
		else if (ok1 == 0 && ok2 == 1) subs++;

		cout << subs << '\n';
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
	//cin >> t;
	while (t--) solve();

	return 0;
}