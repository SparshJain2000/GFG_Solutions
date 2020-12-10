#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;
        cin >> n >> sum;
        vector<int> arr(n);
        for (auto &itr : arr)
            cin >> itr;
        bool flag = false;
        for (int i = 1; i < arr.size(); i++)
        {
            arr[i] += arr[i - 1];
            if (arr[i] == sum)
            {
                cout << 1 << " " << i + 1 << endl;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        int i = 0, k = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (k >= arr.size())
            {
                cout << -1 << endl;
                flag = true;
                break;
            }

            while (arr[i] - arr[k] > sum)
                k++;
            if (arr[i] - arr[k] == sum)
            {
                cout << k + 2 << " " << i + 1 << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << -1 << endl;
    }
    return 0;
}