// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int l=1,h=x;
        long long int mid;
        
        long long int prev = l;
        while(l<=h){
            mid = (h+l)/2;
            long long int temp = mid*mid;
            if(temp==x) return mid;
            if(temp<x){
                prev=l;
                l=mid+1;
                if(l*l>x){
                    l--;
                    break;
                }
            }
            else{
                h=mid-1;
            }
        }
        return l;
        
    }
};
