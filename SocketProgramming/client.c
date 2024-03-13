#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MSG_SIZE 1024

int main() {

    int sock = 0, valread;      // `sock` usually represents an uninitialized or invalid socket descriptor. `valread` will be used to store the number of bytes read by the read() function

    struct sockaddr_in serv_addr;   //This structure will be used to specify the address and port of the server to which the client will connect.

    char buffer[MAX_MSG_SIZE] = {0};    // This buffer will be used to store the message received from the server.

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) { // it creates a socket using the socket() function.
        printf("\n Socket creation error \n");
        return -1;
    }


    serv_addr.sin_family = AF_INET;         // do
    serv_addr.sin_port = htons(PORT);       // do


    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
        /* 
            This function converts an IPv4 address in text format to binary form and stores it in the sin_addr member of the serv_addr structure.

                - AF_INET: This specifies the address family (IPv4).

                - "127.0.0.1": This is the IPv4 address in text format to be converted. In this case, it represents the loopback address.

                - &serv_addr.sin_addr: This is a pointer to the sin_addr member of the serv_addr structure, where the binary representation of the IPv4 address will be stored.

            The result of inet_pton() is checked. If it returns a value less than or equal to 0, it indicates an error in converting the address.
         */
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;

        /* 
        This line attempts to establish a connection to the server using the connect() function.

            - sock: The file descriptor of the socket to connect.

            - (struct sockaddr *)&serv_addr: A pointer to the server address structure (serv_addr) cast to the generic sockaddr structure.

            - sizeof(serv_addr): The size of the server address structure.

        If connect() fails (returns a value less than 0), it indicates a failure in establishing a connection with the server. In such cases, an error message is printed, and the program returns -1.
         */
    }
    
   
    printf("Enter message to send to server: ");


    fgets(buffer, MAX_MSG_SIZE, stdin);
    /* 
        This line reads a line of input from the user (stdin) and stores it into the character array buffer.
        
            - buffer: The destination buffer where the input will be stored.

            - MAX_MSG_SIZE: The maximum number of characters to read, ensuring that the input does not exceed the buffer size to prevent buffer overflow.

            - stdin: The standard input stream from which the input is read (typically the keyboard).

        fgets() reads characters from the input stream until either a newline character ('\n') is read, the end-of-file (EOF) is reached, or the specified maximum number of characters (MAX_MSG_SIZE - 1) is read.
     */
    
    valread=send(sock , buffer , strlen(buffer) , 0 );

    /* 
        send() function sends the data stored in the buffer to the server through the established socket connection (sock).  It returns the number of bytes sent on success or -1 on failure.

            sock: The file descriptor of the socket through which the data will be sent.

            buffer: The data (message) to be sent, which was previously read from the user input.

            strlen(buffer): The length of the data (message) to be sent. strlen() calculates the length of the string in buffer excluding the null terminator ('\0').

            0: This parameter is used for flags, indicating additional options for the send operation. In this case, it's set to 0, indicating no special flags are used.
        

     */
    printf("Message sent to server\n");
        
    
    
    return 0;
}
