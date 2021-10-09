Video Editorial : https://youtu.be/GzND1mzfUHs

int jump(vector<int>& ar) {
        
      int n = ar.size();
      int INF = 100000000;
      int dp[n];

      //set every position to INF

      for(int i=0;i<n;i++) dp[i] = INF;
      dp[0] = 0;

      for(int i=0;i<n;i++){
          int reach = ar[i];

          for(int j=1;j<=reach;j++) 
              if(i+j<n)
                  dp[i+j] = min(dp[i+j] , dp[i] + 1);
      }

      return dp[n-1];
  }
