/**
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {

    if (head == NULL || left == right)
        return head;

    // Dummy node helps when left = 1
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *prev = &dummy;

    // Move prev to the node before 'left'
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    // Reverse the required portion
    struct ListNode *curr = prev->next;

    for (int i = 0; i < right - left; i++) {

        struct ListNode *temp = curr->next;

        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }

    return dummy.next;
}
