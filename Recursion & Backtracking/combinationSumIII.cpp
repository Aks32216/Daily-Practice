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

void solve(int n,int k,int initial,int count,int sum,vector<int> temp,vector<vector<int> >& res){
	if(count==k && sum==n){
		res.push_back(temp);
		return;
	}
	if(count>k || sum>n || initial>9)
		return;
	solve(n,k,initial+1,count,sum,temp,res);
	temp.push_back(initial);
	solve(n,k,initial+1,count+1,sum+initial,temp,res);
	temp.pop_back();
}

vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int> > res;
	vector<int> temp;
	solve(n,k,1,0,0,temp,res);
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
    cin>>k>>n;
    vector<vector<int> > res=combinationSum3(k,n);
    for(int i=0;i<res.size();++i){
        for(int j=0;j<res[i].size();++j)
            cout<<res[i][j]<<" ";
        cout<<"\n";
    }
       
}