// *************************************************************************** 
// 
//   Mike Rasmussen
//   z1696323
//   CSCI 470-PE1 
// 
//   I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
// ***************************************************************************
import java.util.Scanner;

public class TipApp
{
    /**
     * @param args
     * 
     * This main program constructs a TipCalculator object and then
     * prompts users for input and calls the 
     * calculateTips method to calculate and display the output.
     * It returns nothing
     */
    public static void main(String[] args)
    {
        //declare variables
        TipCalculator tipObj = new TipCalculator();
        char repeat = 'y';
        Scanner input = new Scanner (System.in);

        //run until user stops 
        while (repeat == 'y')
        {
            System.out.println("\n* * * Tip Calculator * * *\n");

            //prompt user and read input
            do 
            {
                System.out.print("Please Enter Your Bill Amount: " ); 
                
                //check that valid input was entered
                while(!input.hasNextDouble())
                {
                    System.out.print("Please enter a valid number! ");
                    input.next();
                }

                tipObj.setBillAmount(input.nextDouble());
            } while(tipObj.getBillAmount() <= 0);

            // prompt user and read input
            do 
            {
                System.out.print("Please Enter Your Tip Percentage: " ); 
                
                //check that valid input was entered 
                while(!input.hasNextInt())
                {
                    System.out.print("Please enter a valid tip percentage!  ");
                    input.next();
                }

                tipObj.setTipPercentage(input.nextInt());
            } while(tipObj.getTipPercentage() < 0);

            //prompt user and read input
            do 
            {
                System.out.print("Please Enter Your Party Size: " ); 
                
                //check for valid input
                while(!input.hasNextInt())
                {
                    System.out.print("Please enter a valid Party size! ");
                    input.next();
                }

                tipObj.setPartySize(input.nextInt());
            } while(tipObj.getPartySize() < 1);

            calculateTips(tipObj);

            //prompt user to do another calculation
            System.out.print("Type 'y' to calculate another tip. ");
            repeat = Character.toLowerCase(input.next().charAt(0));

        }
        
        //end program
        System.out.println("\nThank you for using the Tip Calculator! Goodbye!\n");
        input.close();
    }


    /**
     * @param tipObj A TipCalculator object
     * 
     * This method calculates the tips taking a TipCalculator object
     * as input. It calls TipCalculator methods to calculate the 
     * Total Bill and the individual share. It will then print the output.
     * 
     */
    public static void calculateTips(TipCalculator tipObj)
    {
        //calculations
        double total = tipObj.getTotalBill();
        double indShare = tipObj.getIndividualShare();

        //print output
        System.out.println("\n* * * Your Bill * * *\n");
        System.out.println("Bill Amount: $" + tipObj.getBillAmount());
        System.out.println("Tip Percentage: " + tipObj.getTipPercentage() + "%");
        System.out.println("Party Size: " + tipObj.getPartySize() + "\n");
        System.out.println("Bill Amount with Tip: $" + String.format("%.2f", total));
        System.out.println("Each person pays: $" + String.format("%.2f", indShare) + "\n");


    }

}