//TC----->O(1) , SC----->O(1)
int Xor(int n){
        if(n%4==1) return 1;
        else if(n%4==2) return n+1;
        else if(n%4==3) return 0;
        return n;
    }
  
    int findXOR(int l, int r) {
        // complete the function here
        int val1 = Xor(l-1);
        int val2 = Xor(r);
        return val1^val2;
        
    }
