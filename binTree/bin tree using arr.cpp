#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int tree[100];

    for(int i = 1; i <= n; i++)
    {
        cin >> tree[i];
    }

    cout << "Root: " << tree[1] << endl;
    cout << "Left child of root: " << tree[2 * 1] << endl;
    cout << "Right child of root: " << tree[2 * 1 + 1] << endl;

    return 0;
}
