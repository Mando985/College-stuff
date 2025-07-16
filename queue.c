#include <stdio.h>
int list[8];
int front=-1;
int rear=-1;
int len=sizeof(list)/sizeof(list[0]);

    void enqueue(int value)
    {
        if(rear==len-1)
        {
            printf("The queue is overflowing\n");
        }
        else
        {
            front=0;
            rear+=1;
            list[rear]=value;
            printf("%d added to the queue\n",value);
        }
    }

    void dequeue()
    {
        if(front==-1 || front>rear)
        {
            printf("The queue is underflowing\n");

        }
        else
        {
            printf("Dequeueing %d from queue...\n",list[front]);
            front++;

        }
    }

    void display()
    {
        if(front==-1 || front>rear)
        {
            printf("The queue is empty\n");
        }
        else{
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",list[i]);
        }
        printf("\n");
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
            int value;
            scanf("%d",&value);
            enqueue(value);

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