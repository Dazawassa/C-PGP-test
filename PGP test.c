#include <stdio.h>
#include <gpgme.h>

// use GPGme to encrypt the password.
void pgpEncrypt(char* str, char* key) {
    gpgme_error_t err;
    gpgme_ctx_t ctx;
    gpgme_data_t in, out;
    gpgme_key_t keys[2] = { NULL, NULL };
    size_t nread;
    char* ciphertext;

    // Initialize the library
    // gpgme_check_version(NULL);
    // setlocale(LC_ALL, "");
    // gpgme_set_locale(NULL, LC_CTYPE, setlocale(LC_CTYPE, NULL));
    // gpgme_set_locale(NULL, LC_MESSAGES, setlocale(LC_MESSAGES, NULL));

    // Create a new context
    err = gpgme_new(&ctx);
    if (err) {
        printf("Failed to create context: %s\n", gpgme_strerror(err));
        return;
    }

    // Set the protocol to OpenPGP
    err = gpgme_set_protocol(ctx, GPGME_PROTOCOL_OpenPGP);
    if (err) {
        printf("Failed to set protocol: %s\n", gpgme_strerror(err));
        return;
    }

    // Get the key to encrypt with
    err = gpgme_get_key(ctx, key, &keys[0], 0);
    if (err) {
        printf("Failed to get key: %s\n", gpgme_strerror(err));
        return;
    }

    // Create data objects for the plaintext and ciphertext
    err = gpgme_data_new_from_mem(&in, str, strlen(str), 0);
    if (err) {
        printf("Failed to create data object for plaintext: %s\n", gpgme_strerror(err));
        return;
    }

    err = gpgme_data_new(&out);
    if (err) {
        printf("Failed to create data object for ciphertext: %s\n", gpgme_strerror(err));
        return;
    }

    // Encrypt the plaintext
    err = gpgme_op_encrypt(ctx, keys, GPGME_ENCRYPT_ALWAYS_TRUST, in, out);
    if (err) {
        printf("Failed to encrypt: %s\n", gpgme_strerror(err));
        return;
    }

    // Get the ciphertext
    ciphertext = gpgme_data_release_and_get_mem(out, &nread);

    // Print the ciphertext
    printf("Encrypted: %s\n", ciphertext);

    // Clean up
    free(ciphertext);
}

// Run at boot.
int main() {
    printf("Please enter a password.\n");
    // Passwords can't be more than 30 characters.
    char str[30];
    // Encryption keys for PGP should be 50 characters.
    char key[50];
    // Get the password from the user.
    fgets(str, 30, stdin);
    // Asks for a key.
    fgets(key, 30, stdin)
    // Encrypt the password.
    pgpEncrypt(str, key);
    return 0;
}