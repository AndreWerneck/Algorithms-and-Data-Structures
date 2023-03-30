#include "list.h"

ListSentinel* createList(){
    ListSentinel *head = malloc(sizeof(ListSentinel));
    head->first = NULL;
    head->last = NULL;
    return head;
} //Allocates head node of the Linked List

void addNodeList(ListSentinel *head, string word){
    if(head->first == NULL){ //Lista vazia
        ListNode *add;
        add = (ListNode*)malloc(sizeof(ListNode));
        add->next = NULL;
        add->word = malloc(strlen(word) * sizeof(char));
        strcpy(add->word, word);
        head->first = add;
        head->last = add;
    }
    else {
        ListNode *add;
        add = (ListNode*)malloc(sizeof(ListNode));
        add->next = NULL;
        add->word = malloc(strlen(word) * sizeof(char));
        strcpy(add->word, word);
        head->last->next = add;
        head->last = add;
    }
} //Adds the word into the last position of the Linked List

void printList(ListSentinel *head){
    ListNode *percorre;
    percorre = head->first;

    while (percorre != NULL) {
            printf("%s \n", percorre->word);
            percorre = percorre->next;
    }
    printf("\n");
} //Prints the word, in order o addition

void clearlist(ListSentinel *head){
    ListNode *del;
    while (head->first != NULL){
        del = head->first;
        head->first = del->next;
        del->next = NULL;
        free(del);
    }
    head->last = NULL;
    free(head);
} //Deletes all nodes and clear the memory
