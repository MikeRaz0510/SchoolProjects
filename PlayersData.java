////////////////////////////////////////////////////////
// 
//   Mike Rasmussen
//   z1696323
//   CSCI 470-PE1
//   
//  I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
////////////////////////////////////////////////////////

import java.util.concurrent.ConcurrentHashMap;

public class PlayersData 
{
    //stores the player data in a concurrent hash map
    private ConcurrentHashMap<Integer, Player> players;

    //constructor
    public PlayersData()
    {
        this.players = new ConcurrentHashMap<>();
    }

    //getter
    public Player getPlayer(int i)
    {
        return players.get(i);
    }

    //This method adds a plyer to the map
    public void addPlayer(int i, Player player)
    {
        players.put(i, player);
    }

    //this method prints out a players info
    public void printInfo(int i)
    {
        Player f = getPlayer(i);
        f.printPlayerInfo();
    }

}
