#include <bits/stdc++.h>
using namespace std;

int findPartition(vector<int>& arr, int low, int high) {
    int pivot = high;
    int j = low - 1;
    for (int i = low; i <= high - 1; i++) {
        if (arr[i] < arr[pivot]) {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[pivot], arr[j + 1]);
    return j + 1;
}

void quickSort(vector<int>& arr) {
    const int n = arr.size();
    stack<pair<int, int>> s; // <leftIdx, rightIdx>
    s.push({0, n - 1});
    while (!s.empty()) {
        pair<int, int> rem = s.top();
        s.pop();

        //we are picking the last element as pivot
        int partition_index = findPartition(arr, rem.first, rem.second);

        //add the ranges to the stack
        if (partition_index > rem.first) {
            s.push({rem.first, partition_index - 1});
        }
        if (rem.second > partition_index) {
            s.push({partition_index + 1, rem.second});
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x: arr) cin >> x;
    quickSort(arr);
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
