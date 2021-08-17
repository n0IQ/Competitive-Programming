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
	int n, m, d;
	cin >> n >> m >> d;

	vector<int> a(m);
	rep(i, 0, m) cin >> a[i];

	int i = d - 1, j = 0;
	while (i < n) {
		if (j >= m) {
			cout << "NO" << '\n';
			return;
		}

		int wood = a[j++];

		while (i < n && wood) {
			wood--;
			i++;
		}

		i += (d - 1);
	}

	vector<int> res(n, 0), pos;
	i = 0, j = 0;
	while (i < n && j < m) {
		int wood = a[j];
		while (wood--) res[i++] = j + 1;
		pos.pb(i - 1);
		j++;
	}

	reverse(all(pos));
	int end = n;
	j = m - 1;

	rep(i, 0, sz(pos)) {
		int old_pos = pos[i], new_pos = end - d, l = a[j];

		if (old_pos + d < end) {
			while (l--) res[old_pos--] = 0;
			l = a[j];
			while (l--) res[new_pos--] = j + 1;
			end = new_pos + 1;
			j--;
		}
		else break;
	}

	cout << "YES" << '\n';
	for (auto x : res) cout << x << " ";
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
	//cin>>t;
	while (t--) solve();

	return 0;
}