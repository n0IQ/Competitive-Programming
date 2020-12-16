#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int main()
{
	fastio

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;

	while (T-- > 0)
	{
		int n;
		cin >> n;

		string s;
		cin >> s;

		if (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0') {
			cout << "YES" << '\n';
		}
		else if (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n - 1] == '0') {
			cout << "YES" << '\n';
		}
		else if (s[0] == '2' && s[1] == '0' && s[n - 2] == '2' && s[n - 1] == '0') {
			cout << "YES" << '\n';
		}
		else if (s[0] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') {
			cout << "YES" << '\n';
		}
		else if (s[n - 4] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}