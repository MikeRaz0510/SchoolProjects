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

public class USMoneyTester
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        USMoney moneyObj1 = new USMoney();
        USMoney moneyObj2 = new USMoney();
        USMoney sum = new USMoney();
        int userDollars = 0;
        int userCents = 0;

        //prompt user for first object
        System.out.println("Enter your first amount!");
        System.out.print("Dollars: ");
        userDollars = input.nextInt();
        System.out.print("Cents: ");
        userCents = input.nextInt();
        moneyObj1 = new USMoney(userDollars, userCents);

        //prompt user for second object
        System.out.println("Enter your second amount!");
        System.out.print("Dollars: ");
        userDollars = input.nextInt();
        System.out.print("Cents: ");
        userCents = input.nextInt();
        moneyObj2 = new USMoney(userDollars, userCents);

        //add
        sum = moneyObj1.plus(moneyObj2);

        System.out.println("Money object 1: $" + moneyObj1.getDollars() + "." + moneyObj1.getCents());
        System.out.println("Money object 2: $" + moneyObj2.getDollars() + "." + moneyObj2.getCents());
        System.out.println("Sum: $" + sum.getDollars() + "." + sum.getCents());

        input.close();
        
        
    }
}