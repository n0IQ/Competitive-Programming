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

	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];

	int l = 0, r = n - 1, mx = 0;
	bool ok = false;
	string res;

	while (l <= r) {
		if (a[l] > mx && a[r] > mx) {
			if (a[l] == a[r]) {
				ok = true;
				break;
			}
			else if (a[l] < a[r]) {
				res.pb('L');
				mx = a[l++];
			}
			else {
				res.pb('R');
				mx = a[r--];
			}
		}
		else if (a[l] > mx) {
			res.pb('L');
			mx = a[l++];
		}
		else if (a[r] > mx) {
			res.pb('R');
			mx = a[r--];
		}
		else break;
	}

	if (ok) {
		string t1 = res, t2 = res;
		int j = l, temp = mx;

		while (l <= r && a[l] > mx) {
			t1.pb('L');
			mx = a[l++];
		}

		l = j, mx = temp;
		while (r >= j && a[r] > mx) {
			t2.pb('R');
			mx = a[r--];
		}

		if (sz(t1) > sz(t2)) res = t1;
		else res = t2;
	}

	cout << sz(res) << '\n';
	cout << res << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}