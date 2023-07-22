//Matthew Hernandez
//UCFID: 5357015
//2021/10/28
//in this code I created a function that allowed the user to create, delete and input data for fictional E-sports teams using
//I used a matrix to store the data and had different functions for every action

#include <stdio.h>
#include <stdlib.h>
//these are constants that are used in the main matrix and for the parameters of the functions
#define TOTAL_TEAMS 10
#define TEAM_DATA 3

//this function adds team ID to the matrix in the first column
void createTeam(int matrix[][TEAM_DATA]);
//function that deletes the data of a team and reverses the values to 0
void deleteData(int matrix[][TEAM_DATA]);
//function for inputting wins and losses to the teams
void inputData(int matrix[][TEAM_DATA]);
//prints the data for the user by choosing an existing team
void getData(int matrix[][TEAM_DATA]);

int main()
{
    printf("Welcome to the UnderIgnore E-Sports Win/Loss Tool!\n");

    //First userInput variable and matrix for the whole function
    int userInput1=0;
    int dataMatrix[TOTAL_TEAMS][TEAM_DATA]={0};

    //this while loop is the menu and where the user gets directed to different actions
    while(1)
    {
        printf("\nWhat function do you want to do?\n1= Add New Team \n2= Remove Team \n");
        printf("3= Update Data for a team \n4= Get Data for a team \n-1= End Program\n");
        scanf("%d",&userInput1);

        //this if statement end the while loop and the program
        if(userInput1==-1)
        {
            printf("Goodbye!");
            break;
        }
        //if the user puts 1 it will allow them to create a new team
        else if(userInput1==1)
            createTeam(dataMatrix);

        //if the user puts 2 it will allow them to delete a team
        else if(userInput1==2)
            deleteData(dataMatrix);

        //if the user puts 3 it will allow them to input win/loss data to a team
        else if(userInput1==3)
            inputData(dataMatrix);

        //if the user puts 4 it will give them the data they put for a team
        else if(userInput1==4)
            getData(dataMatrix);

        //this else statements is for when the user picks an invalid option
        else
            printf("Please input a valid option.\n");
    }
    return 0;
}
//this function creates a team when it ask for user input on the team ID
void createTeam(int matrix[][TEAM_DATA])
{
    //the variable input is for what team ID the user wants to add
    int input=0;
    printf("Enter a team ID: ");
    scanf("%d",&input);
    // this for loop goes through the first column of the matrix to put in and store the value from the user
    //the loop also tells the user if they put in a duplicate team ID
    for(int i=0;i<TOTAL_TEAMS;i++)
    {
        if(matrix[i][0]==0)
        {
            matrix[i][0]=input;
            return;

        }
        if(matrix[i][0]==input)
        {
            printf("ERROR: Duplicate team ID \n");
            return;
        }
    }
}
//this function deletes the data of a team ID chosen by the user
void deleteData(int matrix[][TEAM_DATA])
{
    //the variable input is for what team the user wants to delete
    int input;
    printf("Enter a team ID: ");
    scanf("%d",&input);
    //for loop that erases the data for a team and will ask the user to make an ID first if their input is not in the matrix
    for(int i=0;i<TOTAL_TEAMS;i++)
    {
        if(matrix[i][0]==input)
        {
            matrix[i][0]=0;
            matrix[i][1]=0;
            matrix[i][2]=0;
            break;
        }
        if(matrix[i][0]!=input)
        {
            printf("Please make the team ID first.\n");
            return;

        }
    }
}
//this function lets the user put in the data for win and losses if a team was already made
void inputData(int matrix[][TEAM_DATA])
{

    //the variable input is for what team the user wants to add data to
    int input;
    printf("What team do you want to update data for? \n");
    scanf("%d",&input);
    //this for loop is to check that the inputted value is in the matrix
    for(int i=0;i<TOTAL_TEAMS;i++)
    {
        if(matrix[i][0]!=input)
        {
            printf("Please make the team ID first.\n");
            return;
        }
        else
            break;
    }
    //while loop for inputting wins/losses and will ask again if the user puts an invalid option for the second question
    while(1)
    {
        //the variable input2 is for what option the user wants to add data to
        int input2;
        printf("What team do you want to update data for?(1=win,2=lose) \n");
        scanf("%d",&input2);
        //the if statement lets the user input wins for the chosen team
        if(input2==1)
        {
            //the variable input3 is for how many wins the team got
            int input3;
            printf("How many wins? \n");
            scanf("%d",&input3);
            //for loop that puts the input into the matrix and returns to main function
            for(int i=0;i<TOTAL_TEAMS;i++)
            {
                if(matrix[i][0]==input)
                {
                    matrix[i][1]=input3;
                    return;
                }
            }
        }
        //the if statement lets the user input losses for the chosen team
        else if(input2==2)
        {
            //the variable input4 is for how many losses the team got
            int input4;
            printf("How many losses? \n");
            scanf("%d",&input4);
            //for loop that puts the input into the matrix and returns to main function
            for(int i=0;i<TOTAL_TEAMS;i++)
            {
                if(matrix[i][0]==input)
                {
                    matrix[i][2]=input4;
                    return;
                }
            }
        }
        //else statement when the user does not put a valid option
        else
        {
            printf("Please input a valid option.\n\n");
        }
    }
}
//function that reads the data based on what the user chooses
void getData(int matrix[][TEAM_DATA])
{
    //the variable input is for which team the user wants to see the data for
    int input=0;
    printf("Enter a team ID: ");
    scanf("%d",&input);
    //for loop that prints the row of data from the matrix and will return to the main menu if the team ID does not exist
    for(int i=0;i<TOTAL_TEAMS;i++)
    {
        if(matrix[i][0]==input)
        {
            printf("\nPrinting Data... \nTeam ID: %d \nTeam Wins: %d \nTeam Losses:%d \n",matrix[i][0],matrix[i][1],matrix[i][2]);
            return;

        }
        if(matrix[i][0]!=input)
        {
            printf("Please make the team ID first.\n");
            return;

        }
    }
}
