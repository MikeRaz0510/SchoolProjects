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
import java.util.Scanner;

public class mazeTester
{

    public static void main(String[] args) throws FileNotFoundException
    {
        //declare variables
        Scanner input = new Scanner(System.in);
        String fileName;
        boolean fileFound = true;

        //Prompt for file until a valid responce 
        do
        {
            System.out.print("Enter the name of your file: ");
            fileName = input.next();
            File file = new File(fileName);
            if(file.exists())
            {
                fileFound = true;
            }
            else
            {
                System.err.println("File not found, plese try again.");
                fileFound = false;
            }

        }while (!fileFound);
        input.close();

        //create the maze object
        Maze maze = new Maze(fileName);

        //display original maze
        System.out.println("Original Maze:");
        maze.printMaze();

        //solve the maze, if possible
        boolean solved = maze.solve();

        //display the ending state of the maze
        System.out.println("\nSolved Maze:");
        maze.printMaze();

        //display weather or not the maze was solvable
        if (solved) 
        {
            System.out.println("This maze was solvable!");
        } 
        else 
        {
            System.out.println("This maze was unsolvable.");
        }
            
    }
}