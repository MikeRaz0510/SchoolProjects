#include<iostream>
#include<ctime>
#include<limits>
#include<cctype>
#include<iomanip>

using namespace std;

int main(void)
{
    const short seconds_per_minute = 60,
                minutes_per_hour = 60,
                seconds_per_hour = seconds_per_minute * minutes_per_hour,//3600
                hours_per_day = 24,
                GMT_to_CDT = -5; //Converting GMT into CDT

    const long seconds_per_day = static_cast<long>(seconds_per_hour) 
        * hours_per_day; //86,400 seconds per day
  
         //modulo off every second before today
    long seconds_today = time(nullptr) % seconds_per_day; 
          //calculating current hour in GMT
    short current_hour = seconds_today / seconds_per_hour, 
          //calculating current minute
          current_minute = seconds_today % seconds_per_hour
              / seconds_per_minute,
          //calculating current second
          current_second = seconds_today % seconds_per_hour 
              % seconds_per_minute;
    char y_or_n; //for asking yes or no question
    char AM_PM; //for converting to 12 hour format

          //calculating current hour in CDT
    current_hour = static_cast<short>((seconds_today / seconds_per_hour
        + GMT_to_CDT + hours_per_day) % hours_per_day);

    cout.fill('0'); //setting the fill character to 0 for leading 0s on 0-9
   //displaying the time
    cout << "The time is currently " << setw(2) << current_hour << ':' 
        << setw(2) << current_minute << ':' << setw(2) << current_second
        << " CDT\n";

    //asking if the user would like to see the time in 12 hour format
    cout << "Would you like to covert the time into 12 hour format? "
        << "Please type Yes or No!\n";
    cin >> y_or_n; //reading their input
    //ignoring anything after the first letter they type
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //using demorgans laws to check if the iunput is not Y or N
    while (toupper(y_or_n) != 'Y' && toupper(y_or_n) != 'N')
    {
       cerr << "Input not recognized! Please type Yes or No\n";
     
        if (cin.fail())  //checking to see if cin has failed
        {
            cin.clear(); //clearing and ignoring cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
        cin >> y_or_n; //rereading input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Displaying American 12 hour time

    //if the user types lowercase, convert to uppercase and see if it is 'Y'
    if (toupper(y_or_n) == 'Y')
    {
        //recalculating the current time becase a few seconds have passed
        seconds_today = time(nullptr) % seconds_per_day;
        current_hour = static_cast<short>((seconds_today / seconds_per_hour
            + GMT_to_CDT + hours_per_day) % hours_per_day);
        current_minute = seconds_today % seconds_per_hour
            / seconds_per_minute;
        current_second = seconds_today % seconds_per_hour
            % seconds_per_minute;
        
        AM_PM = 'A'; //setting AM_PM to A
        //if the hour is 12 or greater change AM_PM to P
        if (current_hour >= 12)
        {
            AM_PM = 'P';
        }
        //if the current hour is greater than 12 subtract 12
        if (current_hour > 12)
        {
            current_hour = current_hour - 12;
        }
        
        cout << "The time is currently " << setw(2) << current_hour << ':'
            << setw(2) << current_minute << ':' << setw(2) << current_second
            << ' ' << AM_PM << "M CDT\n";
    }

    cout << "\n\tThank you for using Mike's Time of Day Program!\n";

    return 0;
}
