// *************************************************************************** 
// 
//   Mike Rasmussen
//   z1696323
//   CSCI 470-PE1 
// 
//   I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
// ***************************************************************************

public class TipCalculator {

    //data members
    private double billAmount = 0;
    private int tipPercentage = 20;
    private int partySize = 1;

    //default constructor
    public TipCalculator()
    {
        billAmount = 0;
        tipPercentage = 20;
        partySize = 1;
    }

    //constructor
    public TipCalculator(double billAmt, int tipPct, int partySze)
    {
        billAmount = billAmt;
        tipPercentage = tipPct;
        partySize = partySze;
    }
    
    //getters
    public double getBillAmount() 
    {
        return billAmount;
    }

    public int getTipPercentage() 
    {
        return tipPercentage;
    }

    public int getPartySize() 
    {
        return partySize;
    }

    public double getTotalBill()
    {
        //convert percent to ratio and multiply by billAmount
        double calc = (this.tipPercentage / 100.0) + 1;
        double totalBill = this.billAmount * calc;

        return totalBill;
    }
    public double getIndividualShare()
    {
        double individualShare = this.getTotalBill() / this.partySize;
        
        return individualShare;
    }

    //setters
    public void setBillAmount(double billAmount) 
    {
        this.billAmount = billAmount;
    }

    public void setTipPercentage(int tipPercentage) 
    {
        this.tipPercentage = tipPercentage;
    }

    public void setPartySize(int partySize) 
    {
        this.partySize = partySize;
    }   

}
