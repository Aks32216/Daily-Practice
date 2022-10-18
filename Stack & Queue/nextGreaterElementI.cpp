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

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	stack<int> s;
	int n=nums2.size();
        // vector<int> ngr(n);
	unordered_map<int,int> mp;
	for(int i=n-1;i>=0;--i)
	{
		if(s.empty())
			mp[nums2[i]]=-1;
		else if(s.top()>nums2[i])
			mp[nums2[i]]=s.top();
		else
		{
			while(!s.empty() && s.top()<=nums2[i])
				s.pop();
			if(s.empty())
				mp[nums2[i]]=-1;
			else
				mp[nums2[i]]=s.top();
		}
		s.push(nums2[i]);
	}
	for(int i=0;i<nums1.size();++i)
	{
		nums1[i]=mp[nums1[i]];
	}
	return nums1;
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
 	vector<int> nums1(n);
 	for(auto& i:nums1)
 		cin>>i;
 	int m;
 	cin>>m;
 	vector<int> nums2(m);
 	for(auto& i:nums2)
 		cin>>i;
 	vector<int> res=nextGreaterElement(nums1,nums2);
 	for(auto i:res)
 		cout<<i<<" ";
}