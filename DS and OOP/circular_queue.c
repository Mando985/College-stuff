#include <stdio.h>
//enqueue,dequeue,display

int list[4];
int rear=-1;
int front=-1;
int len=4;

void enqueue()
{
    if(front==((rear+1)%len))
    {
        printf("The queue is overflowing\n");
        return;
    }
    else if(front==-1)
    {
        front=0;
    }
    rear=(rear+1)%len;
    printf("Enter the element\n=>");
    scanf("%d",&list[rear]);
    printf("Element %d inserted\n",list[rear]);
}

void display()
{
    if(front==-1)
    {
        printf("cant cuz list empty foo\n");
    }
    else
    {
    int i=front;
    while(1)
    {
        printf("%d ",list[i]);
        if(i==rear) break;
        i=(i+1)%len;

    }
    printf("\n");
    }
}

void dequeue()
{
    if (front == -1) {
        printf("Queue is already empty\n"); 
        return;
    }

    printf("Dequeuing element: %d\n", list[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % len;
    }
}



int main()
{
    char flag='t';
    while(flag=='t')
    {
        printf("Choose your option:\n[1]Add element\n[2]Show queue\n[3]Delete element\n[0]Exit\n=>");
        int opt;
        scanf("%d",&opt);
        if(opt==1)
        {   
            printf("Enter the value of the element\n=>");
            enqueue();

        }
        else if (opt==2)
        {
            display();
        }
        else if (opt==3)
        {
            dequeue();
        }
        else if (opt==0)
        {
            printf("Exiting....");
            flag='f';
        }
        else
        {
            printf("Enter a valid option\n");
        }

    }
    return 0;
}