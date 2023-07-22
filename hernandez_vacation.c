//Matthew Hernandez
//2021/09/20
//UCFID: 5357015
//This file is a game that uses different functions to choose an activity by the player and tells them the total profit for what they earn from doing the activities.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int fishing();
int gem_digging();
int bird_watching();
int sellfish(int snookCount,int troutCount,int catfishCount,int koiCount);
int sellpics(int doveCount,int crowCount,int seagullCount,int bluejayCount);
int sellgems(int rubyCount,int sapphireCount,int emeraldCount,int diamondCount);

// main function that has the start of the game asking the player what they want to do and it calls the other functions
//after the one of the calling function stops the profits made are added to wallet which will be displayed once the player chooses to end the game
int main()
{
    //the playerInput variable is what the user has to type to do an activity
    // variable wallet is used to add up the money obtained from each activity
    int playerInput;
    int wallet;
    printf("Welcome to your Island Vacation!\n");
    //reoccurring while loop that keeps asking what the player wants to do until they type "-1"
    while(playerInput!=-1)
    {
        printf("\nWhat activity do you want to perform?\n");
        printf("1 = Fishing\n");
        printf("2 = Gem Digging\n");
        printf("3 = Birdwatching\n");
        printf("-1 = To stop the game\n");
        scanf("%d",&playerInput);
        if(playerInput==-1)
        {
            printf("\nIn total you made: $%d\n",wallet);
            printf("Thank you for playing!\n");
            break;
        }
        if(playerInput==1)
       {
            wallet=wallet+fishing();
       }
        else if(playerInput==2)
        {
             wallet=wallet+gem_digging();
        }
        else if(playerInput==3)
        {
            wallet=wallet+bird_watching();
        }
        else
        {
            printf("Please type a valid number.\n");
        }
    }
    return 0;
}
//fishing activity function
//counts the number of fishes caught by the player and which is limited to 5 fishes and at the end it calls the selling function to tell the player their profits
int fishing()
{
    //variables used to keep count of the fishes and the player Input
    int snookCount=0;
    int troutCount=0;
    int giantCFcount=0;
    int koiCount=0;
    int playerInput;

    printf("\nLets go fishing!\n");
//while loop that does not stop unless inventory reaches 5 or the player types "-1"
//when it stop it adds the amount of money profited from selling to wallet in the main function and lets them know how much they made from the catch and how much of each fish they caught
    while(1)
    {
        srand(time(NULL));
        int probability=(rand()% 100)+1;

        printf("\nAre you ready to cast your line?\n (1=yes,-1=Stop Activity)\n");
        scanf("%d",&playerInput);

        if(snookCount+ troutCount+giantCFcount+koiCount==5)
        {
            printf("Your inventory is full, proceeding to sell.\n");
            printf("You caught %d Snook(s), %d Trout(s), %d Giant CatFish(s), and %d Koi Fish(s).\n", snookCount,troutCount,giantCFcount,koiCount );
            int cash=sellfish(snookCount,troutCount,giantCFcount,koiCount);
            return cash;
            break;
        }
        if(playerInput==-1)
        {
            printf("\nYou caught %d Snook(s), %d Trout(s), %d Giant CatFish(s), and %d Koi Fish(s).\n", snookCount,troutCount,giantCFcount,koiCount );
            int cash=sellfish(snookCount,troutCount,giantCFcount,koiCount);
            return cash;
            break;
        }
        if(playerInput==1)
        {
            if(probability>=50 && 100>=probability)
            {
                printf("You caught nothing.\n");
            }
            else if(probability>=25 && 50>probability)
            {
                printf("You caught a Snook.\n");
                snookCount++;
            }
            else if(probability>=10 && 25>probability)
            {
                printf("You caught a Trout.\n");
                troutCount++;
            }
            else if(probability>=2.5 && 10>probability)
            {
                printf("You caught a Giant Catfish.\n");
                giantCFcount++;
            }
            else if(2.5>=probability)
            {
                printf("You caught a Koi Fish.\n");
                koiCount++;
            }
        }
    }
}
//gem digging activity
//counts the number of gems found by the player and which is limited to 5 gems and at the end it calls the selling function of gems to tell the player their profits
int gem_digging()
{
    int rubyCount=0;
    int sapCount=0;
    int emCount=0;
    int diCount=0;
    int playerInput;

    printf("\nLet's go digging for gems!\n");
//while loop that does not stop unless inventory reaches 5 or the player types "-1"
//when it stop it adds the amount of money profited from selling to the wallet integer in the main function and lets them know how much they made from the digging and how much of each gem they found
    while(1)
    {
        srand(time(NULL));
        int probability=(rand()% 100)+1;

        printf("\nAre you ready to dig?\n (1=yes,-1=quit)\n");
        scanf("%d",&playerInput);

        if(rubyCount+ sapCount+emCount+diCount==5)
        {
            printf("\nYour inventory is full,proceeding to sell.\n");
            printf("You found %d Ruby(s), %d Sapphires(s), %d Emeralds(s), and %d Diamonds(s).\n", rubyCount,sapCount,emCount,diCount );
            int cash=sellgems(rubyCount,sapCount,emCount,diCount);
            return cash;
            break;
        }
        if(playerInput==-1)
        {
            printf("\nYou found %d Ruby(s), %d Sapphires(s), %d Emeralds(s), and %d Diamonds(s).\n", rubyCount,sapCount,emCount,diCount );
            int cash=sellgems(rubyCount,sapCount,emCount,diCount);
            return cash;
            break;
        }
        if(playerInput==1)
        {
            if(probability>=20 && 100>=probability)
            {
                printf("You found nothing.\n");
            }

            else if(probability>=14 && 20>probability)
            {
                printf("You found a Ruby!\n");
                rubyCount++;
            }
            else if(probability>=8 && 14>probability)
            {
                printf("You found a Sapphire!\n");
                sapCount++;
            }
            else if(probability>=2 && 8>probability)
            {
                printf("You found an Emerald!\n");
                emCount++;
            }
            else if(2>=probability)
            {
                printf("You found a Diamond!\n");
                diCount++;
            }
        }
    }
}
//bird watching activity function
//counts the number of pictures the player snapped of different birds and which is limited to 5 pictures and at the end it calls the selling function to tell the player their profits
int bird_watching()
{
    int dovCount=0;
    int croCount=0;
    int sgCount=0;
    int bluejCount=0;
    int playerInput;

    printf("\nLet's go birdwatching!\n");
    //while loop that does not stop unless inventory reaches 5 or the player types "-1"
//when it stop it adds the amount of money profited from selling to wallet in the main function and lets them know how much they made from taking pictures and how many birds they snapped a picture of
    while(1)
    {


        srand(time(NULL));
        int probability=(rand()% 100)+1;


        printf("\nAre you ready to snap photos?\n (1=yes,-1=quit)\n");

        scanf("%d",&playerInput);
        if(dovCount+croCount+sgCount+bluejCount==5)
        {
            printf("\nYour inventory is full,proceeding to sell what you got.\n");
            printf("You saw %d Dove(s), %d Crow(s), %d Sea gull(s), and %d Blue Jay(s).\n", dovCount,croCount,sgCount,bluejCount);
            int cash=sellpics(dovCount,croCount,sgCount,bluejCount);
            return cash;
            break;
        }
        if(playerInput==-1)
        {
            printf("\nYou saw %d Dove(s), %d Crow(s), %d Sea gull(s), and %d Blue Jay(s).\n", dovCount,croCount,sgCount,bluejCount);
            int cash=sellpics(dovCount,croCount,sgCount,bluejCount);
            return cash;
            break;
        }
        if(playerInput==1)
        {
            if(probability>=90 && 100>=probability)
            {
                printf("You took a picture of nothing.\n");
            }
            else if(probability>=65 && 90>probability)
            {
                printf("You took a picture of a Dove!\n");
                dovCount++;
            }
            else if(probability>40 && 65>probability)
            {
                printf("You took a picture of a Crow!\n");
                croCount++;
            }
            else if(probability>=15 && 40>probability)
            {
                printf("You took a picture of a Seagull!\n");
                sgCount++;
            }
            else if(15>=probability)
            {
                printf("You took a picture of a Jay!\n");
                bluejCount++;
            }
        }
    }
}
//sell function for fishs
//gets the number of fishes in the parameters and multiplies the value of each and returns and prints the total
int sellfish(int snookCount,int troutCount,int catfishCount,int koiCount)
{
    int total=(snookCount*500) + (troutCount*1000) + (catfishCount*3500) + (koiCount*5000);
    printf("You made: $%d\n",total);
    return total;
}
//sell function for gems
//gets the number of each gem in the parameters and multiplies the value of each and returns and prints the total
int sellgems(int rubyCount,int sapphireCount,int emeraldCount,int diamondCount)
{
    int total=(rubyCount*10000)+(sapphireCount*10000)+(emeraldCount*10000) +(diamondCount*20000);
    printf("You made: $%d\n",total);
    return total;
}
//sell function for birdwatching
//gets the number of pictures in the parameters and multiplies the value of each and returns and prints the total
int sellpics(int doveCount,int crowCount,int seagullCount,int bluejayCount)
{
    int total= (doveCount*500)+(crowCount*500)+(seagullCount*500) +(bluejayCount*1000);
    printf("You made: $%d\n",total);
    return total;
}
