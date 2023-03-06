class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,s=0,t=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) f++;
            else if(bills[i]==10){
                f--;
                if(f<0) return false;
                s++;
            }
            else{
                if(f<=0||(s<=0&&f<=2)) return false;
                if(s>0){
                    s--;f--;
                }
                else{
                    f-=3;
                }
            }
        }
        
        return true;
    }
};
