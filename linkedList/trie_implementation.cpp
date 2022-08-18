class TrieNode{
 
    public:
    
    char c;
    unordered_map<char,TrieNode*> mp;
    bool isWord;
    
    TrieNode(char c)
    {
        this->c=c;
        isWord=false;
    }
};


class Trie {
public:
    
    TrieNode* root;
    
    Trie() {
        root=new TrieNode(' ');
    }
    
    void insert(string word) {
        TrieNode* cur=root;
        for(auto& c:word)
        {
            if(cur->mp[c]==NULL)
            {
                TrieNode* next=new TrieNode(c);
                cur->mp[c]=next;
            }
            cur=cur->mp[c];
        }
        cur->isWord=true;
    }
    
    bool search(string word) {
        TrieNode* cur=root;
        
        for(auto& c:word)
        {
            if(cur->mp[c]==NULL)
                return false;
            cur=cur->mp[c];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for(auto& c:prefix)
        {
            if(cur->mp[c]==NULL)
                return false;
            cur=cur->mp[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */