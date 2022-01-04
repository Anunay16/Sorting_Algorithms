#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> c(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    while (i <= mid and j <= high) {
        if (arr[i] <= arr[j]) {
            c[k++] = arr[i++];
        }
        else {
            c[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        c[k++] = arr[i++];
    }
    while (j <= high) {
        c[k++] = arr[j++];
    }
    for (k = 0; k < c.size(); k++) {
        arr[low + k] = c[k];
    }
}

void __mergeSort(vector<int>& arr, int start, int end) {
    if (start >=  end) {
        return;
    }
    int mid = start + (end - start) / 2;
    __mergeSort(arr, start, mid);
    __mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void mergeSort(vector<int>& arr) {
    __mergeSort(arr, 0, arr.size() - 1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x: arr) cin >> x;
    mergeSort(arr);
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
