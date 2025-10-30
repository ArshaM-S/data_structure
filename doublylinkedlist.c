#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
int data;
struct node*Llink;
struct node*Rlink;
};
struct node*head=NULL;
void insertFirst()
{
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
printf("\nNo space available");
return;}
newnode->Llink=NULL;
newnode->Rlink=NULL;
printf("\nEnter the element to insert");
scanf("%d",&newnode->data);
if(head==NULL)
{
head=newnode;
}
else{
newnode->Rlink=head;
head->Llink=newnode;
head=newnode;
}
printf("\n%d inserted successfully",newnode->data);
}
void insertLast()
{
struct node*newnode,*temp=head;
newnode=(struct node*)malloc(sizeof (struct node));
if(newnode==NULL)
{printf("\nError:No space available for a new node.\n");
return;
}
newnode->Llink=NULL;
newnode->Rlink=NULL;
printf("\nEnter the element to insert");
scanf("%d",&newnode->data);
if(head==NULL)
{head=newnode;
}
else{
while(temp->Rlink!=NULL)
{
temp=temp->Rlink;
}
newnode->Llink=temp;
temp->Rlink=newnode;
}
printf("%d inserted successfully",newnode->data);
}
void display()
{
struct node*temp=head;
if(head==NULL)
{printf("\nNo elements in list");
return;}
else{
printf("\n**Elements in the list**\n");
while(temp!=NULL)
{
printf("%d",temp->data);
temp=temp->Rlink;
}}}
void insertLocation()
{
struct node*newnode,*temp=head,*nxt;
int key;
newnode=(struct node*)malloc(sizeof (struct node));
if(newnode==NULL)
{
printf("\nError:No space available for a new node\n");
return;
}
if(head==NULL)
{
printf("\n List is empty\n");
}
else{
printf("\nEnter the key were after you want to insert the element\n");
scanf("%d",&key);
while(temp!=NULL &&temp->data!=key)
{temp=temp->Rlink;
}
if(temp==NULL)
{
printf("\nNo element found\n");
return;
}
printf("\nEnter the element to insert\n");
scanf("%d",&newnode->data);
if(temp->Rlink==NULL)
{
newnode->Llink=temp;
newnode->Rlink=NULL;
temp->Rlink=newnode;
}
else{
nxt=temp->Rlink;
newnode->Llink=temp;
newnode->Rlink=nxt;
temp->Rlink=newnode;
nxt->Llink=newnode;
}
printf("%d inserted successfully",newnode->data);
}}
void deleteFirst()
{
struct node*temp=head,*nxt;
if(head==NULL)
{
printf("\nList Empty\n");
return;
}
printf("\n%d is deleted",temp->data);
if(temp->Rlink==NULL)
{
head=NULL;
}
else{
nxt=temp->Rlink;
head=nxt;
nxt->Llink=NULL;
}
free(temp);
}
void deleteLast()
{
struct node*temp=head,*nxt;
if(head==NULL)
{
printf("\nList is empty\n");
return;}
if(temp->Rlink==NULL)
{
printf("\n%d is deleted",temp->data);
head=NULL;
}
else{while(temp->Rlink!=NULL)
{
temp=temp->Rlink;
}
printf("\n%d is deleted",temp->data);
nxt=temp->Llink;
nxt->Rlink=NULL;}
free(temp);}
void deleteLocation()
{
struct node*temp=head,*prev,*nxt;
int key;
if(head==NULL)
{
printf("\nList is Empty\n");
return;}
printf("\nEnter the key which you want to delete:\n");
scanf("%d",&key);
while(temp!=NULL&&temp->data!=key)
{
temp=temp->Rlink;}
if(temp==NULL)
{
printf("\nNO element found\n");
return;}
if(temp->Llink==NULL)
{head=temp->Rlink;
if(head!=NULL)
{head->Llink=NULL;
}}
else if(temp->Rlink==NULL)
{
temp->Llink->Rlink=NULL;}
else{
prev=temp->Llink;
nxt=temp->Rlink;
prev->Rlink=nxt;
nxt->Llink=prev;}
printf("%dDeleted successfully\n",temp->data);
free(temp);}
void search()
{
int key,pos=1,found=0;
struct node*temp=head;
if(head==NULL)
{
printf("\nList Empty\n");
return;}
printf("\nEnter the key to search");
scanf("%d",&key);
while(temp!=NULL)
{if(temp->data==key)
{
printf("%d is found at location %d",temp->data,pos);
found=1;
}
temp=temp->Rlink;
pos++;
}
if(!found)
{
printf("\n Element not found\n");
}}
void main()
{
int choice;
do{
printf("\n*****Doubly Linkedlist*****\n");
printf("\n1->InsertFirst\n2->Insertlast\n3->InsertLocation\n4->DeleteFirst\n5->Deletelast\n6->DeleteLocation\n7->Search\n8->Display\n9->Exit");
printf("\nEnter choice:\n");
scanf("%d",&choice);
switch(choice)
{
case 1:insertFirst();
break;
case 2: insertLast();
break;
case 3: insertLocation();
break;
case 4:deleteFirst();
break;
case 5:deleteLast();
break;
case 6:deleteLocation();
break;
case 7:search();
break;
case 8:display();
break;
case 9:printf("\nExit\n");
exit(0);
default:printf("\nEnter valid choice\n");
}}
while(choice!=9);}




