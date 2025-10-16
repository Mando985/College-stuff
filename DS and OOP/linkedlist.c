#include <stdio.h>
#include <stdlib.h>

struct node {

	int data;
	struct node *next;
	};

struct node* head=NULL;

struct node* createnode(int val){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
	}
	
void insert_b(int val){
	struct node* newnode= createnode(val);
	newnode->next=head;
	head=newnode;
	}
	
void insert_e(int val){
	struct node* temp = head;
	struct node* newnode=createnode(val);
	if(head==NULL){
		head=newnode;
		return;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;

	}

void insert_pos(int val, int pos){
	struct node* newnode= createnode(val);
	
	if (pos==1){
	newnode->next=head;
	head=newnode;
	return;
	}
	
	struct node* temp=head;

	for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    	}	
    	
    	if(temp==NULL){
    	printf("Position out of range!\n");
        free(newnode);
        return;
    	}
    	
    	newnode->next=temp->next;
    	temp->next=newnode;
    	}
    	
    	
void del_b() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* temp = head;
    head = temp->next;
    free(temp);
}

void del_e() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void del_pos(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (pos == 1) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }
    struct node* del = temp->next;
    temp->next = del->next;
    free(del);
}

void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("[ %d ]-> ", temp->data);
        temp = temp->next;
    }
    printf("[ NULL ]\n");
}

int main() {
    int opt, value, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("[1] Insert at Beginning\n");
        printf("[2] Insert at End\n");
        printf("[3] Insert at Specific Position\n");
        printf("[4] Delete from Beginning\n");
        printf("[5] Delete from End\n");
        printf("[6] Delete at Specific Position\n");
        printf("[7] Display\n");
        printf("[0] Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_b(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_e(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insert_pos(value, pos);
                break;
            case 4:
                del_b();
                break;
            case 5:
                del_e();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                del_pos(pos);
                break;
            case 7:
                display();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
    
