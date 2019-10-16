#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CONTINUE 1
#define WON 2
#define LOST 3

void main()
{
	int myPoint;
	int gameStatus;
	int sum, dice1, dice2;
	int bankBalance = 1000;
    	int betAmount;
	    
    	printf("Balance = Rs.%d\n", bankBalance);
    	
    	srand(time(NULL));
 
	    while(bankBalance != 0)
    	{
     
      		printf("Bet Amount = "); 
        	scanf("%d", &betAmount);
 
        	do
        	{
            		printf("Can't bet more than what you have.\n  Please enter a valid Bet Amount:  ");
            		scanf("%d", &betAmount);
        	}while(betAmount > bankBalance);
	
	
		dice1 = 1 + rand() % 6;
		dice2 = 1 + rand() % 6;
	
		sum = dice1 + dice2;
		printf("Player rolled %d + %d = %d\n",dice1,dice2,sum);
	
		switch(sum)
		{
			case 7:
			case 11:
				gameStatus = WON;
				break;
			case 2:
			case 3:
			case 12:
				gameStatus = LOST;
				break;

			default:
				gameStatus = CONTINUE;
				myPoint = sum;
				printf("Point is %d\n", myPoint);
				break;
		}
	
		while(gameStatus == CONTINUE)
		{
			dice1 = 1 + rand() % 6;
			dice2 = 1 + rand() % 6;
			sum = dice1 + dice2;
			printf("Player rolled %d + %d = %d\n",dice1,dice2,sum);
			if(sum == myPoint)
			{
				gameStatus = WON;
			}
			else
			{
				if(sum == 7)
				{
					gameStatus = LOST;
				}
			}	
		}
		if(gameStatus == WON)
		{
			printf("Player Wins.\n");
			winQuotes();
           		bankBalance += betAmount;
            		printf("New Balance = %d\n", bankBalance);
		}
		else
		{
			printf("Player Loses.\n");
			loseQuotes();
            		bankBalance -= betAmount;
                	printf("New Balance = %d\n", bankBalance);
			if(bankBalance==0)
			{
				printf("Sorry. You busted!\n");
			}
		}
	}
}
