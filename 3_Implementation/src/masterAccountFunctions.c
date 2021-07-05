#include "masterAccountFunctions.h"

typedef struct
{
    unsigned char username[SHA256_DIGEST_LENGTH];
    unsigned char password[SHA256_DIGEST_LENGTH];

} masterAccount;

bool masterUserAccountExist()
{
    if (access(UserFile, F_OK) == 0)
    {
        return true;
    }

    // if no UserFile exist then check if credential file exist , if yes delete it
    if (access("credentialFile.dat", F_OK) == 0)
    {
        remove("credentialFile.dat");
    }

    return false;
}

int createMasterUserAccount(const char *username, const char *password)
{
    int return_value = 0;
    FILE *outfile;
    masterAccount account;
    outfile = fopen(UserFile, "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit(1);
    }

    EVP_Digest(username, strlen(username), account.username, NULL, EVP_sha256(), NULL);

    EVP_Digest(password, strlen(password), account.username, NULL, EVP_sha256(), NULL);

    fwrite(&account, sizeof(masterAccount), 1, outfile);
    if (fwrite != 0)
    {
        printf("Account created Succefully !\n");
    }
    else
    {
        printf("error writing file !\n");
        return_value = 1;
    }

    fclose(outfile);
    return return_value;
}