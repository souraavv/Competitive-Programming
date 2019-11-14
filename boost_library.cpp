  
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace boost::multiprecision;
using boost::multiprecision::cpp_dec_float_50;


// using this we can compute upto large precision

int main(){

cpp_dec_float_50 x=100000000034.343,y=938438843843.34;

cpp_dec_float_50 ans=x*y;
cout<<ans<<endl;


return 0;
}
