#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

#define fo(i,n) for(int i=0; i<n; i++)
#define vsort sort(v.begin(),v.end())
#define ll long long int

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	int small_letters = 0, capital_letters = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			small_letters++;
		}
		else
		{
			capital_letters++;
		}
	}

	if (small_letters >= capital_letters)
	{
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		cout << s << endl;
	}
	else
	{
		transform(s.begin(), s.end(), s.begin(), ::toupper);
		cout << s << endl;
	}

	return 0;
}

