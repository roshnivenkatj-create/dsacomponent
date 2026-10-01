/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    
    if (head == NULL || k == 1)
        return head;

    struct ListNode *curr = head;
    int count = 0;

    // Check if there are at least k nodes
    while (curr != NULL && count < k) {
        curr = curr->next;
        count++;
    }

    // Less than k nodes -> leave them unchanged
    if (count < k)
        return head;

    // Reverse k nodes
    struct ListNode *prev = NULL;
    curr = head;

    for (int i = 0; i < k; i++) {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // head is now the end of the reversed group
    head->next = reverseKGroup(curr, k);

    return prev;
}
