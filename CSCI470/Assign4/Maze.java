////////////////////////////////////////////////////////
// 
//   Your Name Mike Rasmussen
//   Your NIU ID z1696323
//   Your Course and Section Number 470-PE1
//   
//  I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
////////////////////////////////////////////////////////

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Maze 
{
    //Decalare Variables
    private static char[][] maze;
    private static final char WALL = 'X';
    private static final char START = '+';
    private static final char END = '-';
    private static final char PATH = '*';
    private static final char DEAD_END = '.';

    //constructor
    public Maze(String fileName) throws FileNotFoundException
    {
        loadMaze(fileName);
    }

    
    /** This method loads the maze from a file into a 2D array
     * 
     * @param fileName The name of the file
     * @throws FileNotFoundException 
     */
    private static void loadMaze(String fileName) throws FileNotFoundException
    {

        Scanner scanner = new Scanner(new File(fileName));
        ArrayList<String> lines = new ArrayList<>();
        
        //read each line and store in an ArrayList
        while (scanner.hasNextLine()) 
        {
            //add each line of the file to the array list
            lines.add(scanner.nextLine().trim()); //trim in case of extra white space
        }
        scanner.close();
        
        if (!lines.isEmpty()) 
        {
            //initilize the 2D arrary assming all rows are the same length
            maze = new char[lines.size()][lines.get(0).length()];
            
            //add each char to the 2D array line by line
            for (int i = 0; i < lines.size(); i++) 
            {
                maze[i] = lines.get(i).toCharArray();
            }
        } else 
        {
            System.out.println("File is empty.");
            maze = null;
        }
    }

    /**
     * This method allows the user to call the private solveMaze method.
     * 
     * @return This method returns true or false based upon if the maze was able
     * to be solved or not.
     */
    public boolean solve() 
    {
        //call the findStart method
        int[] start = findStart();
        if (start != null) 
        {
            //call the solveMaze method with the starting coordinates 
            return solveMaze(start[0], start[1]);
        }
        return false;
    }

     /**
      * This method finds the start loacation for the maze, indicated by a '+'

     * @return This method returns the starting location as an array of 2 intigers
     * The first int is the row in which the starting loaction is and the second
     * is the column the starting location is in.
     */
    private static int[] findStart() 
    {
        //itterate over the whole maze looking for a '+'
        for (int i = 0; i < maze.length; i++) 
        {
            for (int j = 0; j < maze[i].length; j++) 
            {
                if (maze[i][j] == START) 
                {
                    //when found, return the coordinates as an array of ints
                    return new int[]{i, j};
                }
            }
        }
        //return null if no starting location is found
        return null;
    }


    /**
     * This method solves the maze by recursvly calling itself.
     * 
     * @param x The row of the maze
     * @param y The column of the maze
     * @return This method returns true if it reaches the end and false if it doesnt
     */
    private static boolean solveMaze(int x, int y) 
    {
        //BASE CASES
        //check if the position is out of bounds
        if (x < 0 || y < 0 || x >= maze.length || y >= maze[x].length) 
        {
            return false;
        }
        //check if the postion is the end
        if (maze[x][y] == END) 
        {
            return true;
        }
        //check if the position is a place that it is not a solution
        if (maze[x][y] == WALL || maze[x][y] == PATH || maze[x][y] == DEAD_END) 
        {
            return false;
        }
        //END OF BASE CASES

        //mark the position as part of the path
        maze[x][y] = PATH;

        //recursivly call the solveMaze method checking each direction
        //LEFT
        if (solveMaze(x, y - 1)) 
        {
            return true;
        } 
        //RIGHT
        else if (solveMaze(x, y + 1)) 
        {
            return true;
        } 
        //UP
        else if (solveMaze(x - 1, y)) 
        {
            return true;
        } 
        //DOWN
        else if (solveMaze(x + 1, y)) 
        {
            return true;
        }

        //if no direction is a path to the end mark it
        //as a dead end
        maze[x][y] = DEAD_END;
        return false;
    }

    /**
     * This method prints the maze
     */
    public void printMaze() 
    {
        for (char[] row : maze) 
        {
            for (char c : row) 
            {
                System.out.print(c);
            }

            //start a new line after reaching the end
            System.out.println();
        }
    }
}
