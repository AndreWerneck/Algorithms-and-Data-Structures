
#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

typedef struct ListNode{
    string word;
    struct ListNode *next;
} ListNode;

typedef struct ListNodeH{
    struct ListNode *first;
    struct ListNode *last;
} ListSentinel;

ListSentinel* createList();
void addNodeList(ListSentinel *head, string word);
void printList(ListSentinel *head);
void clearlist(ListSentinel *head);

#endif /* list_h */
