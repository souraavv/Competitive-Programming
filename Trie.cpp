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

/* 
Remove and Finding element which given min xor vlaue with given value
*/

class TrieNode {
    public:
        int cnt = 0;
        TrieNode* arr[2];
        TrieNode() {
            this->cnt = 0;
            this->arr[0] = this->arr[1] = NULL;
        }
};
 
void insert(TrieNode* head, int val) {
    TrieNode* itr = head;
    for (int i = 30; i >= 0; --i) {
        int curBit = (val >> i) & 1;
        if (itr->arr[curBit] == NULL) {
            itr->arr[curBit] = new TrieNode();
        }
        itr = itr->arr[curBit];
        itr->cnt++;
    }
}
 
void rem(TrieNode* head, int val) {
    TrieNode* itr = head;
    for (int i = 30; i >= 0; --i) {
        int curBit = (val >> i) & 1;
        itr = itr->arr[curBit];
        itr->cnt--;
    }
}
 
int query(TrieNode* head, int val) {
    TrieNode* itr = head;
    int ans = 0;
    for (int i = 30; i >= 0; --i) {
        int curBit = (val >> i) & 1;
        if (itr->arr[curBit] != NULL && itr->arr[curBit]->cnt > 0) {
            itr = itr->arr[curBit];
        }
        else {
            ans += (1LL << i);
            itr = itr->arr[curBit ^ 1];
        }
    }    
    return ans;
}


/*
Cnt number of subarray, such that xor is atleast k
*/

 
int query(Trie* head, int val, int k) {
    Trie* itr = head;
    int ans = 0;
    for (int i = 30; i >= 0; --i) {
        int curBit = (val >> i) & 1;
        if ((k >> i) & 1) {
            // If bit is set in k at index i. Then we need to look for 
            // prefixes which have opposite bit that what val have at i, then only xor will happen to 1 at i, as 
            // condition is >= k
            if (itr->arr[curBit ^ 1] != NULL) {
                itr = itr->arr[curBit ^ 1];
            }
            else {
                return ans;
            }
        }
        else {
            // IF it is zero, I have a good chance to find some prefix, which make xor at val_i ^ prefix =1, because then I 
            // can immediately return ans 
            if (itr->arr[curBit ^ 1] != NULL) {
                ans += itr->arr[curBit ^ 1]->cnt;
            }   
            if (itr->arr[curBit] != NULL) {
                itr = itr->arr[curBit];
            }       
            else {
                return ans;
            }
        }
    }
    ans += itr->cnt;
    return ans;
}

// pref is used, becasue each query if updating original array, with xoring each element with some value k, then pref = k1 ^ k2 ...
// It is not require in general then you can set pref = 0 and It will behave normal 
int queryLessThanK(TrieNode* head, int K, int pref = 0) {
    TrieNode* itr = head;
    int ans = 0;
    for (int i = 30; i >= 0; --i) {
        int curK = (K >> i) & 1;
        int curPref = (pref >> i) & 1;
        if (curK) {
            if (curPref) {
                if (itr->arr[curPref] != NULL) {
                    ans += itr->arr[curPref]->cnt;
                }
                if (itr->arr[curPref ^ 1] != NULL) {
                    itr = itr->arr[curPref ^ 1];
                }
                else {
                    return ans;
                }
            }
            else {
                if (itr->arr[curPref] != NULL) {
                    ans += itr->arr[curPref]->cnt;
                }
                if (itr->arr[1 ^ curPref] != NULL) {
                    itr = itr->arr[1 ^ curPref];
                }
                else {
                    return ans;
                }
            }
        }
        else {
            // if curbit is not set.
            // then I also need to pick 0.
            if (itr->arr[curPref] != NULL) {
                itr = itr->arr[curPref];
            }
            else {
                return ans;
            }
        }
    }
    ans += itr->cnt;
    return ans;
}
 
bool exist(TrieNode* head, int val) {   
    TrieNode* itr = head;
    for (int i = 30; i >= 0; --i) {
        int curBit = (val >> i) & 1;
        if (itr->arr[curBit]) {
            itr = itr->arr[curBit];
        }
        else {
            return false;
        }
    }
    return true;
}


int queryMaxXor(TrieNode* head, int val) {
    TrieNode* itr = head;
    int ans = 0;
    for (int i = 30; i >= 0; --i) {
        int curBit = (val >> i) & 1;
        if (itr->arr[1 ^ curBit] != NULL && itr->arr[1 ^ curBit]->cnt > 0) {
            itr = itr->arr[1 ^ curBit];
            ans += (1LL << i);
        }
        else {
            itr = itr->arr[curBit];
        }
    }    
    return ans;
}


int queryMinXor(TrieNode* head, int val) {
    TrieNode* itr = head;
    int ans = 0;
    for (int i = 30; i >= 0; --i) {
        int curBit = (val >> i) & 1;
        if (itr->arr[curBit] != NULL && itr->arr[curBit]->cnt > 0) {
            itr = itr->arr[curBit];
        }
        else {
            ans += (1LL << i);
            itr = itr->arr[curBit^1];
        }
    }    
    return ans;
}

