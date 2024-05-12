////////////////////////////////////////////////////////
// 
//   Mike Rasmussen
//   z1696323
//   CSCI 470-PE1
//   
//  I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
////////////////////////////////////////////////////////

public class Card
{
    //Member variables
    private String cardName;
    @SuppressWarnings("unused")
    private int value;
    private String suit;
    private String rank;

    
    //getters
    public String getCardName() 
    {
        return cardName = this.getRank() + " of " + this.getSuit() + "s ";
    }

    public int getValue() 
    {
        return convertRankToValue(this.getRank());
        
    }

    public String getSuit() 
    {
        return suit;
    }
    public String getRank()
    {
        return rank;
    }   

    //setters
    public void setCardName(String cardName) 
    {
        this.cardName = cardName;
    }
    public void setValue(int value) 
    {
        this.value = value;
    }
    public void setSuit(String suit)
     {
        this.suit = suit;
    }
    public void setRank (String rank)
    {
        this.rank = rank;
    }


    //methods
    //This method converts the cards rand to its value
    private int convertRankToValue(String rank)
    {
        switch (rank)
        {
            case "A":
                return 11;  
            case "2":
                return 2;
            case "3":
                return 3;
            case "4":
                return 4;
            case "5":
                return 5;
            case "6":
                return 6;
            case "7":
                return 7;
            case "8":
                return 8;
            case "9":
                return 9;
            case "10":
            case "J":
            case "Q":
            case "K":
                return 10;
            default:
                return 0;  
        }
    }
    
    //Print methods
    //This method prints out the cards name
    public void printCard()
    {
        System.out.print(cardName);
    } 


}