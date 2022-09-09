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
 
int func(){
	return 1;
}

int sum(int a,int b){
	return a+b;
}

int getSum(int a,int b,int(*sumPtr)(int ,int))
{
	return sumPtr(a,b);
}

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	// how to create function pointer
 	// lets define a function which returns 1
       cout<<func()<<"\n"; // returns 1 from function
       cout<<func<<"\n"; // but if we output only function without invoking it, it will return the address of the function
    // so to store this addres we can use function pointer
    // returnType(*functionPtrName)(arguments if any)=name of function

    int(*funcPtr)()=func;
    cout<<funcPtr()<<"\n";
    // function pointer with argument
    int(*sumPtr)(int,int)=sum;
    cout<<sumPtr(4,3)<<"\n";
    // why to use function pointer
    // function pointers are used to pass function as an argument to another function
    // just like call back function
    cout<<getSum(4,5,sum)<<"\n"; // passing  sum as an argument
    cout<<getSum(5,6,sumPtr)<<"\n";
}