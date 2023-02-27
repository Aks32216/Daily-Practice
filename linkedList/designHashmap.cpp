// Appraoch - 1

class MyHashMap {
public:
    
    vector<int> v;
    
    MyHashMap() {
        v.resize(1e6+1,-1);
    }
    
    void put(int key, int value) {
        v[key]=value;
    }
    
    int get(int key) {
        return v[key];
    }
    
    void remove(int key) {
        v[key]=-1;
    }
};

// Approach - 2

class MyHashMap {
public:
    // keep a array of linked list and a hash function
    // for us hash function would be f(key%size)
    vector<list<pair<int,int> > > hashMap;
    int size=100000;

    MyHashMap() {
        hashMap.resize(size);
    }
    
    // find the key and put the value in the key and if not found then just make a new pair 
    void put(int key, int value) {
        auto& list=hashMap[key%size];
        for(auto& i:list)
        {
            if(i.first==key)
            {
                i.second=value;
                return;
            }
        }
        list.emplace_back(key,value);
    }

    
    int get(int key) {
        auto& list=hashMap[key%size];
        if(list.empty())
            return -1;
        for(auto i:list)
        {
            if(i.first==key)
            {
                return i.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        auto& list=hashMap[key%size];
        for(auto it=list.begin();it!=list.end();it++)
        {
            if(it->first==key)
            {
                list.erase(it);
                return;
            }
        }

    }
};