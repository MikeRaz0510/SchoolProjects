#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <openssl/aes.h>

using namespace std;

void EncryptAES(const unsigned char *plaintext, unsigned char *ciphertext) {
    // prepare AES key
    AES_KEY enc_key;
    unsigned char keyBytes[] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
                                 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef };
    AES_set_encrypt_key(keyBytes, 128, &enc_key);

    // encrypt the data
    AES_ecb_encrypt(plaintext, ciphertext, &enc_key, AES_ENCRYPT);
}

void DecryptAES(const unsigned char *ciphertext, unsigned char *decryptedtext) {
    // prepare AES key
    AES_KEY dec_key;
    unsigned char keyBytes[] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
                                 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef };
    AES_set_decrypt_key(keyBytes, 128, &dec_key);

    // decrypt the data
    AES_ecb_encrypt(ciphertext, decryptedtext, &dec_key, AES_DECRYPT);
    decryptedtext[16] = '\0'; 
}

int main() {
    // 16 bytes of data
    unsigned char plaintext[] = "CSCI350 is fun.";

    // buffer to hold encrypted data and decrypted data
    unsigned char ciphertext[16];
    unsigned char decryptedtext[17];

    int all = 0, count = 10000, runcount = -1;
	struct timespec start, stop;
	srand (time(NULL));

    // Encrypt
	for (int i=0; i < count; i++) {
		
		clock_gettime(CLOCK_REALTIME, &start);	
		
		// payload			
		EncryptAES(plaintext, ciphertext);
		// end of payload 	
			
		clock_gettime(CLOCK_REALTIME, &stop);
	
		long start_time = start.tv_sec * 1000000000 + start.tv_nsec ;
		long stop_time = stop.tv_sec * 1000000000 + stop.tv_nsec;
		all += stop_time - start_time;
        runcount++;
        if (runcount == 1000)
        {
            cout << "Encrypt Run #: " << i << " Time: " << stop_time - start_time << " nanoseconds\n";
            runcount = 0;
        }
	}
	int avgEncrypt = all/count;

	cout << "----------------------------- \n";
    runcount = -1;
    long longestTime = 0;
    long runNum = 0;
    int countHigh = 0;
    all = 0;
    
    // Decrypt
	for (int i=0; i<count; i++) {
		
		clock_gettime(CLOCK_REALTIME, &start);	
		
		// payload			
		DecryptAES(ciphertext, decryptedtext);
		// end of payload 	
			
		clock_gettime(CLOCK_REALTIME, &stop);
	
		long start_time = start.tv_sec * 1000000000 + start.tv_nsec ;
		long stop_time = stop.tv_sec * 1000000000 + stop.tv_nsec;
      /*   if (stop_time - start_time > longestTime)
        {
            longestTime = stop_time - start_time;
            runNum = i;
        }
        if (stop_time - start_time > 1000)
        {
            countHigh++;
        } */
		all += stop_time - start_time;	
        runcount++;
        if (runcount == 1000) //this is here to only output every 1000th value
        {
            cout << "Decrypt Run #: " << i << " Time: " << stop_time - start_time << " nanoseconds\n";
            runcount = 0;
        }
	}
	int avgDecrypt = all/count;

    cout << "----------------------------- \n";

    // Output both of the average values
    cout << "Average time used to encrypt: " << avgEncrypt << " nanoseconds\n";
	cout << "Average time used to decrypt: " << avgDecrypt << " nanoseconds\n";

    cout << "----------------------------- \n";
/* 
    cout << "Longest time to decrypt: " << longestTime << " On run #" << runNum << endl;
    cout << "Number of high decrypt times: " << countHigh << endl;
 */
    // Output decrypted text to check correctness
    cout << "Decrypted Text: " << decryptedtext << endl;

    return 0;
}
