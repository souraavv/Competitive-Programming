#include <bits/stdc++.h>

using namespace std;

#define MAXN 100100

int vet[MAXN], tree[4*MAXN], lazy[4*MAXN];

void build(int node, int l, int r){

    if(l==r){
        tree[node]=vet[l];
        return;
    }

    int mid = (l+r)>>1;

    build(2*node,l,mid);
    build(2*node+1,mid+1,r);

    tree[node] = tree[2*node] + tree[2*node+1];
}

void flush(int node, int l, int r){

    if(!lazy[node]){
        return;
    }

    tree[node] = lazy[node]*(r-l+1);

    if(l!=r){
        lazy[2*node] = lazy[node];
        lazy[2*node+1] = lazy[node];
    }

    lazy[node]=0;
}

void update(int node, int tl, int tr, int l, int r, int v){

    if(tl>r or l>tr)return;

    flush(node,tl,tr);

    if(tl>=l and tr<=r){
        lazy[node]=v;
        flush(node,tl,tr);
        return;
    }

    int mid = (tl+tr) >> 1;

    update(2*node, tl, mid, l, r, v);
    update(2*node+1, mid+1, tr, l, r, v);

    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int tl, int tr, int l, int r){

    if(tl>r or l>tr)return 0;

    flush(node,tl,tr);

    if(tl>=l and tr<=r)return tree[node];

    int mid = (tl+tr) >> 1;

    return query(2*node, tl, mid, l, r) + query(2*node+1, mid+1, tr, l ,r);
}


void updateRange(int node,int start,int end,int l,int r,int val){
    
    if(start>end or start>r or end<l)return;
    
    flush(node,start,end);
   
    if(start>=l and end<=r){
        tree[node]+(end-start+1)*val; 
        if(start!=end){
            // not the leaf node
            lazy[node<<1]+=val;
            lazy[node<<1|1]+=val;
            
        }
        return;
        
    }
     int mid=(start+end)/2;
     updateRange(node<<1,start,mid,l,r,val);
     updateRange(node<<1|1,mid+1,end,l,r,val);
     tree[node]=tree[node<<1]+tree[node<<1|1];
}




int queryRange(int node,int start,int end,int l,int r){
   
   
   if(start>end or start>r or start<l)return 0;
   
  flush(node,start,end);
   if(start>=l and end<=r)return tree[node]; 
   int mid=(start+end)/2;
 
   int p1=queryRange(node<<1,start,mid,l,r);
   int p2=queryRange(node<<1|1,mid+1,end,l,r);
   
   return (p1+p2);
}

int main(){

   
  return 0;
}
