
//Better way using seive
vector<int> findPrimeFactors(int N) {

        // Write your code here
        vector<int> ans;
        vector<int>hash(N+1,0);
        for(int i=2;i*i<=N;i++){
            if(hash[i]==0 && N%i==0){
                for(int j=2;j*i<=N;j++){
                    hash[j*i]=1;
                }
                while(N!=0 && N%i==0){
                    N = N/i;
                    ans.push_back(i);
                }
            }
        }
        if(N>1) ans.push_back(N);
        return ans;
    }

//Optimal approach
vector<int> findPrimeFactors(int N) {

        // Write your code here
        vector<int> ans;
        while(N%2==0){
            ans.push_back(2);
            N = N/2;
        }
        while(N%3==0){
            ans.push_back(3);
            N = N/3;
        }
        
        for(int i=5;i*i<=N;i=i+6){
            while(N%i==0){
                ans.push_back(i);
                N = N/i;
            }
            while(N%(i+2)==0){
                ans.push_back(i+2);
                N = N/(i+2);
            }
        }
        
        if(N>1) ans.push_back(N);
        return ans;
    }
