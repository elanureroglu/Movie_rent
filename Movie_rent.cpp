#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
 
 void SignInOrCreateAccount ();
 
 time_t get_user_input_time()
 {
 
 struct tm time_info;
 time_t time_raw_format;
 
 int second,minute,hour,month,year,day;
 
 printf ("\n Enter the year: "); fflush(stdout); scanf("%d", &year);
 printf ("\n Enter the month: "); fflush(stdout); scanf("%d", &month);
 printf ("\n Enter the day: "); fflush(stdout); scanf("%d", &day);
 printf ("\n Enter the hour: "); fflush(stdout); scanf("%d", &hour);
 
 time_info.tm_year = year - 1900;
 time_info.tm_mon = month - 1;
 time_info.tm_mday = day;
 time_info.tm_hour = hour;
 time_info.tm_min = 00;
 time_info.tm_sec = 00;
 time_info.tm_isdst = 0;
 
 time_raw_format = mktime(&time_info);
 
 return time_raw_format ;
}

time_t get_current_time(void)
{
	time_t current_time;
	time(&current_time);
	return current_time;
}
void WelcomeFunction ()
{
	printf(" Welcome to CU Movie Rental \n");
}
struct movie{
	char type[30];
	char name[30];
	int price;
	int id;
};
struct Account{
	char name [30];
	char pass [30];
};
struct movie arr_movie[27] = {
	{"","",0,0},
	{"Action","The Dark Knight",10,1},
	{"Action","The James Bond Series",14,2},
	{"Adventure","Jurassic World",12,3},
	{"Adventure","Mad max",10,4},
	{"Comedy","The Lady Eye",9,5},
	{"Comedy","Trouble in Paradise",7,6},
	{"Crime","The Godfather",13,7},
	{"Crime","Prisoners",12,8},
	{"Drama","The Good Earth",8,9},
	{"Drama","Daughters of the Dust",9,10},
	{"Fantasy","Harry Potter Series",20,11},
	{"Fantasy","The Lord of the Rings Series",18,12},
	{"History","King Arthur",12,13},
	{"History","Elizabeth",13,14},
	{"Horror","The Conjuring",11,15},
	{"Horror","No Escape",9,16},
	{"Muscial","Beauty And The Beast",10,17},
	{"Muscial","The Lion King",11,18},
	{"Mystery","The Illusionist",11,19},
	{"Mystery","The Prestige ",12,20},
	{"Romance","The Notebook",12,21},
	{"Romance","A Walk To Remember",13,22},
	{"Sci-Fi","Frankenstein",9,23},
	{"Sci-Fi","Star Wars Series",16,24},
	{"War"," Full Metal Jacket",8,25},
	{"War"," Dunkirk",12,26},
};
void InfoFunction(){
	printf("\n\n If there is a problem with the movies, please contact us.\n"
	"When the films are damaged by you, you have to afford the damage.\n"
	"Contact Number: 0206 548 3647 \n\n");
}
void Login (){
	char requestedname [30];
	char requestedpassword [30];
	     printf("\n\n Please enter user name: ");
	     scanf("%s",&requestedname);
	     printf("\n\n Please enter password: ");
	     scanf("%s",&requestedpassword);
	     
	 FILE *sc;
	 struct Account acc;
	 bool x = true ;
	 
	 sc = fopen("userInfo.txt","r");
	 
	 while (!feof(sc)){
	 	
	 	 fscanf(sc,"%s %s",&acc.name, &acc.pass);
	 	 
	 	 if (strcmp(requestedname,acc.name)==0 && strcmp(requestedpassword,acc.pass)==0 ){
	 	 	printf("Welcome %s \n\n", acc.name);
	 	 	x = false;
	 	 	break;
		  }
	 }
	 
	 if(x) {
	 	printf("Please try again\n\n");
	 	SignInOrCreateAccount();
	 }
	 fclose(sc);
}

    void CreateAccount (){
    	char requestedname [30];
    	char requestedpassword [30];
    	char email [20];
    	char phone [20];
    	
    	printf("\n\n Please enter the username: ");
    	scanf("%s", &requestedname);
    	
    	printf("\n\n Please enter the password: ");
    	scanf("%s", &requestedpassword);
    	
    	printf("\n\n Please enter the e-mail: ");
    	scanf("%s", &email);
    	
    	printf("Please enter the phone: ");
    	scanf("%s",&phone);
    	
    	FILE *fptr;
    	fptr = fopen ("userInfo.txt","a");
    	
    	   if(fptr == NULL) {
    	   	printf("Error!");
    	   	exit(1);
		   }
		   
		   fprintf(fptr,"\n%s %s %s", requestedname,requestedpassword, email, phone);
		   printf("Welcome \n\n %s", &requestedname);
		   fclose(fptr);
		   
	}
	
	void SignInOrCreateAccount (){
		
		int choice;
		
		for(;;){
			printf("\n\n Select 1 to login, Select 2 to create account.\n[1]-Login\n[2]-Create Account\n ");
			scanf("%d",&choice);
			
			if(choice == 1){
				Login();
				break;
			}
			else if (choice == 2){
				CreateAccount ();
				break;
			}
			else {
				printf("You made the wrong choice.Please try again\n");
			}
		}
	}
	
	void record (char type[30],char name[30],int balance){
		FILE *fptr;
		fptr = fopen("yz.txt","a");
		
		  if(fptr == NULL){
		  	
		  	printf("Error!");
		  	exit(1);
		  }
		  
		  fprintf(fptr, "Movie type: %s, The movie you rented: %s, Available balance: %d \n", type, name,balance);
		  fclose(fptr);
	}
	
	int main (){
		
		int balance =0;
		int addmoney;
		char requestedname[30];
		char requestedpassword[30];
		char email [20];
		char phone [20];
		int choice;
		int moviechoice;
		int i;
		int num;
		time_t user_input_time;
		time_t current_time;
		
		
		WelcomeFunction();
		SignInOrCreateAccount();
		
		  for(;;){
		  	
		  	printf("Please choose one of the transactions\n[1]-Add Money\n[2]-Daily Movie Rental\n[3]-Info\n[4]-Exit\nChoose one of the options: ");
		  	scanf("%d",&choice);
		  	
		  	if(choice == 1){
		  		printf("How much money do you want to add:");
		  		 scanf("%d",&addmoney);
		  		 balance += addmoney;
		  		 printf("Your transaction has been successfully completed\n Amount: %d\n Available Balance: %d", addmoney, balance);
			  }
			  
			  else if (choice ==2 ){
			  	printf(" Available movies: \n");
			  	
			  	for(i=1;i<27;i++){
			  		printf("\n %d %s %s %d", arr_movie[i].id,arr_movie[i].type,arr_movie[i].name,arr_movie[i].price);
				  }
				  printf("\n Available Balance : %d \n", balance);
				  
				  printf("\n Please choose the movie you want to rent: ");
				  scanf("%d", &moviechoice);
				  
				  if (balance >= arr_movie[moviechoice].price){
				  	printf("Movie of your choice: %s %s", arr_movie[moviechoice].type, arr_movie[moviechoice].name);
				  	
				  	
				  	 for (;;){
				  	 	printf("Please enter the date you want to rent");
				  	 	user_input_time = get_user_input_time ();
				  	 	current_time = get_current_time();
				  	 	
				  	 	if(current_time > user_input_time){
				  	 		
				  	 		printf(" Invalid date. \n Please enter again: ");
						   }
						   
						   else {
						   	
						   	printf("The movie you rented: %s %s \n", arr_movie[moviechoice].type,arr_movie[moviechoice].name);
						   	
						   	balance = balance - arr_movie[moviechoice].price;
						   	printf("Available balance : %d ", balance);
						   	break ;
						   }
					   }
					   
					   record(arr_movie[moviechoice].type, arr_movie[moviechoice].name, balance);
					   
					printf ("\nYour transaction has been successfully completed.\n Thank you for choosing us. \n");   
					   
				  }
				  
				  else {
				  	printf("\n Insufficient balance. \n");
				  }
			  }
			  
			  else if ( choice == 3){
			  	InfoFunction();
			  }
		  	
		  	else if ( choice == 4) {
		  		
		  		printf("Thank you for choosing us.\n");
		  		
		  		break ;
			  }
			  
			  else {
			  	printf("You made the wrong choice. Please try again. \n\n");
			  }
			  
		  }
		  
		return 0;
	}
