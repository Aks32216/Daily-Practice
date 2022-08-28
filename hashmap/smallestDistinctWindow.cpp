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
 
int findSubString(string str)
{
	int n=str.length();
	if(n<=1)
		return n;

	int distCount=0;
	vector<bool> freq(256,false);
	for(int i=0;i<n;++i)
	{
		if(freq[str[i]]==false)
		{
			freq[str[i]]=true;
			distCount++;
		}
	}

	int start=0,end=0;
	int len=1e9;
	int count=0;
	vector<int> curFreq(256,0);
	while(end<n)
	{
		curFreq[str[end]]++;
		if(curFreq[str[end]]==1)
			count++;
		if(distCount==count)
		{
			while(curFreq[str[start]]>1)
			{
				if(curFreq[str[start]]>1)
					curFreq[str[start]]--;
				start++;
			}
			len=min(len,end-start+1);
		}
		end++;
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
 
 	
 	string s;
 	cin>>s;      
 	cout<<findSubString(s)<<"\n";
}