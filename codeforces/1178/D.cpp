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

const int N = 1e5;
bool isPrime[N + 10];
set<int> primes;
int deg[1010];
set<pii> edges;

void sieve()
{
	for (int i = 0; i <= N; i++) {
		isPrime[i] = true;
	}

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i <= N; i++) {
		if (isPrime[i] && i * i <= N) {
			for (int j = i * i; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}

	primes.insert(2);
	for (int i = 3; i <= N; i += 2) {
		if (isPrime[i]) primes.insert(i);
	}
}

void solve()
{
	int n;
	cin >> n;

	rep(i, 1, n) {
		edges.insert({i, i + 1});
		deg[i]++;
		deg[i + 1]++;
	}
	edges.insert({n, 1});
	deg[n]++, deg[1]++;

	int x = *(primes.lb(sz(edges))) - sz(edges);
	int i = 1;

	while (x > 0) {
		int curr = deg[i];
		int corp = min(n - deg[i] - 1, curr + x);
		auto it = primes.lb(corp);
		if (*it > corp) it--;
		int add = abs(*it - curr);
		x -= add;

		for (int j = 1, k = 0; k < add && j <= n; j++) {
			if (i == j) continue;
			if (primes.count(deg[j] + 1) && !edges.count({i, j}) && !edges.count({j, i})) {
				edges.insert({i, j});
				deg[i]++, deg[j]++;
				k++;
			}
		}

		i++;
	}

	cout << sz(edges) << '\n';
	for (auto it : edges) {
		cout << it.ff << " " << it.ss << '\n';
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	sieve();
	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}