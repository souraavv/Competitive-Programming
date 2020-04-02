
#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int mod = 1e9+7;

int pow(int a,int b){
    int ans = 1;
    while(b>0){
        if(b%2)
            ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}

int add(int a,int b){
    a+=b;
    if(a>=mod)
        return a-mod;
    return a;
}

int sub(int a,int b){
    a-=b;
    if(a<0)
        return a+mod;
    return a;
}

int multiply(int a,int b){
    int k=(a*b)%m;
    return k;   
}
// since a.b mod m =[ (a mod m)*(b mod m) ]mod m ; since both a and be are same 
int power(int a,int b,int m){
    int ans=1;
    a%=m;
    while(b>0){
        if(b%2)
            ans=(ans*a)%m;
        a=(a*a)%m;
        b/=2;
    }
    return ans;
}


int32_t main(){
    int k = pow(2,20);
    int p = power(2,20,mod);
    cout<<p<<"\n";
    
}
