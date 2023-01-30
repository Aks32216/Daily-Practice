#include <bits/stdc++.h>
 
using namespace std;
#define set_precision cout << fixed << setprecision(10)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)
#define replb(i, a, b) for (ll i = a; i >= b; i--)
#define repl(i, a, b) for (ll i = a; i < b; i++)
#define repit(arr) for (auto it = arr.begin(); it != arr.end(); 
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vl vector<long long int>
#define Vi vector<vector<int>>
#define vpi vector<pair<int,int> >
#define seti set<int>
#define setl set<ll>
#define dseti set<int, greater<int>>
#define dsetl set<ll, greater<ll>>
#define mseti multiset<int>
#define msetl multiset<ll>
#define dmseti multiset<int, greater<int>>
#define dmsetl multiset<ll, greater<ll>>
#define sortA(arr) sort(arr.begin(), arr.end())
#define dsortA(arr) sort(arr.begin(), arr.end(), greater<int>())
#define ssort(arr) stable_sort(arr.begin(), arr.end())
#define search(arr, c) binary_search(arr.begin(), arr.end(), c)
#define pb push_back
#define ll long long
#define cl_bf cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define castl static_cast<ll>
#define BRAHAMASTRA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ull unsigned long long int
#define mod 1e9+7

void merge(vector<int> &count, vector<pair<int, int> > &v, int left, int mid, int right) {
    vector<pair<int, int> > tmp(right-left+1);
    int i = left;
    int j = mid+1;
    int k = 0;

    while (i <= mid && j <= right) {
        // mind that we're sorting in descending order
        if (v[i].first <= v[j].first) { 
            tmp[k++] = v[j++];
        }
        else {
            // only line responsible to update count, related to problem constraint, 
            // remaining part is just regular mergeSort 
            count[v[i].second] += right - j + 1;
            tmp[k++] = v[i++];
        }
    }
    while (i <= mid) {
        tmp[k++] = v[i++];
    }
    while (j <= right) {
        tmp[k++] = v[j++];
    }
    for (int i = left; i <= right; i++)
        v[i] = tmp[i-left];
}        

void mergeSort(vector<int> &count, vector<pair<int, int> > &v, int left, int right) {
    if (left >= right) 
        return;

    int mid = left + (right-left)/2;
    mergeSort(count, v, left, mid);
    mergeSort(count, v, mid+1, right);
    merge(count, v, left, mid, right);
}

vector<int> countSmaller(vector<int>& nums) {
    int N = nums.size();

    vector<pair<int, int> > v(N);
    for (int i = 0; i < N; i++)   
        v[i] = make_pair(nums[i], i);

    vector<int> count(N, 0);
    // sorting in descending order
    mergeSort(count, v, 0, N-1);

    return count;
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	int n;
 	cin>>n;
 	vector<int> v(n);
 	for(auto& i:v)
 		cin>>i;
 	vector<int> res=countSmaller(v);
 	for(auto i:res)
 		cout<<i<<" ";
}