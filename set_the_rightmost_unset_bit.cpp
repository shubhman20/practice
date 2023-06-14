//TC----->O(logn) , SC----->O(1)
int setBit(int N)
    {
        // Write Your Code here
        int ct=0,ans=N;
        while(N){
            if(!(N&1)){
                ans = ans|(1<<ct);
                break;
            }
            ct++;
            N=N>>1;
        }
        return ans;
    }
