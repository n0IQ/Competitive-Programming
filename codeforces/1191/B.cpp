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

bool ismentsu(string a, string b, string c)
{
	if (a == b && a == c) return true;

	int arr[3] = {a[0], b[0], c[0]};
	sort(arr, arr + 3);

	if (a[1] == b[1] && a[1] == c[1]) {
		if (arr[0] + 1 == arr[1] && arr[0] + 2 == arr[2]) {
			return true;
		}
	}

	return false;
}

void solve()
{
	string a, b, c;
	cin >> a >> b >> c;

	if (ismentsu(a, b, c)) {
		cout << 0 << '\n';
	}
	else if (a[1] != b[1] && a[1] != c[1] && b[1] != c[1]) {
		cout << 2 << '\n';
	}
	else {
		map<char, int> mp;
		mp[a[1]]++; mp[b[1]]++, mp[c[1]]++;
		int arr[3] = {100, 100, 100};

		if (mp['m'] >= 2) {
			if (a[1] == 'm') arr[0] = a[0] - '0';
			if (b[1] == 'm') arr[1] = b[0] - '0';
			if (c[1] == 'm') arr[2] = c[0] - '0';
			sort(arr, arr + 3);
			//cout << arr[0] << " " << arr[1] << " " << arr[2] << '\n';

			if ((arr[0] + 1 == arr[1]) || (arr[0] + 2 == arr[1]) || (arr[1] + 1 == arr[2]) || (arr[1] + 2 == arr[2]) || (arr[0] == arr[1]) || (arr[1] == arr[2]) || (arr[0] == arr[2])) {
				cout << 1 << '\n';
			}
			else {
				cout << 2 << '\n';
			}
		}
		else if ((mp['p'] >= 2)) {
			if (a[1] == 'p') arr[0] = a[0] - '0';
			if (b[1] == 'p') arr[1] = b[0] - '0';
			if (c[1] == 'p') arr[2] = c[0] - '0';
			sort(arr, arr + 3);
			//cout << arr[0] << " " << arr[1] << " " << arr[2] << '\n';

			if ((arr[0] + 1 == arr[1]) || (arr[0] + 2 == arr[1]) || (arr[1] + 1 == arr[2]) || (arr[1] + 2 == arr[2]) || (arr[0] == arr[1]) || (arr[1] == arr[2]) || (arr[0] == arr[2])) {
				cout << 1 << '\n';
			}
			else {
				cout << 2 << '\n';
			}
		}
		else if ((mp['s'] >= 2)) {
			if (a[1] == 's') arr[0] = a[0] - '0';
			if (b[1] == 's') arr[1] = b[0] - '0';
			if (c[1] == 's') arr[2] = c[0] - '0';
			sort(arr, arr + 3);
			//cout << arr[0] << " " << arr[1] << " " << arr[2] << '\n';

			if ((arr[0] + 1 == arr[1]) || (arr[0] + 2 == arr[1]) || (arr[1] + 1 == arr[2]) || (arr[1] + 2 == arr[2]) || (arr[0] == arr[1]) || (arr[1] == arr[2]) || (arr[0] == arr[2])) { // 1 8 8
				cout << 1 << '\n';
			}
			else {
				cout << 2 << '\n';
			}
		}
		else {
			cout << 2 << '\n';
		}
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}