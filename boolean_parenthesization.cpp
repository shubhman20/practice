//Recursion  TC-----> Exponential , SC----->O(N)
int mod = 1003;
    int f(int i,int j,string &s,int isTrue){
        if(i>j) return 0;
        
        if(i==j){
            if(isTrue==1) return s[i]=='T'; 
            else{
                return s[i]=='F';
            }
        }
        long long ways=0;
        for(int k=i+1;k<j;k=k+2){
            long long lF = f(i,k-1,s,0);
            long long lT = f(i,k-1,s,1);
            long long rF = f(k+1,j,s,0);
            long long rT = f(k+1,j,s,1);
            
            if(s[k]=='&'){
                if(isTrue==1){
                    ways = (ways + (lT*rT)%mod)%mod;
                }
                else{
                    ways = (ways + (rT*lF)%mod + (lT*rF)%mod + (lF*rF)%mod)%mod;
                }
            }
            else if(s[k]=='|'){
                if(isTrue==1){
                    ways = (ways + (lT*rF)%mod + (rT*lF)%mod + (lT*rT)%mod)%mod;
                }
                else{
                    ways = (ways + (lF*rF)%mod)%mod;
                }
            }
            else{
                if(isTrue==1){
                    ways = (ways + (lF*rT)%mod + (lT*rF)%mod)%mod;
                }
                else{
                    ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
                }
            }
        }
        return ways;
    }

//Memoization  TC-----> O(N*N*2*N) , SC----->O(N*N*2) + O(N)
int mod = 1003;
    int f(int i,int j,string &s,int isTrue,vector<vector<vector<long long>>>&dp){
        if(i>j) return 0;
        
        if(i==j){
            if(isTrue==1) return s[i]=='T'; 
            else{
                return s[i]=='F';
            }
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        long long ways=0;
        for(int k=i+1;k<j;k=k+2){
            long long lF = f(i,k-1,s,0,dp);
            long long lT = f(i,k-1,s,1,dp);
            long long rF = f(k+1,j,s,0,dp);
            long long rT = f(k+1,j,s,1,dp);
            
            if(s[k]=='&'){
                if(isTrue==1){
                    ways = (ways + (lT*rT)%mod)%mod;
                }
                else{
                    ways = (ways + (rT*lF)%mod + (lT*rF)%mod + (lF*rF)%mod)%mod;
                }
            }
            else if(s[k]=='|'){
                if(isTrue==1){
                    ways = (ways + (lT*rF)%mod + (rT*lF)%mod + (lT*rT)%mod)%mod;
                }
                else{
                    ways = (ways + (lF*rF)%mod)%mod;
                }
            }
            else{
                if(isTrue==1){
                    ways = (ways + (lF*rT)%mod + (lT*rF)%mod)%mod;
                }
                else{
                    ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
                }
            }
        }
        return dp[i][j][isTrue]=ways;
    }


    int countWays(int N, string S){
        // code here
        vector<vector<vector<long long>>> dp(N,vector<vector<long long>>(N,vector<long long>(2,-1)));
        return f(0,N-1,S,1,dp);
    }

//Tabulation TC-----> O(N*N*2*N) , SC----->O(N*N*2)
int mod = 1003;
int countWays(int N, string S){
        // code here
        vector<vector<vector<long long>>> dp(N,vector<vector<long long>>(N,vector<long long>(2,0)));
        for(int i=N-1;i>=0;i--){
            for(int j=0;j<=N-1;j++){
                if(i>j) continue;
                
                for(int isTrue=0;isTrue<2;isTrue++){
                    if(i==j){
                        if(isTrue==1) dp[i][j][isTrue] = S[i]=='T'; 
                        else{
                            dp[i][j][isTrue]= S[i]=='F';
                        }
                        continue;
                    }
                    long long ways=0;
                    for(int k=i+1;k<j;k=k+2){
                        long long lF = dp[i][k-1][0];
                        long long lT = dp[i][k-1][1];
                        long long rF = dp[k+1][j][0];
                        long long rT = dp[k+1][j][1];
            
                        if(S[k]=='&'){
                            if(isTrue==1){
                                ways = (ways + (lT*rT)%mod)%mod;
                            }
                            else{
                                ways = (ways + (rT*lF)%mod + (lT*rF)%mod + (lF*rF)%mod)%mod;
                            }
                        }
                        else if(S[k]=='|'){
                            if(isTrue==1){
                                ways = (ways + (lT*rF)%mod + (rT*lF)%mod + (lT*rT)%mod)%mod;
                            }
                            else{
                                ways = (ways + (lF*rF)%mod)%mod;
                            }
                        }   
                        else{
                            if(isTrue==1){
                                ways = (ways + (lF*rT)%mod + (lT*rF)%mod)%mod;
                            }
                            else{
                                ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
                            }
                        }
                    }
                    dp[i][j][isTrue]=ways;
                }
            }
        }
        
        return dp[0][N-1][1];
    }
