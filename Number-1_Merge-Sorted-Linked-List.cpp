#include<stdio.h>
#include<stdlib.h>

struct Student{
    int num;
    Student *navigate;
}*head = NULL, *tail = NULL, *head2 = NULL, *tail2 = NULL, *head_merged = NULL, *tail_merged = NULL;

Student *createList(int num){
    Student *newList = (Student *) malloc(sizeof(Student));
    (*newList).num = num;
    (*newList).navigate = NULL;
    return newList;
}

void add_tail(int num){
    Student *newList = createList(num);
    if(head == NULL){
        head = tail = newList; 
    }
    else{
        (*tail).navigate = newList;
        tail = newList;
    }
}

void add_tail2(int num){
    Student *newList = createList(num);
    if(head2 == NULL){
        head2 = tail2 = newList; 
    }
    else{
        (*tail2).navigate = newList;
        tail2 = newList;
    }
}

void add_tail_merged(int num){
    Student *newList = createList(num);
    if(head_merged == NULL){
        head_merged = tail_merged = newList; 
    }
    else{
        (*tail_merged).navigate = newList;
        tail_merged = newList;
    }
}

void print_student_list(){
    Student (*current) = head;
    printf("List 1: ");
    while(current != NULL){
        printf("%d -> ", (*current).num);
        current = (*current).navigate;
    }
    puts("NULL");
    current = head2;
    printf("List 2: ");
    while(current != NULL){
        printf("%d -> ", (*current).num);
        current = (*current).navigate;
    }
    puts("NULL");
}

void merge_linked_list(){
    Student (*current1) = head, (*current2) = head2;
    while(current1 != NULL && current2 != NULL){
        if((*current1).num > (*current2).num){
            add_tail_merged((*current2).num);
            current2 = (*current2).navigate;
        }
        else{
            add_tail_merged((*current1).num);
            current1 = (*current1).navigate;
        }
    }
    while(current1 != NULL){
        add_tail_merged((*current1).num);
        current1 = (*current1).navigate;
    }
    while(current2 != NULL){
        add_tail_merged((*current2).num);
        current2 = (*current2).navigate;
    }
    current1 = head_merged;
    printf("Merged List: ");
    while(current1 != NULL){
        printf("%d -> ", (*current1).num);
        current1 = (*current1).navigate;
    }
    puts("NULL");
}

int main(){
	int n1, n2;
    printf("mulai\n");
    // for(;;){
    //     scanf("%d", &n1);
    //     add_head(n1);
    //     print_student_list();
    // }
    printf("Amount of Linked List 1: ");
    scanf("%d", &n1);
    printf("Amount of Linked List 2: ");
    scanf("%d", &n2);
    int num;
    for(int i=0; i<n1; i++){
        printf("Num #%d of Linked List 1: ", i+1);
        scanf("%d", &num);
        add_tail(num);
    }
    for(int i=0; i<n2; i++){
        printf("Num #%d of Linked List 2: ", i+1);
        scanf("%d", &num);
        add_tail2(num);
    }
    print_student_list();
    merge_linked_list();
	return 0;
}