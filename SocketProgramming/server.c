#include <stdio.h>
#include <stdlib.h>     //  This header file provides several standard library functions in C. exit() , perror() is defined in this library.
#include <string.h>
#include <unistd.h>     // This header file provides access to the POSIX operating system API . close() , read() , write() , send() are defined in this library.
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MSG_SIZE 1024

int main() {

    int server_fd, new_socket, valread;     // These are integer variables used to hold file descriptors for the server socket (server_fd), the client socket (new_socket), and the number of bytes read from the client socket (valread).

    struct sockaddr_in address;         // This is a structure (defined in <arpa/inet.h>) used to hold address information. Specifically, it's used to store the server address information (IP address and port number).

    int opt = 1;
    int addrlen = sizeof(address);

    char buffer[MAX_MSG_SIZE] = {0};    //This is an array of characters (a buffer) used to store data received from the client. It's initialized with zeros to ensure that it's empty initially.



    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
        perror("socket failed");       // The perror() function is defined in the <stdio.h> header file. This function is used to print an error message to the standard error stream (stderr)
        exit(EXIT_FAILURE);

        /* 
            The socket() function (defined in <arpa/inet.h> ) is called to create a socket. It takes three arguments:

                AF_INET: This specifies the address domain (IPv4).

                SOCK_STREAM: This specifies the socket type (in this case, a stream socket, which provides sequenced, reliable, two-way, connection-based byte streams).

                0: This specifies the protocol (in this case, the default protocol for the given address family and socket type).

            If the socket() function fails (returns 0), it prints an error message using perror() and exits the program with an error code (EXIT_FAILURE).
        
        */
    }




    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR , &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);

        /* 
        

            1. `setsockopt()` function is used to set options on a socket. It allows you to customize various aspects of socket behavior.

            2. The parameters of `setsockopt()` function are as follows:

                - `server_fd`: The file descriptor of the socket for which options are being set.

                - `SOL_SOCKET`: This specifies the level at which the option is defined. In this case, it indicates that the option is at the socket API level.

                - `SO_REUSEADDR`: This is the specific option being set. It allows the socket to bind to an address that is already in use, as long as the previous connection using that address is in a `TIME_WAIT` state. This can be useful for servers that need to quickly restart and reuse the same port.

                - `&opt`: This is a pointer to the value that specifies whether the `SO_REUSEADDR` option is enabled (`opt` is set to 1).

                - `sizeof(opt)`: This specifies the size of the option value.

            3. The `if` statement checks the return value of `setsockopt()`. If it returns a non-zero value, indicating an error, the `perror()` function is called to print an error message indicating the cause of the failure (in this case, an error in setting socket options), and the program exits with a failure status (`EXIT_FAILURE`).

            In summary, this portion of code sets the `SO_REUSEADDR` option on the server socket to allow reusing the same address and port, and it checks for any errors during this operation. If an error occurs, it prints an error message and exits the program.

        */
    }


    address.sin_family = AF_INET;        // it sets sin_family to AF_INET, which indicates that the address is an IPv4 address.

    address.sin_addr.s_addr = INADDR_ANY;   // INADDR_ANY is a constant that represents "any" IPv4 address. When used in this context, it means that the socket will accept connections to any of the IP addresses of the host

    address.sin_port = htons( PORT );       // This line sets the port number to bind the socket to. htons() is a function that converts the unsigned short integer PORT from host byte order to network byte order (big-endian) 




    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, (socklen_t)addrlen)<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);

        /* 
            bind() function: This function is used to associate a socket with a specific address (IP address and port number) on the server side.

            Parameters of bind() function:

            server_fd: The file descriptor of the socket that we want to bind.

            (struct sockaddr *)&address: A pointer to a structure (struct sockaddr_in) containing the server's address information.
            
            (socklen_t)addrlen: The size of the address structure.

            The if statement checks the return value of the bind() function call. If bind() returns a value less than 0, it indicates an error in binding the socket.

            This part of the code attempts to bind the server socket (server_fd) to the specified address (&address) .  Successful binding is essential for the server to start listening for incoming connections on the specified address and port.
        */

    }



    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);

        /* 
            listen() function: This function is used to mark the socket referred to by server_fd as a passive socket, which means it will be used to accept incoming connection requests.

            Parameters of listen() function:

            server_fd: The file descriptor of the socket that will be listening for incoming connections.

            3: This parameter specifies the maximum length of the queue of pending connections. In other words, it sets the maximum number of clients that can be waiting to be served by the server. In this case, it's set to 3.

            If listen() returns a value less than 0, it indicates an error in setting the socket to listen for incoming connections.  Successful invocation of listen() is crucial for the server to start accepting connections from clients.
         */
    }


    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);

        /* 
            accept() function: This function is used by a server to accept a connection request from a client. When a client tries to connect to the server, the accept() function is called to create a new socket (`new_socket`) that is dedicated to communication with that specific client.

            Parameters of accept() function:

            server_fd: The file descriptor of the socket that is listening for incoming connections.

            (struct sockaddr *)&address: A pointer to a structure (struct sockaddr_in) to store the address of the connecting client.

            (socklen_t*)&addrlen: A pointer to a variable (`addrlen`) containing the size of the structure pointed to by address.

            The if condition checks the return value of the accept() function call. If accept() returns a value less than 0, it indicates an error in accepting the connection request.

            If the accept() function succeeds, it returns a new file descriptor (`new_socket`) representing the newly created socket dedicated to communication with the client.
        
        */
    }

    
    valread = read( new_socket , buffer, MAX_MSG_SIZE);
    printf("Received message from client: %s\n",buffer);

    /* 
        read() function: This function is used to read data from a file descriptor (`new_socket` in this case). It reads up to MAX_MSG_SIZE bytes of data from the socket into the buffer.

        Parameters of read() function:

        `new_socket`: The file descriptor of the socket from which data will be read.

        buffer: A pointer to a buffer where the data read from the socket will be stored.

        MAX_MSG_SIZE: The maximum number of bytes to read from the socket.

        valread variable: This variable holds the number of bytes actually read by the read() function. It indicates the size of the data received from the client.

        After reading data from the client into the buffer, the code prints the received message using printf().
    */

        

    return 0;
}
