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
import java.io.File;
import java.io.FileNotFoundException;

public class MileRedemptionApp
{

    public static void main(String[] args) throws FileNotFoundException
    {
        //declare variables
        Scanner input = new Scanner(System.in);
        String fileName = "testfile.txt";
        char repeat = 'y';
        String[] possibleDestinations;
        MileRedeemer mileRedeemer = new MileRedeemer();

        //prompt and read for user input of destination file
        System.out.println("\nPlease enter the name of the file containing destinations");
        fileName = input.next();
        System.out.println("\nWelcome to the Java Airlines Frequent Flyer Miles redemption app!!!");

        //pass Scanner object to read destination info method
        File file = new File(fileName);
        Scanner fileScanner = new Scanner(file);
        mileRedeemer.readDestinationInfo(fileScanner);

        //get list of possible destinations sorted in alphabetical order and print them
        possibleDestinations = mileRedeemer.getDestinationNames();
        System.out.println("\nList of destination cities your client can travel to: ");
        for (int i = 0; i < possibleDestinations.length; i++)
        {
            System.out.print(possibleDestinations[i] + " ");
            
        }

        //main loop of redemption app
        do
        {
            //prompt and read from user
            System.out.print("\n\nPlease enter your client's accumulated Frequent Flyer Miles: ");
            int miles = input.nextInt();
            System.out.print("Please enter your client's month of departure (1-12): ");
            int month = input.nextInt();

            //create a array of strings of redeemed destinations
            String[] redeemedTickets = mileRedeemer.redeemCustomerMiles(miles, month);
            if (redeemedTickets.length == 0)
            {
                System.out.println("*** Your client has not accumulated enough Frequent Flyer Miles ***");
            }
            else
            {
                //print out all redeemed destinations
                for (String ticket : redeemedTickets)
                {
                    System.out.println(ticket);
                }
            }

            //show miles remaining
            System.out.println("Your client's remaining Frequent Flyer Miles:" + mileRedeemer.getLeftoverMiles());
            
            //prompt user to repeat the program
            System.out.print("\nDo you want to continue (y/n)? ");
            repeat = Character.toLowerCase(input.next().charAt(0));
        } while(repeat == 'y');

        //exit the program
        System.out.println("\nThank you for using the Java Airlines Frequent Flyer Miles redemption app!");
        input.close();        
    }

}