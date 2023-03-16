class Solution {
public:
    bool static comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return 0;
        int ans=0;
        sort(intervals.begin(),intervals.end(),comp);
        int i=0,j=1,temp=intervals[0][1];
        while(i<intervals.size()&&j<intervals.size()){
            if(temp>intervals[j][0]){
                ans++;
            }
            else{
                i=j;
                temp =intervals[i][1];
            }
            j++;
        }
        return ans;

    }
};
