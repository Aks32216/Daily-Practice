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


/*int maxOnes(vector<int>& v){
    int ans=0;
    for(int i=0;i<v.size();++i){
        if(v[i]==0){
            v[i]=1;
            int curCount=0;
            int maxCount=0;
            for(int j=0;j<v.size();++j){
                if(v[j]==1)
                    curCount++;
                else
                    curCount=0;
                maxCount=max(maxCount,curCount);
            }
            ans=max(maxCount,ans);
            v[i]=0;
        }
    }
    return ans;
}*/

/*int maxOnes(vector<int>& v){
    int curCount=0;
    int n=v.size();
    vector<int> prefix(n),sufix(n);
    for(int i=0;i<v.size();++i){
        if(v[i]==1)
            curCount++;
        else
            curCount=0;
        prefix[i]=curCount;
    }
    curCount=0;
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]==1)
            curCount++;
        else
            curCount=0;
        sufix[i]=curCount;
    }
    int ans=0;
    for(int i=0;i<n;++i){
        if(v[i]==0){
            int left=i==0?0:prefix[i-1];
            int right=i==n-1?0:sufix[i+1];
            ans=max(ans,left+right+1);
        }
    }
    return ans;
}*/

int maxOnes(vector<int>& v){
    int res=0,cur=0,cnt=0;
    for(int i=0;i<v.size();++i){
        cnt++;
        if(v[i]==0){
            cur=cnt;
            cnt=0;
        }
        res=max(res,cur+cnt);
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
 	vector<int> v(n);
 	for(auto& i:v)
 		cin>>i;
 	cout<<maxOnes(v)<<"\n";
}