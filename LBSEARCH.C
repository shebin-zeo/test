#include <stdio.h>
#include <conio.h>

void linear(int a[10],int n,int num);
void binary(int a[10],int n,int num);

void main(){

	int a[10],n,i,num,ch;
	clrscr();

	printf("Enter size of Array\n");
	scanf("%d",&n);

	printf("Enter %d numbers\n",n);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}

	printf("The array is\n\t");

	for(i=0;i<n;++i){
		printf("%d ",a[i]);
	}
	printf("\nEnter value to be searched\n");
	scanf("%d",&num);
	printf("Enter Choice for searching\n1.Linear Search\n2.Binary Search\n");
	scanf("%d",&ch);
	switch(ch){

		case 1: linear(a,n,num);
			break;
		case 2:binary(a,n,num);
			break;
		default: break;
	}

	getch();
}

void linear(int a[],int n,int num){

	int flag=0,i;
	for(i=0;i<n;++i){
		if(a[i]==num){
			printf("%d found at position %d\n",num,i+1);
			flag=1;
			break;
		}

	}
	if(flag==0){
		printf("\n%d not found\n",num);
	}



}


void binary(int a[],int n,int num){

	 int i,j,low,high,mid,temp,flag=0;

	//Sort

	for(i=0;i<n-1;++i){
		for(j=i+1;j<=n;++j){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}

		}
	}
		printf("\nSorted array is\n\t");

	for(i=0;i<n;++i){
		printf("%d ",a[i]);
	}
	low=0;
	high=n-1;

	for(i=low;i<=high;++i){

		mid=(low+high)/2;

		if(a[mid]==num){
			printf("\n%d found at position %d\n",num,mid+1);
			flag=1;
			break;
		}
		else if(num<a[mid]){
			high=mid-1;
		}
		else{
			low=mid+1;
		}

	}

	if(flag==0){
		 printf("\n%d not found\n",num);
	}
}