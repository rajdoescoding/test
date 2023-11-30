#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *prev;
    struct node *next;
}*start=NULL, *q;


void createNode(int data);
void display();
void insertatBeg(int data);
void insertatEnd(int data);
void search(int data);
void deleteNode(int data);

int main() {
 int n, m, ch;
 while(1) {
  printf("1. Create node\n");
  printf("2. Insert node\n");
  printf("3. Search\n");
  printf("4. Delete\n");
  printf("5. Display\n");
  printf("6. Quit\n");
  printf("-Enter your choice:");
  scanf("%d", &ch);
  switch(ch) {
   case 1: 
   {
    printf("How many nodes you want to enter: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
     printf("Enter the data for %d node: ", i + 1);
     scanf("%d", &m);
     createNode(m);
    }
   }
   break;
   
   case 2:
    {
     int ch1;
     printf("1. Insert at beg\n");
     printf("2. Insert at end\n");
     printf("-Enter your choice: ");
     scanf("%d", &ch1);
     switch(ch1) {
      case 1:
       printf("-Enter node data: ");
       scanf("%d", &m);
       insertatBeg(m);
       break;
       
      case 2:
       printf("-Enter node data: ");
       scanf("%d", &m);
       insertatEnd(m);
       break;
       
      default:
       printf("Wrong choice.\n");;
       break;
       
     }
     
    }
    break;
    
   case 3: 
    {
     printf("-Enter the search data: ");
     scanf("%d", &m);
     search(m);   
    }
    break;
    
   case 4:
    printf("Enter data to delete: ");
                scanf("%d", &m);
                deleteNode(m);
                break;
   
   case 5: 
    display();
    break;
    
   case 6:
    exit(0);
    break;
   
   default:
    printf("Wrong choice");
    break;
  }
 }
}


// create new node
void createNode(int data) {
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;

    if (start == NULL) {
        start = tmp;
    } else {
        struct node *q = start;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = tmp;
        tmp->prev = q;
    }
}


void display() {
 if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *q = start;
    while (q != NULL) {
        printf("%d \n", q->info);
        q = q->next;
    }
}


void insertatBeg(int data) {
 struct node *tmp;
 tmp = (struct node *)malloc(sizeof(struct node));

    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = start;

    if (start != NULL) {
        start->prev = tmp;
    }

    start = tmp;
    printf("Node with data %d inserted at the beginning.\n", data);
}


void insertatEnd(int data) {
 struct node *tmp;
 tmp = (struct node *)malloc(sizeof(struct node));

    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;

    if (start == NULL) {
        start = tmp;
    } else {
        struct node *current = start;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = tmp;
        tmp->prev = current;
    }

    printf("Node with data %d inserted at the end.\n", data);
}

void search(int data) {
 struct node *q = start;
    int pos = 1;
    while (q != NULL) {
        if (q->info == data) {
            printf("Data %d found at position %d.\n", data, pos);
            return;
        }
        q = q->next;
        pos++;
    }
    printf("Data %d not found in the list.\n", data);
}

void deleteNode(int data) {
    struct node *q = start;
    while (q != NULL) {
        if (q->info == data) {
            if (q->prev != NULL) {
                q->prev->next = q->next;
            } else {
                start = q->next;
            }

            if (q->next != NULL) {
                q->next->prev = q->prev;
            }

            free(q);
            printf("Node with data %d deleted successfully.\n", data);
            return;
        }
        q = q->next;
    }
    printf("Data %d not found in the list. Cannot delete.\n", data);
}


