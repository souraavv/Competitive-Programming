

/*                                                       Mathematics                                                                     */


/*1). Compute x^y^z mod M.

    Efficient approach: We know that if a^M - a is divisible by M if M is prime and a is not divisible by M
    if that is so then only we can say a^M == a % M
                                        or a ^ (M - 1) == 1 (mod M)
                                           a ^ [x * (M - 1)]  == 1 (mod M)
                                           a ^ (M - 1) * a ^ (M - 1) .... x times mod M
                                           1 * 1 * 1 * ... = 1 mod M;
                                        
    This is little Fermat's Theorem : a ^ ( M - 1 ) == 1 mod M.
                                    
                                   Let's see how to apply it to make y ^ z a smaller value, that's why we
                                   intentionally taking the factor i.e a * (M - 1) because computing this is equivalent to 
                                   computing nothing as it is 1 mod M.
                                   
    So if we write y ^ z = ans, then ans =  a * (M - 1) + b ; where a is q, b is rem.
        where b = (y ^ z) % (M - 1)
    thus x ^ y ^ z become x ^ (a * (M - 1) + b)  == x ^ (a * (M - 1) * x ^ b 
    and we know x ^ (a * (M - 1)) = 1 . So x ^ y ^ z == x ^ b
    
    So here x ^ b, b is nothing but = (y ^ z) mod (M - 1) and that we know how to compute using modular exponentiation.
    and whatever the ans will make it raise to pow a ^ ans % M and that is our final ans.                                                 *///
    
    
    // Code 
    
    const int mod = 1e9 + 7;
    
    int pow(int a, int b, int MOD) {
        int ans = 1;
        a %= MOD, b %= MOD;
        while(b) {
            if(b % 2 == 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            b /= 2;
        }
        return ans % MOD;  
     }
     int x, y, z;
     cin >> x >> y >> z;
     int newPower = pow(y, z, mod - 1);
     int finalAns = pow(x, newPower, mod);
     
     cout << finalAns;
     


/*                                           Find all the divisor of a number  - BASIC                                                      

        We will find the smallest prime factor of a number and then to handle each query we can ans in O(log n) time.
        To find SPF we will use seive.
        
*/

    // code
    
    const int N = 1e6 + 10;
    int spf[N];

    void seive() {
        // Initial setup
        for(int i = 1; i < N; ++i) {
            spf[i] = i;
        }
        for(int i = 2; i * i < N; ++i) {
            if(spf[i] == i) {
                for(int j = i * i; j < N; j += i) {
                    if(spf[j] == j) // If none have modified then i is the smallest spf of j
                        spf[j] = i;
                }
            }
        }
    }
    
    vector<int> prime_factorization(int x) {
        vi store;
        while(x != 1) {
            store.push_back(spf[x]);
            x /= spf[x];
        }
        return store;
    }

    int main() {
        seive();
        int x;
        cin >> x;
        vi store = prime_factorization(x);
    }
        

/*                       Given an array find pair of number (a, b) such that the gcd(a, b) is max of all possible pair      

    Constraint on N = 1e5
    
    Idea : Using the basic of Seive.
    We know the ans can have range = [1, max_element(a) ]
    So thus we will iterate from the max_element(a) to 1 and 
    maintain a count array which count the no. of time it has been come as a common factor.
    So initially all element are there gcd and thus count[a[i]] for each 0 <= i < n is equal to 1.
    
    And then as we are iterating from the max to 1, once we find some one if it's count is 2 then we immediately return ans.

*/
    
    // Code
    
    const int N = 1e6 + 10;
    vi a;

    int findMaxGcd() {
        int mx = *max_element(all(a));
        for(int i = mx; i >= 1; --i) {
            int j = i;
            int tempCounter = 0; // Used to check whether i itself is factor of two number's from the array a, in that case ans is i.
            for(int j = i; j <= mx; j += i) {
                if(count[j] >= 2)
                    return j;
                else if(count[i] == 1) // This condition will work only for those which are present in array a, i.e count[a[i]] = 1
                    tempCounter++;
            
                if(tempCounter == 2)
                    return i;
            }
        }
    }

    int main() {
        int n;
        a = vi(n);
        for(int &i: a)
            cin >> i;
        cout << findMaxGcd();
        return 0;
    }



/*                                        Find the sum of divisor of number <= n  
        
        If we do this naively then to find ans of each i <= n we will take O(sqrt(n)) time to find the sum of it's divisor
        and in total O(n sqrt(n)) , But what if N <= 1e12. Then this solution will exceed the time limit.
        
        Let's think more clever solution.
        
        Instead of finding the divisor of each number 1 <= i <= n, we will find how many times a number comes as divisor.
        So integer i comes in i * 1, i * 2, i * 3, ... 
                                                            which is equal to = i * floor(n / i);
        
        So ans is simply = for(int i = 1; i <= n; ++i)
                                ans += i * floor(n / i);
        Again this is O(n) and won't pass time limit.
        
        Can we do something more better ... ?
        Loot at the floor(n / i) how many distinct value it can have ?
            To count easily consider two cases 
                   1). i <= sqrt(n) ; then floor(n / i) will have sqrt(n) different ans ( only integers) .
                   2). i > sqrt(n)  ; this is equivalent to n / i < sqrt(n) or equivalently floor(n / i) < sqrt(n)
                                      and this can also have sqrt(n) different values.
            So in total at most this expression floor(n / i) can have 2sqrt(n) = O(sqrt(n)) different values.
            
        How this statement can help us ?
        for each distinct sqrt(n) values if I know in which range it is same then we can break our original sequence (1 to n)
        into sqrt(n) sequence [why sqrt(n) ? because only this much unique value) ](Li, Ri) where each element in range Li, Ri 
        will have same n / i value. And now for this range computing sum is is not like 
                for(int i = l; i <= r; ++i)
                    ans += i * floor(n / i);
                
                    But instead
                
                sum += (l, l + 1, l + 2, ..., r) * floor(n / i);
        Finding sum from l to r which is a simple sequence is easy.
        Since each element in the range (l, r) have same floor(n / i) value.
        
        Ok now question might be how to find these sequence fast.
        2 ways : Binary Search [ O(log(n)) ], or some simple math [O(1)] (just one division)
        
        One thing we know l1 = 1 (As 1st segment start from 1), Now we have to find r1?
        
        one thing we know floor(n / l1) == floor(n / r1)
                                    or 
                           n / r1 >= floor(n / l1) 
                           r1 / n < 1 / floor(n / l1))
                           r1 < n / floor(n / l1))
                           or 
                           r1 = floor(n / floor(n / l1));
                           
                           So in simple r1 = n / n / l;
         And now we know what is l2 = r1 + 1 ; In general l(i + 1) = r(i) + 1;
         
         
         Example: 
          N = 16;
          let's see what are values of N / i for all  1 <= i <= N;
          16, 8, 5, 4, 3, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1
          
          So we can see there are some segment which give same value's. 
*/

    // Code : 
        
    #include<bits/stdc++.h>
    using namespace std;
    #define int long long int
    const int mod = 1e9 + 7;

    int multiply(int a, int b) {
        a %= mod, b %= mod;
        return (a * b) % mod;
    }

    int add(int a, int b) {
        a += b;
        if(a >= mod)
            return a - mod;
        return a;
    }

    int modpow(int a, int b) {
        if(b == 1)
            return a % mod;
        a = a % mod;
        b = b % (mod - 1);
        int ans = 1;
        a %= mod, b %= mod;
        while(b) {
            if(b % 2)
                ans = multiply(ans, a);
            a = multiply(a, a);
            b >>= 1;
        }
        return ans % mod;
    }
    
    int modinv(int x) {
        return modpow(x, mod - 2);
    }

    void go() {
        int n;
        cin >> n;
        auto sumtill = [&](int x) {
            x %= mod;
            int sum = multiply(x, x + 1);
            sum = multiply(sum, modinv(2));
            return sum % mod;
        };
            
        int ans = 0;

        for(int l = 1; l <= n; ) {
            int r = n / (n / l);
            int toAdd = sumtill(r) - sumtill(l - 1);
            toAdd = multiply(toAdd, n / l);
            ans += toAdd;
            l = r + 1;
        }   
        cout << ans % mod << "\n";
    }
    int32_t main() {
        go();
        return 0;
    }
    
        
        

