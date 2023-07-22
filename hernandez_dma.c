//Matthew Hernandez
//UCFID: 5357015
//2021/12/03
//in this code I used linked list and structs to create a program where you can input information about houses in a row
//the program lets you get sum of residents and prints out the whole array of houses
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main struct used throughout the code
//contains name of owner, number of residents in the house and the next house struct
struct House{
    struct House* next;
    char* name;
    int numPeeps;
};
//crating a new data type for the house struct
typedef struct House house;
//prototype for creating a new House struct
house* GetHouse();
//prototype for inputting a new house
void Inputhouse(house* root, house* insertMe);
//prototype function for getting the sum of residents
int sumResidents(house* root);
//prototype function for printing the whole array/row of houses
void printBlock(house* root);

int main()
{
    //this is the corner house called root
    house* root = (house*) malloc(sizeof(house));

    printf("Lets make the corner house.\n");

    //user goes to create root house
    root=GetHouse();


    while(1)
  {
      //menu asking the user for input
    printf("\nWhat function do you want to do?\n");
    printf(" 1= Add New House\n 2= Get Number of Residents\n 3= Print Neighborhood\n-1= Quit\n ");
    int userInput;
    scanf("%d",&userInput);

    //if statement that stops the program
    if(userInput==-1)
    {
      printf("\nGoodbye, you quit the program.");
      break;
    }
    //if statement that inserts new house
    else if(userInput==1)
    {

        Inputhouse(root, GetHouse());
        continue;
    }
    //if statement that calls to the function that gets the number of residents
    else if(userInput==2)
    {

      sumResidents(root);
        continue;
    }
    //if statement that prints all houses on the block
    else if(userInput==3)
    {
        printf("\nThe houses in the row were:\n");
        printBlock(root);
        continue;

    }

    //else statement that prints in case the user inputs a word thats not an available option
    else
      printf("Please pick a valid option.\n");
  }

  return 0;
}
//function for inputting a new house using the root and a new house parameter
void Inputhouse(house* root, house* insertMe)
{
    //creating new house with a while loop that makes sure the next one is NULL
   house* currentHouse = root;
    while(currentHouse->next!= NULL)
    {
        currentHouse = currentHouse->next;
    }
    currentHouse->next = insertMe;


}
//function that creates house by getting user input
house* GetHouse()
{
    //variables for fields of struct
    char name[100];
    int peeps;

    printf("Who lives here?\n");
    scanf("%s",&name);

    printf("How many people live here?\n");
    scanf("%d", &peeps);

    int lengName = strlen(name) + 1;
    //allocating the memory for the string "name"
    char* tName= (char*) malloc(sizeof(char) * lengName);

    strcpy(tName, name);

    //allocating memory for the house being returned
    house* newHouse = (house*) malloc(sizeof(house));

    //changing fields for newHouse from user input
    newHouse->numPeeps = peeps;
    newHouse->name = tName;
    newHouse->next=NULL;

    return newHouse;

}
//function that sums up the residents in each home
int sumResidents(house* root)
{
    //uses an  int and new house for the function
    house* currentHouse = root;
    int total=0;
    //while loop that goes through each house and adds the residents to total
 while(currentHouse!=NULL)
{
    total=total+currentHouse->numPeeps;
    currentHouse= currentHouse->next;
}
 printf("\n The total number of residents on the block is %d.\n",total);

}
//final function that prints the row of houses
void printBlock(house* root)
{
    //while loop going through each house and printing the owner and number of people who live in each house
    while(root!= NULL)
    {
        printf(" House Owner and those living in the house: %s %d\n", root->name,root->numPeeps);
        root = root->next;
    }

}

