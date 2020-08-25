#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;

	int sum_solved = 0;

	for (int i = 0; i < n; i++)
	{
		vector<int> v;

		for (int j = 0; j < 3; j++)
		{
			int num;
			cin >> num;
			v.push_back(num);
		}

		int num = 0;
		sort(v.begin(), v.end());
		auto it1 = lower_bound(v.begin(), v.end(), 1);
		auto it2 = upper_bound(v.begin(), v.end(), 1);

		num = it2 - it1;

		if (num >= 2)
		{
			sum_solved++;
		}
	}

	cout << sum_solved << endl;

	return 0;
}


