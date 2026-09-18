#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;

        auto it = lower_bound(arr.begin(), arr.end(), x);
        int index = it - arr.begin(); ///it akta pointer so it theke first pos - korle it kon pos e oita pabo (index ta peye jbo)

        if(arr[index] == x)
        {
            cout << "Yes " << index + 1 << endl;
        }
        else
        {
            cout << "No " << index + 1 << endl;
        }
    }
    return 0;
}
