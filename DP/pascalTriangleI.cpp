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

vector<vector<int>> generate(int numRows) {
	vector<vector<int> > res;
	vector<int> temp;
	temp.push_back(1);
	res.push_back(temp);
	if(numRows==1)
		return res;
	temp.push_back(1);
	res.push_back(temp);
	if(numRows==2)
		return res;
	for(int i=3;i<=numRows;++i)
	{
		vector<int> temp2;
		temp2.push_back(1);
		for(int j=1;j<temp.size();++j)
			temp2.push_back(temp[j]+temp[j-1]);
		temp2.push_back(1);
		temp=temp2;
		res.push_back(temp);
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
 	vector<vector<int> > res=generate(n);
 	for(int i=0;i<res.size();++i){
 		for(int j=0;j<res[i].size();++j)
 			cout<<res[i][j]<<" ";
 		cout<<"\n";
 	}   
}