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
import java.net.*;
import java.util.*;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.Semaphore;


public class Server implements Runnable 
{  
    //declare variables
    private ServerSocket serverSocket;
    private PlayersData players;
    private List<Service> services = new ArrayList<>();
    private CyclicBarrier barrier;
    private int numPlayers;
    private String repeat = "yes";
    private Deck deck;
    private BlockingQueue<Integer> dealerTotal;
    private BlockingQueue<Integer> winners = new LinkedBlockingQueue<>();
    private Semaphore serverSemaphore = new Semaphore(0);
    private Semaphore serviceSemaphore = new Semaphore(0);



    //constructor
    public Server(int port, int numPlayers, Deck deck, PlayersData players, BlockingQueue<Integer> dealerTotal) 
    {
        this.numPlayers = numPlayers;
        this.players = players;
        this.deck = deck;
        this.dealerTotal = dealerTotal;
        try 
        {
            serverSocket = new ServerSocket(port);

        } 
        catch (IOException e) 
        {
            e.printStackTrace();
        }
    }

    //runs when the server starts
    @Override
    public void run() 
    {
        //create new barrier and scanner
        barrier = new CyclicBarrier(numPlayers);
        Scanner scanner = new Scanner(System.in);

        //wait for all clients to connect
        try 
        {
            while (services.size() < numPlayers) 
            {
                //accept connection from the client
                Socket clientSocket = serverSocket.accept();
                
                //create new threads for client service
                Service service = new Service(clientSocket, this, players, barrier, winners);
                new Thread(service).start();
                services.add(service);
            }

            //wait until service tells server to proceed and reset barrier
            serverSemaphore.acquire(numPlayers);
            barrier.reset();

            //Set up First round
            System.out.println("\nInitial Balances:");
            int round = 0;

            //wait until service tells server to proceed and reset barrier
            serverSemaphore.acquire(numPlayers);
            barrier.reset();

            do
            {
                //Set variables for new round
                winners.put(0);
                dealerTotal.put(0);
                round++;
                
                System.out.println("\nRound: " + round);
                
                //tell service to proceed
                serviceSemaphore.release(numPlayers);
                
                //wait until service tells server to proceed and reset barrier
                serverSemaphore.acquire(numPlayers);
                barrier.reset();
                System.out.println("\nDealing cards...");

                //tell service to proceed
                serviceSemaphore.release(numPlayers);

                //wait until service tells server to proceed and reset barrier
                serverSemaphore.acquire(numPlayers);
                barrier.reset();
                
                //building dealers and giving them cards
                Dealer dealer = new Dealer();
                Card card = deck.selectRandomCard();
                dealer.addCardToDealerHand(card);
                card = deck.selectRandomCard();
                dealer.addCardToDealerHand(card);
                dealer.printDealersHand();
                System.out.println("\nChoose Action...");

                //tell service to proceed
                serviceSemaphore.release(numPlayers);

                //wait until service tells server to proceed and reset barrier
                serverSemaphore.acquire(numPlayers);
                barrier.reset();
                System.out.println("\nDealers Turn...");
                System.out.println("Dealers hidden card is a " + dealer.revealHiddenCard());
                
                //play dealers hand
                while (dealer.getTotalValue() < 17)
                {
                    dealer.hit(deck.selectRandomCard());
                }

                //print results of dealers turn
                if (dealer.getTotalValue() > 21)
                {
                    System.out.println("Dealer busts with " + dealer.getTotalValue());
                }
                else
                {
                    System.out.println("Dealer stands with " + dealer.getTotalValue());
                }

                //send dealers total to clients
                dealerTotal.put(dealer.getTotalValue());
                System.out.println("\nResults...");

                //tells service to proceed
                serviceSemaphore.release(numPlayers);

                //wait until service tells server to proceed and reset barrier
                serverSemaphore.acquire(numPlayers);
                barrier.reset();

                //recieve number of winners from clients
                int roundWinners = winners.take();
                
                //print out dealers result
                if (roundWinners == 0)
                {
                    System.out.println("Dealer wins.");
                }
                else if (roundWinners == numPlayers)
                {
                    System.out.println("Dealer loses.");
                }
                else
                {
                    int playersBeaten = numPlayers - roundWinners;
                    System.out.println("Dealer beat " + playersBeaten + (playersBeaten == 1 ? " player." : " players."));
                }

                //prompt server if it should run another round
                System.out.println("\nEnd of round "+ round +".");
                System.out.print("Play anoither round? YES/NO ");
                repeat = scanner.nextLine();

                //tell service to proceed
                serviceSemaphore.release(numPlayers);

                //wait until service tells server to proceed and reset barrier
                serverSemaphore.acquire(numPlayers);
                barrier.reset();

                //reset dealers hand
                dealer.clearHand(dealer.getHand());

            //loop back up to the start if another round is being played
            }while(repeat.equalsIgnoreCase("YES"));

            System.out.println("Thank you for playing!");
            //System.out.println("SERVER: END OF SERVER!");
            scanner.close();
            
        } 
        catch (IOException | InterruptedException e) 
        {
            e.printStackTrace();
        }
    }

    public void serverAdvance()
    {
        serverSemaphore.release();
    }

    public void serviceWait() throws InterruptedException
    {
        serviceSemaphore.acquire();
    }

    public synchronized void processCommand(String command, Service sender) 
    {
        //System.out.println("SERVER: Received from " + sender.getClientName() + ": " + command);
        switch (command)
        {
            case "BET":
            {
                sender.placeBet();
                break;
            }
            case "HIT":
            {
                break;
            }
            case "STAND":
            {
                break;
            }
            case "QUIT":
            {
                break;
            }
            case "DONE":
            {
                break;
            }
            default:
            {
                System.err.println("Invalid command recieved!");
            }
        }

        //nextTurn();
    }

}
