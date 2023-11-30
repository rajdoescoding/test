// circular linked list
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct node {
	int info;
	struct node *link;
}*last=NULL, *q;

void createnode(int data);
void display();
void del(int data);
void insertatbeg(int data);
void insertafterpos(int data, int pos);

void main() {
	int i, n, m, ch, p;
	while (1) {
		printf("\n1. Create a list\n");
		printf("2. Insert node\n");
		printf("3. Delete node\n");
		printf("4. Display\n");
		printf("5. Quit\n");
		
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch) {
			case 1:
				{
					printf("-How many nodes you want to enter: ");
					scanf("%d", &n);
					for (i = 0; i < n; i++) {
						printf("-Enter the data for %d node: ", i + 1);
						scanf("%d", &m);
						createnode(m);
					}
				}
				break;
				
			case 2:
				{
					int ch1;
					printf("1. Insert at beg\n");
					printf("2. Insert after position\n");
					printf("Where you want to insert: ");
					scanf("%d", &ch1);
					switch(ch1) {
						case 1:
							{
								printf("-Enter data: ");
								scanf("%d", &m);
								insertatbeg(m);
							}
							break;
							
						case 2:
							{
								printf("-Enter postion: ");
								scanf("%d",&p);
								printf("-Enter data: ");
								scanf("%d",&m);
								insertafterpos(m, p);
							}
							break;
						
						default:
							printf("\nWrong choice.\n");
							break;
					}
				}
				break;
				
			case 3:
				{
					printf("Which node you want to delete: ");
					scanf("%d", &m);
					del(m);
				}
				break;
				
			case 4:
				display();
				break;
				
			case 5:
				exit(0);
				break;
				
			default:
				printf("\nWrong choice.\n");
				break;
		}
	}
}

void insertatbeg(int data) {
	struct node *tmp;
	tmp = malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = last->link;
	last->link = tmp;
}

void insertafterpos(int data, int pos) {
	struct node *tmp;
	q=last->link;
	for (int i=0; i<pos-1; i++) {
		q=q->link;
		if (q==last->link) {
			printf("Position not found.\n");
			return;
		}
	}
	tmp = malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = q->link;
	q->link = tmp;
	if (q == last) {
		tmp->link = last->link;
		q->link = tmp;
		last=tmp;
	}
}

void del(int data) {
	struct node *tmp;
	q=last->link;
	
	//	deleting first node
	if (q->link == last->link && q->info == data) {
		tmp=q;
		free(tmp);
		return;
	}
	
	if (q->info == data) {
		tmp=last->link;
		last->link = q->link;
		free(tmp);
		return;
	}
	
	//	in between
	while (q->link != last) {
		if (q->link->info == data) {
			tmp=q->link;
			q->link = tmp->link;
			free(tmp);
			return;
		}
		q=q->link;
	}	
	
	//	last node
	if (q->link == last && q->link->info == data) {
		tmp=q->link;
		q->link = tmp->link;
		last = q;
		free(tmp);
		return;
	}
	
	printf("Node not found.\n");
}

void display() {
	q=last->link;
	do {
        printf("\n %d", q->info);
        q = q->link;
    } while (q != last->link);
}

void createnode(int data) {
	struct node *tmp;
	tmp = malloc(sizeof(struct node));
	tmp->info = data;
	if (last == NULL) {
		last = tmp;
		tmp->link = last;
	}
	tmp->link = last->link;
	last->link = tmp;
	last = tmp;
}