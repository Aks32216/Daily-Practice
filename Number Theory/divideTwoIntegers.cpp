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

int divide(int dividend, int divisor) {
    if(dividend == divisor)
        return 1;
    bool isPositive = (dividend<0 == divisor<0);    // if both are of same sign, answer is positive
    unsigned int a = abs(dividend);
    unsigned int b = abs(divisor);
    unsigned int ans = 0;
    while(a >= b){  // while dividend is greater than or equal to divisor
        short q = 0;
        while(a > (b<<(q+1)))
            q++;
        ans += (1<<q);  // add the power of 2 found to the answer
        a = a - (b<<q);  // reduce the dividend by divisor * power of 2 found
    }
    if(ans == (1<<31) and isPositive)   // if ans cannot be stored in signed int
        return INT_MAX;
    return isPositive ? ans : -ans;
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	int dividend,divisor;
 	cin>>dividend>>divisor;
 	cout<<divide(dividend,divisor)<<"\n";
}