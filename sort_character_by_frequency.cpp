class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:m){
            int t=it.second;
            char c = it.first;
            pq.push({t,c});
        }
        string ans="";
        while(!pq.empty()){
            ans+=string(pq.top().first,pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
