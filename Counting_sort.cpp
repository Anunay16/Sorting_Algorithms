#include <bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int>& arr) {
    const int n = arr.size();
    int maxi = arr[0];
    int mini = arr[0];
    for (auto& x: arr) {
        maxi = max(maxi, x);
        mini = min(mini, x);
    }
    vector<int> freq(maxi - mini + 1, 0);
    for (int& x: arr) {
        freq[x - mini]++;
    }
    for (int i = 1; i < (int) freq.size(); i++) {
        freq[i] += freq[i - 1];
    }
    vector<int> sorted(n);
    for (int i = n - 1; i >= 0; i--) {
        freq[arr[i] - mini]--;
        sorted[freq[arr[i] - mini]] = arr[i];
    }
    return sorted;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x: arr) cin >> x;
    vector<int> sorted = countSort(arr);
    for (auto& x: sorted) cout << x << " ";
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
