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
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }

        // Find the end of the first half.
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split and reverse the second half.
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = secondHalf;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        secondHalf = prev;

        // Merge the two halves alternately.
        ListNode* firstHalf = head;

        while (secondHalf) {
            ListNode* nextFirst = firstHalf->next;
            ListNode* nextSecond = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = nextFirst;

            firstHalf = nextFirst;
            secondHalf = nextSecond;
        }
    }
};