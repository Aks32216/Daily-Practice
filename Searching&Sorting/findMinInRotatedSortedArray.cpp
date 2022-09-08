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

/*
int findMin(vector<int>& nums)
{
    int minElem=1e9;
    int n=nums.size();
    for(int i=0;i<n;++i)
    {
        minElem=min(minElem,nums[i]);
    }
    return minElem;
}

int findMin(vector<int>& nums) {
    int n=nums.size();
    if(n==1)
        return nums[0];
    for(int i=0;i<n;++i)
    {
        int prevIdx=(i-1+n)%n;
        int nextIdx=(i+1)%n;
        if(nums[prevIdx]>nums[i] && nums[nextIdx]>nums[i])
            return nums[i];
    }
    return -1;
}
*/
    
int findMin(vector<int>& nums)
{
	int n=nums.size();
	int start=0,end=n-1;
	if(start==end)
		return nums[start];
	if(nums[start]<nums[end])
		return nums[start];
	while(start<=end)
	{
		int mid=start+(end-start)/2;
		int prevIdx=(mid-1+n)%n;
		int nextIdx=(mid+1)%n;
		if(nums[mid]<nums[prevIdx] && nums[mid]<nums[nextIdx])
			return nums[mid];
		else if(nums[mid]<nums[end])
			end=mid-1;
		else
			start=mid+1;
	}
	return nums[start];
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
 	cout<<findMin(v)<<"\n";
}