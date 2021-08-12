Video Solution : https://www.youtube.com/watch?v=BSU8tUeVchM
Time Complexity : O(N)

int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 0) return 0;
        
        int mp[100] = {0};
        int n = s.size();
        int count = 0;
        int res = 1;
        int L = 0;
        int R = -1;
        
        
        while(1){
            if(count > 0){
                mp[s[L] - ' ']--;
                
                if(mp[s[L] -' '] == 1) count--;
                
                L++;
            }
            else{
                R++;
                if(R == n) break;
                
                mp[s[R] - ' ']++;
                if(mp[s[R] - ' '] == 2) count++;
            }
            if(count == 0) res = max(res , R - L + 1);
        }
        
        return res;
    }
    
    ============================================= Solution No. 2 ==========================================
    
    Time Complexity : O(NlogN)
    
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 0) return 0;
        
        map<char ,int> mp;
        int n = s.size();
        int count = 0;
        int res = 1;
        int L = 0;
        int R = -1;
        
        
        while(1){
            if(count > 0){
                mp[s[L]]--;
                
                if(mp[s[L]] == 1) count--;
                
                L++;
            }
            else{
                R++;
                if(R == n) break;
                
                mp[s[R]]++;
                if(mp[s[R]] == 2) count++;
            }
            if(count == 0) res = max(res , R - L + 1);
        }
        
        return res;
    }
