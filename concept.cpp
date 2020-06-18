

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
     
