
#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int bit[N];
int n;


void add(int idx,int val){
    while(idx<=n){
        bit[idx]+=val;
        idx+=idx & -idx;
    }
}

int query(int idx){
    int sum=0;
    while(idx){
        sum+=bit[idx];
        idx-=idx & -idx;
    }
    return sum;
}

int range_query(int idx1,int idx2){
	return (query(idx1)-query(idx2-1));	
}

int main(){
    
    cin>>n;
    for(int i=1;i<=n;++i){
        int a;
        cin>>a;
        add(i,a);
    }
    
    cout<<range_query(14,5);
    
}
