//TC----->O(nlogn) + O(n*m) , SC----->O(max(deadlines))
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comp(Job a,Job b){
        return a.profit>b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        int maxi=arr[0].dead;
        for(int i=1;i<n;i++) maxi = max(maxi,arr[i].dead);
        vector<int> hash(maxi+1,-1);
        int cnt=0,profit=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(hash[j]==-1){
                    cnt++;
                    profit+=arr[i].profit;
                    hash[j]=i;
                    break;
                }
            }
        }
        vector<int> ans = {cnt,profit};
        return ans;
    } 
};
