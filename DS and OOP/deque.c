#include <stdio.h>
#include <stdlib.h>
#define size 5
int deque[size];
int front=-1;
int rear=-1;

void insertfront(int x){
	if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Deque Overflow!\n");
	}
	else{
	    if (front == -1) { 
		front = rear = 0;
	    } else if (front == 0) {
		front = size - 1;
	    } else {
		front--;
	    }
	    deque[front] = x;
	}
}

void rearinsert(int x){

if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Deque Overflow!\n");
        return;
    }
    else{
	    if (front == -1) {
		front = rear = 0;
	    } else if (rear == size - 1) {
		rear = 0;
	    } else {
		rear++;
	    }
	    deque[rear] = x;
	}

}

void deletefront() {
    if (front == -1) {
        printf("Deque Underflow!\n");
        return;
    }
    printf("Deleted: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }
}



void deleterear() {
    if (front == -1) {
        printf("Deque Underflow!\n");
        return;
    }
    printf("Deleted: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear--;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

void inputresmenu() {
    int choice, x;
    while (1) {
        printf("\n--- Input Restricted Deque ---\n");
        printf("1. Insert at Rear\n");
        printf("2. Delete from Front\n");
        printf("3. Delete from Rear\n");
        printf("4. Display\n");
        printf("5. Exit to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &x); rearinsert(x); break;
            case 2: deletefront(); break;
            case 3: deleterear(); break;
            case 4: display(); break;
            case 5: return;
            default: printf("Invalid choice!\n");
        }
    }
}

void outputresmenu() {
    int choice, x;
    while (1) {
        printf("\n--- Output Restricted Deque ---\n");
        printf("1. Insert at Rear\n");
        printf("2. Insert at Front\n");
        printf("3. Delete from Front\n");
        printf("4. Display\n");
        printf("5. Exit to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &x); rearinsert(x); break;
            case 2: printf("Enter value: "); scanf("%d", &x); insertfront(x); break;
            case 3: deletefront(); break;
            case 4: display(); break;
            case 5: return;
            default: printf("Invalid choice!\n");
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n=== Deque Menu ===\n");
        printf("1. Input Restricted Deque\n");
        printf("2. Output Restricted Deque\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: inputresmenu(); break;
            case 2: outputresmenu(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
