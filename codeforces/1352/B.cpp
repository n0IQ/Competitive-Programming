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
	ll n, k;
	cin >> n >> k;

	int temp = k;

	if (n == k) {
		cout << "YES" << '\n';

		while (n != 0) {
			cout << 1 << " ";
			n--;
		}

		cout << '\n';
		return;
	}

	if (k == 1) {
		cout << "YES" << '\n';
		cout << n << '\n';
		return;
	}

	if (n < k) {
		cout << "NO" << '\n';
		return;
	}

	if (n - k == 1) {
		cout << "NO" << '\n';
		return;
	}

	if (n % 2 == 1) {
		if (k % 2 == 0 || k > n) {
			cout << "NO" << '\n';
			return;
		}
	}

	int a[101], i = 0;

	if (n % 2 == 0) {
		if (k % 2 == 1) {
			while (1) {
				a[i] = 2;
				i++; n -= 2; k--;
				if (k == 1) {
					if (n <= 0) {
						cout << "NO" << '\n';
						return;
					}

					a[i] = n;
					break;
				}
			}
		}
		else {
			while (1) {
				a[i] = 1;
				i++; n -= 1; k--;
				if (k == 1) {
					if (n <= 0) {
						cout << "NO" << '\n';
						return;
					}

					a[i] = n;
					break;
				}
			}
		}
	}
	else {
		while (1) {
			a[i] = 1;
			i++; n -= 1; k--;
			if (k == 1) {
				if (n <= 0) {
					cout << "NO" << '\n';
					return;
				}

				a[i] = n;
				break;
			}
		}
	}

	cout << "YES" << '\n';

	rep(i, 0, temp) {
		cout << a[i] << " ";
	}

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