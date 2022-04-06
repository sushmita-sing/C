#include<stdio.h>
#include<conio.h>
#include<process.h>
struct student
{
	int rno;
	char name[20];
	int m;
};

void main()
{
	FILE *fp1, *fp2;
	struct student s[5];
	int i;
	char ch,ch2;
	clrscr();
	printf("Enter choice\n");
	scanf("%c",&ch);
	switch(ch)
	{
		case 'w':
		fp1=fopen("record.txt","wb");
		if(fp1==NULL)
		{
			printf("Error");
			exit(1);
		}
		do
		{
			printf("Enter details of students\n");
			printf("Enter roll no\n");
			scanf("%d",&s[i].rno);
			printf("Enter name\n");
			scanf("%s",s[i].name);
			printf("Enter marks\n");
			scanf("%d",&s[i].m);
			fflush(stdin);
			fwrite(&s[i],sizeof(struct student ),1,fp1);
			printf("Do u want to enter more records\n");
			scanf("%c",&ch2);
		}while(ch2=='y');
		fclose(fp1);
		break;
		case 'r':
		fp2=fopen("record.txt","r");
		if(fp2==NULL)
		{
			printf("error");
			exit(1);
		}
		i=0;
		while(fread(&s[i],sizeof(struct student),1,fp2))
		{
			printf("RollNo= %d  Name= %s Marks= %d\n",s[i].rno, s[i].name, s[i].m);
			i++;
		}
		fclose(fp2);
		break;
		default:
		printf("Wrong choice\n");
	}
	getch();
}