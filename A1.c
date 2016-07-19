// ----Assignment 1

#include<stdio.h>
#include<string.h>
typedef struct Student
{
	int Roll_No;
	char Name[10];	
}Student;

void Accept(Student S[],int n);
void Display(Student S[], int n);
int Member(Student S[], int x, int n);

int Union(Student A[], Student B[], Student R[], int n2, int n3);
int Intersection(Student A[], Student B[], Student R[], int n2, int n3);
int Difference_A(Student A[], Student B[], Student R[], int n2, int n3);
int Difference_B(Student A[], Student B[], Student R[], int n2, int n3);
int Neither_Nor(Student A[],Student B[], Student M[],Student R[], int n1, int n2, int n3);


int Member(Student S[], int x, int n)
{
	int i;
	for(i=0;i<n;i++)
		if(S[i].Roll_No==x)
			return 1;
	return 0;
}

void Accept(Student S[],int n)
{
	int i,rno;
	char name[10];
	
	printf("\nEnter Roll No :");
	scanf("%d",&S[0].Roll_No);
	printf("\nEnter Name of Student : ");
	scanf("%s",S[0].Name);

	for(i=1;i<n;)
	{
		printf("\nEnter Roll No :");
		scanf("%d",&rno);
		printf("\nEnter Name of Student : ");
		scanf("%s",name);
		if(!Member(S, rno, n))
		{
			S[i].Roll_No=rno;
			strcpy(S[i].Name,name);
			i++;
		}
		
	}
	
}
void Display(Student S[], int n)
{
	int i;
	printf("\nRoll No\tName");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%s", S[i].Roll_No,S[i].Name);
	}
}

int Union(Student A[], Student B[], Student R[], int n2, int n3)
{

	int i,k;
	
	for(k=0;k<n2;k++)
	{
		R[k]=A[k];
	}
	
	for(i=0;i<n3;i++)
	{
		if(!Member(R,B[i].Roll_No,k))
		{
			R[k]=B[i];
			k++;
		}
				
	}
	return k;
	
}

int Intersection(Student A[], Student B[], Student R[], int n2, int n3)
{
	int i,j,k=0;
	
	for(i=0;i<n2;i++)
	{
		if(Member(B,A[i].Roll_No,n3))
		{
			R[k]=A[i];
			k++;
		}
				
	}

	return k;	
}
int Difference_A(Student A[], Student B[], Student R[], int n2, int n3)
{
	int i,k=0;	
	for(i=0;i<n2;i++)
	{
		if(!Member(B,A[i].Roll_No,n3))
		{
			R[k]=A[i];
			k++;
		}
				
	}
	return k;
}
int Difference_B(Student A[], Student B[], Student R[], int n2, int n3)
{
	int i,k=0;	
	for(i=0;i<n3;i++)
	{
		if(!Member(A,B[i].Roll_No,n2))
		{
			R[k]=B[i];
			k++;
		}
				
	}
	return k;
	
}

int Neither_Nor(Student A[],Student B[], Student M[],Student R[], int n1, int n2, int n3)
{
	int i,k=0;
	for(i=0;i<n1;i++)
	{
		if(!(Member(A,M[i].Roll_No,n2)) && !(Member(B, M[i].Roll_No, n3)))
		{
			R[k]=M[i];
			k++;
		}
	}
	return k;
	
}

int main()
{
	Student A[10],B[10], M[20],R[20];
	char ch;
	int choice, n1,n2,n3,count;
	
	printf("\nEnter how many records for Set M : ");
	scanf("%d", &n1);
	printf("\nReading the Elements of Set M : ");
	Accept(M,n1);
				
	printf("\nEnter how many records for Set A : ");
	scanf("%d", &n2);
	printf("\nReading the Elements of Set A : ");
	Accept(A,n2);
		
	printf("\nEnter how many records for Set B : ");
	scanf("%d", &n3);
	printf("\nReading the Elements of Set B : ");
	Accept(B,n3);
	
	do
	{
		
		printf("\nMenu :");
		printf("\n1.Students who play either cricket or badminton or both");
		printf("\n2.Students who play both cricket and badminton");
		printf("\n3.Students who play only cricket");
		printf("\n4.Students who play only badminton");
		printf("\n5.Number of students who play neither cricket nor badminton");
		
		printf("\nEnter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				count=Union(A,B,R,n2,n3);
				Display(R,count);
				break;
			case 2:
				count=Intersection(A,B,R,n2,n3);
				Display(R,count);
				break;
			case 3:
				count=Difference_A(A,B,R,n2,n3);
				Display(R,count);
				break;
			case 4:
				count=Difference_B(A,B,R,n2,n3);
				Display(R,count);
				break;
			case 5: count=Neither_Nor(A,B,M,R,n1,n2,n3);
				Display(R, count);
				printf("\nTotal No. of students neither play cricket not badminton  = %d",count);
				break;
			default:printf("\nNot A valid choice ");
		}
		printf("\nDo you Want to continue [Y/y] :");
		scanf(" %c",&ch);	
	}while(ch=='Y' || ch =='y');
	return 0;
}




