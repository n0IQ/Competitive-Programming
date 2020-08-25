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

	int n;
	string s;
	cin >> n >> s;

	int stones = 0;
	char c[51];

	for (int i = 0, j = 1; j < s.length();)
	{
		if (s[i] == s[j])
		{
			stones++;
			s.erase(s.begin() + j);
		}
		else 
		{
			i++;
			j++;
		}
	}

	cout << stones << endl;
	
	return 0;
}

