#include <bits/stdc++.h>
using namespace std;
// Build Segment Tree (XOR)
void buildTree(vector<int>& arr, vector<int>& st, int node, int tL, int tR)
{
    if(tL == tR)
    {
        st[node] = arr[tL];
    }
    else
    {
        int mid = (tL + tR) / 2;

        int left_child = 2 * node;
        int right_child = 2 * node + 1;

        buildTree(arr, st, left_child, tL, mid);
        buildTree(arr, st, right_child, mid + 1, tR);

        st[node] = st[left_child] ^ st[right_child];
    }
}
// Range XOR Query
int rangeQuery(vector<int>& st, int node, int tL, int tR, int L, int R)
{
    // No overlap
    if(tL > R || tR < L)
    {
        return 0;
    }
    // Full overlap
    if(tL >= L && tR <= R)
    {
        return st[node];
    }
    // Partial overlap
    int mid = (tL + tR) / 2;
    int left_result = rangeQuery(st, 2*node, tL, mid, L, R);
    int right_result = rangeQuery(st, 2*node+1, mid+1, tR, L, R);

    return left_result ^ right_result;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> st(4*n);
    // Build tree
    buildTree(arr, st, 1, 0, n-1);

    while(q--)
    {
        int a, b;
        cin >> a >> b;
        // 1-based to 0-based
        a--;
        b--;
        cout << rangeQuery(st, 1, 0, n-1, a, b) << endl;
    }
    return 0;
}
