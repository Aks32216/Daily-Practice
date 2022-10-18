#include <bits/stdc++.h>
using namespace std;

class Player{
    // space complexity - O(n)
        unordered_map<int,int> mp;
        multiset<int,greater<int> > mt;
    public:
        Player(){};
        
        // time Complexity - O(log n)
        void addScore(int id,int score){
            if(mp.count(id))
                mt.erase(mt.find(mp[id]));
            mp[id]+=score;
            mt.insert(mp[id]);
        }
        
        // time complexity - O(k)
        int top(int k){
            int sum=0;
            for(auto i:mt){
                if(k==0)
                    break;
                sum+=i;
                k--;
            }
            return sum;
        }
        
        // time complexity - O(log n)
        void reset(int id){
            mt.erase(mt.find(mp[id]));
            mp.erase(id);
        }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
    #endif

    Player p;
    p.addScore(1,73);
    p.addScore(2,56);
    p.addScore(3,39);
    p.addScore(4,51);
    p.addScore(5,4);
    cout<<p.top(1)<<"\n";
    p.reset(1);
    p.reset(2);
    p.addScore(2,51);
    cout<<p.top(3)<<"\n";
}