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

public class Player
{
    //member variables
    private int playerNumber;
    private int funds;
    private ArrayList<Card> hand = new ArrayList<Card>();
    private int bet;
    private int totalValue;
    private String action;
    private boolean standing = false;
    private int winnings;
    
    //constructor
    public Player(int i)
    {
        setPlayerNumber(i);
        setFunds(1000);
    }

    //getters
    public int getFunds() 
    {
        return funds;
    }

    public ArrayList<Card> getHand() 
    {
        return hand;
    }

    public int getBet() 
    {
        return bet;
    }

    public int getPlayerNumber()
    {
        return playerNumber;
    }

    public int getTotalValue()
    {
        return totalValue;
    }

    public String getAction()
    {
        return action;
    }

    public boolean getStanding()
    {
        return standing;
    }

    public int getWinnings() 
    {
        return winnings;
    }

    //setters
    //returns true if funds is set sucessfully
    public boolean setFunds(int funds) 
    {
        this.funds = funds;
        return true;
    }

    public void setHand(ArrayList<Card> hand) 
    {
        this.hand = hand;
    }

    //returns true if bet is set sucessfully
    public boolean setBet(int bet) 
    {
        if (bet < 10 || bet > 500)
        {
            return false;
        }
        else if (bet > getFunds())
        {
            return false;
        }
        this.bet = bet;
        setFunds(getFunds() - bet);
        return true;
    }

    public void setPlayerNumber(int i) 
    {
        this.playerNumber = i;
    }

    public void setTotalValue(int i) 
    {
        this.totalValue = i;
    }

    //returns true if action is set sucessfully
    public boolean setAction(String s)
    {
        if (!s.equalsIgnoreCase("hit") && !s.equalsIgnoreCase("stand"))
        {
            return false;
        }
        this.action = s;
        return true;
    }

    public void setStanding(boolean status)
    {
        this.standing = status;
    }

    public void setWinnings(int winnings) 
    {
        this.winnings = winnings;
    }

    

    //methods
    //This method adds a card to a players hand
    public void addCardToHand(Card card)
    {
        //System.out.println("Adding " + card.getCardName() + " to Player #" + getPlayerNumber() + "\'s hand.");
        hand.add(card);
    }

    //this method calculates and sets the total value of a players hand
    public void calcTotalValue()
    {
        this.totalValue = calcValue(this.hand);
    }

    //this method calculates the value of a players hand
    private int calcValue(ArrayList<Card> hand)
    {
        int handValue = 0;
        for (Card card : hand)
        {
            handValue += card.getValue();
        }
        return handValue;
    }

    //This method process the players action
    public void processAction(String action, Deck deck)
    {
       
        switch (action)
        {
            case "HIT":
            case "Hit":
            case "hit":
            {
                this.addCardToHand(deck.selectRandomCard());
                this.printHand();
                break;
            }
            case "STAND":
            case "Stand":
            case "stand":
            {
                this.setStanding(true);
                break;
            }
        }
    }

    //This method calculates the amount of money won by a player
    public void calculateWinnings()
    {
        setWinnings(this.getBet() * 2);
        setFunds(this.getFunds() + this.winnings); 
    }

    //this method removes all cards from a players hand
    public void clearHand(ArrayList<Card> hand)
    {
        hand.clear();
    }

    //Print methods
    public void printTotalValue()
    {
        System.out.println("(Total: " + this.getTotalValue() + ")");
    }

    public void printHand()
    {
        System.out.print("Player #" + getPlayerNumber() + "'s Hand: " );
        for (Card card : hand) 
        {
            System.out.print(card.getCardName() + " ");    
        }
        this.calcTotalValue();
        this.printTotalValue();

    }

    public void printPlayerInfo()
    {
        System.out.println("\nPlayer #" + getPlayerNumber() + " info:");
        System.out.println("Current Funds: $" + getFunds());
        System.out.println("Current Bet: $" + getBet());
        System.out.print("Current Hand: ");
        if (hand == null)
        {
            System.out.println("Hand Empty");
        }
        else       
        {
            for (Card card : hand)
            {
                card.printCard();
            }
        }   
    }


}