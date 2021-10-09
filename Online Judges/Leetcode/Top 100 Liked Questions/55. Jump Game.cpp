Video Editorial : https://youtu.be/D2Rcv28mRp0

bool canJump(vector<int>& ar) {
        
      int n = ar.size();
      bool result = true;

      int last = ar[0];

      for(int i=0;i<n;i++){
          if(i > last) {
              result = false;
              break;
          }
          last = max(last , i + ar[i]);
      }

      return result;
  }
