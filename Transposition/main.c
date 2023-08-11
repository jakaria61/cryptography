#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to perform columnar transposition encryption
void encryptColumnarTransposition(char *plaintext, int key) {
    int textLength = strlen(plaintext);
    int numRows = (textLength + key - 1) / key; // Calculate the number of rows
    char ciphertext[numRows][key]; // 2D array to hold the ciphertext

    // Initialize the 2D array with spaces
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < key; j++) {
            ciphertext[i][j] = ' ';
        }
    }

    // Fill in the 2D array with the plaintext characters
    int index = 0;
    for (int j = 0; j < key; j++) {
        for (int i = 0; i < numRows && index < textLength; i++) {
            ciphertext[i][j] = plaintext[index++];
        }
    }

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < key; j++) {
            printf("%c", ciphertext[i][j]);
        }
    }
    printf("\n");
}

int main() {
    char plaintext[1000];
    int key;

    // Input plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    // Input the encryption key (number of columns)
    printf("Enter the encryption key (number of columns): ");
    scanf("%d", &key);

    // Perform encryption and print the result
    encryptColumnarTransposition(plaintext, key);

    return 0;
}
