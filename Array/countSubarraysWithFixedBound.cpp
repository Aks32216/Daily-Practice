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
 
long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    // initialize some variables
    int n = nums.size();
    int leftBound = -1;
    int lastMin = -1, lastMax = -1;
    long long count = 0;
    
    for (int i = 0; i < n; i++) {
        // check if nums[i] is within the range [minK, maxK]
        if (nums[i] >= minK && nums[i] <= maxK) {
            // if nums[i] is equal to minK, update lastMin to the current index i
            lastMin = (nums[i] == minK) ? i : lastMin;
            // if nums[i] is equal to maxK, update lastMax to the current index i
            lastMax = (nums[i] == maxK) ? i : lastMax;
            // update the count by the number of valid subarrays between leftBound and the 
            // smaller of lastMin and lastMax
            count += max(0, min(lastMin, lastMax) - leftBound);
        } else {
            // if nums[i] is not within the range [minK, maxK], update leftBound to i
            leftBound = i;
            // reset lastMin and lastMax to -1
            lastMin = -1;
            lastMax = -1;
        }
    }
    
    // return the final count of valid subarrays
    return count;
}

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	int n,minK,maxK;
 	cin>>n>>minK>>maxK;
 	vector<int> v(n);
 	for(auto& i:v)
 		cin>>i;
 	cout<<countSubarrays(v,minK,maxK)<<"\n";
}