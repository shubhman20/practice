//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comp(Item &a,Item &b){
        double v1 = (double)a.value/(double)a.weight;
        double v2 = (double)b.value/(double)b.weight;
        return v1<v2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        // for(int i=0;i<n;i++){
        //     cout<<arr[i].value<<" "<<arr[i].weight<<endl;
        // }
        // cout<<endl;
        double ans=0;
        int idx=n-1;
        while(W>0&&idx>=0){
            if(W>=arr[idx].weight){
                W -=arr[idx].weight;
                ans+=arr[idx].value;
                idx--;
            }
            else{
                ans+= W*((double)arr[idx].value/(double)arr[idx].weight);
                // break;
                W-=W;
                idx--;
            }
        }
        return ans;
    }
        
};
