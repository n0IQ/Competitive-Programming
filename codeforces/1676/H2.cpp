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

// BIT -> Source GFG = https://www.geeksforgeeks.org/number-elements-less-equal-given-number-given-subarray/

struct Query
{
	int l, r, x, idx;
};

// structure to hold array
struct ArrayElement
{
	int val, idx;
};

// bool function to sort queries according to k
bool cmp1(Query q1, Query q2)
{
	return q1.x < q2.x;
}

// bool function to sort array according to its value
bool cmp2(ArrayElement x, ArrayElement y)
{
	return x.val < y.val;
}

// updating the bit array
void update(int bit[], int idx, int val, int n)
{
	for (; idx <= n; idx += idx & -idx)
		bit[idx] += val;
}

// querying the bit array
int query(int bit[], int idx, int n)
{
	int sum = 0;
	for (; idx > 0; idx -= idx & -idx)
		sum += bit[idx];
	return sum;
}

ll answerQueries(int n, Query queries[], int q,
                 ArrayElement arr[])
{
	// initialising bit array
	int bit[n + 1];
	memset(bit, 0, sizeof(bit));

	// sorting the array
	sort(arr, arr + n, cmp2);

	// sorting queries
	sort(queries, queries + q, cmp1);

	// current index of array
	int curr = 0;

	// array to hold answer of each Query
	int ans[q];

	// looping through each Query
	for (int i = 0; i < q; i++)
	{
		// traversing the array values till it
		// is less than equal to Query number
		while (arr[curr].val <= queries[i].x && curr < n)
		{
			// updating the bit array for the array index
			update(bit, arr[curr].idx + 1, 1, n);
			curr++;
		}

		// Answer for each Query will be number of
		// values less than equal to x upto r minus
		// number of values less than equal to x
		// upto l-1
		ans[queries[i].idx] = query(bit, queries[i].r + 1, n) -
		                      query(bit, queries[i].l, n);
	}

	// printing answer for each Query
	ll cnt = 0;
	for (int i = 0 ; i < q; i++)
		cnt += ans[i];

	return cnt;
}

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	ArrayElement arr[n];
	rep(i, 0, n) {
		arr[i].val = a[i];
		arr[i].idx = i;
	}

	int q = n - 1;
	Query queries[q];
	rep(i, 1, q + 1) {
		queries[i - 1].l = i;
		queries[i - 1].r = n - 1;
		queries[i - 1].x = a[i - 1];
		queries[i - 1].idx = i - 1;
	}

	cout << answerQueries(n, queries, q, arr) << '\n';
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
	cin >> t;
	while (t--) solve();

	return 0;
}