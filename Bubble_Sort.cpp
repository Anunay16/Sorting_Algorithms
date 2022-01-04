#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    const int n = arr.size();
    bool flag = true;
    for (int i = 0; i < n and flag; i++) {
        flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                flag = true;
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x: arr) cin >> x;
    bubbleSort(arr);
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
