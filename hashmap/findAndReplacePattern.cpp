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

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
	vector<string> res;
	for(int i=0;i<words.size();++i)
	{
		unordered_map<char,char> mp1,mp2;
		bool isMatched=false;
		for(int j=0;j<words[i].length();++j)
		{
			if(mp1.find(words[i][j])==mp1.end())
				mp1[words[i][j]]=pattern[j];
			else if(mp1[words[i][j]]==pattern[j])
				continue;
			else
			{
				isMatched=true;
				break;
			}
		}
		for(int j=0;j<pattern.length();++j)
		{
			if(mp2.find(pattern[j])==mp2.end())
				mp2[pattern[j]]=words[i][j];
			else if(mp2[pattern[j]]==words[i][j])
				continue;
			else{
				isMatched=true;
				break;
			}
		}
		if(isMatched==false)
			res.push_back(words[i]);
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
 	vector<string> v(n);
 	for(auto& i:v)
 		cin>>i;
 	string pattern;
 	cin>>pattern;
 	vector<string> res=findAndReplacePattern(v,pattern);
 	for(auto i:res)
 		cout<<i<<" ";
 	cout<<"\n";
}