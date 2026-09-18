#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<pair<int,int>> arr(n);///pair nisi cuz sorting er pore index gula jate ulta palta na hoye jay ejonno value newar shathe shathe index tao rakhbo

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr.begin(), arr.end());

    int l = 0;
    int r = n - 1;

    while(l < r)
    {
        int sum = arr[l].first + arr[r].first;

        if(sum == x)
        {
            cout << arr[l].second << " " << arr[r].second;
            return 0;
        }
        else if(sum < x)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
