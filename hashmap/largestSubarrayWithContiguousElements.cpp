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

/*bool isContiguous(vector<int>& temp)
{
	sort(begin(temp),end(temp));
	for(int i=1;i<temp.size();++i)
	{
		if(temp[i]-temp[i-1]!=1)
			return false;
	}
	return true;
}

int solution(vector<int> &arr){
    int n=arr.size();
	int len=0;
	for(int i=0;i<n;++i)
	{
		vector<int> temp;
		for(int j=i;j<n;++j)
		{
			temp.push_back(arr[j]);
			if(isContiguous(temp))
				len=max(len,j-i+1);
		}
	}
	return len;
}*/

int solution(vector<int>& arr)
{
	int n=arr.size();
	int len=0;
	for(int i=0;i<n;++i)
	{
		set<int> s;
		int minSub=1e9;
		int maxSub=-1e9;
		for(int j=i;j<n;++j)
		{
			if(s.find(arr[j])!=s.end())
				break;
			minSub=min(minSub,arr[j]);
			maxSub=max(maxSub,arr[j]);
			s.insert(arr[j]);
			// cout<<i<<" "<<j<<" "<<s.size()<<" "<<(maxSub-minSub)<<"\n";
			if(((maxSub-minSub+1)==(j-i+1)))
				len=max(len,j-i+1);
		}
	}
	return len;
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
 	vector<int> v(n);
 	for(auto& i:v)
 		cin>>i;
 	cout<<solution(v)<<"\n";
}