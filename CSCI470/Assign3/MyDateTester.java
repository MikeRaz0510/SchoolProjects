// *************************************************************************** 
// 
//   Your Name Mike Rasmussen
//   Your NIU ID z1696323
//   Your Course and Section Number 470-PE1
// 
//   I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
// ***************************************************************************
import java.util.Scanner;

public class MyDateTester 
{
    public static void main(String[] args)
    {
        //declare vairables
        Scanner input = new Scanner(System.in);
        int userDay = 1;
        int userMonth = 1;
        int userYear = 1970;
        
        //promt the user and read input
        System.out.println("Enter your first date!");
        System.out.print("Day: ");
        userDay = input.nextInt();
        System.out.println(userDay);
        System.out.print("Month: ");
        userMonth = input.nextInt();
        System.out.print("Year: ");
        userYear = input.nextInt();
        input.close();

        //create a myDate object
        MyDate myDate = new MyDate(userDay, userMonth, userYear);

        //print out the calculated days since Jan 1
        System.out.println(userMonth + "/" + userDay + "/" + userYear + " is " + myDate.daysSinceJan1() + " days since 1/1/" + userYear);
    }
}
