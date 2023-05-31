//Function for sorting the vector of strings in terms of length
static bool comp(const string &a,const string &b){
        return a.size()<b.size();
    }

//Function for checking if the string a is predecessor of b or not 
    bool checkString(string &a,string &b){
        if(a.size()!=b.size()+1) return false;
        int first=0,second=0;
        while(first<a.size()){
            if(second<b.size() && a[first]==b[second]){
                first++;second++;
            }
            else{
                first++;
            }
        }
        if(first==a.size() && second==b.size()) return true;
        return false;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp); //As we need to return the largest possible sequence length so we can pick any string at any position that's why we have to sort the vector  
        vector<int> dp(n,1);
        int maxi=1;
        
      //Finding longest string chain 
        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(dp[j]+1>dp[i] && checkString(words[i],words[j])){
                    dp[i]=dp[j]+1;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
