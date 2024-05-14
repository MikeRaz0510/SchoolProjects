/*
 * Assignment 5 CSCI 350
 *
 *
 *
 *
 */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// Constants
const char* SERVER_IP = "10.158.56.43";

// Function Prototypes
string connectUDP();
string connectTCP();
string decryptRC4(const string& data, const string& key);

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

//Connect to the server with UDP and return the secret key.
string connectUDP() 
{
	// Create the UDP socket
	int sock, rc;
	unsigned int addrlen;
	char buffer[1024];
	
	// Create the socket
	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("Failed to create socket");
		exit(EXIT_FAILURE);
	}
	
	// Construct the target sockaddr_in structure
	struct sockaddr_in target; // structure for address of target	
	memset(&target, 0, sizeof(target)); /* Clear struct */
	target.sin_family = AF_INET;			/* Internet/IP */
	target.sin_addr.s_addr = inet_addr(SERVER_IP); /* IP address */

	// set socket to timeout mode
	struct timeval read_timeout;
	read_timeout.tv_sec = 0;
	read_timeout.tv_usec = 200000;	// varies depending of network connectivity
	setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &read_timeout, sizeof read_timeout);

	// loop to probe for responses
	for (int port=9000; port <= 9100; port++) {
		target.sin_port = htons(port); /* target port */

		// Send the packet to the target
		rc = sendto(sock, "group 4", 7, 0, (struct sockaddr *) &target, sizeof(target));
		if (rc < 0)
		{
			perror("sendto");
			exit(EXIT_FAILURE);
		}

		// Receive the message back from the server
		addrlen = sizeof(target);
		rc = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&target, &addrlen);
		if (rc < 0)
		{		
			if (errno == EWOULDBLOCK) {
				cout << "." << flush;
				continue;
			} else {
				perror("sendto");
				exit(EXIT_FAILURE);
			}
		}
		cout << " Target port " << ntohs(target.sin_port) << " sent: " << rc << " bytes\n";
		break;
	}
	close(sock);

	return buffer;
}


//Connect to the server with TCP and return the secret message. 

string connectTCP() {
	// Create the TCP socket
    int sock, rc;
    vector<char> buffer(4096); // Needed a larger buffer
    string response;

	// Create the socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

	// Construct the target sockaddr_in structure
    sockaddr_in target = {};
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(SERVER_IP); // IP address 

	// loop to probe for responses
    for (int port = 9000; port <= 9100; port++) {
        target.sin_port = htons(port);// target port

		// Connect to target
		/*
        rc = connect(sock, (struct sockaddr *) &target, sizeof(target));
        if (rc < 0) {
            if (errno == ECONNREFUSED) continue;
            perror("connect");
            exit(EXIT_FAILURE);
        }
*/

		rc = connect(sock, (struct sockaddr *) &target, sizeof(target));
		if (rc < 0) {
			if (errno == ECONNREFUSED) {
				cout << "." << flush;
				continue;
			} else {
				perror("connect");
				exit(EXIT_FAILURE);
			}
		}

		// Send the message to the server 
        if (write(sock, "group 4", 7) < 0) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Receive the message back from the server. Continue reading until the end. 
		
        while ((rc = read(sock, buffer.data(), buffer.size())) > 0) {
            response.append(buffer.data(), rc);
        }
        if (rc < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }
		cout << " Target port " << ntohs(target.sin_port) << " sent: " << response.size() << " bytes\n";
		//cout << "Received data: " << buffer << endl; // Display the received data
        break; 
    }
    close(sock);
    return response;
}


// Decrypt the RC4 encrypted message
string decryptRC4(const string& data, const string& key) {
    vector<unsigned char> plaintext(data.size());
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handleErrors();

    if (!EVP_DecryptInit_ex(ctx, EVP_rc4(), NULL, reinterpret_cast<const unsigned char*>(key.data()), NULL))
        handleErrors();

    int len = 0, plaintext_len = 0;
    if (!EVP_DecryptUpdate(ctx, plaintext.data(), &len, reinterpret_cast<const unsigned char*>(data.data()), data.size()))
        handleErrors();
    plaintext_len += len;

    if (!EVP_DecryptFinal_ex(ctx, plaintext.data() + len, &len)) handleErrors();
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return string(plaintext.begin(), plaintext.begin() + plaintext_len);
}

int main() {

	

    // Step 1 connect to server with UDP and return the RC4 secret key
    string rc4SecretKey = connectUDP();

	// Step 2 connect to the server with TCP and return the encrypted RC4 Message    
    string rc4Message = connectTCP();

    // Step 3 Decrypt the message
    string decryptedMessage = decryptRC4(rc4Message, rc4SecretKey);


    //Output the decrypted message.
    cout << endl <<"Decrypted Message: " << decryptedMessage << endl;

    return 0;
}
