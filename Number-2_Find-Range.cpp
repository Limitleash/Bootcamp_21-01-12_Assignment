#include<stdio.h>
#include<stdlib.h>

struct Info{
    int num;
    Info *next;
}*head = NULL, *tail = NULL;

Info *createMemory(int num){
    Info *newInfo = (Info *) malloc(sizeof(Info));
    newInfo -> num = num;
    newInfo -> next = NULL;
    return newInfo;
}

void add_list(int num){
    Info *newInfo = createMemory(num);
    if(head == NULL){
        head = tail = newInfo;
    }
    else{
        tail -> next = newInfo;
        tail = newInfo;
    }
}

void print_list(){
    Info *current = head;
    printf("List: ");
    while(current != NULL){
        printf("%d -> ", current -> num);
        current = current->next;
    }
    puts("NULL");
}

void print_range(){
    Info *current = head;
    int min = current->num, max = current->num;
    current = current->next;
    for(;current != NULL; current = current->next){
        if(current->num > max){
            max = current->num;
        }
        if(current->num < min){
            min = current->num;
        }
    }
    printf("Range (%d-%d): %d\n", max, min, max-min);
}

int main(){
    int n, num;
    printf("Amount of Numbers: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Number %d-th: ", i+1);
        scanf("%d", &num);
        add_list(num);
    }
    print_list();
    print_range();
    return 0;
}