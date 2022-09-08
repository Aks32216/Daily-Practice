tclass RandomizedSet {
public:
    
    /*
    set<int> s;
    
    RandomizedSet() {
        
    }
    // O(n)
    bool insert(int val) {
        if(s.find(val)!=s.end())
            return false;
        else{
            s.insert(val);
            return true;
        }
    }
    // O(n)
    bool remove(int val) {
        if(s.find(val)!=s.end()){
            s.erase(val);
            return true;
        }
        else
            return false;
    }
    
    // O(n)
    int getRandom() {
        int idx=rand()%s.size();
        auto it=s.begin();
        advance(it,idx);
        return *it;
    }
    */
    
    RandomizedSet() {
        
    }
    
    unordered_map<int,int> mp;
    vector<int> v;
    int i=0;
    
    bool insert(int val) {
        bool ret=mp.find(val)==mp.end();
        if(ret)
        {
            mp[val]=v.size();
            v.push_back(val);
        }
        return ret;
    }
    
    bool remove(int val) {
        bool ret=mp.find(val)!=mp.end();
        if(ret)
        {
            int old_index=mp[val];
            v[old_index]=v.back();
            mp[v[old_index]]=old_index;
            v.pop_back();
            mp.erase(val);
        }
        return ret;
    }
    
    int getRandom() {
        int n=v.size();
        int r=rand()%n;
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */