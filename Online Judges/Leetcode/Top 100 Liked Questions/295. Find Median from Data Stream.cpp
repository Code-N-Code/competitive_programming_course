video Editorial : https://youtu.be/5n8zI4ZOVCc

**************** CODE ******************

priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int> maxHeap;

  MedianFinder() {

  }

  void addNum(int num) {
      if(maxHeap.size() == 0) {
          maxHeap.push(num);
          return;
      }

      if(maxHeap.size() == minHeap.size()){
          //swap top elements
          if(minHeap.top() < num){
              maxHeap.push(minHeap.top());
              minHeap.pop();
              minHeap.push(num);
          }
          else{
              maxHeap.push(num);
          }
      }

      else{
          if(maxHeap.top() > num){
              minHeap.push(maxHeap.top());
              maxHeap.pop();
              maxHeap.push(num);
          }
          else{
              minHeap.push(num);
          }
      }
  }

  double findMedian() {
      if(minHeap.size() == maxHeap.size()){
          double res = minHeap.top() + maxHeap.top();
          return res / 2;
      }
      else{
          return maxHeap.top();
      }
  }
