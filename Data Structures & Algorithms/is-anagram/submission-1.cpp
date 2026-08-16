class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }

        int count[26]={0};

        for(int i=0; i<s.length(); i++){
            char c=s[i];
            count[c-'a']++;
        }

        for(int i=0; i<t.length(); i++){
            char c=t[i];
            count[c-'a']--;
        }

        for(int i=0; i<26; i++){
            if(count[i]!=0){
                return false;
            }
        }

        return true;
    }
};
