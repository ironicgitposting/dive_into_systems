#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
    C Program: Basic pthread Example
    Compile: gcc -Wall -g -o pthread_ex pthread_ex.c -lpthread
    Run: ./pthread_ex

    This program demonstrates:
    - How to create a thread using pthreads
    - How to pass data to a thread
    - How to wait for a thread to finish (join)
*/

// Thread function: receives a void pointer argument
// Prints the message passed from the main thread
void *print_message(void *arg)
{
    char *message = (char *)arg;          // Cast argument to char*
    printf("Thread says: %s\n", message); // Print the message
    pthread_exit(NULL);                   // Exit the thread
}

int main()
{
    pthread_t thread;                  // Thread identifier
    char msg[] = "Hello from thread!"; // Message to pass to the thread

    // Create a new thread
    // Arguments:
    //   &thread: pointer to thread identifier
    //   NULL: default thread attributes
    //   print_message: function to run in the new thread
    //   msg: argument to pass to the thread function
    if (pthread_create(&thread, NULL, print_message, msg) != 0)
    {
        perror("pthread_create failed"); // Print error if thread creation fails
        return 1;
    }

    // Wait for the thread to finish
    // Arguments:
    //   thread: thread identifier
    //   NULL: we don't need the thread's return value
    pthread_join(thread, NULL);

    printf("Main thread done.\n"); // Indicate main thread is finished
    return 0;
}
