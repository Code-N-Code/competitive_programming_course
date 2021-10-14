Video Editorial : https://youtu.be/1jTzmre77Pc

int maxArea(vector<int>& height) {
        
        int res = 0;
        
        int L = 0;
        int R = height.size() - 1;
        
        while(L < R){
            if(height[L] <= height[R]){
                res = max(res , height[L] * (R - L));
                L++;
            }
            else{
                res = max(res , height[R] * (R - L));
                R--;
            }
        }
        
        return res;
    }
