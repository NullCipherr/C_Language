#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a message using the Caesar cipher
void encryptCaesar(char *message, int key) 
{
    int size = strlen(message);

    for (int i = 0; i < size; i++) 
    {
        // Check if the character is an uppercase letter
        if (message[i] >= 'A' && message[i] <= 'Z') 
        {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
        // Check if the character is a lowercase letter
        else if (message[i] >= 'a' && message[i] <= 'z') 
        {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        // Do nothing if the character is not a letter
    }
}

// Function to calculate the index of coincidence of a message
double calculateIndexOfCoincidence(const char *message) 
{
    int uppercaseLetters[26] = {0};
    int totalLetters = 0;
    int size = strlen(message);

    for (int i = 0; i < size; i++) 
    {
        if (isupper(message[i])) 
        {
            uppercaseLetters[message[i] - 'A']++;
            totalLetters++;
        }
    }

    double indexOfCoincidence = 0.0;

    for (int i = 0; i < 26; i++) 
    {
        double frequency = (double)uppercaseLetters[i] / totalLetters;
        indexOfCoincidence += frequency * frequency;
    }

    return indexOfCoincidence;
}

// Function to check the strength of the Caesar encryption
void checkCaesarStrength(const char *message) 
{
    double originalIndexOfCoincidence = calculateIndexOfCoincidence(message);

    printf("Index of Coincidence of the original message: %.4f\n", originalIndexOfCoincidence);

    for (int key = 1; key < 26; key++) 
    {
        char decryptedMessage[100];
        for (int i = 0; i < strlen(message); i++) 
        {
            if (isupper(message[i])) 
            {
                decryptedMessage[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
            } 
            else 
            {
                decryptedMessage[i] = message[i];
            }
        }
        
        decryptedMessage[strlen(message)] = '\0';

        double indexOfCoincidence = calculateIndexOfCoincidence(decryptedMessage);

        printf("Key %d: Index of Coincidence %.4f\n", key, indexOfCoincidence);
    }
}

int main() 
{
    char message[100];
    int key;

    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the encryption key (an integer): ");
    scanf("%d", &key);

    // Remove the newline character ('\n') inserted by fgets
    message[strcspn(message, "\n")] = '\0';

    // Call the function to encrypt the message
    encryptCaesar(message, key);

    printf("\nEncrypted Message --> %s\n", message);

    // Check Caesar encryption strength(IN PROGRESS ....)
    // checkCaesarStrength(message);

    return 0;
}
