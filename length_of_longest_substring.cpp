//Better Approach TC----->O(2*n) , SC----->O(n)
 int longestUniqueSubsttr(string S){
        //code
        int n = S.size();
        int i=0,j=0,cnt=0,maxi=0;
        vector<int> hash(26,0);
        for(int k=0;k<n;k++){
            if(hash[S[k]-'a']==0){
                hash[S[k]-'a']++;
                cnt++;
            }
            else{
                maxi = max(maxi,cnt);
                while(S[j]!=S[k]){
                    cnt--;
                    hash[S[j]-'a']--;
                    j++;
                }
                j++;
            }
        }
        maxi = max(maxi,cnt);
        return maxi;
    }

//Optimal Approach TC----->O(n) , SC----->O(n)
int longestUniqueSubsttr(string S){
        //code
        int n = S.size();
        int j=0,maxi=0;
        vector<int> hash(26,-1);
        for(int k=0;k<n;k++){
            if(hash[S[k]-'a']!=-1){
                j = max(j,hash[S[k]-'a']+1);
            }
            maxi=max(maxi,k-j+1);
            hash[S[k]-'a'] = k;
        }
        if(maxi==0) return n;
        
        return maxi;
    }
