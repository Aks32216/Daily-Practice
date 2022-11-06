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
 
void rotate(vector<vector<int>>& matrix) {
	int n=matrix.size();
	int m=matrix[0].size();
	for(int i=0;i<n;++i)
	{
		for(int j=i;j<n;++j)
		{
			swap(matrix[i][j],matrix[j][i]);
		}
	}
	int i=0,j=m-1;
	while(i<j)
	{
		for(int k=0;k<n;++k)
			swap(matrix[k][i],matrix[k][j]);
		i++,j--;
	}
}

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	int n,m;
 	cin>>n>>m;
 	vector<vector<int> > v(n,vector<int>(m));
 	for(int i=0;i<n;++i){
 		for(int j=0;j<m;++j){
 			cin>>v[i][j];
 		}
 	}      
 	rotate(v);
 	for(int i=0;i<n;++i){
 		for(int j=0;j<m;++j){
 			cout<<v[i][j]<<" ";
 		}
 		cout<<"\n";
 	}
}