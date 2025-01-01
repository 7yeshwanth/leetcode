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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode();
        auto *temp = result;
        int c = 0;
        while(l1 != nullptr || l2 != nullptr) {
            int s = 0;
            if (l1 != nullptr)
            {
                s += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                s += l2->val;
                l2 = l2->next;
            }
            s += c;
            ListNode *node = new ListNode(s % 10);
            c = s / 10;
            temp->next = node;
            temp = temp->next;
        }
        if(c!=0) {
          ListNode *node = new ListNode(c);
          temp->next = node;
        }
        return result->next;
    }
};