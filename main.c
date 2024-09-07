#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// XOR Encryption/Decryption function
static char *xor(char *a, char *secret)
{
    int secret_length = strlen(secret);
    int a_length = strlen(a);
    int i;
    char *cipher = malloc(a_length);
    if (cipher == NULL) {
        perror("cipher-buffer");
        return NULL;
    }

    for (i = 0; i < a_length; i++) {
        cipher[i] = a[i] ^ secret[i % secret_length];
    }
    return cipher;
}

// Function to convert string to ASCII Hex representation
void string_to_ascii_hex(char *str)
{
    while (*str) {
        printf("0x%02x ", (unsigned char)*str++);
    }
    printf("\n");
}

// Function to convert ASCII Hex representation to string
void ascii_hex_to_string(char *hex, int len)
{
    for (int i = 0; i < len; i++) {
        printf("%c", hex[i]);
    }
    printf("\n");
}

int main()
{
    // Task 1: Klartext in ASCII-Hexdarstellung
    char cleartext[] = "Geheimnachricht";
    printf("Klartext in ASCII-Hexdarstellung:\n");
    string_to_ascii_hex(cleartext);

    // Task 2: Schlüssel in ASCII-Hexdarstellung
    char key[] = "secret";
    printf("\nSchlüssel in ASCII-Hexdarstellung:\n");
    string_to_ascii_hex(key);

    // Task 3: Verschlüsseln des Klartextes mit dem Schlüssel
    char *encrypted = xor(cleartext, key);
    if (encrypted) {
        printf("\nVerschlüsselte Nachricht in ASCII-Hexdarstellung:\n");
        string_to_ascii_hex(encrypted);
        free(encrypted);
    }

    // Task 4: Entschlüsseln der gegebenen Geheimbotschaft
    char hex_message[] = {
        0x3a, 0x0b, 0x05, 0x1d, 0x17, 0x19, 0x12, 0x11, 0x0a, 0x19,
        0x45, 0x19, 0x12, 0x06, 0x0b, 0x06, 0x45, 0x27, 0x03, 0x04,
        0x10, 0x01
    };
    int hex_message_len = sizeof(hex_message);

    // Entschlüsseln
    char *decrypted = xor(hex_message, key);
    if (decrypted) {
        printf("\nEntschlüsselte Geheimbotschaft:\n");
        ascii_hex_to_string(decrypted, hex_message_len);
        free(decrypted);
    }

    return 0;
}
