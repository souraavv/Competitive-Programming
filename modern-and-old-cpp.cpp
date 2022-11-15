#include<bits/stdc++.h> // includes all standard library, but is not a standard header file of GNU C++
// don't use this :)
using namespace std;

/*
 * auto Vs Decltype in c++
 */

/* C++ 11 syntax */
template<class T, class U> 
auto mul(T t, U u) -> decltype(t * u) {return t * u; }
// if decltype is not written then scope problem as t and u types are not known


/* c++14 syntax 
 * removed this decltype and now simply it will work
*/

template<class T, class U>
decltype(auto) mul2(T t, U u) {return t * u;}

/*
 * constexpr says that the function must be of a simple form so that it can be
 * evaluated at compile time if given constant expressions arguments
 */

constexpr int mod = 1e9 + 7;

/*
 * nullptr in c++, replace #define NULL nullptr
 
 * f(int) {}
 * f(int*) {}
 * so f(NULL) is amb.
 * because NULL = 0 or pointer to nothing ?
 * but nullptr resolve this issue :)
 * f(nullptr) binds to the f(int*)
 */

int main() {
    const int& x = 5;
    auto y = x; // can deduce cv-qualifier or reference
    y = 6; // ok
    cout << y << endl; 
    decltype(x) z = 6; // can deduce cv-qualifier or reference
    // z = 5; is not ok
    decltype(auto) k = y; // c++14 simplify
    cout << z << " " << k << "\n";
    
    auto ans = mul(5, 4.3);
    cout << ans << "\n";
    ans = mul2(4, 3.3);
    cout << ans << "\n";

    constexpr int x1 = 5 | 6; // ok as this can be evaluated at compile time only
    cout << x1 << '\n';
    
    
    /*
     * raw string literals
     */
     
    std::regex re1(R"!("operator"|"operator->")!"); // "operator()"|"operator->"
    std::regex re2(R"xyzzy("\([A-Za-z_] \w *\)")xyzzy"); // "(identifier)" \
    return 0;
    
    /*
     * move is c++
     */
     
    int var = 5;
    decltype(var) var2(std::move(var));
    cout << var2 << "\n";
    // note var continue to exist event after move, only thing they point to same
    
}    
