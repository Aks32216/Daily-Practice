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
int findUnique(string s)
{
    int count=0;
    vector<int> freq(26,0);
    for(int i=0;i<s.length();++i){
        freq[s[i]-97]++;
        if(freq[s[i]-97]==1)
            count++;
    }
    return count;
}

int numSplits(string s) {
    int goodSplits=0;
    int n=s.length();
    for(int i=0;i<n-1;++i){
        string first=s.substr(0,i+1);
        string second=s.substr(i+1);
        int c1=findUnique(first);
        int c2=findUnique(second);
        if(c1==c2)
            goodSplits++;
    }
    return goodSplits;
}
*/
    
int numSplits(string s){
	int n=s.length();
	int leftDistinct=0,rightDistinct=0;
	vector<int> freqLeft(26,0),freqRight(26,0);
	for(int i=0;i<n;++i){
		freqRight[s[i]-97]++;
		if(freqRight[s[i]-97]==1)
			rightDistinct++;
	}
	int goodSplits=0;
	for(int i=0;i<n-1;++i){
		freqLeft[s[i]-97]++;
		if(freqLeft[s[i]-97]==1)
			leftDistinct++;
		freqRight[s[i]-97]--;
		if(freqRight[s[i]-97]==0)
			rightDistinct--;
		if(leftDistinct==rightDistinct)
			goodSplits++;
	}
	return goodSplits;
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
 	cout<<numSplits(s)<<"\n"; 
}