#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Data Data;
typedef struct Node *PNode;

struct Data
{
    int index;
    double min;
    double max;
};

struct Node
{
    Data data;
    PNode next;
};

PNode insert(PNode list, Data item) {
    PNode temp = (PNode) malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = NULL;

    //Case 1: list is Empty
    if (list == NULL) {
        return temp;
    }

    //Case 2: To be inserted first (trivial case)
    if (item.index < list->data.index) {
        temp->next = list;
        return temp;
    }

    //Case 3: General (Need to go only the needed node, join Temp to the node after it and join that node to Temp, placing temp in between)
    PNode current = list;
    while (current->next != NULL && current->next->data.index < item.index) {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;

    return list;
}

PNode delete(PNode list, int index) {
    //Case 1: List is Empty
    if (list == NULL) {
        return NULL;
    }
    PNode temp = list;

    //Case 2: First Node contains the index
    if (temp->data.index == index) {
        list = temp->next; 
        free(temp);        
        return list;
    }

    //Case 3: General (Need to track previous node to join with node after current node, removing current off the list)
    PNode prev = NULL;
    while (temp != NULL && temp->data.index != index) {
        prev = temp;       
        temp = temp->next; 
    }

    //Case 4: Node not Found
    if (temp == NULL) {
        return list;
    }

    prev->next = temp->next;
    free(temp); 

    return list;
}


void display(PNode list){
  PNode temp;
  temp = list;
  printf("day\tmin\tmax\n");
  if(list==NULL){
    return;
  }
  while(temp){
    printf("%d\t%lf\t%lf\n",(temp->data).index, (temp->data).min, (temp->data).max);
    temp=temp->next;
  }
  printf("\n");
}


int main()
{
    PNode list = NULL;
    do
    {
        char command[100];
        int index;
        double min, max;
        printf("Enter command:");
        scanf("%s", command);
        if(!strcmp(command,"A")) {
            scanf("%d", &index);
            scanf("%lf", &min);
            scanf("%lf", &max);
            Data item;
            item.index=index; item.min=min; item.max=max; 
            list = insert(list, item);
        }
        else if(!strcmp(command,"D")) {
            scanf("%d", &index);
            list = delete(list,index);
        }
        else if(!strcmp(command,"P")) {
            display(list);
        }
        else if(!strcmp(command,"Q")) {
            return 0;
        }
        else {
           printf("Invalid Command\n");
        }
    } while (1);
    return 0;
}