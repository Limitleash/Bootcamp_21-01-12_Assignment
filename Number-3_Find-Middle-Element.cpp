#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
    char name[100+1];
    int score;
    Student *next;
}*head, *tail;

Student *createNew(const char *name, int score){
    Student *newList = (Student *) malloc(sizeof(Student));
    strcpy(newList->name, name);
    newList->score = score;
    newList->next = NULL;
    return newList;
}

void add_List(const char *name, int score){
    Student *newList = createNew(name, score);
    if(head == NULL){
        head = tail = newList;
    }
    else{
        tail->next = newList;
        tail = newList;
    }
}

void print_List(){
    Student *current = head;
    printf("List: ");
    while(current != NULL){
        printf("%s (%d) -> ", current->name, current->score);
        current = current->next;
    }
    puts("NULL");
}

void print_middle_element(int middle, int n){
    Student *result = head;
    while(middle > 1){
        result = result->next;
        middle--;
    }
    printf("Middle Element: %s (%d)", result->name, result->score);
    if(n % 2 == 0){
        result = result->next;
        printf(" & %s (%d)", result->name, result->score);
    }
    puts("");
}

int main(){
    int middle = 0, n;
    printf("Amount of Student: ");
    scanf("%d", &n);
    getchar();
    char name[100+1];
    int score;
    for(int i=0; i<n; i++){
        if(i % 2 == 0){
            middle++;
        }
        printf("Student %d-th:\n", i+1);
        printf("Name\t: ");
        scanf("%[^\n]", name);
        getchar();
        printf("Score\t: ");
        scanf("%d", &score);
        getchar();
        add_List(name, score);
        puts("");
    }
    print_List();
    print_middle_element(middle, n);
    return 0;
}