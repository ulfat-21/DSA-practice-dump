#include <iostream>
using namespace std;

void buildTree(int arr[], int st[], int node, int tL, int tR)
{
    // Leaf node
    if(tL == tR)
    {
        st[node] = arr[tL];
    }
    else
    {
        int mid = (tL + tR) / 2;

        int left_child = 2 * node;
        int right_child = 2 * node + 1;

        // Build left subtree
        buildTree(arr, st, left_child, tL, mid);

        // Build right subtree
        buildTree(arr, st, right_child, mid + 1, tR);

        // Store sum of left and right child
        st[node] = st[left_child] + st[right_child];
    }
}

int main()
{
    int n = 5;

    int arr[] = {2, 3, 5, 1, 6};

    int st[4 * n] = {0};

    buildTree(arr, st, 1, 0, n - 1);

    // Print segment tree
    for(int i = 1; i < 4 * n; i++)
    {
        if(st[i] != 0)
        {
            cout << "st[" << i << "] = " << st[i] << endl;
        }
    }

    return 0;
}
