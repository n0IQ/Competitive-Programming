#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	string s1, s2;
	cin >> s1 >> s2;

	/*int small1 = 0, med1 = 0, large1 = 0, x1 = 0;
	int small2 = 0, med2 = 0, large2 = 0, x2 = 0;

	for (auto ch : s1) {
		if (ch == 'S') small1++;
		else if (ch == 'M') med1++;
		else if (ch == 'L') large1++;
		else x1++;
	}

	for (auto ch : s2) {
		if (ch == 'S') small2++;
		else if (ch == 'M') med2++;
		else if (ch == 'L') large2++;
		else x2++;
	}

	int n = s1.size(), m = s2.size();

	if (s1[n - 1] == 'S' && s2[m - 1] == 'S') {
		int x1 = 0, x2 = 0;
		for (int i = 0; i < n - 1; i++) x1++;
		for (int i = 0; i < m - 1; i++) x2++;

		if ()
		}
	else if (s1[n - 1] == 'S') {

	}
	else if (s2[m - 1] == 'S') {

	}*/

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int x1 = 0, x2 = 0;
	while (s1.size() > 1) {
		s1.pop_back();
		x1++;
	}
	while (s2.size() > 1) {
		s2.pop_back();
		x2++;
	}

	if (s1[0] == 'S') {
		if (s2[0] == 'S') {
			if (x1 == x2) cout << "=\n";
			else if (x1	> x2) cout << "<\n";
			else cout << ">\n";
		}
		else if (s2[0] == 'M' || s2[0] == 'L') {
			cout << "<\n";
		}
	}
	else if (s1[0] == 'M') {
		if (s2[0] == 'M') {
			if (x1 == x2) cout << "=\n";
		}
		else if (s2[0] == 'S') {
			cout << ">\n";
		}
		else if (s2[0] == 'L') {
			cout << "<\n";
		}
	}
	else if (s1[0] == 'L') {
		if (s2[0] == 'L') {
			if (x1 == x2) cout << "=\n";
			else if (x1	> x2) cout << ">\n";
			else cout << "<\n";
		}
		else if (s2[0] == 'M' || s2[0] == 'S') {
			cout << ">\n";
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("Error.txt", "w", stderr);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}