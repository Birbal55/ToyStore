/*********************************  PROJECT   TOYSTORE  ***********************************/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

/****************************  Declaration of structure of ToyStore  ****************************/
struct TotStore
{
	int id,age;
	char name[30],type[30];
	float weight,price;
}toy;  /*Glovbal variable of structure ----toy*/

struct Billing
{
	
};

struct Customer
{
	
};

struct Dealer
{
	
};

/*****************************************  Declaration of function  ************************************************/  

void add_new_toy();
void search_toy();
void update_toy();
void delete_toy();
void show_list_toys();

/**********************************************  Main function of programm  ***************************************************/
 main()
 {
 	int ich;
 	while(1)
 	{
 		system("cls");
 		printf("\n1.Add new toy");
 		printf("\n2.Search toy");
 		printf("\n3.Show all toys");
 		printf("\n4.Update toy");
 		printf("\n5.Delete toy");
 		printf("\n6.Exit");
 		printf("\nSelect your choice:");
 		scanf("%d",&ich);
 		system("cls");
 		
 		switch(ich)
 		{
 			case 1:
 				add_new_toy();
 			break;
 			
			case 2:
			    search_toy();
			break;
			
			case 3:
			    show_list_toys();	
			break;
			
			case 4:
			    update_toy();
			break;
			
			case 5:
			    delete_toy();
			break;
			
			case 6:
			    exit(0);		     	
		} //switch
		printf("\n");
		system("pause");
	 }//while closed
 } //main closed
 
 
 /**************************************************  Definition of add_new_toy() function  ****************************************************/
 void add_new_toy()
 {
 	FILE *fptr=fopen("toystore.ty","ab");
 	//accept new toy detail in toy(structure variable) memory from console input
 	printf("Enter toy id:");
 	scanf("%d",&toy.id);
 	printf("\nEnter toy name:");
 	fflush(stdin);
 	gets(toy.name);
 	printf("\nEnter toy type:");
 	gets(toy.type);
 	printf("\nEnter toy weight:");
// 	gets(toy.weight);
    scanf ("%f",&toy.weight);
    printf("\nEnter toy price:");
    scanf("%f",toy.price);
    //write data from toy(structure variable memory) into file toystore.ty
    fwrite((char*) &toy,1,sizeof(toy),fptr);
    fclose(fptr);
}

/*******************************************  Definition of search_toy() function  *******************************************************/
void search_toy()
{
	
	FILE *fptr=fopen("toystore.ty","rb");
	int f=0;
	char toyname[20];
	printf("Enter name of toy for search :");
	fflush(stdin);
	gets(toyname);
	while(fread((char *)&toy,1,sizeof(toy),fptr))
	{
		if(!strcmp(toyname,toy.name))
		{
			printf("\nToy id : %d",toy.id);
			printf("\nToy name : %s",toy.name);
			printf("\nToy type : %s",toy.type);
			printf("\nToy weight : %f",toy.weight);
			printf("\nToy price : %f",toy.price);
			  f=1;
			break;
		}
	}
	if(f==0)
	  printf("Toy not found");
	  
	 /*  or
	   FILE * fptr=fopen("toystore.ty","rb");
	   int sno,f=0;
	   printf("Enter id of toy:");
	   scanf("%d",&sno);
	   while(fread((char*)&toy,1,sizeof(toy),fptr))
	   {
	   	if(sno==toy.id)
	   	{
	   		printf("\nToy id : %d",toy.id);
			printf("\nToy name : %s",toy.name);
			printf("\nToy type : %s",toy.type);
			printf("\nToy weight : %f",toy.weight);
			printf("\nToy price : %f",toy.price);
			  f=1;
			    break;
		}
	   if(f==0)
	    printf("Toy not found"); 
      }*/
}
/*********************************  Definition of show_list_toys() function  *********************************************/
void show_list_toys()
{
	FILE *fptr=fopen("toystore.ty","rb");
	while(fread((char*)&toy,1,sizeof(toy),fptr))
	{
		printf("\nToy id : %d",toy.id);
		printf("\nToy name : %s",toy.name);
		printf("\nToy type : %s",toy.type);
		printf("\nToy weight : %f",toy.weight);
		printf("\nToy price : %f",toy.price);
		 
	}
}

/***********************************  Definition of update_toy() function  ******************************************/

void update_toy()
{
	FILE *fptr1=fopen("toystore.ty","rb");
	FILE *fptr2=fopen("newfile.ty","wb");
	int f=0;
	char toyname[20];
	printf("Enter name of toy for update:");
	fflush(stdin);
	gets(toyname);
	
	while(fread((char*)&toy,1,sizeof(toy),fptr1))
	{
		if(!strcmp(toyname,toy.name))
		{
			printf("\nToy id : %d",toy.id);
			printf("\nToy name : %s",toy.name);
			printf("\nToy type : %s",toy.type);
			printf("\nToy weight : %f",toy.weight);
			printf("\nToy price : %f",toy.price);
			printf("Enter new input for toy:");
			//new input
			printf("\nEnter toy id:");
			scanf("%d",&toy.id);
			printf("\nEnter toy name:");
			fflush(stdin);
			gets(toy.name);
			printf("\Enter toy type:");
			gets(toy.type);
			printf("\nEnter toy weight:");
			scanf("%f",&toy.weight);
			printf("\nEnter toy price:");
			scanf("%f",&toy.price);
			//new file
			fwrite((char *)&toy,1,sizeof(toy),fptr2);
			f=1;
			
		}
		else
		{
			fwrite((char*)&toy,1,sizeof(toy),fptr2);
		}
	}
	if(f==0)
	  printf("Toy not found");
	  fclose(fptr1);
	  fclose(fptr2);
	  remove("toystore.ty");
	  rename("newfile.ty","toystore.ty");
}
    
    /****************************************  Definition of delete_toy() function *****************************************/
    
void delete_toy()
{
	FILE *fptr1=fopen("toystore.ty","rb");
	FILE *fptr2=fopen("newfile.ty","wb");
	int f=0;
	char toyname[20];
	printf("Enter name of toy for delete:");
	fflush(stdin);
	gets(toyname);
	while(fread((char*)&toy,1,sizeof(toy),fptr1))
    {
    	if(strcmp(toyname,toy.name))//strcmp(str1,str2)---true==>0    false=nonzero
    	{
    		fwrite((char*)&toy,1,sizeof(toy),fptr2);
		}
		else
		{
			f=1;
		}
	}
	if(f==0)
	  printf("Toy not found");
	else
	  printf("Toy deleted");
	  fclose(fptr1);
	  fclose(fptr2);
	  remove("toystore.ty");
	  rename("newfile.ty","toystore.ty");      	
}




