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
 
bool subarraySum(vector<int>& v,int k)
{
	int n=v.size();
	int sum=0;
	unordered_map<int,int> mp;
	for(int i=0;i<n;++i)
	{
		sum+=v[i];
		sum%=k;
		if(sum==0 && i>0) // there are atleast two elements and sum is divisible by k
			return true;
		if(mp.find(sum)!=mp.end()) // if mod exists in the map then this subarray must be divisible by k
		{
			if(i-mp[sum]>1) // check if subarray has more than 1 element or not
				return true;
		}
		else
			mp[sum]=i; // else store the index at which this mod sum occurs so that it will ease in finding no of element in subarray
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
 
 	int n,k;
 	cin>>n>>k;
 	vector<int> v(n);
 	for(auto& i:v)
 		cin>>i;
 	cout<<subarraySum(v,k)<<"\n";      
}