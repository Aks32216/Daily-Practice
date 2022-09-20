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

bool searchRotated(vector<int>& nums, int target) {
	int n=nums.size();
	if(n==0)
		return false;
	int start=0,end=n-1;
	while(start<=end)
	{
		while(start<end && nums[start]==nums[start+1])
			start++;
		while(start<end && nums[end]==nums[end-1])
			end--;
		int mid=start+(end-start)/2;
		if(nums[mid]==target)
			return true;
		else if(nums[0]<=nums[mid])
		{
			if(target<nums[mid] && target>=nums[start])
				end=mid-1;
			else
				start=mid+1;
		}
		else
		{
			if(target<=nums[end] && target>nums[mid])
				start=mid+1;
			else
				end=mid-1;
		}
	}
	return false;
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	int n,target;
 	cin>>n>>target;
 	vector<int> v(n);
 	for(auto& i:v)
 		cin>>i;
 	cout<<searchRotated(v,target)<<"\n";
}