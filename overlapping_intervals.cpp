//TC----->O(nlogn) , SC----->O(n)
 vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         vector<vector<int>>ans;
         sort(intervals.begin(),intervals.end());
         int start=intervals[0][0],end=intervals[0][1];
         int n = intervals.size();
         for(int i=1;i<n;i++){
             if(intervals[i][0]>end){
                 vector<int>temp={start,end};
                 start=intervals[i][0];
                 end=intervals[i][1];
                 ans.push_back(temp);
             }
             else if(end>=intervals[i][0]){
                 start=min(start,intervals[i][0]);
                 end=max(end,intervals[i][1]);
             }
             else{
                 vector<int> temp={start,end};
                 ans.push_back(temp);
                 start=intervals[i][0];
                 end=intervals[i][1];
             }
         }
         ans.push_back({start,end});
         return ans;
    }
