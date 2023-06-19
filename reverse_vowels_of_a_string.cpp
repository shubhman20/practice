//TC----->O(n) , SC----->O(1)
string reverseVowels(string s) {
        int n = s.size();
        int l=0,h=n-1;
        while(l<=h){
          //Instead of below while loops we can use find_first_of & find_last_of functions to find next set of vowel to be swapped
            while(l<=h && (s[l]!='a'&&s[l]!='e'&&s[l]!='i'&&s[l]!='o'&&s[l]!='u'&&s[l]!='A'&&s[l]!='E'&&s[l]!='I'&&s[l]!='O'&&s[l]!='U')) l++;
        
            while(h>=l && (s[h]!='a'&&s[h]!='e'&&s[h]!='i'&&s[h]!='o'&&s[h]!='u'&&s[h]!='A'&&s[h]!='E'&&s[h]!='I'&&s[h]!='O'&&s[h]!='U')) h--;

            if(l>h) break;
            swap(s[l],s[h]);
            l++;h--;
        }
        return s;

    }

