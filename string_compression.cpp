//TC----->O(n) , SC----->O(1)
int compress(vector<char>& chars) {
        int i=0,j=1;
        int n = chars.size();
        if(n==1) return 1;
        char ch=chars[0];
        int len=1;
        for(int i=1;i<n;i++){
            if(chars[i]!=ch){
                ch=chars[i];
                if(len>1){
                    string temp = to_string(len);
                    int k = 0;
                    while(k<temp.size()){
                        chars[j++]=temp[k++];
                    }
                }
                len=1;
                chars[j]=ch;
                j++;
            }
            else{
                len++;
            }

        }
        if(len>1){
            string temp = to_string(len);
            int k = 0;
            while(k<temp.size()){
                chars[j++]=temp[k++];
            }
        }
        return j;
    }
