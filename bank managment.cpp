#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<unistd.h>
int login();
struct a {
	 char name[60];
    int acc_no;
    int age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct  dob;
	struct deposit;
    struct withdraw;
} add,check;
int main()
{
	char pass[10],password[10]="archana";
	int i,j;
	printf("\n\t\tENTER THE PASSWORD:\n\t\t");
	scanf("%s",&pass);
	if(strcmp(pass,password)==0)
	{
		printf("\t\tsuccesfull login.\n");
		login();
	}
	else
	{
		printf("\t\tINVALID PASSWORD.\n");
		printf("\n\t\tenter 0 to retry and 1 to exit.\n\t\t\t");
		scanf("%d",&i);
		switch(i)
		{
			case 0: system("cls");
					main();
					break;
			case 1: return 0;
					break;
		}
	}
}
int login()
{
	int j,create(),display();
	printf("1. enter 1 to create an account.\n");
	printf("2. enter 2 to see details of account.\n");
	printf("3. enter 3 to do transaction.\n");
	printf("4.enter 4 to exit.\n");
	printf("enter the choice: ");	
	scanf("%d",&j);
	switch(j)
	{
		case 1: create();
				break;
		case 2: display();
				break;
		case 3: //trans();
				break;
		case 4:break;
	}
	return 0;
}
void create()
{
	int choice;
    FILE *ptr;

    ptr=fopen("record.txt","a+");
    system("cls");
	printf("ADD RECORD\n");
    printf("\nEnter the account number: ");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s  %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {
				printf("Account no. already in use!");
				sleep(5);
                login();
			 }
    }
    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);

    fprintf(ptr,"%d %s %d %s %s %lf %s %f \n",add.acc_no,add.name,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt);


    fclose(ptr);
    printf("\nAccount created successfully!");
    login();
    
}
void display()
{
	FILE *view;
    view = fopen("record.txt","r");
    int test=0,main_exit;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d %s %s %lf %s %f",&add.acc_no,&add.name,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt)!=EOF)
       {
		   printf("\n%d\t %s\t\t\t%s\t\t%f",add.acc_no,add.name,add.address,add.phone);
           
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");
		}

    view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
        if (main_exit==1)
            login();
        else if(main_exit==0)
            main();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

 
