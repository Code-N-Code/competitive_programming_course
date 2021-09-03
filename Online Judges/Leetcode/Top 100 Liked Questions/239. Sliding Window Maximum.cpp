Video Editorial : https://youtu.be/0UHJsW2yyVg

vector<int> maxSlidingWindow(vector<int>& ar, int k) {
        
        vector<int> res;
        
        map<int,int> mp;
        int n = ar.size();
        int L = 0;
        int R = k-1;
        
        for(int i=0;i<R;i++) mp[ar[i]]++;;
        
        
        for(;R<n;R++ , L++){
            mp[ar[R]]++;
            
            pair<int,int> max = *mp.rbegin();
            res.push_back(max.first);
            
            mp[ar[L]]--;
            
            if(mp[ar[L]] == 0)
            mp.erase(ar[L]);
        }
        
        return res;
    }
