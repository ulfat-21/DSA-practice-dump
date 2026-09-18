#include <bits/stdc++.h>
using namespace std;

/// Normal Binary Search
int binary_search(int arr[], int len, int value)
{
    int left = 0;
    int right = len - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] == value)
            return mid;

        else if(arr[mid] < value)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

/// First Occurrence
int binary_search_first_occurrence(int arr[], int len, int value)
{
    int left = 0;
    int right = len - 1;
    int result = -1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] == value)
        {
            result = mid;
            right = mid - 1;   /// left side e aro khujbe
        }

        else if(arr[mid] < value)
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }

    return result;
}

/// Last Occurrence
int binary_search_last_occurrence(int arr[], int len, int value)
{
    int left = 0;
    int right = len - 1;
    int result = -1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] == value)
        {
            result = mid;
            left = mid + 1;   /// right side e aro khujbe
        }

        else if(arr[mid] < value)
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }

    return result;
}

int main()
{
    int len;
    cout << "Enter array size: ";
    cin >> len;
    int arr[len];
    cout << "Enter array elements: ";
    for(int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    /// Fast sorting O(n log n)

    sort(arr, arr + len);
    cout << "Sorted array: ";
    for(int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int value;
    cout << "Enter value to search: ";
    cin >> value;

    int normal = binary_search(arr, len, value);
    int first = binary_search_first_occurrence(arr, len, value);
    int last = binary_search_last_occurrence(arr, len, value);

    cout << "Normal occurrence index: " << normal << endl;
    cout << "First occurrence index: " << first << endl;
    cout << "Last occurrence index: " << last << endl;

    return 0;
}
