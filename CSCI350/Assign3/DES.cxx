#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <openssl/des.h>

using namespace std;
int main() {
   
   // prepare DES key:
	DES_cblock cbc_key = {0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef};
	DES_key_schedule key;	
	// example input block: 8 bytes of data
	DES_cblock plaintext = { 'm','y','s','e','c','r','e','t'};
	// block to hold encrypted data
	DES_cblock cyphertext;	
	// set DES key
	DES_set_key(&cbc_key,&key);
	
	// block to hold decrypted data
	DES_cblock decyphertext;	


    int all = 0, count = 10000, runcount = -1;
	struct timespec start, stop;
	srand (time(NULL));

    // Encrypt
	for (int i=0; i < count; i++) {
		
		clock_gettime(CLOCK_REALTIME, &start);	
		
		// payload			
		// run encryption
	    DES_ecb_encrypt(&plaintext, &cyphertext, &key,DES_ENCRYPT);
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
    all = 0;
    
    // Decrypt
	for (int i=0; i<count; i++) {
		
		clock_gettime(CLOCK_REALTIME, &start);	
		
		// payload
        // run decryption
	    DES_ecb_encrypt(&cyphertext, &decyphertext, &key,DES_DECRYPT);
		// end of payload 	
			
		clock_gettime(CLOCK_REALTIME, &stop);
	
		long start_time = start.tv_sec * 1000000000 + start.tv_nsec ;
		long stop_time = stop.tv_sec * 1000000000 + stop.tv_nsec;
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

    // Output decrypted text to check correctness
    cout << "Decrypted Text: " << decyphertext << endl;

    return 0;
}