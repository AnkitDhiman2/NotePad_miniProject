#include "masterAccountFunctions.h"

typedef struct
{
    unsigned char username[SHA256_BLOCK_SIZE];
    unsigned char password[SHA256_BLOCK_SIZE];

} masterAccount;

bool masterUserAccountExist()
{

    //1. Check if UserFile exist then master account Exist
    if (access(UserFile, F_OK) == 0)
    {
        return true;
    }

    // 2. if no UserFile exist then check if credential file exist , if yes delete it
    if (access(CredentialFile, F_OK) == 0)
    {
        remove(CredentialFile);
    }

    // 3. Master account do not exist
    return false;
}

status createMasterUserAccount(const char *username, const char *password)
{
    status return_value;   //
    FILE *outfile;         // To write the UserFile.
    SHA256_CTX sha256;     // For hashing
    masterAccount account; // For username and password hash

    if (username == NULL || password == NULL || strlen(username) == 0 || strlen(password) == 0)
    {
        return NULL_PTR;
    }

    //1. Open UserFile to write master account data.
    outfile = fopen(UserFile, "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit(1);
    }

    // 2. Create hash of Username string and save it in account.username
    sha256_init(&sha256);
    sha256_update(&sha256, username, strlen(username));
    sha256_final(&sha256, account.username);

    //3. create hash of Password string and save it in account.password
    sha256_init(&sha256);
    sha256_update(&sha256, password, strlen(password));
    sha256_final(&sha256, account.password);

    // EVP_Digest(username, strlen(username), account.username, NULL, EVP_sha256(), NULL);

    // EVP_Digest(password, strlen(password), account.password, NULL, EVP_sha256(), NULL);

    // 4. Write struct masterAccount to UserFile
    fwrite(&account, sizeof(masterAccount), 1, outfile);
    if (fwrite != 0)
    {
        //printf("Account created Succefully !\n");
        return_value = SUCCESS;
    }
    else
    {
        printf("error writing masterUser file !\n");
        return_value = FAILURE;
    }

    // Close  FILE *outfile
    fclose(outfile);
    return return_value;
}

status deleteMasterUserAccount()
{
    //1. Check if master Account Exist if true delete it
    if (masterUserAccountExist())
    {
        remove(UserFile);
        return SUCCESS;
    }
    // There was no UserFile to delete
    return FAILURE;
}

bool verifyMasterUserAccount(const char *username, const char *password)
{
    masterAccount userInput, masterUser; // for user enterd credentials and credentials saved in UserFile
    FILE *infile;                        // to read UserFile
    SHA256_CTX sha256;                   // For Hashing

    if (username == NULL || password == NULL || strlen(username) == 0 || strlen(password) == 0)
    {
        return false;
    }

    //1. create hash of username entered by user
    sha256_init(&sha256);
    sha256_update(&sha256, username, strlen(username));
    sha256_final(&sha256, userInput.username);

    //2. create hash of password entered by user
    sha256_init(&sha256);
    sha256_update(&sha256, password, strlen(password));
    sha256_final(&sha256, userInput.password);

    // EVP_Digest(username, strlen(username), userInput.username, NULL, EVP_sha256(), NULL);

    // EVP_Digest(password, strlen(password), userInput.password, NULL, EVP_sha256(), NULL);

    //3. open UserFile
    infile = fopen(UserFile, "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening masterUser.dat file\n");
        exit(1);
    }

    //4. Read UserFile
    fread(&masterUser, sizeof(masterAccount), 1, infile);

    //5. Compare hashes of UserFile Credentials and Credentials entered by User
    if (memcmp(&userInput, &masterUser, sizeof(masterUser)) == 0)
    {
        // If Credential match
        return true;
    }

    // 6. close the infile
    fclose(infile);

    return false;
}

status modifyMasterPassword(const char *new_password)
{
    masterAccount account; // For master user password and username
    status return_value;
    FILE *infile, *outfile;
    SHA256_CTX sha256;

    if (new_password == NULL || strlen(new_password) == 0)
    {
        return NULL_PTR;
    }

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
    sha256_init(&sha256);
    sha256_update(&sha256, new_password, strlen(new_password));
    sha256_final(&sha256, account.password);
    // EVP_Digest(new_password, strlen(new_password), account.password, NULL, EVP_sha256(), NULL);

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
    SHA256_CTX sha256;

    if (new_username == NULL || strlen(new_username) == 0)
    {
        return NULL_PTR;
    }

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

    sha256_init(&sha256);
    sha256_update(&sha256, new_username, strlen(new_username));
    sha256_final(&sha256, account.username);

    // EVP_Digest(new_username, strlen(new_username), account.username, NULL, EVP_sha256(), NULL);

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