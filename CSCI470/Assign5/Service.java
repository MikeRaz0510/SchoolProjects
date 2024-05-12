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
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;


class Service implements Runnable 
{
    //declare variables
    private Socket socket;
    private BufferedReader in;
    private PrintWriter out;
    private Server server;
    private String clientName;
    private int clientNum;
    private PlayersData players;
    private CyclicBarrier barrier;
    private static final Object lock = new Object();
    private BlockingQueue<Integer> winners;

    //constructor
    public Service(Socket socket, Server server, PlayersData players, CyclicBarrier barrier, BlockingQueue<Integer> winners) 
    {
        this.socket = socket;
        this.server = server;
        this.players = players;
        this.barrier = barrier;
        this.winners = winners;

        try 
        {
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintWriter(socket.getOutputStream(), true);
           
            //getting the clients name from the client
            this.clientName = in.readLine();

            //extracting the clients number from their name
            clientNum = Integer.parseInt(clientName.replaceAll("[^0-9]", ""));
        } 
        catch (IOException e) 
        {
            e.printStackTrace();
        }
    }

    //run when the service starts
    @Override
    public void run() 
    {
        try 
        {
            //send welcome command to client
            synchronized(lock)
            {
                out.println("WELCOME");
            }

            String response = in.readLine();
            while (true)
            {   
                if (response.equals("DONE"))
                {
                    break;
                }
            }

            //wait for all clients to finish and then tell the server to continue
            barrier.await();
            server.serverAdvance();

            int playerNumber = Integer.parseInt(clientName.replaceAll("[^0-9]", ""));
            System.out.println(clientName + ": $" + players.getPlayer(playerNumber).getFunds());
            
            //wait for all clients to finish and then tell the server to continue and have the service wait for the server to continue
            barrier.await();
            server.serverAdvance();
            server.serviceWait(); 


            do
            {
                synchronized(lock)
                {
                    
                    out.println("BET");
                    response = in.readLine();
                    server.processCommand(response, this);
                }   

                //wait for all clients to finish and then tell the server to continue and have the service wait for the server to continue
                barrier.await();
                server.serverAdvance();
                server.serviceWait(); 

                //send the clients a command 1 at a time
                synchronized(lock)
                {
                    out.println("DEALT");
                    response = in.readLine();
                    //System.out.println(response);
                    while (true)
                    {
                        if (response.equals("GOT CARDS"))
                        {
                            //System.out.println(clientName + ": Got my cards, waiting for everyone else");
                            break;
                        }
                    }
                }

                //wait for all clients to finish and then tell the server to continue and have the service wait for the server to continue
                barrier.await();
                server.serverAdvance();
                server.serviceWait();

                //send the clients a command 1 at a time
                synchronized(lock)
                {
                    out.println("ACTION");
                    response = in.readLine();
                    while (true)
                    {
                        if (response.equals("TURN OVER"))
                        {
                            break;
                        }
                    }

                }

                //wait for all clients to finish and then tell the server to continue and have the service wait for the server to continue
                barrier.await();
                server.serverAdvance();
                server.serviceWait();

                //send the clients a command 1 at a time
                synchronized(lock)
                {
                    out.println("RESULT");
                    response = in.readLine();
                    while (true)
                    {
                        if (response.equals("0") || response.equals("1"))
                        {
                            //update the amount of winners from the response
                            int updatedWinners = winners.take();
                            updatedWinners += Integer.parseInt(response);
                            winners.put(updatedWinners);
                            break;
                        }
                    }
                }

                //wait for all clients to finish and then tell the server to continue and have the service wait for the server to continue
                barrier.await();
                server.serverAdvance();
                server.serviceWait();
                synchronized(lock)
                {
                    out.println("RESET");
                    response = in.readLine();
                    while (true)
                    {
                        if (response.equals("RESET COMPLETE"))
                        {

                            
                            break;
                        }
                    }
                }

                //wait for all clients to finish and then tell the server to continue and have the service wait for the server to continue
                barrier.await();
                server.serverAdvance();
                server.serviceWait();

            }while(true);

        } 
        catch (IOException | BrokenBarrierException | InterruptedException e) 
        {
            e.printStackTrace();
        } 
        finally 
        {
            try 
            {
                socket.close();
            } 
            catch (IOException e) 
            {
                e.printStackTrace();
            }
        }
    }

    //getters
    public String getClientName() 
    {
        return clientName;
    }

    public int getClientNum()
    {
        return clientNum;
    }

    //methods
    //This method prints out the players bet and remaining balance
    public void placeBet()
    {
        Player player = players.getPlayer(this.getClientNum());
        System.out.println(this.getClientName() + " bets $" + player.getBet() + " and has $" + player.getFunds() + " remaining.");
    }
}
