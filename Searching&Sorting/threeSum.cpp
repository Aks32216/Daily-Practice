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
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(begin(nums),end(nums));
    vector<vector<int> > res;
    int n=nums.size();
    for(int i=0;i<n;++i)
    {
        if(i!=0 && nums[i]==nums[i-1])
            continue;
        for(int j=i+1;j<n;++j)
        {
            if(j!=i+1 && nums[j]==nums[j-1])
                continue;
            for(int k=j+1;k<n;++k)
            {
                if(k!=j+1 && nums[k]==nums[k-1])
                    continue;
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    res.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }
    }
    return res;
}
*/

vector<vector<int> > threeSum(vector<int>& nums){
	sort(begin(nums),end(nums));
	vector<vector<int> > res;
	int n=nums.size();
	for(int i=0;i<n;++i)
	{
		if(i!=0 && nums[i]==nums[i-1])
			continue;
		int j=i+1;
		int k=n-1;
		while(j<k)
		{
			if(nums[i]+nums[j]+nums[k]==0)
			{
				res.push_back({nums[i],nums[j],nums[k]});
				j++;
				while(j<k && nums[j]==nums[j-1])
					j++;
			}
			else if(nums[i]+nums[j]+nums[k]<0)
				j++;
			else
				k--;
		}
	}
	return res;
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
 	vector<vector<int> > res=threeSum(v);
 	for(auto i:res){
 		cout<<"["<<i[0]<<","<<i[1]<<","<<i[2]<<"]\n";
 	}      
}