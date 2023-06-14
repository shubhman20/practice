//TC----->O(logn) , SC----->O(1)
int countBitsFlip(int a, int b){
        
        // Your logic here
        a = a^b;
        int cnt=0;
        while(a){
            if(a&1) cnt++;
            a = a>>1;
        }
        return cnt;
        
    }
