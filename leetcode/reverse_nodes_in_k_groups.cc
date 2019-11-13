/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* lastTime;
        ListNode* firstNode = NULL;
        ListNode* prev = NULL;
        ListNode* next;
        ListNode* veryFirst = head;
        int i = 0;
        while (true) {
            ListNode n = ListNode(0);
            n.next = head;
            ListNode* lastInGroup = &n;
            // Get to the last node in group
            for (int j = 0; j < k; j++) {
                if (lastInGroup != NULL && lastInGroup->next != NULL) {
                    lastInGroup = lastInGroup->next;
                    i += 1;
                } else {
                    break;
                }
            }
            
            if (i % k != 0 || head == NULL || head->next == NULL) {
                break;
            } else if (i == k) {
                veryFirst = lastInGroup;
            }
            
            if (firstNode != NULL) {
                firstNode->next = lastInGroup;
            }
            
            lastInGroup = lastInGroup->next;
            
            firstNode = head;
            for (int j = 0; j < k; j++) {
                next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }
            firstNode->next = head = lastInGroup;
        }
        return veryFirst;
    }
};