#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <openssl/blowfish.h>

using namespace std;

void EncryptBF(const unsigned char *plaintext, unsigned char *ciphertext) {
    // prepare BF key
    BF_KEY enc_key;
    unsigned char keyBytes[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
                                0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
                                0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
                                0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};
    BF_set_key(&enc_key, 64, keyBytes);
    // encrypt the data
    BF_ecb_encrypt(plaintext, ciphertext, &enc_key, BF_ENCRYPT);
}

void DecryptBF(const unsigned char *ciphertext, unsigned char *decryptedtext) {
    // prepare BF key
    BF_KEY dec_key;
    unsigned char keyBytes[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
                                0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
                                0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
                                0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};
    BF_set_key(&dec_key, 64, keyBytes);
    // decrypt the data
    BF_ecb_encrypt(ciphertext, decryptedtext, &dec_key, BF_DECRYPT);
    decryptedtext[8] = '\0'; 
}

int main() {
    // 16 bytes of data
    unsigned char plaintext[] = "mySecret";
    // buffer to hold encrypted data and decrypted data
    unsigned char ciphertext[8];
    unsigned char decryptedtext[8];
    int all = 0, count = 10000, runcount = -1;
    struct timespec start, stop;
    srand(time(NULL));
    // Encrypt
    for (int i=0; i<count; i++) {
        clock_gettime(CLOCK_REALTIME, &start);
        // payload
        EncryptBF(plaintext, ciphertext);
        // end of payload
        clock_gettime(CLOCK_REALTIME, &stop);
        long start_time = start.tv_sec * 1000000000 + start.tv_nsec;
        long stop_time = stop.tv_sec * 1000000000 + stop.tv_nsec;
        all += stop_time - start_time;
        runcount++;
        if (runcount == 1000){
            cout << "Encrypt Run #: " << i << " Time: " << stop_time - start_time << " nanoseconds\n";
            runcount = 0;
        }
    }
    int avgEncrypt = all/count;
    cout << "----------------------------- \n";
    runcount = -1;
    all = 0;
    // Decrypt
    for (int j=0; j<count; j++) {
        clock_gettime(CLOCK_REALTIME, &start);
        // payload
        DecryptBF(ciphertext, decryptedtext);
        // end of payload
        clock_gettime(CLOCK_REALTIME, &stop);
        long start_time = start.tv_sec * 1000000000 + start.tv_nsec;
        long stop_time = stop.tv_sec * 1000000000 + stop.tv_nsec;
        all += stop_time - start_time;
        runcount++;
        if (runcount == 1000){
            cout << "Decrypt Run #: " << j << " Time: " << stop_time - start_time << " nanoseconds\n";
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
    cout << "Decrypted Text: " << decryptedtext << endl;
    return 0;
}
