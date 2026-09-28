struct ListNode* swapPairs(struct ListNode* h) {
    if(!h || !h->next) return h;

    struct ListNode *a=h, *b=h->next;

    a->next=swapPairs(b->next);
    b->next=a;

    return b;
}
