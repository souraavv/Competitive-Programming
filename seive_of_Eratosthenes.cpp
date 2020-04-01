#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<bool>is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;
    
    for(int i=4;i<=n;i+=2)
            is_prime[i]=false;
    
    for(int i=3;i*i<=n;++i){
        if(is_prime[i]){
            for(int j=i*i;j<=n;j+=i)
                is_prime[j]=false;
        }
    }
    // Asymptotic complexity-- O(nlog(log(n))) = N/2 + N/3 + N/5 + N/7 + .... 
    // though because we are going till root n-- complexity will be O(n)+O(n ln ln (sqrt(n)))
    
    for(int i=1;i<=n;++i)if(is_prime[i])cout<<i<<", ";
    
    return 0;
}
