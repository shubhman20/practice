class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static comp(pair<int,int> &a,pair<int,int> &b){
        return (a.second<b.second);
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),comp);
        int cnt=1,limit=v[0].second;
        for(int i=1;i<v.size();i++){
            if(v[i].first>limit){
                cnt++;
                limit = v[i].second;
            }
        }
        return cnt;
    }
};
