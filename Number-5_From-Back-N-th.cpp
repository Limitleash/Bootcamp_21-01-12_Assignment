#include<stdio.h>
#include<stdlib.h>

struct Info{
    int num;
    Info *next;
} *head = NULL, *tail = NULL;

void add_list(int num){
    Info *newList = (Info *) malloc(sizeof(Info)*1);
    newList->num = num;
    newList->next = NULL;

    if(head == NULL){
        head = tail = newList;
    }
    else{
        tail->next = newList;
        tail = newList;
    }
}

void find_n_th_elements(){
    puts("\nLook for ...-th elements from back?");
    printf("Answer: ");
    int num, answer, count = 1;
    scanf("%d", &answer);
    Info *temp = head, *current = head;
    while(temp != NULL){
        if(count >= answer){
            num = current->num;
            current = current->next;
        }
        count++;
        temp = temp->next;
    }
    printf("The %d-th Elements from back is %d\n", answer, num);
}



void print_List(){
    Info *current = head;
    printf("List: ");
    while(current != NULL){
        printf("%d -> ", current->num);
        current = current->next;
    }
    puts("NULL");
}

int main(){
    int n;
    printf("Amount of Elements: ");
    scanf("%d", &n);
    getchar();
    int num;
    for(int i=0; i<n; i++){
        printf("Elements %d-th: ", i+1);
        scanf("%d", &num);
        add_list(num);
    }
    print_List();
    find_n_th_elements();
    return 0;
}