//Matthew Hernandez
//UCFID: 5357015
//2021/10/10
//in this code I created a function that allowed the user to input data of heights for different categories of sports
//it will also return the averages of the heights in each sport or the total average height for all sports
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //variable for first user input and file declaration below
    int input;
    FILE *fp;
    FILE *fp2;
    fp = fopen("heightData.txt", "a");
    fp2 = fopen("heightData.txt", "r");

    //primitive type variables for finding the sum, count,and average of the height for players in each activity
    int sum1=0;
    int sum2=0;
    int sum3=0;
    double rowCount1;
    double rowCount2;
    double rowCount3;
    double average0=0;
    double average1=0;
    double average2=0;
    double average3=0;

    printf("Welcome to the Athlete Height Tally Tool. \n");
    //the main while loop that controls the whole function
    while(1)
    {
        // asking user what he action he wants to take
        printf("What do you want to do?\n");
        printf(" 1=Enter Height Data\n 2= Get Height Average(s)\n -1= Quit Program \n");
        scanf("%d",&input);
        // if statement that stops the program
        if(input==-1)
        {
            printf("\n Goodbye for now! ");
            break;
        }
        //while loop in a if statement for when the user wants to input data
        if(input==1)
        {
            //activityNum will write the number of the activity in the file depending on what the user chooses with the second input
            printf("Writing Data...Please hold\n");
            int activityNum;
            int input2;
            while(1)
            {
                printf("For what sport do you want to save data? \n 1= Track\n 2=Swimming\n 3=Soccer\n -1=Quit\n ");
                scanf("%d",&input2);
                //stops the function when user inputs -1
                if(input2==-1)
                    break;
                //this if statement will start when user chooses 1
                if(input2==1)
                {
                    while(1)
                    {
                        printf("Enter a value(-1=Quit)\n");
                        activityNum=1;
                        int inputData;
                        scanf("%d",&inputData);

                        if (inputData==-1)
                            break;

                        fprintf(fp,"%d %d\n",activityNum,inputData);
                        fflush(fp);
                    }
                }
                //this if statement will start when user chooses 2
                if(input2==2)
                {
                    while(1)
                    {
                        printf("Enter a value(-1=Quit)\n");
                        activityNum=2;
                        int inputData2;
                        scanf("%d",&inputData2);

                        if(inputData2==-1)
                            break;

                        fprintf(fp,"%d %d\n",activityNum,inputData2);
                        fflush(fp);
                    }
                }
                //this if statement will start when user chooses 3
                if(input2==3)
                {
                    while(1)
                    {
                        printf("Enter a value(-1=Quit)\n");
                        activityNum=3;
                        int inputData3;
                        scanf("%d",&inputData3);

                        if(inputData3==-1)
                            break;

                        fprintf(fp,"%d %d\n",activityNum,inputData3);
                        fflush(fp);
                    }
                }
                // if the user writes something that is not an option then this if statement will tell him to choose an available option
                if(input2!=1&&input2!=2&&input2!=3&&input2!=-1)
                    printf("\nPlease pick a valid option. \n ");
            }
        }
        //this is the part of the function that reads the inputted data and prints an average depending on what the user writes
        if(input==2)
        {

            printf("Reading Data...Please Hold \n");
            int input3;

            // while loop that controls the second part of the function
            while(1)
            {
                printf("\nFor what sport do you want to see the average? \n0=All\n1=Track\n2=Swimming\n3=Soccer\n-1=Quit\n ");
                scanf("%d",&input3);

                //if statement that stops the while loop
                if(input3==-1)
                    break;
                //while loop for doing all the necessary math
                while(1)
                {
                    //below we scan the activity number and the data in each row, and add and divide(with a row counter) for each activity
                    int dataNum;
                    int readNum;

                    int totalRows= fscanf(fp2,"%d %d\n",&dataNum,&readNum);
                    //stops the while loop when it reaches the end of the rows
                    if(totalRows==EOF)
                        break;

                    if(dataNum==1)
                    {
                        sum1= sum1+readNum;
                        ++rowCount1;
                        average1=sum1/rowCount1;
                    }

                    if(dataNum==2)
                    {
                        sum2= (sum2+readNum);

                        printf("%d %d\n",readNum,sum2);
                        ++rowCount2;
                        average2=sum2/rowCount2;
                    }
                    if(dataNum==3)
                    {
                        sum3= sum3+readNum;
                        ++rowCount3;
                        average3=sum3/rowCount3;
                    }
                    average0=(sum1+sum2+sum3)/(rowCount1+rowCount2+rowCount3);
                }
                //when the user chooses 0 this if statement will give the average of all the heights in each category
                //if there are is no data then it will return the user to the start so they can input data
                if(input3==0)
                {
                    if(average0==0)
                    {
                        printf("There was no average for all the categories.\nPlease Input values first.\n \n");
                        break;
                    }
                    printf("The total average height was: %.2f\n", average0);
                }
                //when the user chooses 1 this if statement will give the average of all the heights in 'Track'
                //if there are is no data then it will return the user to the start so they can input data
                if(input3==1)
                {
                    if(average1==0)
                    {
                        printf("There was no average for this category.\nPlease Input values first. \n \n");
                        break;
                    }
                    printf("The average height was: %.2f\n", average1);
                }
                //when the user chooses 2 this if statement will give the average of all the heights in 'Swimming'
                //if there are is no data then it will return the user to the start so they can input data
                if(input3==2)
                {
                    if(average2==0)
                    {
                        printf("There was no average for this category.\nPlease Input values first.\n \n");
                        break;
                    }

                    printf("The average height was: %.2f\n", average2);
                }
                //when the user chooses 3 this if statement will give the average of all the heights in 'Soccer'
                //if there are is no data then it will return the user to the start so they can input data
                if(input3==3)
                {
                    if(average3==0)
                    {
                        printf("There was no average for this category.\nPlease Input values first.\n \n");
                        break;
                    }
                    printf("The average height was: %.2f\n", average3);
                }
                // if the user writes a number that is not an option then this if statement will run
                if(input3!=0&&input3!=1&&input3!=2&&input3!=3&&input3!=-1)
                    printf("\nPlease pick a valid option. \n ");
            }
        }
        // if the user writes a number that is not an option then this if statement will run
        if(input!=1&&input!=2&&input!=-1)
                    printf("\nPlease pick a valid option. \n ");
    }
//closing the file for appending and reading
 fclose(fp);
 fclose(fp2);
}
