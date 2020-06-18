

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



        

