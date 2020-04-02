#include<bits/stdc++.h>
using namespace std;
#define int long long int

/*

 F[n+1] = 1*F[n] + 1*F[n-1];
 F[n]   = 1*F[n] + 0*F[n-1];

 { F[n+1], F[n] } = | 1 1 | { F[n] , F[n-1] }
                    | 0 1 |




 We know F[1] and F[0] so To compute  F[n] We have to compute { F[n], F[n-1] } 
 
 And If we generalize thing then we have to rewrite the equation for { F[n], F[n-1] } 
 in same order as for { F[n+1], F[n] } and to the base case we will get
                
                            
 { F[n], F[n-1]} = | 1 1 |^(n-1) { F[1] , F[0] }
                   | 0 1 |
                   
                   
    So using Matrix Exponentiation we will compute | 1 1 | raise to power n-1.
                                                   | 0 1 | 

*/

void multiply(int F[2][2], int M[2][2]) 
{ 
    int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
    int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
    int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
    int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
  
    F[0][0] = x; 
    F[0][1] = y; 
    F[1][0] = z; 
    F[1][1] = w; 
}

int M[2][2] = {{1,1},{1,0}}; 

void power(int F[2][2],int n){
    
    if(n<=1) 
        return; 
  
    power(F, n/2); 
    
    multiply(F, F); 
    
    if (n%2 != 0) 
        multiply(F, M); 
    
}


int fibMatrix(int n) {
    int F[2][2] = {{1,1},{1,0}}; 
    if (n == 0) 
        return 0; 
    power(F, n-1); 
    return F[0][0];
}


int32_t main(){
    
    int n;
    cin>>n;
    cout<<fibMatrix(n);
}
