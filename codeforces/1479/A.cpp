#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repR(i, n) for (int i = n-1; i >= 0; --i)
#define repA(i, a, n) for (int i = a; i <= n; ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vd vector<double>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>
#define vpdd vector<pdd>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int N = 1e5 + 10;
int n;
int a[N];

void query(int x)
{
	if (1 <= x && x <= n) {
		cout << "? " << x << endl;
		cout.flush();
		cin >> a[x];
	}
}

int main()
{
	fastio;

	cin >> n;

	a[0] = a[n + 1] = n + 1;
	int l = 1, r = n;

	while (l < r) {
		int mid = (l + r) / 2;
		query(mid);
		query(mid + 1);

		if (a[mid] < a[mid + 1]) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}

	cout << "! " << l << endl;
	cout.flush();

	return 0;
}
