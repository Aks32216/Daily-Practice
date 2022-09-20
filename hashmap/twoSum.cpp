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
vector<int> twoSum(vector<int>& nums, int target) {
    int n=nums.size();
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(nums[i]+nums[j]==target)
                return {i,j};
        }
    }
    return {-1,-1};
}


vector<int> twoSum(vector<int>& nums,int target)
{
    vector<pair<int,int> > vp;
    for(int i=0;i<nums.size();++i)
    {
        vp.push_back({nums[i],i});
    }
    sort(begin(vp),end(vp));
    int i=0,j=nums.size()-1;
    while(i<j)
    {
        int sum=vp[i].first+vp[j].first;
        if(sum==target)
            return {vp[i].second,vp[j].second};
        else if(sum<target)
            i++;
        else
            j--;
    }
    return {-1,-1};
}
*/
    
vector<int> twoSum(vector<int>& nums,int target)
{
	unordered_map<int,int> mp;
	for(int i=0;i<nums.size();++i)
	{
		if(mp.find(target-nums[i])!=mp.end())
		{
			return {i,mp[target-nums[i]]};
		}
		else
			mp[nums[i]]=i;
	}
	return {-1,-1};
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
 	vector<int> res=twoSum(v,target);
 	cout<<res[0]<<" "<<res[1]<<'\n';
}