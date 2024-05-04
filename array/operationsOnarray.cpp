#include <iostream>
#include <cmath>
using namespace std;

int insert(int arr[], int n, int x, int cap, int pos)
{
    if (n == cap)
        return n;

    int idx = pos - 1;

    for (int i = n - 1; i >= idx; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[idx] = x;

    return n + 1;
}
int deleteElement(int arr[], int n, int key)
{
    // Find position of element to be deleted
    int pos = findElement(arr, n, key);

    if (pos == -1)
    {
        cout << "Element not found";
        return n;
    }

    // Deleting element
    int i;
    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    return n - 1;
}

// Function to implement search operation
int findElement(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    // Return -1 if key is not found
    return -1;
}
int main()
{

    int arr[5], cap = 5, n = 3;

    arr[0] = 5;
    arr[1] = 10;
    arr[2] = 20;

    cout << "Before Insertion" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int x = 7, pos = 2;

    n = insert(arr, n, x, cap, pos);

    cout << "After Insertion" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
