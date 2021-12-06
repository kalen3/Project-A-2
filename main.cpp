#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_LEN = 50;
const int OFFSET = 'a' - 'A';

//function prototypes
bool Isalphabet(char);
bool Isdigit(char);
char toLower(char);
char toUpper(char);

//main
int main() 
{
  //variables
  string check1;
  int string_len  = 0;
  int numOfValid = 0;
  int numOfInvalid = 0;
  int plusCount = 0;
  int minusCount = 0;
  int decimalCount = 0;
  int eCount = 0;

  ifstream myfile ("example.txt");

  if (myfile.is_open())
  {
    while ( getline (myfile,check1) )
    {
      //Check for line being blank
      if (check1.empty())
      {
        cout << "Line is empty. \n";
      }
      cout << check1 << endl;
      
      //For loop to check every input on line
      for (int i = 0; i < MAX_LEN; i++)
      {
        if (Isdigit(check1[i]))
        {
          //cout << "Valid \n";
          string_len++;
          numOfValid++;
        }
        
        else if (Isalphabet(check1[i]))//use for e
        {
          if (check1[i] >= 'e' || check1[i] <= 'E') //condtion for input before
          {
            eCount++;//Create conditions
            //After checking for e or E create conditions for after e or E
            if (Isdigit(check1[i + 1]))
            {
              //cout << "Valid \n";
              numOfValid++;
            }
            else if ((check1[i+ 1] == '+') || (check1[i + 1] == '-'))
            {
              //Plus or minus counter
              if (check1[i+ 1] == '+')
              {
                plusCount++;//Create conditions
              }
              else if (check1[i + 1] == '-')
              {
                minusCount++;//Create conditions
              }
              
              //Valid counter
              if (Isdigit(check1[i + 2]))
              {
                //cout << "Valid. \n";
                numOfValid++;
              }
              else 
              {
                //cout << "Invalid. \n";
                numOfInvalid++;
              }
            }
            else
            {
              //cout << "invalid. \n";
              numOfInvalid++;
            }
          }
          //Else statement for case that it passes alphabet but fails
          else 
          {
            //cout << "Invalid?(e) \n";
            numOfInvalid++;
          }
          string_len++;
        }

        //else if for + - starting
        else if ((check1[0] == '+') || (check1[0] == '-'))
        {
          //Plus or minus counter
          if (check1[0] == '+')
          {
            plusCount++;//Create conditions
            //cout << "Plus: " << plusCount << endl;
          }
          else if (check1[0] == '-')
          {
            minusCount++;//Create conditions
            //cout << "Minus: " << minusCount << endl;
          }

          //Statement for what's after i
          if (Isdigit(check1[i + 1]))//maybe begin offset
          {
            //cout << "Valid. \n";
            numOfValid++;
          }

          //Statement for what's before i

          else 
          {
            //cout << "Invalid. \n";
            numOfInvalid++;
          }
          string_len++;
        }

        //else if for . (only one .)
        else if (check1[i] == '.')
        {
          decimalCount++;//Create conditions
          if (Isdigit(check1[i - 1]))
          {
            //cout << "valid \n";
            numOfValid++;
          }
          else if (Isdigit(check1[i + 1]))
          {
            //cout << "valid \n";
            numOfValid++;
          }
          else
          {
            //cout << "Invalid \n";
            numOfInvalid++;
          }
          string_len++;
        }

        //else statement saying anything else invalid
        else
        {
          //cout << "nvalid. \n";
          numOfInvalid++;
          //string_len++;
          i = MAX_LEN;
        }
      }

      //Change b/c if valid = 0
      if (numOfValid >= numOfInvalid)
      {
        //New conditions for + - . e
        if ((plusCount > 1) || (minusCount > 1) || (decimalCount > 1) || (eCount > 1))
        {
          cout << "This is Not a literal. \n";//Create more conditions for + -
        }
        else
        {
          cout << "This is a literal. \n";
        }
        cout << "This is a literal. \n";
      }
      else
      {
        cout << "This is not a literal. \n";
      }
      //cout << "Valid: " << numOfValid << endl;
      //cout << "Invalid: " << numOfInvalid << endl;
      //cout << "Len: " << string_len << endl;
      cout << "Plus: " << plusCount << endl;
      cout << "Minus: " << minusCount << endl;
      cout << endl;

      //reset counters
      string_len = 0;
      numOfValid = 0;
      numOfInvalid = 0;
      plusCount = 0;
      minusCount = 0;
      decimalCount = 0;
      eCount = 0;
    }
    myfile.close();
  }
} 

bool Isalphabet(char letter)
{
  return ((letter >= 'A' && letter <= 'Z') ||
          (letter >= 'a' && letter <= 'z'));
}

bool Isdigit(char digit)
{
  return (digit >= '0' && digit <= '9');
}

char toLower(char letter)
{
  if (letter >= 'A' && letter <= 'Z')
  {
    letter = letter + OFFSET;
  }
  return letter;
}

char toUpper(char letter)
{
  if (letter >= 'a' && letter <= 'z')
  {
    letter = letter - OFFSET;
  }
  return letter;
}