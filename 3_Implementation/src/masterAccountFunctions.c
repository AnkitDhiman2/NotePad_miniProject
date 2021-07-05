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

status createMasterUserAccount(const char *username, const char *password)
{
    status return_value;
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
        return_value = SUCCESS;
    }
    else
    {
        printf("error writing file !\n");
        return_value = FAILURE;
    }

    fclose(outfile);
    return return_value;
}

status deleteMasterUserAccount()
{
    if (masterUserAccountExist)
    {
        remove(UserFile);
        return SUCCESS;
    }
    return FAILURE;
}

bool verifyMasterUserAccount(const char *username, const char *password)
{
}