#include<bits/stdc++.h>
using namespace std;

class BIT{
    private: 
        vector<int> m_array;
    
    public: 
        BIT(vector<int>a){
            m_array=vector<int>(a.size()+1,0);
            for(int i=0;i<a.size();++i){
                m_array[i+1]=a[i];
            }
            
            for(int i=1;i<m_array.size();++i){
                int idx=i+(i&(-i)); // adding 1 to last set bit infact each one is contributing either to its upward parent or next parent;
                if(idx<m_array.size()){
                    m_array[idx]+=m_array[i];
                } 
            }
        }
        
        int prefix_query(int idx)const{
            int result=0;
            ++idx;
            for(;idx>0;idx-=idx& -idx){
                result+=m_array[idx];
            }
            return result;
        }
        
        int range_query(int from_idx,int to_idx){
            
            if(from_idx==0){
                return prefix_query(to_idx);
            }
            
            else return prefix_query(to_idx)-prefix_query(from_idx-1);
        }
        
        void update(int idx,int val){
            for(++idx;idx<m_array.size();idx+=idx & -idx){
                m_array[idx]+=val;
            }
        }
        
        
};



int main(){
    
    std::vector<int> a{1,1,0,1,0,1,1,1,2,0,0,1,0,1 };
    
    BIT bit(a);
    
    std::cout << "Prefix sum of first 13 elements: \t" << bit.prefix_query(12) << std::endl;
	std::cout << "Prefix sum of first 7 elements: \t" << bit.prefix_query(6) << std::endl;
	std::cout << "Range sum from index 4 to index 5: \t" << bit.range_query(4, 5) << std::endl;
    bit.update(4, 2);
    
    std::cout << "Prefix sum of first 13 elements: \t" << bit.prefix_query(12) << std::endl;
	std::cout << "Prefix sum of first 7 elements: \t" << bit.prefix_query(6) << std::endl;
	std::cout << "Range sum from index 4 to index 4	: \t" << bit.range_query(4, 4) << std::endl;
	
	return 0;
}
