/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        unordered_map<Node*,Node*>mp;
        Node* newnode = head;
        while(newnode){
            mp[newnode]=new Node(newnode->val);
            newnode = newnode->next;
        }

        newnode = head;
        while(newnode){
            mp[newnode]->next = mp[newnode->next];
            mp[newnode]->random = mp[newnode->random];
            newnode = newnode->next;
        }
        return mp[head];
    }
};