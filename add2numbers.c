struct ListNode* addTwoNumbers(struct ListNode* a, struct ListNode* b) {
    struct ListNode *head = NULL, *t;
    int carry = 0;

    while(a || b || carry) {
        int sum = carry;

        if(a) { sum += a->val; a = a->next; }
        if(b) { sum += b->val; b = b->next; }

        struct ListNode *n = malloc(sizeof(struct ListNode));
        n->val = sum % 10;
        n->next = NULL;

        if(head == NULL) head = n;
        else t->next = n;

        t = n;
        carry = sum / 10;
    }

    return head;
}
