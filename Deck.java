////////////////////////////////////////////////////////
// 
//   Mike Rasmussen
//   z1696323
//   CSCI 470-PE1
//   
//  I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
////////////////////////////////////////////////////////

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Deck 
{
    public ArrayList<Card> deck = new ArrayList<Card>();

    //This method builds the deck of cards from the Deck.txt file
    public void buildDeck() throws FileNotFoundException
    {
        // Path to the deck file
        String fileName = "Deck.txt";

        // Read the deck file and fill the list
        Scanner s = new Scanner(new FileReader(fileName));
        
        for(int i = 0; i < 52; i++)
        {
            Card card = new Card();
            String[] data = s.nextLine().split(";");
            card.setSuit(data[0]);
            card.setRank(data[1]);

            deck.add(card);
        }
        s.close();
    }

    //this method selects a random card from the deck and returns it
    public Card selectRandomCard() 
    {
        if (deck.isEmpty()) 
        {
            System.out.println("No cards in the deck.");
            return null;
        }
        Random random = new Random();
        int index = random.nextInt(deck.size());
        return deck.get(index);
    }

    //this method prints the deck
    public void printDeck()
    {
        for (Card card : this.deck)
        {
            System.out.println(card.getCardName());
        }
    }
}

