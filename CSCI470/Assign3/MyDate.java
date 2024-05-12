// *************************************************************************** 
// 
//   Your Name Mike Rasmussen
//   Your NIU ID z1696323
//   Your Course and Section Number 470-PE1
// 
//   I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
// ***************************************************************************
public class MyDate 
{
    //member data
    private int day;
    private int month;
    private int year;

    //constructor
    public MyDate(int day, int month, int year)
    {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    /*
     * This method calculates the number of days since january 1 of the
     * users year. It can account for leap years. It returns the number
     * of days as an int.
     */
    public int daysSinceJan1()
    {
        //declare variables
        int totalDays = this.day;
        int daysInMonth = 0;

        //check for a leap year
        if (isLeapYear(this.year))
        {
            //add an extra day
            if (this.month >= 2)
            {
                totalDays++;
            }
        }

        //add up the total number of days
        for (int i = 0; i < this.month; i++)
        {
            daysInMonth = getDaysInMonth(i);
            totalDays += daysInMonth;
        }

        return totalDays;
    }

    /*
     * This Method checks to see if the users year is a leap year.
     * This takes in the year, and returns either true or false.
     */
    private boolean isLeapYear(int year) 
    {
        if (year % 4 == 0) 
        {
            if (year % 100 == 0) 
            {
                if (year % 400 == 0) 
                {
                    return true;
                }
                return false;
            }
            return true;
        }
        return false;
    }

    /*
     * This method returns the number of days in each month.
     * It takes in a month and returns the number of days in that month.
     */
    private int getDaysInMonth(int month) 
    {
        switch (month) 
        {
            case 1: return 31;
            case 2: return 28;
            case 3: return 31;
            case 4: return 30;
            case 5: return 31;
            case 6: return 30;
            case 7: return 31;
            case 8: return 31;
            case 9: return 30;
            case 10: return 31;
            case 11: return 30;
            case 12: return 31;
            default: return 0; 
        }
    }
}

