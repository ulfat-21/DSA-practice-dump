#include <bits/stdc++.h>
using namespace std;

struct Node
{
    long long sum;
    long long pref;
};

Node mergeNode(Node a,Node b)
{
    Node ans;
    ans.sum=a.sum+b.sum;
    ans.pref=max(a.pref,a.sum+b.pref);
    return ans;
}

void buildTree(vector<long long>& arr,vector<Node>& st,int node,int tL,int tR)
{
    if(tL==tR)
    {
        st[node].sum=arr[tL];
        st[node].pref=max(0LL,arr[tL]);
        return;
    }
    int mid = (tL + tR) / 2;
    int left_child = 2 * node;
    int right_child = 2 * node + 1;

    buildTree(arr, st, left_child, tL, mid);
    buildTree(arr, st, right_child, mid + 1, tR);
    st[node]=mergeNode(st[left_child],st[right_child]);
}

void pointUpdate(vector<Node>& st,int node,int tL,int tR,int idx,long long val)
{
    if(tL==tR)
    {
        st[node].sum=val;
        st[node].pref=max(0LL,val);
        return;
    }
    int mid = (tL + tR) / 2;
    int left_child = 2 * node;
    int right_child = 2 * node + 1;

    if(idx <= mid)
    {
        pointUpdate(st, left_child,tL, mid, idx, value);
    }
    else
    {
        pointUpdate(st, right_child,mid + 1, tR, idx, value);
    }
    st[node] = mergeNode(st[left_child], st[right_child]);
}

Node rangeQuery(vector<Node>& st, int node, int tL, int tR,int L, int R)
{
    if(tL > R || tR < L)
    {
        return {0,LLONG_MIN};
    }
    if(tL >= L && tR <= R)
    {
        return st[node];
    }
    int mid = (tL + tR) / 2;
    int left_child = 2 * node;
    int right_child = 2 * node + 1;

    Node left_result =rangeQuery(st, left_child,tL, mid, L, R);
    Node right_result =rangeQuery(st, right_child, mid + 1, tR, L, R);
    return mergeNode(left_result, right_result);
}

int main()
{
    int n,q;
    cin>>n>>q;
    vector<long long> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<Node> st(4*n);
    buildTree(arr,st,1,0,n-1);
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int k;
            long long u;
            cin>>k>>u;
            k--;
            pointUpdate(st,1,0,n-1,k,u);
        }
        else
        {
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            Node ans=rangeQuery(st,1,0,n-1,a,b);
            cout<<max(0LL,ans.pref);
        }
    }
    return 0;
}
