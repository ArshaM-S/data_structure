#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
int isFull()
{
if((rear+1)%MAX==front)
{
return 1;
}
return 0;
}
int isEmpty()
{
if(front==-1&&rear==-1)
{
return 1;
} 
return 0;
}
void display()
{
int i;
if(isEmpty())
{
printf("\n QUEUE IS EMPTY \n");
return;
}
printf("\n QUEUE ELEMENTS: ");
i=front;
do
{
printf("%d ",queue[i]);
i=(i+1)%MAX;
}
while(i!=(rear+1)%MAX);
printf("\n");
}
void dequeue()
{
if(isEmpty())
{
printf("\n QUEUE IS Empty\n");
return;
}
printf("\n %d is DELETED \n",queue[front]);
if(front==rear)
{
front=rear=-1;
}
else
{
front=(front+1)%MAX;
}
}
void enqueue()
{
int x;
if(isFull())
{
printf("\n QUEUE IS FULL\n");
return;
}
printf("Enter the element to insert: ");
scanf("%d",&x);
if(isEmpty())
{
front=rear=0;
}
else
{
rear=(rear+1)%MAX;
}
queue[rear]=x;
printf("\n ELEMENT %d INSERTED SUCCESSFULLY \n",queue[rear]);
}
void search()
{
int key,i,found=0;
if(isEmpty())
{
printf("\n QUEUE IS EMPTY \n");
return;
}
printf("\n Enter the element to search: ");
scanf("%d",&key);
i=front;
do
{
if(queue[i]==key)
{
printf("\n ELEMENT %d FOUND AT POSITION %d.\n",key,i+1);
found=1;
break;
}
i=(i+1)%MAX;
}
while(i!=(rear+1)%MAX);
if(!found)
{
printf("\n Element %d not found in the queue \n",key);
}
}
int main()
{
int choice;
printf("\n CIRCULAR QUEUE USING ARRAY\n");
do
{
printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.SEARCH\n5.EXIT\n");
printf("ENTER YOUR CHOICE: ");
scanf("%d",&choice);
switch(choice)
{
case 1:enqueue();
break;
case 2:dequeue();
break;
case 3:display();
break;
case 4:search();
break;
case 5:printf("\nExiting...\n");
return 0;
default:printf("\n INVALID CHOICE\n");
break;
}
}
while(choice!=5);
return 0;
}

