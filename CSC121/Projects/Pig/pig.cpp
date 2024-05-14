#include<iostream>	
#include<string>
#include<cctype>
#include<limits>

using namespace std;

inline bool isVowelY(char c)
{
    //check if the char is a vowel
    return (c == 'A' || c == 'E' || c == 'I' ||
        c == 'O' || c == 'U' || c == 'a' ||
        c == 'e' || c == 'i' || c == 'o' ||
        c == 'u' || c == 'Y' || c == 'y');
}

inline bool isVowel(char c)
{
    //check if the char is a vowel
    return (c == 'A' || c == 'E' || c == 'I' ||
        c == 'O' || c == 'U' || c == 'a' ||
        c == 'e' || c == 'i' || c == 'o' ||
        c == 'u');
}

inline bool isPunct(char c)
{
    //check if the char is punctuation
    return (c == ',' || c == '.' || c == '?' || c == '!' || c == ':');
}

//function prototypes
string pigLatin(string s);

int main(void)
{
    // declaring variables
    string line,     //user entered line     
           word,     //user entered word   
           pigLine,  //translated line  
           preSpace, //space before the words  
           pigWord;  //translated word

    string::size_type wordBeg,   //begining of the word  
                      wordEnd;   //end of the word  
    bool repeat;
    char again;

    //welcome message
    cout << "Elcomeway otay ethay igpay atinlay anslatortray!\n" 
         << "(Welcome to the pig latin translator!)\n";

    do
    {
        //repeat set to false
        repeat = false;

        pigLine = "";

        //prompting the user
        cout << "\nEnteryay youryay entancesay:\n(Enter your sentance:)\n";
        getline(cin, line); //reading input

        wordEnd = 0; //word before the first word ends at the begining of string    
        wordBeg = line.find_first_not_of(" \t"); //find the first thats not space

        //word extraction
        while (wordBeg != string::npos)
        {
            //assign the space before the word
            preSpace.assign(line, wordEnd, wordBeg - wordEnd);

            //find space after the word
            wordEnd = line.find_first_of(" \t", wordBeg);

            //finding the end of the string
            if (wordEnd == string::npos)
            {
                wordEnd = line.length();
            }

            //assign the word
            word.assign(line, wordBeg, wordEnd - wordBeg);

            //translate the word
            pigWord = pigLatin(word);

            //capitalize the translation if the word is capitalized
            for (string::size_type i = 0; i < pigWord.size(); i++)
            {
                //check for capitalization
                if (isupper(pigWord[i]))
                {
                    pigWord[i] = tolower(pigWord[i]); //lowercase the letter
                    pigWord[0] = toupper(pigWord[0]); //uppercase the first letter
                    break;
                }

            }
            //making the translated sentance
            pigLine += preSpace + pigWord;

            //resetting the word begining
            wordBeg = line.find_first_not_of(" \t", wordEnd);
        }
        //printing results and asking to repeat
        cout << "\nTranslation:\n\n" << pigLine << "\n\n"
             << "Oday youyay avehay anotheryay entancesay otay anslatetray?" 
             << "(Yes/No)\n(Do you have another sentance to translate?)\n";
        cin >> again; //reading input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //input validation
        while (cin.fail())
        {
            //clear and ignore
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid Entry! Please try again!\n"; //error message
            cin >> again; //reading input

        }
        again = toupper(again); //toupper user entry
        if (again != 'N') //end program if user tyypes "N"
        {
            repeat = true;
        }             
    } while (repeat);
    return 0;

}

//This function translates a word into pig latin. It takes in a string,
//translates it, and returns the translation as a string.
string pigLatin(string s)
{
    //declaring variables
    string suffix;          //suffix
    short len = s.length(); //legnth of the word
    short index = -1;       //index of the first vowel
    char punct = '\0';      //empty punctuation
    
    //finding punctuation.
    for (string::size_type i = 0; i < len; i++)
    {
        if (isPunct(s[i]))
        {
            //punct is the punctuation
            punct = s[i];  //store it for later use
            s.erase(i, 1); //erase it from the string
        }
    }

    //finding vowels
    for (string::size_type i = 0; i < len; i++)
    {    
        //if y is first letter check for other vowles
        if (s[i] == 'Y' || s[i] == 'y' && isVowel(s[i+1]))
        {
            //advance i to ignore y because it isnt a vowel
            index = i + 1;
            break;
        }

        //if q, check after it for a u
        else if (s[i] == 'Q' || s[i] == 'q' && s[i+1] == 'u')
        {
            //skip over the qu
            index = i + 2;
            break;
        }
        else if (isVowelY(s[i]))
        {
            //index is position of the first vowel
            index = i; // store for later
            break;     //break the loop
        }     
    }

    //setting the suffix
    if (isVowel(s[0]))
    {
        //first letter vowel means suffix is "yay"
        suffix = "yay";
    }
    else
    {
        //else suffix is "ay"
        suffix = "ay";
    }

    //if no vowels set the index to the legnth.
    if (index == -1)
    {
        index = s.length();
    }

    //creating a string out of punct so it can be added to the end of the word
    string sPunct(1, punct);

    // Take all characters after index (including
    // index). Add all characters which are before
    // index. Finally add the suffix and punct and return.
    return s.substr(index) + s.substr(0, index) + suffix + sPunct;
}

