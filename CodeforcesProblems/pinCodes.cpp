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
 
int getAvailable(int& res)
{
	for(int i=0;i<=9;++i)
	{
		if((res&(1<<i)))
			continue;
		else
		{
			res=res|(1<<i);
			return i;
		}
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
 


 	ll t;
 	cin>>t;
 	while(t--)
 	{
 		int n;
 		cin>>n;
 		unordered_map<string,vector<pair<string,int> > > mp;
 		int res=0;
 		string temp;
 		int change=0;
 		for(int i=1;i<=n;++i)
 		{
 			cin>>temp;
 			mp[temp].push_back({temp,i-1});
 			int firstDigit=temp[0]-'0';
 			res=res|(1<<firstDigit);
 		}
 		for(auto& i:mp)
 		{
 			if(i.second.size()==1)
 				continue;
 			else
 			{
 				vector<pair<string,int> > temp=i.second;
 				for(int j=1;j<temp.size();++j)
 				{
 					int dig=getAvailable(res);
 					temp[j].first[0]=dig+48;
 					change++;
 				}
 				i.second=temp;
 			}
 		}
 		cout<<change<<"\n";
 		vector<string> ans(n);
 		for(auto i:mp)
 		{
 			for(auto j:i.second)
 			{
 				int idx=j.second;
 				string temp=j.first;
 				ans[idx]=temp;
 			}
 		}
 		for(auto i:ans)
 			cout<<i<<"\n";
 	}
}