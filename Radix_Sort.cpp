// this implementation is valid only for non-negative arrays

#include <bits/stdc++.h>
using namespace std;
void countSort(vector<int>& arr, int exp) {
    const int n = arr.size();
    vector<int> freq(10, 0);
    for (int& x: arr) {
        int dig = (x / exp) % 10;
        freq[dig]++;
    }
    for (int i = 1; i < (int) freq.size(); i++) {
        freq[i] += freq[i - 1];
    }
    vector<int> sorted(n);
    for (int i = n - 1; i >= 0; i--) {
        int dig = (arr[i] / exp) % 10;
        freq[dig]--;
        sorted[freq[dig]] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = sorted[i];
    }
}

void radixSort(vector<int>& arr, int maximum) {
    int exp = 1;
    while (exp <= maximum) {
        countSort(arr, exp);
        exp = exp * 10;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x: arr) cin >> x;
    int maxi = *max_element(arr.begin(), arr.end());
    radixSort(arr, maxi);
    for (auto& x: arr) cout << x << " ";
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
