#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CONTINUE 1
#define WON 2
#define LOST 3

int winQuotes(void);
int loseQuotes(void);

int winQuotes(void)
{
    int rn = rand() % 6;
    switch(rn)
    {
        case 0:
            printf("Lucky for you!!\n");
            break;
        case 1:
                        printf("Winner!!\n");
                        break;
        case 2:
                        printf("Hey there! You're cleaning me out over here!!\n");
                        break;
        case 3:
                        printf("Big WINNER!\n");
                        break;
        case 4:
                        printf("Ouch!! Looks like I'm going broke!\n");
                        break;
        case 5:
                        printf("You Win! PERFECT!\n");
                        break;
    }
       return 0;
}
 
 
int loseQuotes(void)
{
        int rn = rand() % 6;
        switch(rn)
        { 
                case 0:
                        printf("Not so lucky, are we?\n");
                        break;
                case 1:
                        printf("YOU LOSE!!\n");
                        break;
                case 2:
                        printf("Hey there! Glad to be cleaning you out over here!!\n");
                        break;
                case 3:
                        printf("LOSER!\n");
                        break;
                case 4:
                        printf("HA!! Looks like you're going broke!\n");
                        break;
                case 5:
                        printf("You lose! NOT PERFECT!\n");
                        break;
        }
return 0;
}

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
