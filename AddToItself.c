/* last written on 11/09/2017 16:34:14
owner ise2017001 rajaneesh
@devrezo on twitter
@devrezo on github
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
        int data;
        struct node *next;
};
struct node *createNode (int value) {
        struct node *newNode = (struct node *) malloc (sizeof (struct node));
        newNode -> data = value;
        newNode -> next = NULL;
        return newNode;
}
void insertNode (struct node **head_ref, struct node **tail_ref, int value) {
        struct node *newNode = createNode (value);
        if (*head_ref == NULL) {
                *head_ref = newNode;
                *tail_ref = newNode;
}
        else {
                (*tail_ref) -> next = newNode;
                *tail_ref = newNode;
}
}
void  printList (struct node *head) {
        while (head != NULL) {
                printf ("%d -> ", head->data);
                head = head->next;
}
        printf ("NULL\n");
}
void destroyList (struct node *head) {
        struct node *nextNode = head;
        while (head != NULL) {
                nextNode = head -> next;
                free (head);
                head = nextNode;
}
        printf("Killed off all her feelings\n" );
}
void addToItself (struct node **head_ref) {
        struct node *headNew = NULL;
        struct node *tailNew = NULL;
        struct node *prevNode = NULL;
        struct node *currentNode = NULL;
        currentNode = (*head_ref);
        if (currentNode == NULL) {
                return;
}
        while (currentNode != NULL) {
                insertNode (&headNew, &tailNew, currentNode->data);
                prevNode = currentNode;
                currentNode = currentNode->next;
}
        prevNode->next = headNew;
        return;
}
int main (int argc, char *argv[]) {
        int value;
        struct node *head = NULL, *tail = NULL;
        char buffer[2048];
        char *p = NULL;

        fgets (buffer, 2048, stdin);
        p = strtok (buffer, "NULL >|\n");
        while (p != NULL) {
                sscanf (p, "%d", &value);
                insertNode (&head, &tail, value);
                p = strtok (NULL, "> | NULL \n");
        }
        printList (head);
        addToItself (&head);
        printList (head);
        destroyList (head);
        head = NULL;
        tail = NULL;
        return 0;
}
