//TC----->O(n*2^n) , SC----->(2*n)
vector<string> AllPossibleStrings(string s){
		    vector<string>ans;
		    int n = s.size();
		    for(int i=0;i<(1<<n);i++){
		        string a="";
		        for(int j=0;j<n;j++){
		            if((i&1<<j)!=0) a+=s[j];
		        }
		        if(a.size()>0) ans.push_back(a);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
