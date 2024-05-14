#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Shared resource
char sharedString[] = "All work and no play makes Jack a dull boy.";

// Semaphores
sem_t rw_sem; // Semaphore for writing or when no readers are reading
sem_t cs_sem; // Semaphore for critical section (managing readCount)

// Read count
int readCount = 0;

void* reader(void* args) {
    int id = *((int*)args);

    while(1) 
    {
        // Attempt to enter the reading section
        sem_wait(&cs_sem); // Protect access to readCount
        readCount++;

        if (readCount == 1) 
        {
            // First reader locks the writers out
            sem_wait(&rw_sem);
        }

        // Release access to readCount
        sem_post(&cs_sem); 
        printf("read_count increments to %d\n", readCount);

        // Check if the shared string is empty before proceeding
        if (strlen(sharedString) == 0) 
        {
            // If empty, exit 
            break;
        }

        // Perform reading
        printf("reader %d is reading ... Content: %s\n", id, sharedString);
        sleep(1); // Simulate reading time

        // Exit the reading section
        sem_wait(&cs_sem); // Protect access to readCount
        readCount--;
        printf("read_count decrements to %d\n", readCount);
        
        // Last reader unlocks the writers
        if (readCount == 0) 
        {
            sem_post(&rw_sem);
        }
        sem_post(&cs_sem); // Release access to readCount

        // Break if the shared string is empty
        if (strlen(sharedString) == 0)
        {
            break;
        }
    }

    // Reader is exiting
    printf("reader %d is exiting ...\n", id);
    free(args);
    return NULL;
}

void* writer(void* args) 
{
    int id = *((int*)args);

    while(1) 
    {
        //Wait for rw lock 
        sem_wait(&rw_sem); 

        // Check if the string is empty and exit
        if (strlen(sharedString) == 0) 
        {
            sem_post(&rw_sem); 
            break;
        }

        // Perform the writing operation
        printf("Writer %d is writing...\n", id);
        sharedString[strlen(sharedString) - 1] = '\0'; // Remove the last character
        printf("Content is now: %s\n", sharedString);
        sleep(1); // Simulate writing time
        sem_post(&rw_sem); // Release the lock
        
    }
    
    //writer is exiting
    printf("Writer %d is exiting ...\n", id);
    free(args);
    return NULL;
}


int main(int argc, char* argv[]) 
{
    //Check if input is correct format
    if (argc != 3) 
    {
        fprintf(stderr, "Usage: %s <number of readers> <number of writers>\n", argv[0]);
        return -1;
    }
    
    printf("*** Reader-Writer Problem Simulation ***\n");

    //store number of readers and writers
    int numReaders = atoi(argv[1]);
    int numWriters = atoi(argv[2]);
    printf("Number of reader thereads: %d\n", numReaders);
    printf("Number of writer thereads: %d\n", numWriters);

    //initilize readers and writers
    pthread_t readers[numReaders], writers[numWriters];
    sem_init(&rw_sem, 0, 1);
    sem_init(&cs_sem, 0, 1);

    // Create reader threads
    for (int i = 0; i < numReaders; i++) 
    {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&readers[i], NULL, reader, id);
    }

    // Create writer threads
    for (int i = 0; i < numWriters; i++) 
    {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&writers[i], NULL, writer, id);
    }

    // Wait for all threads to finish
    for (int i = 0; i < numReaders; i++) 
    {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < numWriters; i++) 
    {
        pthread_join(writers[i], NULL);
    }


    printf("All threads are done.\n");

    // Cleanup
    sem_destroy(&rw_sem);
    sem_destroy(&cs_sem);

    printf("Resources cleaned up.\n");

    return 0;
}
