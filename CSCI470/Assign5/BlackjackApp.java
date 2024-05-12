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
import java.util.*;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;



public class BlackjackApp
{
    public static void main(String[] args) throws InterruptedException, FileNotFoundException
    {
        //declare variable
        int port = 1234;
        ArrayList<Thread> threads = new ArrayList<Thread>();
        BlockingQueue<Integer> dealerTotal = new LinkedBlockingQueue<>();
        int numOfPlayers;
        PlayersData players = new PlayersData();
        Deck deck = new Deck();
        Scanner input = new Scanner(System.in);


        //build deck
        deck.buildDeck();

        //welcome message and prompt for number of players
        System.out.println("Welcome to BlackJack");
        System.out.print("Enter the number of players:\t");
        numOfPlayers = input.nextInt();

        //Start the server
        Server server = new Server(port, numOfPlayers, deck, players, dealerTotal);
        Thread serverThread = new Thread(server);
        serverThread.start();

        // Small delay to start server
        try 
        {
            Thread.sleep(500);
        } 
        catch (InterruptedException e) 
        {
            Thread.currentThread().interrupt();
        }

        //create that many players
        for (int i = 0; i < numOfPlayers; i++)
        {
            String name = "Player #" + (i+1);
            Client newClient = new Client(name, "localhost", port, deck, players, dealerTotal);
            Thread newThread = new Thread(newClient);
            newThread.start();
            threads.add(newThread);
        }

        //when the server ends, exit the program
        serverThread.join();
        input.close();
        System.exit(0);
        
    }
}
