#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

bool reverse(int x, int y)
{
    return x > y;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int scores;
        cin >> scores;
        v.push_back(scores);
    }

    int num = v[--k];

    sort(v.begin(), v.end(), reverse);

    int qualified = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if ((v[i] >= num) && (v[i] != 0))
        {
            qualified++;
        }
    }

    cout << qualified << endl;

    return 0;
}

