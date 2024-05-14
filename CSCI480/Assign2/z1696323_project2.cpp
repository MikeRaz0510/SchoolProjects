#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

using namespace std;

int main(void) 
{
    int pipe_a[2], pipe_b[2];
    
    //create 2 pipes
    if (pipe(pipe_a) < 0 || pipe(pipe_b) < 0) 
    {
        //error message if pipes creation fails
        perror("Pipe creation failed");
        return 1;
    }

    pid_t child_pid1, child_pid2, intermediate_pid;
    

    //Fork first child
    if ((child_pid1 = fork()) < 0) 
    {
        perror("Fork failed");
        return 1;
    } 

    //Child Process
    else if (child_pid1 == 0) 
    {
        //create buffer
        char buffer[50];

        //Close write end of pipe_a
        close(pipe_a[1]); 

        //read from pipe a
        read(pipe_a[0], buffer, sizeof(buffer));

        cout << "\nChild" << ": My PID is " << getpid() << ", my parent's PID is " << getppid() << ". " << "I read from pipe A: Go do some chores.\n";

        //close read end of pipe a
        close(pipe_a[0]);

        //sleep child for 3 seconds
        sleep(3);
        cout << "Child: " << getpid() << " is awake.\n";

        return 0;
    }

    //Fork second child
    if ((intermediate_pid = fork()) < 0) 
    {
        perror("Fork failed");
        return 1;
    } 

    //Intermediate parent process
    else if (intermediate_pid == 0) 
    { 
        //create buffer
        char buffer[50];

        // Close read end of pipe_a and write end of pipe_b
        close(pipe_a[0]); 
        close(pipe_b[1]);
        
        //read from pipe_b
        read(pipe_b[0], buffer, sizeof(buffer));

        cout << "\nIntermediate Parent" << ": My PID is " << getpid() << ", my parent's PID is " << getppid() << ". " 
             << "My child is " + to_string(child_pid1) + ". I write to pipe B: Go do some chores.\n\n";

        //Close read end of pipe_b and write end of pipe_a
        close(pipe_b[0]); 
        close(pipe_a[1]);

        //sleep for 3 seconds
        sleep(3);
        cout << "Intermediate Parent: " << getpid() << " is awake.\n";

        return 0;
    }

    else 
    {
        //Fork third child
        if ((child_pid2 = fork()) < 0) 
        {
            perror("Fork failed");
            return 1;
        } 

        //Grandchild process
        else if (child_pid2 == 0) 
        { 
            //create buffer
            char buffer[50];

            //Close read end of pipe_b
            close(pipe_b[0]); 
            
            //read from pipe_b
            read(pipe_b[1], buffer, sizeof(buffer));

            cout << "\nChild" << ": My PID is " << getpid() << ", my parent's PID is " << getppid() << ". " 
                 << "I read from pipe B: Go do some chores.\n";

            //Close write end of pipe_b
            close(pipe_b[1]); 

            //sleep for 3 seconds
            sleep(3);
            cout << "Child: " << getpid() << " is awake.\n";
            return 0;
        } 

        //Parent process
        else 
        { 
            //fix output from being garbled
            setbuf(stdout,NULL);

            //Close read end of pipe_a and read end of pipe_b
            close(pipe_a[0]); 
            close(pipe_b[0]); 

            cout << "\nParent: My PID is " << getpid() << ", my parent's PID is " << getppid() 
                 << ". My Children are " << child_pid1 << ", " << child_pid2 
                 << ". I write to pipe A: Go do some chores.\n";
                   
            //write command using all process IDs
            string command = "/bin/ps -f --ppid " + to_string(getpid()) + "," + to_string(getppid()) + "," + to_string(child_pid1) + "," + to_string(child_pid2);
            cout << "\nParent: Issuing command: "  + command << endl;

            //message for children
            const char *message = "Go do some chores.";

            // Write to pipe_a for child process
            write(pipe_a[1], message, strlen(message) + 1);

            // Write to pipe_b for intermediate parent process
            write(pipe_b[1], message, strlen(message) + 1);

            //convert string to const char *
            const char *commandChar = command.c_str();

            //run command
            system(commandChar);
            cout << endl;

            //Close write end of pipe_a and write end of pipe_b
            close(pipe_a[1]); 
            close(pipe_b[1]);

            //wait for children to finish
            wait(NULL);
            wait(NULL);
            wait(NULL);
            cout << "Parent: Child process finished their work." << endl << endl;
        }
    }
    return 0;
}