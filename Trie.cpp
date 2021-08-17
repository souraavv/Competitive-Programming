class TrieNode {
    public: 
    TrieNode* child[26];
    bool isEnd;

    TrieNode () {
        this->isEnd = false;
        for (int i = 0; i < 26; ++i) {
            this->child[i] = NULL;
        }
    }
    void markEnd() {
        this->isEnd = true;
    }
};

class Solution {
    public:
    int ans = 0;
    TrieNode* root = new TrieNode();
    
    void insertRec(TrieNode* itr, string s, int i) {
        if (i == s.length()) {
            itr->markEnd();
            return;
        }
        int idx = s[i] - 'a';
        if (itr->child[idx] == NULL) {
            itr->child[idx] = new TrieNode();
        }
        insertRec(itr->child[idx], s, i + 1);
        
    }
    void insert(string s) {
        insertRec(root, s, 0);
    }
};

// Missing Shimla a lot....:(
