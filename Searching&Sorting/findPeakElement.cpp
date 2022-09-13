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
 
/* int findPeakElement(vector<int>& nums) {
    int n=nums.size();
    if(n==1)
        return 0;
    if(n==2){
        if(nums[0]>nums[1])
            return 0;
        else
            return 1;
    }
    if(nums[0]>nums[1])
        return 0;
    if(nums[n-1]>nums[n-2])
        return n-1;
    for(int i=1;i<n-1;++i){
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
            return i;
    }
    return -1;
}
*/

int findPeakElement(vector<int>& nums){
	int start=0,end=nums.size()-1;
	if(start==end)
		return start;
	if(nums[start]>nums[start+1])
		return start;
	if(nums[end]>nums[end-1])
		return end;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
			return mid;
		else if(nums[mid]>nums[mid-1])
			start=mid;
		else
			end=mid;
	}
	return -1;
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
 	cout<<findPeakElement(v)<<"\n";   
}