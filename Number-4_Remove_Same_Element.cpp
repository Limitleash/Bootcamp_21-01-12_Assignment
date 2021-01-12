#include<stdio.h>
#include<stdlib.h>

struct Elements{
    int num;
    Elements *next;
}*start, *end;

void add_List(int num){
    Elements *newList = (Elements *) malloc(sizeof(Elements));
    (*newList).num = num;
    (*newList).next = NULL;

    if(start == NULL){
        start = end = newList;
    }
    else{
        end->next = newList;
        end = newList;
    }
}


void remove_same_elements(){
    Elements *element1 = start;
    Elements *element2 = element1->next;
    while(element2 != NULL){
        if(element1->num == element2->num){
            Elements *temp = (*element2).next;
            (*element1).next = (*element2).next;
            (*element2).next = NULL;
            free(element2);
            element2 = temp;
        }
        else{
            element1 = element2;
            element2 = element2->next;
        }
    }
}

void print_List(){
    Elements *current = start;
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
        add_List(num);
    }
    printf("\nFrom:\n");
    print_List();
    remove_same_elements();
    printf("\nBecome\n");
    print_List();
    return 0;
}