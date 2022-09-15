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
 
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	int left=0,top=0,right=matrix[0].size()-1,bottom=matrix.size()-1;
	int d=0;
	while(top<=bottom && left<=right)
	{
		if(d==0)
		{
			for(int i=left;i<=right;++i)
				res.push_back(matrix[top][i]);
			top++;
		}
		else if(d==1)
		{
			for(int i=top;i<=bottom;++i)
				res.push_back(matrix[i][right]);
			right--;
		}
		else if(d==2)
		{
			for(int i=right;i>=left;--i)
				res.push_back(matrix[bottom][i]);
			bottom--;
		}
		else
		{
			for(int i=bottom;i>=top;--i)
				res.push_back(matrix[i][left]);
			left++;
		}
		d=(d+1)%4;
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
 
 	
 	int n,m;
 	cin>>n>>m;
 	vector<vector<int> > v(n,vector<int>(m));
 	for(int i=0;i<n;++i)
 	{
 		for(int j=0;j<m;++j)
 		{
 			cin>>v[i][j];
 		}
 	}      
 	vector<int> res=spiralOrder(v);
 	for(auto i:res)
 		cout<<i<<" ";
 	cout<<"\n";
}