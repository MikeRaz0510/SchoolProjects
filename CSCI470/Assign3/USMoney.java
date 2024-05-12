// *************************************************************************** 
// 
//   Your Name Mike Rasmussen
//   Your NIU ID z1696323
//   Your Course and Section Number 470-PE1
// 
//   I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
// ***************************************************************************
public class USMoney
{
    //member data
    private int dollars;
    private int cents;

    //default constructor
    public USMoney()
    {
        dollars = 0;
        cents = 0;
    }
    
    //parameterized constructor
    public USMoney(int dollars, int cents)
    {
        //checks is the value for cents is more than 99 and
        //adds value to the dollars member variable
        if (cents > 99 )
        {
            dollars += (cents / 100);
            cents %= 100;
        }
        this.setDollars(dollars);
        this.setCents(cents);
        
    }

    //getters
    public int getDollars() 
    {
        return dollars;
    }
    public int getCents() 
    {
        return cents;
    }

    //setters
    public void setDollars(int dollars) 
    {
        this.dollars = dollars;
    }
    public void setCents(int cents) 
    {


        this.cents = cents;
    }

    //methods
    /*
     * This method adds the calling object to a second object.
     * The second object is passed as a parameter. This method does not 
     * alter either of the original 2 objects, it creates a new object 
     * and returns it.
     */
    public USMoney plus(USMoney obj2)
    {
        int sumDollars = this.dollars + obj2.dollars;
        int sumCents = this.cents + obj2.cents;
        return new USMoney(sumDollars, sumCents); 
    }


}
