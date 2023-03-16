class Solution {
public:
    // bool comp(pair)

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int i=0,j=0,temp;
        temp=intervals[0][1];
        while(i<intervals.size()&&j<intervals.size()){
            if(temp>=intervals[j][0]){
                temp = max(temp,intervals[j][1]);
                // j++;
            }
            else{
                ans.push_back({intervals[i][0],temp});
                i=j;
                temp = intervals[i][1];
            }
            j++;
        }
        ans.push_back({intervals[i][0],temp});
        return ans;
    }
};
