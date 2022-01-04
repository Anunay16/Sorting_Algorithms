#include <bits/stdc++.h>
using namespace std;

//time complexity: O(NlogN)
void heapify(vector<int>& arr, int i, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n and arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n and arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

void heapSort(vector<int>& arr) {
    const int n = arr.size();

    //create a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }

    //extract from root and swap it with i'th element from the back
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x: arr) cin >> x;
    heapSort(arr);
    for (int& x: arr) cout << x << " ";
    cout << "\n";
}

void FIO()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main()
{
    FIO();
    solve();
    return 0;
}
