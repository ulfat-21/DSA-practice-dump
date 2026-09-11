#include <iostream>
using namespace std;
// Build segment tree (sum)
void buildTree(int arr[], int st[], int node, int tL, int tR)
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

        st[node] = st[left_child] + st[right_child];
    }
}
// Range Query (sum)
int rangeQuery(int arr[], int st[], int node, int tL, int tR, int L, int R)
{
    // Case 1: No overlap
    if(tL > R || tR < L)
    {
        return 0;
    }
    // Case 2: Full overlap
    if(tL >= L && tR <= R)
    {
        return st[node];
    }
    // Case 3: Partial overlap
    int mid = (tL + tR) / 2;

    int left_child = 2 * node;
    int right_child = 2 * node + 1;

    int left_result = rangeQuery(arr, st, left_child, tL, mid, L, R);
    int right_result = rangeQuery(arr, st, right_child, mid + 1, tR, L, R);
    // Merge operation
    return left_result + right_result;
}

int main()
{
    int n = 5;

    int a[] = {4, 5, 7, 6, 8};

    int st[4*n] = {0};
    // Build tree
    buildTree(a, st, 1, 0, n-1);
    // Query sum from index 2 to 4
    int result = rangeQuery(a, st, 1, 0, n-1, 2, 4);
    cout << "Sum = " << result << endl;
    return 0;
}
