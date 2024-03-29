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


/*
Range query
*/

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 3e5 + 5;
 
typedef struct data
{
	data* bit[2];
	int cnt = 0;
}trie;
 
int n, q, r, key, curRoot=0;
map<int, trie*> root;
trie* head;
 
trie* get(trie* node, int b)
{
	if(!node || !node->bit[b])
		return NULL;
	return node->bit[b];
}
 
int getCnt(trie* node)
{
	if(!node)
		return 0;
	return node->cnt;
}
 
void addNew(trie* old, trie* cur, int val, int i=20)
{
	cur->cnt = getCnt(old) + 1;
	if(i < 0)
		return;
	int b = val>>i & 1;
	cur->bit[b] = new trie();
	addNew(get(old, b), cur->bit[b], val, i-1);
	cur->bit[!b] = get(old, !b);
}
 
void add(int par, int u, int val)
{
	trie* cur = new trie();
	addNew(root[par], cur, val, 20);
	root[u] = cur;
}
 
int minXor(trie* cur, int x, int i)
{
	if(i < 0)
		return 0;
	int b = x>>i & 1;
	if(cur->bit[b] && cur->bit[b]->cnt>0)
		return minXor(cur->bit[b], x, i-1);
	else
		return (1LL<<i) + minXor(cur->bit[!b], x, i-1);
}	
 
int maxXor(trie* cur, int x, int i)
{
	if(i < 0)
		return 0;
	int b = x>>i & 1;
	if(cur->bit[!b] && cur->bit[!b]->cnt>0)
		return (1LL<<i) + maxXor(cur->bit[!b], x, i-1);
	else
		return maxXor(cur->bit[b], x, i-1);
}	
 
int getMaxXor(trie* L, trie* R, int x, int i=20)
{
	if(i < 0)
		return 0;
	int b = x>>i & 1;
	int have = getCnt(get(R, !b)) - getCnt(get(L, !b));
	if(have > 0)
		return (1LL<<i) | getMaxXor(get(L, !b), get(R, !b), x, i-1);
	else
		return getMaxXor(get(L, b), get(R, b), x, i-1);
}
 
int getMax(trie* L, trie* R, int x, int i=20)
{
	if(i < 0)
		return 0;
	int b = x>>i & 1;
	int have = getCnt(get(R, !b)) - getCnt(get(L, !b));
	if(have > 0)
		return ((!b)<<i) | getMax(get(L, !b), get(R, !b), x, i-1);
	else
		return b<<i | getMax(get(L, b), get(R, b), x, i-1);
}
 
int getLeq(trie* L, trie* R, int x, int i=20)
{	
	if(i < 0)
		return getCnt(R) - getCnt(L);
	int b = x>>i & 1;
	int ans = 0;
	if(b)
		ans += getCnt(get(R, 0)) - getCnt(get(L, 0));
	return ans + getLeq(get(L, b), get(R, b), x, i-1);
}
 
int getKth(trie* L, trie* R, int k, int i)
{
	if(i < 0)
		return 0;
	int have = getCnt(get(R, 0)) - getCnt(get(L, 0));
	if(have >= k)
		return getKth(get(L, 0), get(R, 0), k, i-1);
	else
		return (1LL<<i) + getKth(get(L, 1), get(R, 1), k-have, i-1);
}
 
void Q0(int x)
{
	add(curRoot, curRoot+1, x);
	curRoot++;
}
 
void Q1(int l, int r, int x)
{
	cout<<getMax(root[l-1], root[r], x, 20)<<endl;
}
 
void Q2(int k)
{
	curRoot-=k;
}
 
void Q3(int l, int r, int x)
{
	cout<<getLeq(root[l-1], root[r], x, 20)<<endl;
}
 
void Q4(int l, int r, int k)
{
	cout<<getKth(root[l-1], root[r], k, 20)<<endl;
}
 
int32_t main()
{
	IOS;
	root[0] = new trie();
	int q;
	cin>>q;
	while(q--)
	{
		int type, l, r, x;
		cin>>type;
		if(type==0)
			cin>>x, Q0(x);
		else if(type==1)
			cin>>l>>r>>x, Q1(l, r, x);
		else if(type==2)
			cin>>x, Q2(x);
		else if(type==3)
			cin>>l>>r>>x, Q3(l, r, x);
		else
			cin>>l>>r>>x, Q4(l, r, x);
	}
	return 0;
}

/*
Given an initially empty integer array (1-indexed) and some queries:

Type 0: Add the integer number x at the end of the array.
Type 1: On the interval L..R find a number y, to maximize (x xor y).
Type 2: Delete last k numbers in the array
Type 3: On the interval L..R, count the number of integers less than or equal to x.
Type 4: On the interval L..R, find the kth smallest integer (kth order statistic).

*/
 
