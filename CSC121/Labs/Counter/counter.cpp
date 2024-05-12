#include<iostream>
#include<cctype>
#include<limits>
#include<iomanip>


using namespace std;

class Count
{
public:

    short total = 0,
          cOnes = total % 10,
          cTens = total % 100 / 10,
          dOnes = total % 1000 / 100,
          dTens = total % 10000 / 1000,
          dollars = total % 10000 / 100,
          cents = total % 100;


    short startingValue(void);
    short upOne(void);
    void display(void);
    Count select(Count& one, Count& two, Count& three, Count& four, Count& five);
   
    Count(short);



};

void menu(Count& one, Count& two, Count& three, Count& four, Count& five);
char ignup(void);

int main(void)
{
    Count one = Count(0),
        two = Count(0),
        three = Count(0),
        four = Count(0),
        five = Count(0);
    
    menu(one, two, three, four, five);

    return 0;
}

short Count::startingValue(void)
{
    cout << "Enter the starting value between 0000 - 9999.\t";
    cin >> total;
    return total;
}

short Count::upOne(void)
{    
    char input;

    input = ignup();

    switch (input)
    {
    case 'A': ++dTens; break;
    case 'S': ++dOnes; break;
    case 'D': ++cTens; break;
    case 'F': ++cOnes; break;
    }

        return total;
}

void Count::display(void)
{
    
    cout.fill('0');
    cout << '$' << setw(2) << dollars << '.' << setw(2) << cents << endl;
}

Count Count::select(Count& one, Count& two, Count& three, Count& four, Count& five)
{
    char selection;
    Count CurrentCount = Count(0);
    cout << "\t\tSelect Count Number\n1. Count 1\n2. Count 2\n3. Count 3\n"
        << "4. Count 4\n5. Count 5\n";
    selection = ignup();

    switch (selection)
    {
    case '1': CurrentCount = one; break;
    case '2': CurrentCount = two; break;
    case '3': CurrentCount = three; break;
    case '4': CurrentCount = four; break;
    case '5': CurrentCount = five; break;
    default:
    {
        cerr << "Invalid Selection!";
    }
    }

    return CurrentCount;
}

char ignup(void)
{
    char input;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return toupper(input);
}

void menu(Count& one, Count& two, Count& three, Count& four, Count& five)
{
    char menu;
    bool repeat = true;
    Count current = Count(0);

    do
    {
        cout << "\t\tMain Menu\n1. Select count\n2. enter starting Value\n"
            << "3. display Price\n4. Add to count\n5. Exit\n";
        menu = ignup();

        switch (menu)
        {
        case '1': case 'S':
        {
            current.select(one, two, three, four, five);
        }break;
        case '2': case 'V':
        {
            current.startingValue();
        }break;
        case '3': case 'P':
        {
            current.display();
        }break;
        case '4': case 'A':
        {
            current.upOne();
        }break;
        case '5': case 'X': case 'Q':
        {
            repeat = false;
        }break;
        default:
        {
            cerr << "Invalid Input!";
        }break;
        }
    } while (repeat);
}

Count::Count(short total)
{
    total = 0;
}
