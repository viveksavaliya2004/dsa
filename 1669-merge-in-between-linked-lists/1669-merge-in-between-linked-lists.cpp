class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        
        ListNode* prevA = list1;
        for (int i = 1; i < a; i++) {
            prevA = prevA->next;
        }

       
        ListNode* afterB = prevA->next;
        for (int i = a; i <= b; i++) {
            afterB = afterB->next;
        }

        
        prevA->next = list2;

        
        ListNode* tail = list2;
        while (tail->next != NULL) {
            tail = tail->next;
        }

        
        tail->next = afterB;

        return list1;
    }
};
