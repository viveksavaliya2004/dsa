class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy_node = new ListNode(-1);
        ListNode* temp;
        temp = dummy_node;
        int sum , k = 0 ,carry = 0 ;
        while(l1 != NULL || l2 != NULL){
            sum = carry;
            if(l1) sum = sum + l1->val;
            if(l2) sum = sum + l2->val;

            ListNode* newnode = new ListNode(sum%10);
            carry = sum / 10;

            temp->next = newnode;
            temp = temp->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
           
        }
        if(carry){
            ListNode* newnode = new ListNode(carry);
            temp->next = newnode ;
        }
        return dummy_node->next;
    }
};