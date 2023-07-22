//Matthew Hernandez
//UCFID: 5357015
//2021/11/29
//in this code I created a function that allowed the user to check if a word was a palindrome, convert a word to Leet speak,encode a phrase using the ceaser cipher, and decrypt a phrase encoded using the ceaser cipher

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//this is the constant I used to put in the strings length
#define MAX_LEN 20

//prototype of the palindrome function which checks if a word inputted by the user is a palindrome
void Palindrom(char string[]);

//the leet translate function prototype it will ask the user for a word and then return it in leet speak
void LeetTranslate(char string[]);

//prototype of the ceaser cipher function, which asks for a phrase to encode in the cypher and returns it back to the user
void CeaserCipher(char string[]);

//prototype of the solve cipher function, which asks for a phrase to decode and returns the original phrase back to the user
void SolveCypher(char string[]);

int main(void) {

  //the main string inputted to each function
  char mainString[MAX_LEN];
  printf("\n Welcome to the Word Processor! \n");

  //while loop that works as the menu for the program
  while(1)
  {
    //this variable is what the user will input into the scanf statement and directs them to the function they want to do
    int input;

    printf("\n What function do you want to do?\n");
    printf(" 1= Palindrome Checker\n 2= 1337 Sp3ak Converter\n 3= Encrypt Message\n 4= UnEncryptMessage\n-1= Quit\n ");

    scanf("%d", &input);

    //if statement that stops the program
    if(input==-1)
    {
      printf("\n Goodbye, you ended the program.");
      break;
    }
    //if statement that leads to the Palindrom function
    else if(input==1)
    {
      Palindrom(mainString);
    }
    //if statment that leads to the Leet traslator function
    else if(input==2)
    {
      LeetTranslate(mainString);
    }
    //if statement that leads to the Ceaser cipher function
    else if(input==3)
    {
      CeaserCipher(mainString);

    }
     //if statment that leads to the SolveCypher function
    else if(input==4)
    {
    SolveCypher(mainString);
    }
    //else statement that prints incase the user inputs a word thats not an availiable option
    else
      printf("Please pick a valid option.\n");
  }

  return 0;
}

// the palindrome function which checks if a word inputted by the user is a palindrome and returns whether it is or not
void Palindrom(char string[])
{
  //this string is used to know if the inputted string is the same but backwards
  char backWards[MAX_LEN]="a";
  int g=0;

  //print and scanf statment asks the user for the word
  printf("Please enter a word: \n");
  scanf("%s",string);

  //for loop that inputs the reverse of the inputted string into backwards
  for(int i=strlen(string);i>=0;i--)
  {
    backWards[g]=string[i-1];
     g++;

  }

  //if and else statement that compares to see if both strings are the same and then prints whether it is
  if(strcmp(string,backWards) == 0)
  {
    printf("'%s' is a Palindrome.\n",string);
  }
  else
  {
   printf("'%s' was not a Palindrome.\n",string);
  }
}

//the leet translate function asks the user for word and returns it in leet speak
void LeetTranslate(char string[])
{
  char inputLeet[MAX_LEN];

  //print and scanf statement that asks for the word
  printf("Please enter a word: \n");
  scanf("%s",inputLeet);

  //for loop that changes a select amount of characters to numbers
  for(int i=0;i<strlen(inputLeet);i++)
  {
    if(inputLeet[i]=='o'||inputLeet[i]=='O')
    inputLeet[i]='0';
    if(inputLeet[i]=='a'||inputLeet[i]=='A')
    inputLeet[i]='4';
    if(inputLeet[i]=='B'||inputLeet[i]=='b')
    inputLeet[i]='8';
    if(inputLeet[i]=='E'||inputLeet[i]=='e')
    inputLeet[i]='3';
    if(inputLeet[i]=='G'||inputLeet[i]=='g')
    inputLeet[i]='6';
    if(inputLeet[i]=='L'||inputLeet[i]=='l')
    inputLeet[i]='1';
    if(inputLeet[i]=='s'||inputLeet[i]=='S')
    inputLeet[i]='5';
    if(inputLeet[i]=='t'||inputLeet[i]=='T')
    inputLeet[i]='7';

  }

  //copying the inputted word to string so that it can be returned back to the user
  strcpy(string,inputLeet);
  printf("Leet Word: %s \n",string);
}

// the ceaser cipher function, which asks for a phrase to encode in the cypher and returns it
void CeaserCipher(char string[])
{

  //int and string used to get input from user
  int wordsNum;
  char inputCeaser[MAX_LEN];

  //asking for amount of words
  printf("How many words in your message? \n");
  scanf("%d",&wordsNum);

  //gets the phrase from user
  printf("Please enter the message: ");
  scanf("\n");
  scanf("%[^\n]s",inputCeaser);

  //this is the main for loop of the function that raises the original character to three characters up and loops in the alphabet
  for(int i=0;i<strlen(inputCeaser);i++)
  {
    char a=inputCeaser[i];
    //if statement for lower case letters
    if(a>='a' && a<='z')
    {
      a=a-3;
      if(inputCeaser[i]=='c')
      {
        a='z';
      }
      if(inputCeaser[i]=='b')
      {
        a='y';
      }
      if(inputCeaser[i]=='a')
      {
        a='x';
      }

    }

    //if statement for upper case letters
    if(a>='A' && a<='Z')
    {
      a=a-3;
      if(inputCeaser[i]=='C')
      {
        a='Z';
      }
      if(inputCeaser[i]=='B')
      {
        a='Y';
      }
      if(inputCeaser[i]=='A')
      {
        a='X';
      }
    }
    inputCeaser[i]=a;

  }

  //copying the string to the string in the parameter of the function and printing out the result
  strcpy(string,inputCeaser);
  printf("Encoded Message: ");
  printf("%s \n",string);

}

//the solve cipher function asks for a phrase to decode and returns the original phrase
void SolveCypher(char string[])
{
  //int and string used to get input from user
  int solveWords;
  char inputSolve[MAX_LEN];

  //asking for the amount of words in thier phrase
  printf("How many words are in your encrypted message?\n");
  scanf("%d",&solveWords);

  //asking the user for the phrase they went to decrypt
  printf("Type the message now: ");
  scanf("\n");
  scanf("%[^\n]s", inputSolve);

  //for loop that is the same concept as the previous one in the encrypt function but it reverses the effect and goes up three characters
  for(int i=0;i<strlen(inputSolve);i++)
  {
    char a=inputSolve[i];

    //if statement for lower case letters
    if(a>='a' && a<='z')
    {
      a=a+3;
      if(inputSolve[i]=='z')
      {
        a='c';
      }
      if(inputSolve[i]=='y')
      {
        a='b';
      }
      if(inputSolve[i]=='x')
      {
        a='a';
      }

    }

    //if statement for upper case letters
    if(a>='A' && a<='Z')
    {
      a=a+3;
      if(inputSolve[i]=='Z')
      {
        a='C';
      }
      if(inputSolve[i]=='Y')
      {
        a='B';
      }
      if(inputSolve[i]=='X')
      {
        a='A';
      }
    }
    inputSolve[i]=a;


  }

  //copying the string to the string the function's parameter and printing it
  strcpy(string,inputSolve);
  printf("Encoded Message: ");
  printf("%s \n",inputSolve);
}
