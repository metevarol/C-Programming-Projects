#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int roll_a_dice(){
	int roll = rand() % 6 + 1;

	return roll;
}

void print_dice(int d1,int d2,int d3,int d4,int d5){

	printf("-> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d [Dice 4]: %d [Dice 5]: %d\n",d1,d2,d3,d4,d5);
}
int counter(int d1,int d2,int d3,int d4,int d5,int count){

	int num = 0;

	if(d1 == count) 
		num++;
	if(d2 == count) 
		num++;
	if(d3 == count) 
		num++;
	if(d4 == count) 
		num++;
	if(d5 == count) 
		num++;

	return num;
}
int computer_intelligence(int d1,int d2,int d3,int d4,int d5){

	if(d1 == d2 && d1 == d3 && d1 == d4 && d1 == d5)
		return 20 + 5 * d1; 
	

	else if(d1 == 1 && d2 == 2 && d3 == 3 && d4 == 4 && d5 == 5)
		return 15; 
	

	else if(d1 != 1 && d2 == 2 && d3 == 3 && d4 == 4 && d5 == 5)
	{

		printf("Rolled Dice 1...\nI got -> ");
		print_dice(d1,d2,d3,d4,d5);

		if(d1 == 1) 
		{
			printf("Lucky me!\n");
			return 15;
		}

	}
	

	else if(d1 == 1 && d2 != 2 && d3 == 3 && d4 == 4 && d5 == 5)
	{

		printf("Rolled Dice 2...\nI got -> ");
		print_dice(d1,d2,d3,d4,d5);

		if(d2 == 2) 
		{
			printf("Lucky me!\n");
			return 15;
		}


	}
	

	else if(d1 == 1 && d2 == 2 && d3 != 3 && d4 == 4 && d5 == 5)
	{

		printf("Rolled Dice 3...\nI got -> ");
		print_dice(d1,d2,d3,d4,d5);

		if(d3 == 3) 
		{
			printf("Lucky me!\n");
			return 15;
		}

	}
	

	else if(d1 == 1 && d2 == 2 && d3 == 3 && d4 != 4 && d5 == 5)
	{

		printf("Rolled Dice 4...\nI got -> ");
		print_dice(d1,d2,d3,d4,d5);

		if(d4 == 4) 
		{
			printf("Lucky me!\n");
			return 15;
		}

	}
	

	else if(d1 == 1 && d2 == 2 && d3 == 3 && d4 == 4 && d5 != 5)
	{

		printf("Rolled Dice 5...\nI got -> ");
		print_dice(d1,d2,d3,d4,d5);

		if(d5 == 5) 
		{
			printf("Lucky me!\n");
			return 15;
		}
	}

	else if(d1 == 2 && d2 == 3 && d3 == 4 && d4 == 5 && d5 == 6)
	{ 
		return 25; 
	} 

	else if(d1 != 2 && d2 == 3 && d3 == 4 && d4 == 5 && d5 == 6)
	{ 
		printf("Rolled Dice 1...\nI got -> ");
		print_dice(d1,d2,d3,d4,d5);

		if(d1 == 2) 
		{
			printf("Lucky me!\n");
			return 25;
		}
	}	
	
	else if(d1 == 2 && d2 != 3 && d3 == 4 && d4 == 5 && d5 == 6)
	{ 
		printf("Rolled Dice 2...\nI got -> ");
		print_dice(d1,d2,d3,d4,d5);

		if(d2 == 3) 
		{
			printf("Lucky me!\n");
			return 25;
		}
	}
	
	else if(d1 == 2 && d2 == 3 && d3 != 4 && d4 == 5 && d5 == 6)
	{
		printf("Rolled Dice 3...\nI got -> ");
		print_dice(d1,d2,d3,d4,d5);

		if(d3 == 4) 
		{
			printf("Lucky me!\n");
			return 25;
		}
	 }
	
	else if(d1 == 2 && d2 == 3 && d3 == 4 && d4 != 5 && d5 == 6)
	{ 
		printf("Rolled Dice 4...\nI got -> ");
		print_dice(d1,d2,d3,d4,d5);

		if(d4 == 5) 
		{
			printf("Lucky me!\n");
			return 25;
		}
	}
	
	else if(d1 == 2 && d2 == 3 && d3 == 4 && d4 == 5 && d5 != 6)
	{ 

		printf("Rolled Dice 5...\nI got -> ");
		print_dice(d1,d2,d3,d4,d5);

		if(d5 == 6) 
		{
			printf("Lucky me!\n");
			return 25;
		}
	}
	else{

		int sixes = 0;
	int fives = 0;

	sixes = counter(d1,d2,d3,d4,d5,6);

	if(sixes > 1 && sixes != 5) 
		return sixes * 6; 
	

	fives = counter(d1,d2,d3,d4,d5,5);

	if(fives > 1 && sixes != 5) 
		return fives * 5; 	


	return 0;
	}

	return 0;
}

int play_computer(){

	int d1,d2,d3,d4,d5;

	d1 = roll_a_dice(); d2 = roll_a_dice();
	d3 = roll_a_dice(); d4 = roll_a_dice();
	d5 = roll_a_dice();

	printf("I got -> ");
	print_dice(d1,d2,d3,d4,d5);
 	

	int score = computer_intelligence(d1,d2,d3,d4,d5);

	return score;	
}

int play_user(){

	int d1,d2,d3,d4,d5;
	int keep1=0,keep2=0,keep3=0,keep4=0,keep5=0;
	int summa = 0;
	int score = 0;

	d1 = roll_a_dice();
	d2 = roll_a_dice();
	d3 = roll_a_dice();
	d4 = roll_a_dice();
	d5 = roll_a_dice();

	printf("Are you ready to play!\nI rolled them for you and you got\n");

	print_dice(d1,d2,d3,d4,d5);

	int check1=0;
	int check2=0;
	int check3=0;
	int check4=0;
	int check5=0;

	int i;

	for(i=0;i<2;i++){

		keep1=0,keep2=0,keep3=0,keep4=0,keep5=0;

		printf("Which ones you want to keep? ");

		char check;

		scanf("%d",&keep1);

		scanf("%c",&check);
		if(check != '\n' && scanf("%d",&keep2) && scanf("%c",&check) 
			&& check != '\n' && scanf("%d",&keep3) && scanf("%c",&check) 
			&& check != '\n' && scanf("%d",&keep4) && scanf("%c",&check)
			&& check != '\n' && scanf("%d",&keep5) && scanf("%c",&check)
			){
    		
		}

		summa += keep1; 
		summa += keep2; 
		summa += keep3; 
		summa += keep4; 
		summa += keep5;

		if(summa > 14) 
			break;

		printf("I rolled the remaining and you got\n-> ");

		if(keep1 == 1 || keep2 == 1 || keep3 == 1 || keep4 == 1 || keep5 == 1) check1 = 1;

		if(!(keep1 == 1 || keep2 == 1 || keep3 == 1 || keep4 == 1 || keep5 == 1) && check1==0){
			d1 = roll_a_dice();
			printf("[Dice 1]: %d ",d1);
		}

		if(keep1 == 2 || keep2 == 2 || keep3 == 2 || keep4 == 2 || keep5 == 2) check2 = 1;

		if(!(keep1 == 2 || keep2 == 2 || keep3 == 2 || keep4 == 2 || keep5 == 2) && check2==0){
			d2 = roll_a_dice();
			printf("[Dice 2]: %d ",d2);
		}

		if(keep1 == 3 || keep2 == 3 || keep3 == 3 || keep4 == 3 || keep5 == 3) check3 = 1;

		if(!(keep1 == 3 || keep2 == 3 || keep3 == 3 || keep4 == 3 || keep5 == 3) && check3==0){
			d3 = roll_a_dice();
			printf("[Dice 3]: %d ",d3);
		}

		if(keep1 == 4 || keep2 == 4 || keep3 == 4 || keep4 == 4 || keep5 == 4) check4 = 1;

		if(!(keep1 == 4 || keep2 == 4 || keep3 == 4 || keep4 == 4 || keep5 == 4) && check4==0){
			d4 = roll_a_dice();
			printf("[Dice 4]: %d ",d4);
		}

		if(keep1 == 5 || keep2 == 5 || keep3 == 5 || keep4 == 5 || keep5 == 5) check5 = 1;

		if(!(keep1 == 5 || keep2 == 5 || keep3 == 5 || keep4 == 5 || keep5 == 5) && check5==0){
			d5 = roll_a_dice();
			printf("[Dice 5]: %d",d5);
		}

		printf("\n");



	}

	

	if((d1 == d2 && d2 == d3 && d3 == d4 && d4 == d5) && d1 !=5 && d2 != 6){ 

		score += 20 + 5 * d1; 
	}
 	
	
	if(d1 == 2 && d2 == 3 && d3 == 4 && d4 == 5 && d5 == 6)
		return 25;  

	if(d1 == 1 && d2 == 2 && d3 == 3 && d4 == 4 && d5 == 5)
		return 15; 
	
	int sixes = 0;
	int fives = 0;

	sixes = counter(d1,d2,d3,d4,d5,6);

	if(sixes > 1) 
		score += sixes * 6;

	if(sixes == 6) 
		score += 20;

	fives = counter(d1,d2,d3,d4,d5,5);

	if(fives > 1) 
		score += fives * 5; 

	if(sixes == 5) 
		score += 20;

	

	return score;
}


int score_sheet(int compScore,int userScore,int round){
	printf("Our scoresheet after round %d:\n",round);
	printf("--------------------------------\n");
	printf("My score      Your score\n");
	printf("%d             %d\n",compScore,userScore);
}


int main()
{
	srand(time(NULL));
	printf("Welcome to the Balut game. \n");
	printf("Lets get started!\n");
	printf("How many round would you like to play? ");
	int roundNumber;
	scanf("%d",&roundNumber);
	int d1=0,d2=0;
		
		d1=roll_a_dice();
		d2=roll_a_dice();
		printf("\nI have rolled the dice and got %d! \n",d1);
		printf("I have rolled the dice for you and you got %d\n",d2);
		int i,compScore=0,userScore=0,temp;
			if(d1>d2)//comp turn
			{
				for(i=1;i<=roundNumber;i++){
					printf("Round %d -- My Turn:\n",i);
					printf("--------------------------------------------------------------\n");
					temp=play_computer();
					compScore+=temp;
					printf("My score: %d\n",temp);
					printf("Round %d -- Your Turn:\n",i);
					printf("--------------------------------------------------------------\n");
					temp=play_user();
					userScore+=temp;
					printf("Your score: %d\n",temp);
					score_sheet(compScore,userScore,i);
				}
			}
			else//user turn 
			{
				for(i=1;i<=roundNumber;i++){
					printf("Round %d -- Your Turn:\n",i);
					printf("--------------------------------------------------------------\n");
					temp=play_user();
					userScore+=temp;
					printf("Your score: %d\n",temp);
					printf("Round %d -- My Turn:\n",i);
					printf("--------------------------------------------------------------\n");
					temp=play_computer();
					compScore+=temp;
					printf("My score: %d\n",temp);
					score_sheet(compScore,userScore,i);
				}
			}

	if(compScore>userScore){
		printf("I won!");
	}
	else{
		printf("You won!");
	}



	return 0;
}