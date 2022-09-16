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
 
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	vector<vector<int> > res;
	int i=0;
	int n=intervals.size();
	while(i<n && intervals[i][1]<newInterval[0])
		res.push_back(intervals[i]),i++;
	while(i<n && intervals[i][0]<=newInterval[1])
	{
		newInterval[0]=min(intervals[i][0],newInterval[0]);
		newInterval[1]=max(intervals[i][1],newInterval[1]);
		i++;
	}
	res.push_back(newInterval);
	while(i<n)
		res.push_back(intervals[i]),i++;
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
 	vector<vector<int> > v(n,vector<int>(2));
 	for(int i=0;i<n;++i)
 	{
 		cin>>v[i][0]>>v[i][1];
 	}      
 	vector<int> interval(2);
 	cin>>interval[0]>>interval[1];
 	vector<vector<int> > res=insert(v,interval);
 	for(auto i:res)
 		cout<<i[0]<<" "<<i[1]<<"\n";
}