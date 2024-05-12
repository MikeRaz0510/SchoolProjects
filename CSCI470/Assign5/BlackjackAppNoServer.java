////////////////////////////////////////////////////////
// 
//   Mike Rasmussen
//   z1696323
//   CSCI 470-PE1
//   
//  I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
////////////////////////////////////////////////////////

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class BlackjackAppNoServer 
{
    public static void main(String[] args) throws InterruptedException, IOException
    {

        //SERVER
        //declare variables
        ArrayList<Player> players = new ArrayList<Player>();
        Deck deck = new Deck();
        int numOfPlayers = 0;
        Scanner input = new Scanner(System.in);
        Dealer dealer = new Dealer();
        int round = 0;
        int winners = 0;
        String repeat = "Yes";

        //SERVER
        //welcome message and prompt for number of players
        System.out.println("Welcome to BlackJack");
        System.out.print("Enter the number of players:\t");
        numOfPlayers = input.nextInt();

        //CLIENT: construct player
        //create that many players
        for (int i = 0; i < numOfPlayers; i++)
        {
            Player newPlayer = new Player(i+1);
            players.add(newPlayer);
            //newPlayer.printPlayerInfo();
        }

        //SERVER
        System.out.println("\nInitial Balances:");
        for (Player player : players) 
        {
            System.out.println("Player #" + player.getPlayerNumber() + ": $" + player.getFunds());
        }

        do
        {
            //SERVER END CONNECTION WITH CLIENTS
            //remove players with no ballance from the game
            for (int i = players.size() - 1; i >= 0; i--) 
            {
                if (players.get(i).getFunds() == 0)
                {
                    System.out.println("Player #" + players.get(i).getPlayerNumber() + " has no remaining balance and has been removed from the game");
                    players.remove(i);
                    numOfPlayers--;
                }    
            }

            //SERVER
            round++;
            System.out.println("\nRound " + round + ":");

            //CLIENT
            //have each player place thier bets
            for (Player player: players)
            {
                System.out.print("Player #" + player.getPlayerNumber() + " please enter your bet:\t");
                
                //check if the bet is valid
                while (!player.setBet(input.nextInt()))
                {
                    System.err.print("Invalid bet!\n\nBETTING RULES\n-------------\nMinimum bet $10\nMaximum bet $500\nYou have $" + player.getFunds() + "\nPlease enter your bet again:\t");
                }
                //display bet
                System.out.println("Player #" + player.getPlayerNumber() + " has bet $" + player.getBet() + " and has $" + player.getFunds() + " remaining.");

            }

            //SERVER
            //build deck from file
            System.out.println("\nServer: Drawing Cards...");        
            deck.buildDeck();

            //CLIENT
            //have each player draw 2 cards
            for (Player player: players)
            {
                //select 2 random cards and place them in the players hand 
                Card playerCard = deck.selectRandomCard();
                player.addCardToHand(playerCard);
                playerCard = deck.selectRandomCard();
                player.addCardToHand(playerCard);

            }

            //SERVER
            //draw 2 cards for the dealer
            Card dealerCard = deck.selectRandomCard();
            dealer.addCardToDealerHand(dealerCard);
            dealerCard = deck.selectRandomCard();
            dealer.addCardToDealerHand(dealerCard);

            System.out.println();

            //SERVER
            //calculate the value of each players hand
            for (Player player: players)
            {
                player.calcTotalValue();
            }

            //SERVER
            //display the every players hand
            for (Player player: players)
            {
                player.printHand();
            }

            //SERVER
            //show the dealers card
            dealer.printDealersHand();

            //CLIENT
            //prompt each player for thier action
            //Scanner actionInput = new Scanner(System.in);
            for (Player player : players)
            {
                if (input.hasNextLine()) 
                {
                    input.nextLine();  // Clear the buffer to avoid immediate consumption of leftover newline characters
                }
                //while the player has not ended their turn
                while (!player.getStanding())
                {
                    //promt for action and check if it valid
                    System.out.print("Player #" + player.getPlayerNumber() + ", choose your action:\t");
                    String playerAction = input.nextLine();
                    while (!player.setAction(playerAction))
                    {
                        //ask for correct action until its recieved
                        System.err.println("Invalid command! You can choose HIT or STAND.");
                        playerAction = input.nextLine();
                    }  
                    //System.out.println("Player #" + player.getPlayerNumber() + " chose " + player.getAction());
                    //process action
                    player.processAction(playerAction, deck);  
                    if (player.getTotalValue() > 21)
                    {
                        System.out.print("Player #" + player.getPlayerNumber() + " Busts! "); 
                        player.printTotalValue();
                        break;
                    }
                }
            }

            //SERVER
            //dealers turn once all players have finished
            System.out.println("\nDealers turn...");
            System.out.println("Dealers hidden card is a " + dealer.revealHiddenCard());

            //SERVER
            //dealer hits until he is at 17
            while (dealer.getTotalValue() < 17)
            {
                dealer.hit(deck.selectRandomCard());
            }

            //SERVER
            if (dealer.getTotalValue() > 21)
            {
                System.out.println("Dealer busts with " + dealer.getTotalValue());
            }
            else
            {
                System.out.println("Dealer stands with " + dealer.getTotalValue());
            }

            //SERVER
            //results
            System.out.println("\nResults...");
            for (Player player : players) 
            {
                System.out.print("Player #" + player.getPlayerNumber() + " ");
                
                //if dealer busts but players dont
                if (player.getTotalValue() <= 21 && dealer.getTotalValue() > 21)
                {
                    winners++;
                    player.calculateWinnings();
                    System.out.print("wins $" + (player.getWinnings()) + ". ");
                }
                //if players have higher total than dealer
                else if (player.getTotalValue() <= 21 && player.getTotalValue() > dealer.getTotalValue())
                {
                    winners++;
                    player.calculateWinnings();
                    System.out.print("wins $" + (player.getWinnings()) + ". ");
                }
                //if the players and dealer tie
                else if (player.getTotalValue() == dealer.getTotalValue())
                {
                    player.setFunds(player.getFunds() + player.getBet());
                    System.out.print("ties. Bet returned. ");
                }
                //if dealer wins
                else
                {
                    System.out.print("loses $" + (player.getBet()) + ". ");
                }
                System.out.println("New balance: $" + player.getFunds());
            }

            //System.out.println("Winners: " + winners + " Players: " + numOfPlayers);

            //SERVER
            if (winners == 0)
            {
                System.out.println("Dealer wins.");
            }
            else if (winners == numOfPlayers)
            {
                System.out.println("Dealer loses.");
            }
            else
            {
                int playersBeaten = numOfPlayers - winners;
                System.out.println("Dealer beat " + playersBeaten + (playersBeaten == 1 ? " player." : " players."));
            }
            winners = 0;

            //SERVER
            //Scanner endGame = new Scanner(System.in);
            System.out.print("\nWould you like to play anouther round? Yes/No: ");
            repeat = input.nextLine();

            //SERVER
            //reset game
            for (Player player : players) 
            {
                player.clearHand(player.getHand());  
                player.setStanding(false); 
            }
            dealer.clearHand(dealer.getHand());
            

        }while(repeat.equalsIgnoreCase("YES"));


        System.out.println("Thank you for playing!");
        input.close();
        //actionInput.close();
        //endGame.close();
        
        

    }
}