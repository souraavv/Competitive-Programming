
#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int bit[N];
int n;


void add(int idx,int val){
    for(++idx;idx<=n;idx+=idx & -idx)
	    bit[idx]+=val;
}

int query(int idx){
    int sum=0;
    for(++idx;idx>0;idx-=idx & -idx)
	    sum+=bit[idx];
    return sum;
}

int range_query(int i,int j){
	if(i==0)return query(j);
	else return query(j)-query(i-1);
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
