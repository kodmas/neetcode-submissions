/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* tmp = head;
        while(tmp){
            sz++;
            tmp = tmp->next;
        }
        cout << sz << endl;
        ListNode* curr = head;
        int c = 0;
        if(sz == n) return head->next;
        while(true){
            
            if(c == sz-n-1){
                if(curr->next->next == nullptr){
                    curr->next = nullptr;
                    return head;
                }
                else{
                    ListNode* tmp = curr->next->next;
                    curr->next = tmp;
                    return head;
                }
            }
            curr = curr->next;
            c++;
        }

    }
};
