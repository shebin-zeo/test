#include<stdio.h>
#include<conio.h>

//functions declared
void enqueue();
void dequeue();
void display();

int limit,queue[30],ele,f=-1,r=-1; //variables declared

//main function
int main()
{
	int ch;
	clrscr();
	printf("ENTER THE LIMIT");
	scanf("%d",&limit);       //gets limit,size of circular queue

	while(1)   //while loop starts
	{
	    printf("\nMENU\n1.ENQUEUE()\n2.DEQUEUE()\n3.DISPLAY()\n4.EXIT()");
	    scanf("%d",&ch);       //gets  choice
		switch(ch)//switch starts
		{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			return 0;

		}//switch ends

	}   //while end
}                      //main fn ends

void enqueue()            //push into queue
{
	printf("ENTER THE ELEMENT TO ENTER");
	scanf("%d",&ele); //element enters

	if((r+1)%limit==f)    //checks over flow
	{
		printf("QUEUE OVERFLOW");
	}
	else if(r==-1&&f==-1)   //checks underflow
	{
		r=0;
		f=0;
		queue[r]=ele;
	}
	else
	{
		r=(r+1)%limit;
		queue[r]=ele;
	}

} //enqueue end
void dequeue()  //pop from queue
{
	if(f==-1)
	{
		printf("UNDERFLOW CONDITION");

	}
	else if(f==r)
	{
		queue[f]=NULL;
		f=-1;
		r=-1;
	}
	else
	{
		queue[f]=NULL;
		f=(f+1)%limit;
	}


}//dequeue ends
void display() //display starts
{
	int i;
	if(r==-1)
	{
		printf("QUEUE UNDER FLOW");
	}
	else
	{
		for(i=0;i<limit;++i)
		{
			if(queue[i]==NULL)
			{
				printf("_\t");
			}
			else
			{
				printf("%d\t",queue[i]);
			}
		}
	}

}//display ends