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
 		ll n,q;
 		cin>>n>>q;
 		vector<vector<ll> > prefix(1005,vector<ll>(1005,0));
 		ll h,w;
 		for(int i=1;i<=n;++i)
 		{
 			cin>>h>>w;
 			prefix[h][w]+=h*w;
 		}
 		for(int i=1;i<1005;++i)
 		{
 			for(int j=1;j<1005;++j)
 			{
 				prefix[i][j]+=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
 			}
 		}
 		ll h1,h2,w1,w2;
 		for(int i=1;i<=q;++i)
 		{
 			cin>>h1>>w1>>h2>>w2;
 			h2--;
 			w2--;
 			ll val=prefix[h2][w2]+prefix[h1][w1]-prefix[h1][w2]-prefix[h2][w1];
 			cout<<val<<"\n";
 		}
 	}      
}