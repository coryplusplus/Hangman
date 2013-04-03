//Author : Cory Kelly
//Date : July 23, 2012


//Includes
//Includes are used to access functions and class types that have previously been created
//This stops an average developer from having to reinvent the wheel each time he goes to code something

//the iostream library is used for the cin and cout methods.
#include <iostream>

//the string library lets us use strings in our code. Strings are basically x number of characters combined together
//many useful methods have already been written for strings and all you have to do is google c++ string to find what you want
//Strings can be added together
//string example1 = "dog";
//string example2 = "cat";
//string example3 =  example1 + example2;
//To access a strings built in methods simply type example3.
//The . after the string tells the compiler to expect a class member next.
//Look through this code for examples of strings and thier associated members.
#include <string>

//the vector library will eventaully become your best friend. A vector is a gift from god and is simply a way to store multiple objects of the same type.
//to add objects to vectors you can simply call vectorname.push_back(object)
//to empty a vector you can call vectorname.clear()
//Vectors are extremely useful and you can find more vector methods by looking online
#include <vector>

//I pulled this library in to use the rand() method which generates a random number.
//It isn't the best way to generate random numbers but since this was simply an example program I figured I would use it.
#include <cstdlib>

//I wouldn't worry too much about namespaces at this point
using namespace std;


//This following lines are global variable declarations
//What makes these variables global(usable by all functions in this file) is because they are not defined inside of a single function
//If one function changes the value of these global variables, the value will still be changed when another function uses them.


//Defining variables:
//Variables are one of the most important things in any programming language.
//The way we define a variable in c++ is 
//variableType variableName
//Some common variableTypes include 
//char - A single character
//string - multiple characters combined together
//int - an integer
//long - a long integer
//bool - a true or false value (1 or 0)
//You can google other types of variables and eventually I will teach you how to define your own and use those within a program (Classes)
//There are a few rules with how you can define variable names
/*/
    Variable names can consist of:
        Letters
        Digits
        Underscores

    Example: "num1" to store the first of 3 numbers

    Variable names cannot start with a digit.

    Example: "3integers" is illegal

    Variable names should not start with an underscore.

    Example: Avoid the use of variable names like "_number"

    Variable names should consist of 31 or fewer characters to ensure portability.

    Variable names should be descriptive of their use.

    Example: "grade" would be a good name to use for a variable that stores
    a student's test grade.

    Variable names are case sensitive.

    Example: "x1" is not the same as "X1"

    Keywords such as "int" and "float" cannot be used as variable names.
/*/





//The const keyword defines the variable as constant.
//This means that the value we give it here will be the value it contains its entire life. No other methods can change the value of a constant variable.
const int num_words = 14;
const string words[14] = {"zigzagging","pinto","horse","cactus","roach","wigwagging","grogginess","beekeeping","mummifying","fluffiness","fulfilling","shabbiness","revivified","hobnobbing"};
string workingCopy = "";
vector<char> guessedLetters;
int wrongGuesses = 0;
bool won = false;


//This is what we call a function/method.
//A function declaration will take the form of the following
//returnType functionName (parameter list)
//For the Initialize method you will notice that the return type is void because the function
//is not returning a value. You will also notice there are no parameters needed to call this method
//because this method is solely responsible for initializing our global variables after each game played.
void Initialize()
{
    workingCopy = "";
    guessedLetters.clear();
    wrongGuesses = 0;
    won = false;
}

//As you will notice the return type for this method is "string"
//This is because this method will return a string to whoever decides to call it.
string getWord()
{
    //the % operator is worth mentioning here.
    //It basically means divide the right number into the left and return the remainder
    //So 5 % 5 would return 0
    //10 % 3 would return 1
    //20 % 13 would return 7
    int num = rand() % num_words;
    return words[num];
}

//This is our first method that contains a parameter.
//Parameters are listed like the following
//(parameterType parameterName, parameterType parameterName, etc)
//Of course if you include the const keyword, that means that during the life of the method
//the parameter can not be changed.
//The & in front of a parameter name means pass this value by reference.
//Google "Pass by reference c++" for more information on this topic.
void print_word(const string &word)
{
    cout<<endl;
    cout<<"Try and guess the following word!"<<endl;
    cout<<"Number of letters: "<<word.size()<<endl;
    for(int i = 0; i < word.size(); i++)
    {
        cout<<" _ ";
        workingCopy = workingCopy + "_";
    }
    cout<<endl<<endl;

}

void WelcomeScreen1()
{   
    cout<<"_________________________________________________________________"<<endl;
    cout<<"          _    _      _____    _      _    _    _"<<endl;
    cout<<"|     |  / \\  | \\   ||        | \\    / |  / \\  | \\   |"<<endl;
    cout<<"| --- | /---\\ |  \\  ||  ----- |  \\  /  | /---\\ |  \\  |"<<endl;
    cout<<"|     |/     \\|   \\_||______| |   \\/   |/     \\|   \\_|"<<endl;
    cout<<"_________________________________________________________________"<<endl;
}
void WelcomeScreen()
{
    cout<<endl;
    cout<<"Welcome to Hangman!"<<endl;
    cout<<"   _________"<<endl;
    cout<<"   |        |"<<endl;
    cout<<"   |"<<endl;
    cout<<"   |"<<endl;
    cout<<"   |"<<endl;
    cout<<"   |"<<endl;
    cout<<"   |"<<endl;
    cout<<"___|___"<<endl;
    cout<<endl;
}

void None()
{
    cout<<endl;
    cout<<"                       HANGMAN"<<endl;
    cout<<"                       _________"<<endl;
    cout<<"                       |        |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                    ___|___"<<endl;
    cout<<endl;
}

void Head()
{
    cout<<endl;
    cout<<"                       HANGMAN"<<endl;
    cout<<"                       _________"<<endl;
    cout<<"                       |        |"<<endl;
    cout<<"                       |        O"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                    ___|___"<<endl;
    cout<<endl;
}

void Body()
{
    cout<<endl;
    cout<<"                       HANGMAN"<<endl;
    cout<<"                       _________"<<endl;
    cout<<"                       |        |"<<endl;
    cout<<"                       |        O"<<endl;
    cout<<"                       |        |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                    ___|___"<<endl;
    cout<<endl;
}

void ArmOne()
{
    cout<<endl;
    cout<<"                       HANGMAN"<<endl;
    cout<<"                       _________"<<endl;
    cout<<"                       |        |"<<endl;
    cout<<"                       |        O"<<endl;
    cout<<"                       |       /|"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                    ___|___"<<endl;
    cout<<endl;
}

void ArmTwo()
{
    cout<<endl;
    cout<<"                       HANGMAN"<<endl;
    cout<<"                       _________"<<endl;
    cout<<"                       |        |"<<endl;
    cout<<"                       |        O"<<endl;
    cout<<"                       |       /|\\"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                    ___|___"<<endl;
    cout<<endl;
}

void LegOne()
{
    cout<<endl;
    cout<<"                       HANGMAN"<<endl;
    cout<<"                       _________"<<endl;
    cout<<"                       |        |"<<endl;
    cout<<"                       |        O"<<endl;
    cout<<"                       |       /|\\"<<endl;
    cout<<"                       |       /"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                    ___|___"<<endl;
    cout<<endl;
}

void LegTwo()
{
    cout<<endl;
    cout<<"                       HANGMAN"<<endl;
    cout<<"                       _________"<<endl;
    cout<<"                       |        |"<<endl;
    cout<<"                       |        O"<<endl;
    cout<<"                       |       /|\\"<<endl;
    cout<<"                       |       / \\"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                       |"<<endl;
    cout<<"                    ___|___"<<endl;
    cout<<endl;
}


void displayHangman()
{
    switch (wrongGuesses)
    {
        case 0:
            None();
            break;
        case 1:
            Head();
            break;
        case 2:
            Body();
            break;
        case 3:
            ArmOne();
            break;
        case 4:
            ArmTwo();
            break;
        case 5:
            LegOne();
            break;
        case 6:
            LegTwo();
            break;
        default:
            None();
            break;
    }
}



bool checkLetter(string word, char letter)
{
    cout<<endl;
    int found = word.find(letter);
    guessedLetters.push_back(letter);
    int offset = 0;
    if(found != string::npos)
    {
        workingCopy.at(found) = letter;
        for(int i = 0; i < word.size(); i++)
        {
            if(word.at(i) == letter)
                workingCopy.at(i) = letter;
        } 
        cout<<"----------CORRECT!----------"<<endl;
        cout<<"Word: "<<workingCopy<<endl;
        return true;
    }
    else 
    {
        wrongGuesses++;
        cout<<"----------INCORRECT GUESS!----------"<<endl;
        cout<<"Word:  "<<workingCopy<<endl;
        return false;
    }
}

void GuessLetter(string word)
{
    cout<<endl;
    bool isAlpha = false;
    bool alreadyGuessed = false;
    cout<<"Please guess a letter..."<<endl;
    char letter;
    cin>>letter;
    while(!isAlpha)
    {
        if(!isalpha(letter))
        {
            cout<<"That is not a letter moron, please try again."<<endl;
            cin>>letter;
        }
        else
        {
            isAlpha = true;
            for(int i = 0; i < guessedLetters.size(); i++)
            {
                if(guessedLetters.at(i) == letter)
                    alreadyGuessed = true;
            }

            if(!alreadyGuessed)
            {
                checkLetter(word,letter);
            }
            else
            {
                cout<<"You have already guessed this letter amigo!"<<endl;
            }
        }
    }

    cout<<endl;
    cout<<"         ________________________________________"<<endl;
    cout<<"        | You have guessed the following letters |"<<endl;
    cout<<"         ";
    for(int i = 0; i < guessedLetters.size(); i++)
    {
        cout<<" "<<guessedLetters.at(i);
    }
    cout<<endl;
    cout<<"         ----------------------------------------"<<endl;
    cout<<endl;

}

void gameOver()
{
    cout<<endl;
    cout<<endl;
    cout<<"----GAME OVER----"<<endl;
    cout<<endl;
    cout<<endl;
}

void CheckWin()
{
    bool foundUnderscore = false;
    for(int i = 0; i < workingCopy.size(); i++)
    {
        if(workingCopy.at(i) == '_')
            foundUnderscore = true;
    }
    if(!foundUnderscore)
        won = true;

}


void WonScreen()
{
    cout<<endl;
    cout<<endl;
    cout<<"YOU JUST WON! You may be the smartest person alive."<<endl;
    cout<<endl;

}

//In order for a c++ program to run it needs an entry point. 
//The main() method is that entry point. 
//Every c++ program you write will need to have a main() method
int main()
{
    WelcomeScreen1();
    WelcomeScreen();
    bool again = true;
    //start of game. Will need to loop this based on user response to play
    while(again)
    {
        Initialize();
        string currentWord = getWord();
        print_word(currentWord);
        while(wrongGuesses < 6 && !won)
        {
            GuessLetter(currentWord);
            displayHangman();
            CheckWin();
        }
        if(won)
            WonScreen();
        else
            gameOver();
        cout<<endl;
        cout<<"Would you like to play again (y/n): ";
        char playAgain;
        cin>>playAgain;
        while(playAgain!='y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N')
        {
            cout<<"I do not understand."<<endl<<"Would you like to play again(YES(y) OR NO(n) FOOL): ";
            cin>>playAgain;
            cout<<playAgain<<endl;
        }
        if(playAgain == 'n' || playAgain == 'N')
            again = false;

    }
    return 0;
}


