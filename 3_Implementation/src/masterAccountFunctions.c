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
    if (access(CredentialFile, F_OK) == 0)
    {
        remove(CredentialFile);
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

    EVP_Digest(password, strlen(password), account.password, NULL, EVP_sha256(), NULL);

    fwrite(&account, sizeof(masterAccount), 1, outfile);
    if (fwrite != 0)
    {
        ///printf("Account created Succefully !\n");
        return_value = SUCCESS;
    }
    else
    {
        printf("error writing masterUser file !\n");
        return_value = FAILURE;
    }

    fclose(outfile);
    return return_value;
}

status deleteMasterUserAccount()
{
    if (masterUserAccountExist())
    {
        remove(UserFile);
        return SUCCESS;
    }
    return FAILURE;
}

bool verifyMasterUserAccount(const char *username, const char *password)
{
    masterAccount userInput, masterUser;
    FILE *infile = fopen(UserFile, "r");

    EVP_Digest(username, strlen(username), userInput.username, NULL, EVP_sha256(), NULL);

    EVP_Digest(password, strlen(password), userInput.password, NULL, EVP_sha256(), NULL);

    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening masterUser.dat file\n");
        exit(1);
    }

    // Read saved sha
    fread(&masterUser, sizeof(masterAccount), 1, infile);

    if (memcmp(&userInput, &masterUser, sizeof(masterUser)) == 0)
    {
        return true;
    }

    fclose(infile);

    return false;
}

status modifyMasterPassword(const char *new_password)
{
    masterAccount account; // For master user password and username
    status return_value;
    FILE *infile, *outfile;

    //1. open current Userfile
    infile = fopen(UserFile, "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening masterUser.dat file\n");
        return FAILURE;
    }

    //2. Read the current userfile
    fread(&account, sizeof(masterAccount), 1, infile);
    fclose(infile);

    //3. change the password
    EVP_Digest(new_password, strlen(new_password), account.password, NULL, EVP_sha256(), NULL);

    // 4. open UserFile again in write mode to write new password
    outfile = fopen(UserFile, "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening masterUser.dat file\n");
        return FAILURE;
    }

    // write to UserFile
    fwrite(&account, sizeof(masterAccount), 1, outfile);
    if (fwrite != 0)
    {
        //printf("Account password changed Succefully !\n");
        return_value = SUCCESS;
    }
    else
    {
        printf("error writing masterUser file !\n");
        return_value = FAILURE;
    }

    fclose(outfile);

    return return_value;
}

status modifyMasterUsername(const char *new_username)
{
    masterAccount account; // For master user password and username
    status return_value;
    FILE *infile, *outfile;

    //1. open current Userfile
    infile = fopen(UserFile, "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening masterUser.dat file\n");
        return FAILURE;
    }

    //2. Read the current userfile
    fread(&account, sizeof(masterAccount), 1, infile);
    fclose(infile);

    //3. change the username
    EVP_Digest(new_username, strlen(new_username), account.username, NULL, EVP_sha256(), NULL);

    // 4. open UserFile again in write mode to write new password
    outfile = fopen(UserFile, "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening masterUser.dat file\n");
        return FAILURE;
    }

    // write to UserFile
    fwrite(&account, sizeof(masterAccount), 1, outfile);
    if (fwrite != 0)
    {
        //printf("Account password changed Succefully !\n");
        return_value = SUCCESS;
    }
    else
    {
        //printf("error writing masterUser file !\n");
        return_value = FAILURE;
    }

    fclose(outfile);

    return return_value;
}