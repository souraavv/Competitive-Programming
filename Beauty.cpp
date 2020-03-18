/*


1)  a+b = (a xor b) + ( a & b ) << 1


    Proof: By Venn diagram 
            Or 
           
           a = 1010110
           b = 0111011
         sum = 1101101
       carry = 0010010 << 1 
   new carry  00100100
              ---------
              10010001
       acutal ans = sum + shift carry by 1 bit to left.
       
     
     Bonus: if a&b==0 then a+b = a ^ b;
       
       
2) a^b and a + b always have same parity i.e if a^b is even then a+b is also even and vice versa
    
    Why? Proof  If both on the last bit are set then a^b get 0 on last bit
                and if a and b has last bit set then 1+1 end with 0 on last bit 
                
    
    Very good problem: https://codeforces.com/problemset/problem/1325/D

3) Array a of size n ( n<=10^5 ) and q (q<=10^5) query where each query ask to xor the p with each element of array A and count the
    total number of set bit odd and even. 
    
    Some Observation : If a number k is xor with say p =[0,1], then what will happen
                        
                       Case 1: p=0
                            If total no. of set bit in k is odd and p=0 then after xor (k^p = k^0 = k) 
                            doesn't change and If k is even then also. Infact as k^0 = k so parity of set
                            bit doesn't change.
                       
                       Case 2: p=1
                            If k has odd no. of set bit then k^1 will have even no. of set bit.
                            If k has even no. of set bit then k^1 will have odd no. of set bit. 
                            
                            e.g 1110000 ^ 1 = 1110001 (3 -> 4)    
                                1100001 ^ 1 = 1100000 (3 -> 2)
                                
                                and 
                                
                                111100 ^ 1 = 111101 (4 -> 5)
                                111001 ^ 1 = 111000 (4 -> 3)
                              
                             So this mean each set bit in p [ the no. which we are xoring with each element]
                             will alter the no. of set bit . If it is even then it will become odd and vice vers
                             
                             So What we have to do precount the no. of __builtin_popcount(x) which are odd
                             and even. And then count this for p .
                             If p has even parity of set bit the p is equivalent to = 1
                             if p has even parity of set bit the p is equivalent to = 0
                             
                             Why ?
                             
                             A no. get the same parity after 2 turn [ even-> | odd -> even | ]
                             So if p has odd no. of set bit ( 2x + 1) then at final 
                                                                                    even -> ...... -> odd
                                                                                and odd -> ...... -> even
                             else if p has even no. of set bit 
                                                            even -> ..... -> even
                                                            odd -> .... -> odd
                             
    
    Good Problem: https://www.codechef.com/problems/ENGXOR
    
    
*/
