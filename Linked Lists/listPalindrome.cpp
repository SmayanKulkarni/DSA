bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return 1;

        ListNode* temp = head;
        int count =0;
        while(temp)
        {
            count++;
            temp=temp->next;
        }

        // delete temp;
        ListNode* curr=head, *prev = NULL;
        count/=2;
        for(int i=0;i<count;i++)
        {   
            prev = curr;
            curr=curr->next;
        }
        prev->next = NULL;

        prev = NULL;

        ListNode* front;
        while(curr)
        {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        // delete curr;
        // delete front;
        ListNode* head1=head, *head2 = prev;

        while(head1)
        {
            if(head1->val!=head2->val)
            {
                return 0;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        return 1;
    }