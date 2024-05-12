////////////////////////////////////////////////////////
// 
//   Mike Rasmussen
//   z1696323
//   CSCI 470-PE1
//   
//  I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
////////////////////////////////////////////////////////

import java.util.ArrayList;

public class Dealer 
{
    //declare variables
    private ArrayList<Card> hand = new ArrayList<Card>();
    private int value = 0;
    private int totalValue = 0;

    //constructor
    public Dealer()
    {

    }

    //getters
    public int getValue() 
    {
        return value;
    }

    public int getTotalValue() 
    {
        return totalValue;
    }

    public ArrayList<Card> getHand() 
    {
        return hand;
    }

    //setters
    public void setValue(int value) 
    {
        this.value = value;
    }
    public void setTotalValue(int totalValue) 
    {
        this.totalValue = totalValue;
    }

    public void setHand(ArrayList<Card> hand) 
    {
        this.hand = hand;
    }
    

    //this method adds a card to the dealers hand
    public void addCardToDealerHand(Card card)
    {
        if (hand.size() == 0)
        {
            //System.out.println("Adding HIDDEN to Dealer's hand.");
        }
        else
        {
            //System.out.println("Adding " + card.getCardName() + " to Dealer's hand.");
        }

        hand.add(card);
    }

    //this method prints out the dealers hand
    public void printDealersHand()
    {
        System.out.println("Dealer's Showing: " + hand.get(1).getCardName());
    }

    //this method reveals the dealers hidden card
    public String revealHiddenCard()
    {
        this.calcTotalValue();
        return hand.get(0).getCardName() + this.printTotalValue();
    }

    //this method claculates and sets the total value of the dealers hand
    public void calcTotalValue()
    {
        setTotalValue(calcValue(this.hand));
    }

    //this method calculates the value of the dealers hand
    //It returns the value as an int
    private int calcValue(ArrayList<Card> hand)
    {
        int handValue = 0;
        for (Card card : hand)
        {
            handValue += card.getValue();
        }
        return handValue;
    }

    //this method prints the total value of the dealers hand
    //It returns the value as a string
    public String printTotalValue()
    {
        this.calcTotalValue();
        return "(Value: " + this.getTotalValue() + ")";
    }

    //this method adds a card to the dealers hand
    public void hit(Card card)
    {
        hand.add(card);
        System.out.println("Dealer hits and recieves a " + card.getCardName() +" "+ this.printTotalValue());
    }

    //this method clears the dealers hand
    public void clearHand(ArrayList<Card> hand)
    {
        hand.clear();
    }
    
}
