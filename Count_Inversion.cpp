// A classical usecase of Merge Sort

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mod 1000000007
#define sz(x) ((int)(x).size())
#define cc(ans) cout << ans << nline
#define all(x) (x).begin(), (x).end()
#define input(v) for (auto &x: v) cin >> x
#define print(v) for (auto &x: v) cout << x << " ";
#define rep(i, start, end) for(int i = start; i < end; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

//=========================debugging================================

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//==================================================================

void merge(vector<int>& nums, int low, int mid, int high, ll& cnt) {
    int i = low, j = mid + 1, k = 0;
    vector<int> temp(high - low + 1);
    while (i <= mid and j <= high) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        }
        else {
            //here, nums[i] > nums[j] i.e. inversion
            //observation: all elements from i to mid will be an inversion
            cnt += mid - i + 1;
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= high) {
        temp[k++] = nums[j++];
    }
    for (int p = 0; p < (int)temp.size(); p++) {
        nums[low + p] = temp[p];
    }
}

void mergeSort(vector<int>& nums, int start, int end, ll& cnt) {
    if (start >= end) {
        return;
    }
    int mid = start + ((end - start) >> 1);
    mergeSort(nums, start, mid, cnt);
    mergeSort(nums, mid + 1, end, cnt);
    merge(nums, start, mid, end, cnt);
}

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    input(nums);
    ll cnt = 0;
    mergeSort(nums, 0, n - 1, cnt);
    cout << cnt << nline;
}

void FIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

signed main()
{
    fast;
    FIO();
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
