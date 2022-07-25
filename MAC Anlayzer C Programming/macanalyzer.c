#include <stdio.h>


int main(){

	char oct1_1='x',oct1_2='x',m1='x',
		 oct2_1='x',oct2_2='x',m2='x',
		 oct3_1='x',oct3_2='x',m3='x',
		 oct4_1='x',oct4_2='x',m4='x',
		 oct5_1='x',oct5_2='x',m5='x',
		 oct6_1='x',oct6_2='x';

	int check = 0;
	int opt4 = 0;
	printf("Welcome to MAC analyser!");
	while(1){
	check = 0;
	printf("\nPlease enter a MAC address: ");

	scanf(" %c",&oct1_1);
	if((oct1_1 >= 48 && oct1_1 <= 57) || (oct1_1 >= 65 && oct1_1 <= 70)){
		check = 1;
	}
	else
		check = 0;
	
	if(check == 1)
	scanf("%c",&oct1_2);
	if(((oct1_2 >= 48 && oct1_2 <= 57) || (oct1_2 >= 65 && oct1_2 <= 70)) && check == 1){
		check = 1;
	}
	else
		check = 0;

	if(check == 1)
	scanf("%c",&m1);
	if( m1 == '-' && check == 1){
		check = 1;
	}
	else
		check = 0;

	if(check == 1)
	scanf("%c",&oct2_1);
	if(((oct2_1 >= 48 && oct2_1 <= 57) || (oct2_1 >= 65 && oct2_1 <= 70))&& check == 1){
		check = 1;
	}
	else
		check = 0;

	if(check == 1)
	scanf("%c",&oct2_2);
	if(((oct2_2 >= 48 && oct2_2 <= 57) || (oct2_2 >= 65 && oct2_2 <= 70))&& check == 1){
		check = 1;
	}
	else
		check = 0;

	if(check == 1)
	scanf("%c",&m2);
	if( m2 == '-' && check == 1){
		check = 1;
	}
	else
		check = 0;

	if(check == 1)
	scanf("%c",&oct3_1);
	if(((oct3_1 >= 48 && oct3_1 <= 57) || (oct3_1 >= 65 && oct3_1 <= 70))&& check == 1){
		check = 1;
	}
	else
		check = 0;

	if(check == 1)
	scanf("%c",&oct3_2);
	if(((oct3_2 >= 48 && oct3_2 <= 57) || (oct3_2 >= 65 && oct3_2 <= 70))&& check == 1){
		check = 1;
	}
	else
		check = 0;

	if(check == 1)
	scanf("%c",&m3);
	if( m3 == '-' && check == 1){
		check = 1;
	}
	else
		check = 0;

	if(check == 1)
	scanf("%c",&oct4_1);
	if(((oct4_1 >= 48 && oct4_1 <= 57) || (oct4_1 >= 65 && oct4_1 <= 70))&& check == 1){
		check = 1;
	}
	else
		check = 0;

	if(check == 1)
	scanf("%c",&oct4_2);
	if(((oct4_2 >= 48 && oct4_2 <= 57) || (oct4_2 >= 65 && oct4_2 <= 70))&& check == 1){
		check = 1;
	}
	else
		check = 0;

	if(check == 1)
	scanf("%c",&m4);
	if( m4 == '-' && check == 1){
		check = 1;
	}
	else
		check = 0;

	if(check == 1)
	scanf("%c",&oct5_1);
	if(((oct5_1 >= 48 && oct5_1 <= 57) || (oct5_1 >= 65 && oct5_1 <= 70))&& check == 1){
		check = 1;
	}
	else
		check = 0;

	if(check == 1)
	scanf("%c",&oct5_2);
	if(((oct5_2 >= 48 && oct5_2 <= 57) || (oct5_2 >= 65 && oct5_2 <= 70))&& check == 1){
		check = 1;
	}
	else
		check = 0;

	if(check == 1)
	scanf("%c",&m5);
	if( m5 == '-' && check == 1){
		check = 1;
	}
	else
		check = 0;


	if(check == 1)
	scanf("%c",&oct6_1);
	if(((oct6_1 >= 48 && oct6_1 <= 57) || (oct6_1 >= 65 && oct6_1 <= 70))&& check == 1){
		check = 1;
	}
	else
		check = 0;

	if(check == 1)
	scanf("%c",&oct6_2);
	if(((oct6_2 >= 48 && oct6_2 <= 57) || (oct6_2 >= 65 && oct6_2 <= 70))&& check == 1){
		check = 1;
	}
	else
		check = 0;

	int option;
	int exit = 0;
	

	if(check == 1){
			  

			  if (opt4 == 0)
			 	 printf("This is valid!");
			  else
			  	 printf("Valid MAC Address!\n");

		while(1){

			  printf("\n==================\n");
			  printf("1. Is It Unicast or Multicast?\n");
			  printf("2. Is It Global or Local?\n");
			  printf("3. What is the Manufacturer Info?\n");
			  printf("4. Enter Another MAC address\n");
			  printf("5. Exit\n");
			  printf("==================\n");
			  printf("What would you like to do? ");

			  scanf("%d",&option);

			  if(option == 1){

			  	printf("\nIs It Unicast or Multicast?\n");

			  	if(oct1_2 == '1' || oct1_2 == '3' || oct1_2 == '5' || oct1_2 == '7' || oct1_2 == 'B' || oct1_2 == 'D' || oct1_2 == 'F'){
			  		printf("\tMulticast: First bit = 1.\n");
			  	}
			  	else
			  		printf("\tUnicast: First bit = 0.\n");
			  }

			  if(option == 2){

			  	printf("\nIs It Global or Local?\n");

			  	if(oct1_2 == '0' || oct1_2 == '1' || oct1_2 == '4' || oct1_2 == '5' || oct1_2 == '8' || oct1_2 == '9' || oct1_2 == 'C' || oct1_2 == 'D'){
			  		printf("\tGlobal: Second bit = 0.\n");
			  	}
			  	else
			  		printf("\tLocal: Second bit = 1.\n");
			  	
			  }

			  if(option == 3){

			  	printf("\nWhat is the Manufacturer Info?\n");

			  	if(oct1_1 == 'C' && oct1_2 == 'C' && oct2_1 == '4' && oct2_2 == '6' && oct3_1 == 'D' && oct3_2 == '6'){
			  		printf("\tManufacturer Info: Cisco\n");
			  	}
			  	else if(oct1_1 == '0' && oct1_2 == '0' && oct2_1 == '0' && oct2_2 == '8' && oct3_1 == '2' && oct3_2 == '0'){
			  		printf("\tManufacturer Info: Cisco\n");
			  	}
			  	else if(oct1_1 == '3' && oct1_2 == 'C' && oct2_1 == '5' && oct2_2 == 'A' && oct3_1 == 'B' && oct3_2 == '4'){
			  		printf("\tManufacturer Info: Google\n");
			  	}
			  	else if(oct1_1 == '0' && oct1_2 == '0' && oct2_1 == '9' && oct2_2 == 'A' && oct3_1 == 'C' && oct3_2 == 'D'){
			  		printf("\tManufacturer Info: Huawei\n");
			  	}
			  	else
			  		printf("\tManufacturer Info: unknown\n");
			  	
			  }

			  if(option == 4){
			  	opt4 = 1;
			  	break;
			  }

			  if(option == 5){
				exit = 1;
				printf("\nByyeee!\n");
			  	break;
			  	
			  }

		}

		if (exit == 1)
			break;

	}
	else{
		printf("This is not a valid MAC address!");
	}
  }
	return 0;
}

