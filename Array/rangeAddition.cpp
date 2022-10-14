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
vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
    vector<int> res(length,0);
    for(int i=0;i<updates.size();++i)
    {
        int sIdx=updates[i][0];
        int eIdx=updates[i][1];
        int inc=updates[i][2];
        for(int j=sIdx;j<=eIdx;++j){
            res[j]+=inc;
        }
    }
    return res;
}
*/

vector<int> getModifiedArray(int length,vector<vector<int> >& updates){
	int start=0;
	vector<int> res(length+1,0);
	for(int i=0;i<updates.size();++i){
		int sIdx=updates[i][0];
		int eIdx=updates[i][1];
		int inc=updates[i][2];
		res[sIdx]+=inc;
		res[eIdx+1]+=(-inc);
	}
	for(int i=0;i<length+1;++i){
		start+=res[i];
		res[i]=start;
	}
	res.pop_back();
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
 	vector<vector<int> > ranges(n,vector<int>(3));
 	int length;
 	cin>>length;
 	for(int i=0;i<n;++i){
 		cin>>ranges[i][0]>>ranges[i][1]>>ranges[i][2];
 	}      
 	vector<int> res=getModifiedArray(length,ranges);
 	for(auto i:res)
 		cout<<i<<" ";
 	cout<<"\n";
}