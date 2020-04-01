#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

vector<bool> prime(N+1,0);

void seive(){

    prime[0]=prime[1]=0;
    
    for(int i=2;i*i<=N;++i){
        if(prime[i]){
            for(int j=i*i;j<=N;j+=i)
                prime[j]=0;
        }
    } 
}
