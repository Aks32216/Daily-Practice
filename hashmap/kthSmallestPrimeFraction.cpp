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
 
vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
	map<long double,pair<int,int> > mp;
	for(int i=0;i<arr.size();++i)
	{
		for(int j=i+1;j<arr.size();++j){
			long double curVal=(1.0)*arr[i]/arr[j];
			mp[curVal]={arr[i],arr[j]};
		}
	}
	vector<int> res;
	for(auto i:mp){
		k--;
		if(k==0){
			res.push_back(i.second.first);
			res.push_back(i.second.second);
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
 
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(auto& i:v)
		cin>>i;
	vector<int> res=kthSmallestPrimeFraction(v,k);
	for(auto i:res)
		cout<<i<<" ";
	cout<<"\n"; 
}