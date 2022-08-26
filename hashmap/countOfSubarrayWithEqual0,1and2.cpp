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

long long getSubstringWithEqual012(string str) {
    /*long long count=0;
    for(int i=0;i<str.length();++i)
    {
        long long c0=0,c1=0,c2=0;
        for(int j=i;j<str.length();++j)
        {
            if(str[j]=='0')
                c0++;
            else if(str[j]=='1')
                c1++;
            else if(str[j]=='2')
                c2++;
            if(c0==c1 && c1==c2 && c0==c2)
                count++;
        }
    }
    return count;*/

	long long c0=0,c1=0,c2=0;
	long long count=0;
	string temp=to_string(c1-c0)+"#"+to_string(c2-c1);
	unordered_map<string,long long> mp;
	mp[temp]=1;
	for(int i=0;i<str.length();++i)
	{
		if(str[i]=='0')
			c0++;
		else if(str[i]=='1')
			c1++;
		else if(str[i]=='2')
			c2++;
		temp=to_string(c1-c0)+"#"+to_string(c2-c1);
		if(mp.find(temp)!=mp.end())
			count+=mp[temp];
		mp[temp]++;
	}
	return count;

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
 	cout<<getSubstringWithEqual012(s)<<"\n";    
}