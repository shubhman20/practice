class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int high) {
        int h=piles[0],l=1;
        if(piles.size()==1){
            return (piles[0]%high==0 ? piles[0]/high : piles[0]/high + 1);
        }
        if(piles.size()>high) return -1;
        for(int i=1;i<piles.size();i++){
            if(h<piles[i])
                h=piles[i];
            if(l>piles[i])
                l=piles[i];
        }
        int mid,res=h;
        while(l<h){
            mid = l + (h-l)/2;
            long long cnt=0;
            for(int i=0;i<piles.size();i++){
                cnt += piles[i]/mid;
                if(piles[i]%mid!=0)
                    cnt++;
            }
            if(cnt<=high){
                res=min(res,mid);
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
};
