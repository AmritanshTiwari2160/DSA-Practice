/**app 1 finding middle node->reversing mid to last node->then using pointers we need to joing nodes in required order*/
  ListNode* reverseLL(ListNode* node) {
        if(node == NULL || node->next == NULL)
            return node;
        ListNode* last = reverseLL(node->next);
        node->next->next = node;
        node->next = NULL;
        return last;
    }//reversing ll very very important
//Approach-1 (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        
        ListNode* curr = head;
        while(curr) {
            st.push(curr);
            curr = curr->next;
        }
        
        int k = st.size()/2;
        curr = head;
        while(k--) {
            ListNode* topNode = st.top();
            st.pop();
            
            ListNode* temp = curr->next;
            curr->next = topNode;
            topNode->next = temp;
            curr = temp;
        }
        
        curr->next = NULL;
    }
};

//Approach-2 (without stack)
//T.C : O(n)
//S.C : O(1) AUxiliary, O(n) Recursion stack space
class Solution {
public:
    ListNode* reverseLL(ListNode* node) {
        if(node == NULL || node->next == NULL)
            return node;
        ListNode* last = reverseLL(node->next);
        node->next->next = node;
        node->next = NULL;
        return last;
    }
    
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* revHalf = reverseLL(slow);
        
        ListNode* curr = head;
        while(revHalf->next) {
            ListNode* tempFront = curr->next;
            curr->next          = revHalf;
            
            ListNode* tempBack  = revHalf->next;
            revHalf->next       = tempFront;
            
            revHalf             = tempBack;
            curr                = tempFront;
        }
    }
};
