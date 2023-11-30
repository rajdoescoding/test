// singly linked list

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *link;
}*start=NULL, *q;



void createnode(int data); 
void display(); 
void insertatbeg(int data);
void insertatpos(int data, int pos);
void insertafterpos(int data, int pos);
void insertatend(int data);
void insertbeforepos(int data, int pos);
void del(int data);
void search(int data);
void reverse(); 
void count();

int main() {
	int i, ch, n, m, p;
	//clrscr();
	while (1) {
		printf("\n1. Create a list\n");
		printf("2. Insert node\n");
		printf("3. Delete node\n");
		printf("4. Search node\n");
		printf("5. Reverse list\n");
		printf("6. Modify list\n");
		printf("7. Count\n");
		printf("8. Display\n");
		printf("9. Quit\n");
		printf("Enter the choice: ");
		scanf("%d", &ch);

		switch (ch) {
			case 1:
				printf("How many nodes you want to enter: ");
				scanf("%d", &n);
				for (i = 0; i < n; i++) {
					printf("Enter the data for %d node: ", i + 1);
					scanf("%d", &m);
					createnode(m);
				}
				break;


			case 2: {
				int ch1;
				printf("1. Insert at beg\n");
				printf("2. Insert at position\n");
				printf("3. Insert before postion\n");
				printf("4. Insert after position\n");
				printf("5. Inset at end\n");
				printf("Enter your choice: ");
				scanf("%d",&ch1);
				switch(ch1) {
					case 1:
						printf("Enter your info: ");
						scanf("%d", &m);
						insertatbeg(m);
						break;

					case 2:
						printf("-Enter postion: ");
						scanf("%d",&p);
						printf("-Enter data: ");
						scanf("%d",&m);
						insertatpos(m, p);
						break;
						
					case 3: 
						printf("Enter the element to be inserted: ");
						scanf("%d", &m);
						printf("Enter the element before which to insert: ");
						scanf("%d", &p);
						insertbeforepos(m, p);
						break;
						
					case 4: 
						printf("-Enter position: ");
						scanf("%d",&p);
						printf("-Enter data: ");
						scanf("%d", &m);
						insertafterpos(m, p);
						break;
						
					case 5:
						printf("Enter your info: ");
						scanf("%d", &m);
						insertatend(m);
						break;
						
					default:
						printf("\nWrong Choice.\n");
						break;
				}
			}
			break;

			case 3: {
				printf("Which node you want to delete: ");
				scanf("%d", &m);
				del(m);
			}
			break;

			case 4: {
				printf("Enter the search data: ");
				scanf("%d", &m);
				search(m);
			}
			break;

			case 5:
				reverse();
				break;

			case 6:
				printf("Modify");
				break;
				
			case 7:
				count();
				break;

			case 8:
				display();
				break;

			case 9:
				exit(0);

			default:
				printf("\nWrong choice.\n");
				break;
		}
	}
}

void reverse() {
	struct node *p1, *p2, *p3;
	if (start->link == NULL) {
		printf("%d", start->link);
		return;
	} else {
		p1 = start;
		p2 = p1->link;
		p3 = p2->link;
		p1->link = NULL;
		p2->link = p1;
		while (p3 != NULL) {
			p1 = p2;
			p2 = p3;
			p3 = p2->link;
			p2->link = p1;
		}
		start = p2;
	}
	q=start;
	while(q != NULL) {
		printf("\n %d", q->info);
		q=q->link;
	}

}

void del(int data) {
	struct node *tmp, *q;
	if (start->info == data) {
		tmp=start;
		start=start->link;
		free(tmp);
		return;
	}
	q=start;
	while (q->link->link != NULL) {
		if (q->link->info == data) {
			tmp=q->link;
			q->link = tmp->link;
			free(tmp);
			return;
		}
		q=q->link;
	}
	if (q->link->info == data) {
		tmp = q->link;
		q->link == NULL;
		free(tmp);
		return;
	}
	printf("The data is not found.\n");
}

void search(int data) {
	int p=1;
	q=start;
	while(q!=NULL) {
		if (q->info == data) {
			printf("Data is found on %d position: \n",p);
			return;
		}
		q=q->link;
		p++;
	}
	if (q==NULL) {
		printf("Search not found.\n");
	}
}


void insertbeforepos(int data, int pos) {
	struct node *tmp, *q;
	if (start == NULL) {
		printf("List is empty.\n");
		return;
	}
	
	//	if data to be inserted before first  node
	if (data == start->info) {
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp->info = data;
		tmp->link = start;
		start=tmp;
		return;
	}
}

void insertatpos(int data, int pos) {
	struct node *tmp, *q;
	int i;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	if (pos == 1) {
		tmp->link = start;
		start=tmp;
		return;
	}
	q=start;
	for (i=1; i<pos-1 && q!=NULL; i++) {
		q=q->link;
	}
	if (q==NULL) {
		printf("There are less than &d elements: ",pos);
	}else {
		tmp->link = q->link;
		q->link = tmp;
	}
}

void insertafterpos(int data, int pos) {
	struct node *tmp, *q;
	int i;
	q=start;
	for (i=0; i<pos-1;i++) {
		q=q->link;
		if (q == data) {
			printf("There are less than %d elements",pos);
			return;
		}
	}
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = q->link;
	q->link = tmp;
	return;
}

void insertatend(int data) {
	struct node *tmp, *q;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	q=start;
	while (q != NULL) {
		q=q->link;
	}
	q->link = tmp;
	tmp->link=NULL;
}

void insertatbeg(int data) {
	struct node *tmp;
	tmp=malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
}

void createnode(int data) {
	struct node *tmp;
	tmp = malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = NULL;
	if (start == NULL) {
		start = tmp;
	} else {
		q = start;
		while (q->link != NULL) {
			q = q->link;
		}
		q->link = tmp;
	}
}

void display() {
	q=start;
	if(start == NULL) {
		printf("List is empty.\n");
		return;
	} else {
		printf("\n %d", q->info);
		while (q->link != NULL) {
			q = q->link;
			printf("\n %d", q->info);
		}
		printf("\n");
	}

}

void count() {
	int c = 0;
	q=start;
	while (q != NULL) {
		c++;
		q=q->link;
	}
	printf("Total number of nodes are %d.",c);
}