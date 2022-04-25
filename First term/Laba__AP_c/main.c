#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct Node {        //structure for node
    struct Node *next;
    struct Node *prev;
    char data[30];
} node;

struct db_linked_lst { // structure for list
    size_t size;
    struct Node *head;
    struct Node *tail;
} dbLinkedLst;

struct db_linked_lst *create_lst() {
    struct db_linked_lst *temp = malloc(sizeof(dbLinkedLst)); //create starting structure for lst
    temp->size = 0;
    temp->head = temp->tail = NULL;
    return temp;
}

void push_back(struct db_linked_lst *list, char *data) {//add elem to the end of lst
    struct Node *temp = malloc(sizeof node);
    if (temp == NULL) {
        exit(1);
    }
    strcpy(temp->data, data);
    temp->next = NULL;
    temp->prev = list->tail;
    if (list->tail) {
        list->tail->next = temp;
    }
    list->tail = temp;
    if (list->head == NULL) {
        list->head = temp;
    }
    list->size++;
}

void *pop_front(struct db_linked_lst *list) { // del elem from front
    struct Node *prev;
    void *temp;
    if (list->head == NULL) {
        printf("\nThere is no elements in a list. Error2!!!");
        return 0;
        //exit(2);
    }
    printf("Deleting element from beginning of the list...\n");
    prev = list->head;
    list->head = list->head->next;//move head to 2nd node
    if (list->head) {
        list->head->prev = NULL; // clear pointer to old head
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    temp = prev->data;
    free(prev);//clear data from old node
    list->size--;
    return temp;
}

void print_lst(struct db_linked_lst *list, int k) {
    struct Node *p;
    p = list->head;
    printf("\nPrinting list...\n");
    if (p == NULL) {
        printf("\nList is empty! Error...\n");
    } else {
        do {
            printf("%s", p->data);
            if (k == 0) {
                printf("\n");
            }
            p = p->next;
        } while (p != NULL);
    }
}


void save_list_to_file(struct db_linked_lst *list, FILE *f1) {
    struct Node *p;
    p = list->head;
    printf("\nSaving list...\n");
    if (p == NULL) {
        printf("List is empty! Error...");
    } else {
        do {
            printf("%s ", p->data);
            printf("\n");
            fputs(p->data, f1);
            fputs("\n", f1);
            p = p->next;
        } while (p != NULL);
    }
}

void rest_from_file(struct db_linked_lst *list, FILE *f1) {
    char str[20];
    printf("\nRestoring List from the file...");
    while (fgets(str, 20, f1) != NULL) {
        push_back(list, str);
    }
}

void del_list(struct db_linked_lst **list) { // delete whole list
    struct Node *temp = (*list)->head;
    struct Node *next = NULL;
    if (temp == NULL) {
        printf("\n\nThere is no such list. Error!!!");
        exit(3);
    }
    printf("\nDeleting list...\n");
    while (temp) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(*list);
    (*list) = NULL;
}


int main() {
    int n, n1;
    FILE *f1;

    while (1) {
        printf("Enter number of elements in a list:");
        scanf("%d", &n);
        if (n > 0) {
            break;
        } else {
            printf("Wrong value! Try again\n");
        }
    }

    struct db_linked_lst *lst = create_lst(); // create list

    for (int i = 0; i < n; i++) { // add elements to that list
        char a[20];
        printf("Enter value %d :", i + 1);
        fflush(stdin);
        gets(a);
        push_back(lst, a);
    }

    print_lst(lst, 0); //print list

    pop_front(lst);//delete 1st elem

    print_lst(lst, 0);


    f1 = fopen("Save.txt", "w");
    save_list_to_file(lst, f1);
    fclose(f1);

    print_lst(lst, 0);

    del_list(&lst);

    struct db_linked_lst *lst1 = create_lst();
    f1 = fopen("Save.txt", "r");

    rest_from_file(lst1, f1);

    fclose(f1);

    print_lst(lst1, 1);

    del_list(&lst1);

    return 0;
}






/*
 * For better times...
 *
 *
 printf("Which element would you like to delete:");

    while (1){
        scanf("%d", &n1);
        if(n1 > 0 && n1 < lst->size){
            break;
        }
        else{
            printf("Wrong value! Try again...");
        }
    }

void push_front(struct db_linked_lst *list, char *data){
    struct Node *temp = malloc(sizeof (node));
    if (temp == NULL){
        exit(1);//end process
    }
    strcpy(temp->data, data);
    temp->next = list->head;
    temp->prev = NULL;
    if (list->head){ //if there is head add pointer to new node
        list->head->prev=temp;
    }
    list ->head=temp; //move head pointer to last new node
    if(list->tail==NULL){//if there is no tail
        list->tail=temp;
    }
    list->size++;
}
 */




