

// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    // code here
    int buy=0,possible=0;
    for(int i=0;i<n-1;i++){
        if(price[i]<price[i+1] && buy==0){
            cout<<"("<<i<<" ";
            buy=1;possible=1;
        }
        else if(price[i]>price[i+1] && buy==1){
            cout<<i<<") ";
            buy=0;
        }
    }
    if(buy==1){
        cout<<n-1<<")";
    }
    if(possible==0){
        cout<<"No Profit";
    }
    cout<<endl;
    
}
