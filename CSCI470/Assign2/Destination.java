// *************************************************************************** 
// 
//   Your Name Mike Rasmussen
//   Your NIU ID z1696323
//   Your Course and Section Number 470-PE1
// 
//   I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
// ***************************************************************************

public class Destination
{
    //variables
    private String cityName;
    private int miles;
    private int ffMiles;
    private int milesForUpgrade;
    private int ffMonthBegin;
    private int ffMonthEnd;

    //getters
    public String getCityName() 
    {
        return cityName;
    }

    public int getMiles() 
    {
        return miles;
    }

    public int getFfMiles() 
    {
        return ffMiles;
    }
    public int getMilesForUpgrade() 
    {
        return milesForUpgrade;
    }

    public int getFfMonthBegin() 
    {
        return ffMonthBegin;
    }

    public int getFfMonthEnd() 
    {
        return ffMonthEnd;
    }

    
    //setters
    public void setCityName(String cityName) 
    {
        this.cityName = cityName;
    }  
    
    public void setMiles(int miles) 
    {
        this.miles = miles;
    }
    
    public void setFfMiles(int ffMiles) 
    {
        this.ffMiles = ffMiles;
    }   
    
    public void setMilesForUpgrade(int milesForUpgrade) 
    {
        this.milesForUpgrade = milesForUpgrade;
    }    

    public void setFfMonthBegin(int ffMonthBegin) 
    {
        this.ffMonthBegin = ffMonthBegin;
    }   
    
    public void setFfMonthEnd(int ffMonthEnd) 
    {
        this.ffMonthEnd = ffMonthEnd;
    }
}