
#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int n;


class BIT {

    private: 
        int n;
        vector<int> bit;
        
    public: 
        BIT(vector<int>a){
            n=a.size();
            bit = vector<int>(n+1,0);
            // O(n) filling of BIT
            // copy(a.begin(),a.end(),bit.begin()+1);
            for(int i=0;i<a.size();++i)bit[i+1]=a[i];
            
            for(int idx=1;idx<=n;++idx){
                int idx1 = idx+(idx & -idx);
                if(idx1<=n){
                    bit[idx1]+=bit[idx];
                }
            }
            
        }
        
        int query(int idx){
            int sum=0;
            for(++idx;idx>0;idx-=idx&-idx)sum+=bit[idx];
            return sum;
        }
        
        void update(int idx,int val){
            for(++idx;idx<=n;idx+=idx & -idx)bit[idx]+=val;
        }
        
        int rangeQuery(int i,int j){
            if(i==0)return query(j);
            return (query(j)-query(i-1));
        }
        
    
};



int main(){
    
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    
    BIT b(a);
    
    cout<<b.rangeQuery(4,13);
    
}
