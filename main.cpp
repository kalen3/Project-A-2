#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_LEN = 6;
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
          cout << "Valid \n";
          string_len++;
          numOfValid++;
        }
        
        else if (Isalphabet(check1[i]))//use for e
        {
          if (check1[i] >= 'e' || check1[i] <= 'E') //condtion for input before
          {
            //After checking for e or E create conditions for after e or E
            if (Isdigit(check1[i + 1]))
            {
              cout << "Valid \n";
              numOfValid++;
              //string_len++;
            }
            else if ((check1[i+ 1] == '+') || (check1[i + 1] == '-'))
            {
              if (Isdigit(check1[i + 2]))
              {
                cout << "Valid. \n";
                numOfValid++;
                //string_len++;
              }
              else 
              {
                cout << "Invalid. \n";
                numOfInvalid++;
                //string_len++;
              }
            }
            else
            {
              cout << "invalid. \n";
              numOfInvalid++;
              //string_len++;
            }
          }
          //Else statement for case that it passes alphabet but fails
          else 
          {
            cout << "Invalid?(e) \n";
            numOfInvalid++;
          }
          string_len++;
        }

        //else if for + - starting
        else if ((check1[i] == '+') || (check1[i] == '-'))
        {
          //Statement for what's after i
          if (Isdigit(check1[i + 1]))//maybe begin offset
          {
            cout << "Valid. \n";
            numOfValid++;
          }

          //Statement for what's before i

          else 
          {
            cout << "Invalid. \n";
            numOfInvalid++;
            //string_len++;
          }
          string_len++;
        }

        //else if for . (only one .)
        else if (check1[i] == '.')
        {
          if (Isdigit(check1[i - 1]))
          {
            cout << "valid \n";
            numOfValid++;
            //string_len++;
          }
          else if (Isdigit(check1[i + 1]))
          {
            cout << "valid \n";
            numOfValid++;
            //string_len++;
          }
          else
          {
            cout << "Invalid \n";
            numOfInvalid++;
            //string_len++;
          }
          string_len++;
        }

        //else statement saying anything else invalid
        else
        {
          cout << "nvalid. \n";
          numOfInvalid++;
          //string_len++;
          //invalid++;
          //maybe use this else as strings MAX_LEN
          i = MAX_LEN;
        }
      }

      //Change b/c if valid = 0
      if (numOfValid >= numOfInvalid)
      {
        cout << "This is a literal. \n";
      }
      else
      {
        cout << "This is not a literal. \n";
      }
      //cout << "Valid: " << numOfValid << endl;
      //cout << "Invalid: " << numOfInvalid << endl;
      //cout << "Len: " << string_len << endl;
      cout << endl;

      //reset counters
      string_len = 0;
      numOfValid = 0;
      numOfInvalid = 0;
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