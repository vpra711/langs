#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

//ALl the globle variables and the composite data types will be declared here
typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;
}pd;

//function prototypes to be used
void reservation(void);							//main reservation function
void viewdetails(void);							//view details of all the trains
void cancel(void);								
void printticket(char name[],int,int,float);	//print ticket 
void specifictrain(int);						//print data related to specific train
float charge(int,int);							//charge automatically w.r.t number of seats and train
void login();

/*********************************************MAIN()*************************************************/

int main()
{
	system("cls"); 
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|              BROUGHT TO YOU BY                |\n");
	printf("\t\t|              |  D. Prakash Raj  |             |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
		
	    
	printf(" \n Press any key to continue:");
	
	getch();	
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Trains");
	printf("\n------------------------");
	printf("\n3>> Cancel Reservation");
	printf("\n------------------------");
	printf("\n4>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();		//Fucntion still not added
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			cancel();
			//function not added. code has been removed due to some errors
			break;
		case 4:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

/*********************************************VIEWDETAILS()*************************************************/

//The function is yet not completed, need more details to be added!
//timings of the trains are still missing 

void viewdetails(void)
{
    system("cls");
    printf("-----------------------------------------------------------------------------");
    printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
    printf("-----------------------------------------------------------------------------");
    printf("\n1001\tVaigai Express\t      madurai to Ramnad  \tRs.300\t\t9am");
    printf("\n1002\tVaigai Express\t      Ramnad To Madurai  \tRs.500\t\t12pm");
    printf("\n1003\tTamil Express\t      chennai To covai  \tRs.450\t\t8am");
    printf("\n1004\tTamil Express\t      covai To chennai  \tRs.450\t\t11am");
    printf("\n1005\tPandiyan Express     ooty To paramakudi  \tRs.400\t\t7am");
    printf("\n1006\tPandiyan Express     paramakudi To ooty  \tRs.400\t\t9.30am");
    printf("\n1007\tCholan Express\t      thiruvarur To karur  \tRs.350\t\t1pm");
    printf("\n1008\tCholan Express\t      karurTo thiruvarur  \tRs.350\t\t4pm");
    printf("\n1009\tRajan Express\t   viruthunagarTo sivagangai  \tRs.340\t\t3.35pm");
    printf("\n1009\tRajan Express\t   sivagangai To viruthunagar  \tRs.340\t\t4.15pm");

}

/*********************************************RESERVATION()*************************************************/

void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");
	
	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);

	if(passdetails.train_num >= 1001 && passdetails.train_num <= 1010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);		
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}
	
	printf("\n\nConfirm Ticket (y/n):>");
	start:
	fflush(stdin);
	scanf("%c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("==================");
		printf("\nReservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n')
		{
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

/*********************************************CHARGE()*************************************************/

float charge(int train_num,int num_of_seats)
{
	if (train_num == 1001)
	{
		return(300.0*num_of_seats);
	}
	else if (train_num==1002)
	{
		return(500.0*num_of_seats);
	}
	else if (train_num==1003)
	{
		return(450.0*num_of_seats);
	}
	else if (train_num==1004)
	{
		return(450.0*num_of_seats);
	}
	else if (train_num==1005)
	{
		return(400.0*num_of_seats);
	}
	else if (train_num==1006)
	{
		return(400.0*num_of_seats);
	}
	else if (train_num==1007)
	{
		return(350.0*num_of_seats);
	}
	else if (train_num==1008)
	{
		return(350.0*num_of_seats);
	}
	else if (train_num==1009)
	{
		return(340.0*num_of_seats);
	}
	else if (train_num==1010)
	{
		return(340.0*num_of_seats);
	}
}


/*********************************************PRINTTICKET()*************************************************/

void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charges);
}

/*********************************************SPECIFICTRAIN()*************************************************/

void specifictrain(int train_num)
{

    if (train_num==1001)
    {
        printf("\nTrain:\t\t\tVaigai Express");
        printf("\nDestination:\t\tmadurai to Ramnad");
        printf("\nDeparture:\t\t9am ");
    }
    if (train_num==1002)
    {
        printf("\nTrain:\t\t\tVaigai Express");
        printf("\nDestination:\t\tRamnad To Madurai");
        printf("\nDeparture:\t\t12pm");
    }
    if (train_num==1003)
    {
        printf("\nTrain:\t\t\tTamil Express");
        printf("\nDestination:\t\tchennai To covai");
        printf("\nDeparture:\t\t8am");
    }
    if (train_num==1004)
    {
        printf("\nTrain:\t\t\tTamil Express");
        printf("\nDestination:\t\tcovai To chennai");
        printf("\nDeparture:\t\t11am ");
    }
    if (train_num==1005)
    {
        printf("\nTrain:\t\t\tPandiyan Express");
        printf("\nDestination:\t\tooty To paramakudi");
        printf("\nDeparture:\t\t7am");
    }
    if (train_num==1006)
    {
        printf("\ntrain:\t\t\tPandiyan Express");
        printf("\nDestination:\t\tparamakudi To ooty");
        printf("\nDeparture:\t\t9.30am ");
    }
    if (train_num==1007)
    {
        printf("\ntrain:\t\t\tCholan Express");
        printf("\nDestination:\t\tthiruvarur To karur");
        printf("\nDeparture:\t\t1pm ");
    }
    if (train_num==1008)
    {
        printf("\ntrain:\t\t\tCholan Express");
        printf("\n Destination:\t\tkarurTo thiruvarur");
        printf("\nDeparture:\t\t4pm ");
    }
    if (train_num==1009)
    {
        printf("\ntrain:\t\t\tRajan Express");
        printf("\nDestination:\t\tviruthunagarTo sivagangai");
        printf("\nDeparture:\t\t3.35pm ");
    }
    if (train_num==1010)
    {
        printf("\ntrain:\t\t\tRajan Express");
        printf("\nDestination:\t\tsivagangai To viruthunagar");
        printf("\nDeparture:\t\t1.15 ");
    }
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
	if(strcmp(uname,"prakash")==0 && strcmp(pword,"ooad")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		getch();//holds the screen
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
}

void cancel(void)   /* Sorry this function does not work. Coding is not completed. Codes have been removed due to some errors  */
{
	/*FILE *f,*t;
	int i=0;
	int trainnum;
	t=fopen("seats_reserved.txt","w");
	if ((f=fopen("seats_reserved.txt","r"))==NULL)
	{
		printf("NO RECORD ADDED.");
		main();
		* * * * *
		*
		*
		*
		*
		*
		*
		*  /  missing codes  /
	}
	else*/
	system("cls");
	int trainnum;
	printf("-----------------------\n");
	printf("Enter the train number: \n");
	printf("-----------------------\n");
	fflush(stdin);
	scanf("%i",&trainnum);
	printf("\n\nCancelled");  
	getch();
}