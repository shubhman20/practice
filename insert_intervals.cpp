//TC----->o(N) , SC----->O(N)
vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &intervals, vector<int> &newEvent) {
        // code here
        vector<vector<int>> ans;
        int i=0;
        while(i<N && newEvent[0]>intervals[i][1]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<N && newEvent[1]>=intervals[i][0]){
            newEvent[0]=min(newEvent[0],intervals[i][0]);
            newEvent[1]=max(newEvent[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newEvent);
        while(i<N){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
