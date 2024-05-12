////////////////////////////////////////////////////////
// 
//   Mike Rasmussen
//   z1696323
//   CSCI 470-PE1
//   
//  I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
////////////////////////////////////////////////////////

import java.io.*;
import java.net.Socket;
import java.util.Scanner;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.LinkedBlockingQueue;


public class Client implements Runnable
{
    //declare variable
    private String name;
    private String host;
    private int port;
    public Player player;
    private PlayersData players;
    private int playerNum;
    private Deck deck;
    private Scanner clientScanner = new Scanner(System.in);
    private BlockingQueue<Integer> dealerTotal = new LinkedBlockingQueue<>();

    //constructor
    public Client(String name, String host, int port, Deck deck, PlayersData players, BlockingQueue<Integer> dealerTotal) 
    {
        this.name = name;
        this.host = host;
        this.port = port;
        this.deck = deck;
        this.players = players;
        this.dealerTotal = dealerTotal;
        playerNum = Integer.parseInt(name.replaceAll("[^0-9]", ""));

        //System.out.println("Client: Client " + name + " Started");
    }

    //run when client starts
    @Override
    public void run() 
    {

        //connect to the server
        try (Socket socket = new Socket(host, port);
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream())))
            //Scanner scanner = new Scanner(System.in)) 
        {
            // Send name to server
            out.println(name);  

            //continusouly monitor for commands
            String fromServer = "REPEAT";
            do
            {
                fromServer = in.readLine();
                if (fromServer != null && !fromServer.equals("REPEAT"))
                {
                    this.processMessage(fromServer, out);
                }
                else if (fromServer == "REPEAT" || fromServer == null)
                {
                    //System.out.println(name+" no command detected.");
                }
                else
                {
                    break;
                }
            }while (true);

            //System.out.println("Client: "+name+" END OF CLIENT.");
        } 
        catch (IOException | InterruptedException | BrokenBarrierException e) 
        {
            e.printStackTrace();
        }
    }

    //This method processes commands from the server.
    //It takes in the command, and the output so that it can let the service know
    //when it has completed processing by sending a message to the service
    private synchronized void processMessage(String command, PrintWriter out) throws InterruptedException, BrokenBarrierException 
    {

        //System.out.println(this.name + ": Received from server: " + command);
        
        //process the command
        switch (command)
        {
            case "WELCOME":
            {
                this.welcome();
                out.println("DONE");

                break;
            }
            case "DEALT":
            {
                this.deal();
                out.println("GOT CARDS");
                break;
            }
            case "RESET":
            {   
                this.reset();
                out.println("RESET COMPLETE");
                break;
            }
            case "ACTION":
            {
                this.action();
                out.println("TURN OVER");
                break;
            }
            case "RESULT":
            {
                int winner = this.results();
                String winnerString = Integer.toString(winner);
                out.println(winnerString);
                break;
            }
            case "BET":
            {

                this.bet(out);
                out.println("BET");
                break;
            }
            case "ERROR":
            default:
            {
                System.err.println("Invalid message recieved!");
            }
        }
        


    }

    //this method constructs a new player
    private void welcome()
    {
        //Construct player
        player = new Player(playerNum);
        players.addPlayer(playerNum, player);
    }

    //this method prompts the client to enter their bet and sets it
    private void bet(PrintWriter out)
    {
        System.out.print("Please enter your bet, " + name + ": $");
        while (!players.getPlayer(playerNum).setBet(clientScanner.nextInt()))
        {
            System.err.print("Invalid bet!\n\nBETTING RULES:\nMinimum bet $10\nMaximum bet $500\nYou have $" 
                              + player.getFunds() + "\nPlease enter your bet again:\t");
        }
    }

    //this method deals cards to the player
    private void deal()
    {
        Player player = players.getPlayer(playerNum);
        Card card = deck.selectRandomCard();
        player.addCardToHand(card);
        card = deck.selectRandomCard();
        player.addCardToHand(card);
        player.calcTotalValue();
        player.printHand();
    }

    //this method prompts the player for an action and processes that action
    private void action()
    {
        Player player = players.getPlayer(playerNum);
        
        // Clear the buffer
        if (clientScanner.hasNextLine()) 
        {
            clientScanner.nextLine();
        }
        while (!player.getStanding())
        {
            //promt for action and check if it valid
            System.out.print("Player #" + player.getPlayerNumber() + ", (Total: " + player.getTotalValue() +") choose your action:\t");
            String playerAction = clientScanner.nextLine();
            while (!player.setAction(playerAction))
            {
                //ask for correct action until its recieved
                System.err.println("Invalid command! You can choose HIT or STAND.");
                playerAction = clientScanner.nextLine();
            }  
            player.processAction(playerAction, deck);  
            if (player.getTotalValue() > 21)
            {
                System.out.print("Player #" + player.getPlayerNumber() + " Busts! "); 
                player.printTotalValue();
                break;
            }
        }
    }

    //this method prints out the results
    //it returns the number of winners (Either 1 or 0) so the server can calculate how many players beat the dealer
    private int results() throws InterruptedException
    {
        int dealerScore = dealerTotal.take();
        int winners = 0;
        System.out.print("Player #" + player.getPlayerNumber() + " ");
    
        //if dealer busts but players don't
        if (player.getTotalValue() <= 21 && dealerScore > 21) {
            winners++;
            player.calculateWinnings();
            System.out.print("wins $" + (player.getWinnings()) + ". ");
        }
        //if players have higher total than dealer
        else if (player.getTotalValue() <= 21 && player.getTotalValue() > dealerScore) {
            winners++;
            player.calculateWinnings();
            System.out.print("wins $" + (player.getWinnings()) + ". ");
        }
        //if the players and dealer tie
        else if (player.getTotalValue() == dealerScore) {
            player.setFunds(player.getFunds() + player.getBet());
            System.out.print("ties. Bet returned. ");
        }
        //if dealer wins
        else {
            System.out.print("loses $" + (player.getBet()) + ". ");
        }
        System.out.println("New balance: $" + player.getFunds());

        return winners;
    }

    //this method resets the players to get ready for a new round
    private void reset()
    {
        Player player = players.getPlayer(playerNum);
        player.clearHand(player.getHand());  
        player.setStanding(false); 
    }
}