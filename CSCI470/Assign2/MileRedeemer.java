// *************************************************************************** 
// 
//   Your Name Mike Rasmussen
//   Your NIU ID z1696323
//   Your Course and Section Number 470-PE1
// 
//   I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
// ***************************************************************************

import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class MileRedeemer
{
    //declare member variables
    private Destination[] destinations = new Destination[9];
    private int milesRemaining;


    /**
     * This method reads in the file and edits the destination member vairable with the destiantions 
     * sorted by the normal miles in decending order. It takes in a scanner object and returns nothing
     *  
     * @param fileScanner the name of the file to read info from
     * @throws FileNotFoundException throw exception if file not found
     */
     public void readDestinationInfo(Scanner fileScanner) throws FileNotFoundException
    {
        //Build the destinations array from the file
        for (int i = 0; i < destinations.length; i++)
        {
            Destination destination = new Destination();
            
            //Split up each line of the file into an array of strings at each ;
            String[] data = fileScanner.nextLine().split(";");
            
            //set all destination member variables 
            destination.setCityName(data[0]);
            destination.setMiles(Integer.parseInt(data[1]));
            destination.setFfMiles(Integer.parseInt(data[2]));
            destination.setMilesForUpgrade(Integer.parseInt(data[3]));
            
            //split up the last part of the data array into another array of stings at the -
            String[] months = data[4].split("-");
            destination.setFfMonthBegin(Integer.parseInt(months[0]));
            destination.setFfMonthEnd(Integer.parseInt(months[1]));
            
            //add each individual destination to the destinations array
            destinations[i] = destination;
        }

        //sort the array using the milageComparitor
        Arrays.sort(destinations, new MileageComparator());

    }

    /** 
     * This method gets the destination names from the destiantions array. 
     *  it returns the City names in an array of stings sorted in alpabetical 
     *  order. 
     * @return 
     */
    public String[] getDestinationNames()
    {
        //creates an array of strings that is the same length as the destinations array
        String[] destinationNames = new String[destinations.length];
        for (int i = 0; i < destinations.length; i++)
        {
            //add each city name to the string
            destinationNames[i] = destinations[i].getCityName();
        }

        //sort the array into alphabetical order and return it
        Arrays.sort(destinationNames);
        return destinationNames;
    }


    /** 
     * This method redeems a clients miles for flights. It will redeem the longest flights first and then 
     *  check if there are more flights to redeem. It will keep redeeming flights until it no longer has 
     *  enough miles. It will then try to use the remaining miles to upgrade flights to first class. It takes
     *  in 2 int variables for the number of miles and the month. It returns an array of Strings
     * 
     * @param miles The number of miles the client has accumulated.
     * @param month The month number the client wishes to fly.
     * @return An array of strings. Each string will have information about the destiantion city and if the 
     *         flight was booked in economy or first class.
     */
    public String[] redeemCustomerMiles(int miles, int month)
    {
        //declare ArrayLists for String and Destination
        List<String> redeemedTickets = new ArrayList<>();
        List<Destination> redeemedDestinations = new ArrayList<>();
        milesRemaining = miles;
        //counter variable
        int i = 0;

        //for each destination in the destinations array, find redeemable destinations
        for (Destination destination : destinations)
        {
            //check if frequent flier discount can be applied first
            if (month >= destination.getFfMonthBegin() && month <= destination.getFfMonthEnd())
            {
                //redeem using frequent flier discount
                if (milesRemaining >= destination.getFfMiles())
                {
                    milesRemaining -= destination.getFfMiles();
                    
                    //add the string and the destination to their respective arraylist
                    redeemedTickets.add("A trip to " + destination.getCityName() + " in Economy Class");
                    redeemedDestinations.add(destination);
                }
            }

            //use normal miles
            else if (milesRemaining >= destination.getMiles() )
            {
                milesRemaining -= destination.getMiles();

                //add the string and the destination to their respective arraylist
                redeemedTickets.add("A trip to " + destination.getCityName() + " in Economy Class");
                redeemedDestinations.add(destination);
            }
        }

        //convert the arraylist to an array of strings 
        String[] bookedTickets = redeemedTickets.toArray(new String[0]);

        //for each redeemed destiantion, check if the flight can be upgraded
        for (Destination destination : redeemedDestinations)
        {
            //redeem miles for first class upgrade
            if (milesRemaining >= destination.getMilesForUpgrade())
            {
                milesRemaining -= destination.getMilesForUpgrade();
                
                //edit the string to reflect the new class upgrade
                bookedTickets[i] = "A trip to " + destination.getCityName() + " in First Class";
            }

            //count up after each destination so that the destination will match the string of the redeemed ticket
            i++;
        }
        
        return bookedTickets;
    }

    //getter
    public int getLeftoverMiles()
    {
        return milesRemaining;
    }
}