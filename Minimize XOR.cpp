class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int set_bits_b=0,res=0;
        while(num2){
            num2&=(num2-1);
            set_bits_b++;
        }
        cout<<set_bits_b;
        for(int i=31;i>=0 && set_bits_b;i--){
            if((num1 & (1<<i)) !=0){
                set_bits_b--;
                res+=(1<<i);
            }
        }
    
        for(int i=0;i<32 && set_bits_b>0;i++){
            if((num1 & (1<<i)) ==0){
                set_bits_b--;
                res+=(1<<i);
            }
        }
        return res;
    }
};
