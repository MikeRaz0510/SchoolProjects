#include <iostream>
#include <unistd.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main(void)
{
    const int MAX_ARR_SIZE = 6;  
    string input[MAX_ARR_SIZE] {"\0", "\0", "\0", "\0", "\0", NULL};
    string reset[MAX_ARR_SIZE]; 
    int inputSize,
        rs,
        pid,
        status;

    for (int i = 0; i < MAX_ARR_SIZE; ++i)
    {
        reset[i] = input[i];
    }

    cout << "Enter command:\t";

    for (int x = 0; x < 5; x++)
    {
        cin >> input[x];
        ++inputSize;
        if (cin.peek() == '\n')
        {
            break;
        }
    }
    
    for (int y = 0; y < inputSize; y++)
    {
        cout << input[y] << endl;
    }
    
    while (input[0] != "exit")
    {
        fork();
        pid = wait(&status);
        if (pid == -1) // error
        {
            cout << "Nothing to wait for!\n";
        }
        else if (pid == 0) //child process
        {
            cout << "In child\n";
            const char* command = input[0];
            rs = execvp(command, input);
            if (rs == -1)
            {
                perror("execvp");
                exit(rs);
            }
        }
        else //parent process
        {
            cout << "Child over, in parent\n";
            
            for (int i = 0; i < MAX_ARR_SIZE; ++i)
            {
                input[i] = reset[i];
            }
            
            inputSize = 0;
            cout << "Enter command:\t";

            for (int x = 0; x < 5; x++)
            {
                cin >> input[x];
                ++inputSize;
                if (cin.peek() == '\n')
                {
                    break;
                }
            }
            
        }
    }
    

    return 0;
}