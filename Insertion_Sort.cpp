#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr) {
    const int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 and key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    /*
        best case: O(N) -> array already sorted
        avg case: O(N ^ 2)
        worst case: O(N ^ 2) -> reverse sorted
        space: O(1)
        Stable sort: Yes
    */
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x: arr) cin >> x;
    insertionSort(arr);
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
