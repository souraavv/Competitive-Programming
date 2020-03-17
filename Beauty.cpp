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
       
       
2) a^b and a + b always have same parity i.e if a^b is even then a+b is also even and vice versa
    
    Why? Proof  If both on the last bit are set then a^b get 0 on last bit
                and if a and b has last bit set then 1+1 end with 0 on last bit 
                
           



*/
