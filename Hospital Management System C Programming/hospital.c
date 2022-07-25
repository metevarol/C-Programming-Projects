#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Patients{

   int ID;
   char name[50];
   char surname[50];
   char birthday[50];
   char email[50];
   char department[50];
   
} Patient;

void updateFile(char *filename,Patient p_arr[50],int p_size){

   FILE * fp;
   int i;

   fp = fopen (filename,"w");
 
   /* write 10 lines of text into the file stream*/
   for(i = 0; i < p_size;i++){

       fprintf (fp, "%d, %s, %s, %s, %s, %s\n",p_arr[i].ID,p_arr[i].name,p_arr[i].surname,p_arr[i].birthday,p_arr[i].email,p_arr[i].department);
   }
 
   /* close the file*/  
   fclose (fp);
}

int main(){

	Patient p_arr[50];
	Patient empty;
	int p_size = 0;

	//-------------------------------------------------------READ FILE---------------------------------------------
	FILE *fp = fopen("record.txt", "r");
    const char s[2] = ", ";
    char *token;
    int i,j;
    if(fp != NULL)
    {
        char line[100];
        while(fgets(line, sizeof line, fp) != NULL)
        {
            token = strtok(line, s);
            for(i=0;i<6;i++)
            {		//printf("%s  ",token);
                  	if(i==0){
	                  	p_arr[p_size].ID = atoi(token);
						token = strtok(NULL,s);
                  	}
                  	if(i==1){
	                  	strcpy( p_arr[p_size].name,token);
						token = strtok(NULL,s);
                  	}
                  	if(i==2){
	                  	strcpy( p_arr[p_size].surname,token);
						token = strtok(NULL,s);
                  	}
                  	if(i==3){
	                  	strcpy( p_arr[p_size].birthday,token);
						token = strtok(NULL,s);
                  	}
                  	if(i==4){
	                  	strcpy( p_arr[p_size].email,token);
						token = strtok(NULL,"\n");
                  	}
                  	if(i==5){
	                  	strcpy( p_arr[p_size].department,token);
						token = strtok(NULL,s);
						p_size++;
                  	}   
            }
        }
        fclose(fp);
    } else {
        perror("record.txt");
    }

    //----------------------------------------------------------------------------------------------------

    int selection;
    int selection2;
    int patientId;
    char name[50];
    char surname[50];
    int searchcount = 0;

	printf("---Welcome to the Hospital Management System---\n");
	printf("-----------------------------------------------\n");

	while(1){

		printf("\n0: Exit | 1: Show All Records | 2: Search Patient | 3: New Patient\n");
		printf("Please select an option: ");
		
		while(1){  //scan selection

			scanf("%d",&selection);

			if(selection!=0 && selection!=1 && selection!=2 && selection!=3){
				printf("\nWrong selection !!!\n");
				printf("Please select an option: ");
			}			
			else
				break;
		}

		if(selection==0){
			break;
		}


		if(selection==1){

			printf("\nPATIENT RECORDS:\n\n");

			 for(i=0;i<p_size;i++){

    			printf("%d\t%s\t%s\t%s\t%s\t%s\n\n",p_arr[i].ID,p_arr[i].name,p_arr[i].surname,p_arr[i].birthday,p_arr[i].email,p_arr[i].department);
    		}
    		

	    	printf("\n0: Return to main menu | 1: Delete Record | 2: Update Record\n");
			printf("Please select an option: ");

			while(1){  //scan selection

				scanf("%d",&selection2);

				if(selection2!=0 && selection2!=1 && selection2!=2){
					printf("\nWrong selection !!!\n");
					printf("Please select an option: ");
				}			
				else
					break;
			}
				
			if(selection2==0){}

			if(selection2==1){

				printf("Patient Id: ");
				scanf("%d",&patientId);

				for(i=0;i<p_size;i++){

					if(p_arr[i].ID == patientId){
	
						p_arr[i] = empty;

						for(j=i;j<p_size-1;j++){

							p_arr[j] = p_arr[j+1];
						}
						p_size--;
						break;
						
					}
				}

				printf("\n\nPatient record is deleted...\n\n");

				updateFile("record.txt",p_arr,p_size);

			}

			if(selection2==2){

				printf("Patient Id: ");
				scanf("%d",&patientId);

				for(i=0;i<p_size;i++){

					if(p_arr[i].ID == patientId){

						printf("\nEnter Name (Old: %s): ",p_arr[i].name);
						scanf(" %s",p_arr[i].name);

						printf("\nEnter Surname (Old: %s): ",p_arr[i].surname);
						scanf(" %s",p_arr[i].surname);

						printf("\nEnter Birthday (Old: %s): ",p_arr[i].birthday);
						scanf(" %s",p_arr[i].birthday);

						printf("\nEnter E-mail (Old: %s): ",p_arr[i].email);
						scanf(" %s",p_arr[i].email);

						printf("\nEnter Department (Old: %s): ",p_arr[i].department);
						scanf(" %s",p_arr[i].department);

					}
				}
					updateFile("record.txt",p_arr,p_size);
			}

		}


		if(selection==2){

			printf("\n\n0: Return to main menu | 1: Search by Id | 2: Search by Name  | 3: Search by Surname \n");
			printf("Please select an option: ");

			while(1){  //scan selection

				scanf("%d",&selection2);

				if(selection2!=0 && selection2!=1 && selection2!=2 && selection2!=3){
					printf("\nWrong selection !!!\n");
					printf("Please select an option: ");
				}			
				else
					break;
			}

			if(selection2==0){}

			if(selection2==1){

				searchcount=0;
				printf("\nPatient Id: ");
				scanf(" %d",&patientId);

				printf("\n\nSearching...\n\n");

				for(i=0;i<p_size;i++){

					if(p_arr[i].ID == patientId){

						printf("%d\t%s\t%s\t%s\t%s\t%s\n\n",p_arr[i].ID,p_arr[i].name,p_arr[i].surname,p_arr[i].birthday,p_arr[i].email
							,p_arr[i].department);

						searchcount++;
					}
				}

				printf("Search completed. %d patient(s) are found...\n",searchcount);
			}

			if(selection2==2){

				searchcount=0;
				printf("\nPatient Name: ");
				scanf(" %s",name); 

				printf("\n\nSearching...\n\n");

				for(i=0;i<p_size;i++){

					if(strcmp(p_arr[i].name,name) == 0){

						printf("%d\t%s\t%s\t%s\t%s\t%s\n\n",p_arr[i].ID,p_arr[i].name,p_arr[i].surname,p_arr[i].birthday,p_arr[i].email
							,p_arr[i].department);

						searchcount++;
					}
				}

				printf("Search completed. %d patient(s) are found...\n",searchcount);

			}

			if(selection2==3){

				searchcount=0;
				printf("\nPatient Surnamame: ");
				scanf(" %s",surname); 

				printf("\n\nSearching...\n\n");

				for(i=0;i<p_size;i++){

					if(strcmp(p_arr[i].surname,surname) == 0){

						printf("%d\t%s\t%s\t%s\t%s\t%s\n\n",p_arr[i].ID,p_arr[i].name,p_arr[i].surname,p_arr[i].birthday,p_arr[i].email
							,p_arr[i].department);

						searchcount++;
					}
				}

				printf("Search completed. %d patient(s) are found...\n",searchcount);
			}


		}

		if(selection==3){

				p_arr[p_size].ID = p_arr[p_size-1].ID + 1;

				printf("\nEnter Name: ");
				scanf(" %s",p_arr[p_size].name);

				printf("\nEnter Surname: ");
				scanf(" %s",p_arr[p_size].surname);

				printf("\nEnter Birthday: ");
				scanf(" %s",p_arr[p_size].birthday);

				printf("\nEnter E-mail: ");
				scanf(" %s",p_arr[p_size].email);

				printf("\nEnter Department: ");
				scanf(" %s",p_arr[p_size].department);

				p_size++;

				printf("\nNew patient has been recorded...\n");

				updateFile("record.txt",p_arr,p_size);
			
		}


	}
	


	return 0;
}