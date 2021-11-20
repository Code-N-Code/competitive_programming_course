Video Editorial : https://youtu.be/YnPzuFxEBy8

ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue <pair<int,ListNode*>, vector<pair<int,ListNode*> >, greater<pair<int,ListNode*> > > pq;
        ListNode* head = NULL;
        ListNode* movingHead = NULL;
        
        int n = lists.size();
        
        for(int i=0;i<n;i++){
            if(lists[i] != NULL) pq.push({lists[i]->val , lists[i]});
        }
        
        while(!pq.empty()){
            
            ListNode* temp = pq.top().second;
            pq.pop();
            
            if(head == NULL) head = movingHead = temp;
            else             movingHead->next = temp , movingHead = temp;
            
            if(temp->next != NULL) {
                temp = temp->next;
                pq.push({temp->val , temp});
            }
        }
        
        return head;
    }
