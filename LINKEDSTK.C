#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};

struct node *head=NULL;
void push()
{
	int val;
	printf("ENTER THE VALUE");
	scanf("%d",&val);

		struct node *newnode=(struct node *)(malloc(sizeof(struct node)));
		newnode->data=val;
		newnode->link=head;
		head=newnode;
		printf("node added");
	
	


}
void pop()
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("NO ELEMENTS ");
	}
	else
	{
	 head=head->link;
	 free(temp);
	 printf("DELETED");
	 
	}

}
void display()
{
     if(head==NULL)
     {
	printf("UNDER FLOW");
     }
     else
     {
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("[%d]->",temp->data);
		temp=temp->link;
	}
     }
}
void line()
{
	printf("\n***********************+++++++++++++++++++++\n");
}
int main()
{
	
	int ch;
	while(1)
	{
	line();
	printf("\nMENU\n1.PUSH()\n2.POP()\n3.DISPLAY()\n4.exit\n");
	scanf("%d",&ch);

	switch(ch)
	{
	case 1:
		push();
		break;
	case 2:
		pop();
		break;
	case 3:
		line();
		display();
		line();
		break;
	case 4:
		return 0;
	}
	line();
	}
}