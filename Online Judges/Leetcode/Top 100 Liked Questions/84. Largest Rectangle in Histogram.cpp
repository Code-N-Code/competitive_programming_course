Video Editorial : https://youtu.be/D0AjkeucpJQ

int largestRectangleArea(vector<int>& height) {
        
        int n = height.size();
        int L[n] , R[n];
        
        stack<int> stack;
        
        //finding left minimums
        for(int i=0;i<n;i++){
            while(!stack.empty() && height[stack.top()]>=height[i])
                stack.pop();
            if(stack.empty())
                L[i] = -1;
            else
                L[i] = stack.top();
            stack.push(i);
        }
        
        //clearing stack
        while(stack.empty() == false) stack.pop();
        
        //finding right minimums
        for(int i=n-1;i>=0;i--){
            while(!stack.empty() && height[stack.top()]>=height[i])
                stack.pop();
            if(stack.empty())
                R[i] = n;
            else
                R[i] = stack.top();
            stack.push(i);
        }
        
        //finding result
        int max_area = 0;
        
        for(int i=0; i<n; i++){
            int width = R[i] - L[i] - 1;
            int area = height[i]*width;
            max_area = max(max_area, area);
        }
        
        return max_area;
    }
