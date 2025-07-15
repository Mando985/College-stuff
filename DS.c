#include <stdio.h>


    void enqueue(int list[],int front,int rear,int value,int len)
    {
        if(rear==len-1)
        {
            printf("The queue is overflowing\n");
        }
        else
        {
            front=0;
            rear++;
            list[rear]=value;
            printf("%d added to the queue\n",value);
        }
    }

    void dequeue(int list[],int front, int rear)
    {
        if(front==-1 || front<rear)
        {
            printf("The queue is underflowing\n");

        }
        else
        {
            front++;
        }
    }

    void display(int list[],int front, int rear)
    {
        if(front==-1)
        {
            printf("The queue is empty\n");
        }
        else{
        for(int i=front;i<rear;i++)
        {
            printf("%d ",list[i]);
        }
        }
    }


int main()
{
    int list[8];
    int front,rear=-1;
    int len=sizeof(list);

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
            enqueue(list,front,rear,value,len);
        }
        else if (opt==2)
        {
            display(list,front,rear);
        }
        else if (opt==3)
        {
            dequeue(list,front,rear);
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