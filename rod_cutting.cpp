//Recursion
int f(int idx,int price[],int size){
        if(idx==0){
            return size*price[idx];
        }
        int notCut = f(idx-1,price,size);
        int cut=INT_MIN;
        if(idx+1<=size) cut = price[idx] + f(idx,price,size-idx-1);
        return max(notCut,cut);
        
    }

//Memoization
int f(int idx,int price[],int size,vector<vector<int>> &dp){
        if(idx==0){
            return size*price[idx];
        }
        if(dp[idx][size]!=-1) return dp[idx][size];
        int notCut = f(idx-1,price,size,dp);
        int cut=INT_MIN;
        if(idx+1<=size) cut = price[idx] + f(idx,price,size-idx-1,dp);
        return dp[idx][size]=max(notCut,cut);
        
    }
  
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(n-1,price,n,dp);
    }

//Tabulation
int f(int n,int price[],int size,vector<vector<int>> &dp){
        for(int i=0;i<=size;i++){
            dp[0][i] = i*price[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=size;j++){
                int notCut = dp[i-1][j];
                int cut = INT_MIN;
                if(i+1<=j) cut = price[i]+dp[i][j-i-1];
                dp[i][j]=max(notCut,cut);
            }
        }
        return dp[n-1][size];
        
    }

//Space Optimization
int f(int n,int price[],int size,vector<int> &dp){
        for(int i=0;i<=size;i++){
            dp[i] = i*price[0];
        }
        for(int i=1;i<n;i++){
            vector<int> temp(size+1,0);
            for(int j=0;j<=size;j++){
                int notCut = dp[j];
                int cut = INT_MIN;
                if(i+1<=j) cut = price[i]+temp[j-i-1];
                temp[j]=max(notCut,cut);
            }
            dp=temp;
        }
        return dp[size];
        
    }
