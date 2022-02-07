#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr, int low, int high) {
    int mini = low;
    for (int i = low + 1; i <= high; i++) {
        if (arr[i] < arr[mini]) {
            mini = i;
        }
    }
    return mini;
}

void selectionSort(vector<int>& arr) {
    const int n = arr.size();
    for (int i = 0; i < n; i++) {
        int low = i; 
        int high = n - 1;
        int minIdx = findMin(arr, low, high);
        swap(arr[i], arr[minIdx]);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& x: arr) cin >> x;
    selectionSort(arr);
    for (auto& x: arr) cout << x << " ";
    cout << "\n";
}

void FIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

int main() {
    FIO();
    solve();
    return 0;
}
