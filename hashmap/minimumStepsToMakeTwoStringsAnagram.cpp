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
int minSteps(string s, string t) {
    vector<int> freq1(26,0),freq2(26,0);
    for(int i=0;i<s.length();++i)
    {
        freq1[s[i]-97]++;
        freq2[t[i]-97]++;
    }
    int res=0;
    for(int i=0;i<26;++i)
    {
        if(freq1[i]==0)
            continue;
        else
        {
            int have=freq2[i];
            int want=freq1[i];
            cout<<i<<" "<<have<<" "<<want<<"\n";
            if(have<=want)
                res+=want-have;
        }
    }
    return res;
}
*/

int minSteps(string s,string t)
{
	unordered_map<char,int> mp;
	for(auto i:s)
		mp[i]++;
	int start=0,end=0,dif=0;
	while(end<t.length())
	{
		if(mp[t[end]]!=0)
		{
			mp[t[end]]--;
			if(mp[t[end]]==0)
				mp.erase(t[end]);
			end++;
		}
		else{
			dif++;
			end++;
		}
	}
	return dif;
}

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	string s,t;
 	cin>>s>>t;
 	cout<<minSteps(s,t)<<"\n";
}