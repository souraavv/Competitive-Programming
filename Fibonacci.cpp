
#include<bits/stdc++.h>
using namespace std;
#define int long long 

/*

We have some properties with fibonacci no.

1) F(n) = F(n-1) + F(n-2) 
    and any F(n-1) and F(n-2) can be find with formulla
    
    F(2K+2) = F(2K) + F(2K+1);
    
    F(2k) = F(k)* [ 2*F(k+1) - F(k) ];
    F(2K+1) = F(k+1)^2 + F(k)^2;
    
    if(n is odd) then we will not compute n-1 , n-2 directly instead we will computer for n-1(it is even ) and then with one more step we will compute for n

2) ( F(n), F(n+1) ) = (F(0) F(1)).P^n

                        where P = |0 1|
                                  |1 1|
                                  

3) IMP. GCD identity : apply euclidean behave worse on fibonacci number 

    so GCD(F(n), F(k)) == F(GCD(n,k));

4) 1st formulla is taken from this general form: 

    Addition Rule: F(n+k) = F(n)*F(k-1) + F(n+1)*F(k);
    
5) Cassini's Identity:  F(n-1)*F(n+1) - F(n)^2 = (-1)^n;

 
*/


// Code of (1)
pair<int,int> fib(int n){
    if(n==0)return {0,1};
    
    auto p = fib(n>>1);
    int c = p.first * (2*p.second - p.first);
    int d = p.first*p.first + p.second*p.second;
    
    if(n%2)return {d,c+d}; // if odd: like n=31  then we will compute for n=30 i.e 28+29 and now for 31 = (29,(29+28==30))
    return {c,d};
}

int32_t main(){
   int n = 30;
   cout<<fib(n-1).first<<" "<<fib(n-1).second<<"\n";
   cout<<fib(n).first<<" "<<fib(n).second<<" \n";
    
}
