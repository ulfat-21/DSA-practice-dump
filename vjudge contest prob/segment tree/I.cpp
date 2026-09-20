#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int open;
    int close;
    int res;
};

Node mergeNode(Node a, Node b)
{
    Node ans;

    int match = min(a.open, b.close);

    ans.res = a.res + b.res + 2 * match;

    ans.open = a.open + b.open - match;

    ans.close = a.close + b.close - match;

    return ans;
}

void buildTree(string& s, vector<Node>& st,
               int node, int tL, int tR)
{
    if(tL == tR)
    {
        if(s[tL] == '(')
        {
            st[node].open = 1;
            st[node].close = 0;
            st[node].res = 0;
        }
        else
        {
            st[node].open = 0;
            st[node].close = 1;
            st[node].res = 0;
        }

        return;
    }

    int mid = (tL + tR) / 2;

    int left_child = 2 * node;
    int right_child = 2 * node + 1;

    buildTree(s, st, left_child, tL, mid);
    buildTree(s, st, right_child, mid + 1, tR);

    st[node] = mergeNode(st[left_child], st[right_child]);
}

Node rangeQuery(vector<Node>& st,
                int node, int tL, int tR,
                int L, int R)
{
    // No overlap
    if(tL > R || tR < L)
    {
        return {0, 0, 0};
    }

    // Full overlap
    if(tL >= L && tR <= R)
    {
        return st[node];
    }

    int mid = (tL + tR) / 2;

    int left_child = 2 * node;
    int right_child = 2 * node + 1;

    Node left_result =
        rangeQuery(st, left_child,
                   tL, mid, L, R);

    Node right_result =
        rangeQuery(st, right_child,
                   mid + 1, tR, L, R);

    return mergeNode(left_result, right_result);
}

int main()
{
    string s;

    cin >> s;

    int n = s.size();

    vector<Node> st(4 * n);

    buildTree(s, st, 1, 0, n - 1);

    int q;

    cin >> q;

    while(q--)
    {
        int L, R;

        cin >> L >> R;

        L--;
        R--;

        Node ans =
            rangeQuery(st, 1, 0, n - 1, L, R);

        cout << ans.res << endl;
    }

    return 0;
}
