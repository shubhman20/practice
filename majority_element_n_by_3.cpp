class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        int c1=0,c2=0;
        int ele1=INT_MAX,ele2=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1) c1++;
            else if(nums[i]==ele2) c2++;
            else if(c1==0){
                ele1=nums[i];
                c1=1;
            }
            else if(c2==0){
                ele2=nums[i];
                c2=1;
            }
            else{
                c1--;c2--;
            }
        }
        c1=0;c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1) c1++;
            else if(nums[i]==ele2) c2++;
        }
        vector<int>ans;
        if(c1>floor(n/3)){
            ans.push_back(ele1);
        }
        if(c2>floor(n/3)){
            ans.push_back(ele2);
        }
        if(ans.size()==0){
            ans.push_back(-1);
        }
        return ans;
    }
};
