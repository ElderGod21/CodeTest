class Solution {
public:
    int bitwiseComplement(int n) {

        int m =n;
        int mask =0;

        if(m==0){
            return 1;
        }

        while(m!=0){
            m = m>>1;
            mask = mask<<1 | 1;
        }
        int ans = (~n)&mask;
        return ans;
        
    }
};