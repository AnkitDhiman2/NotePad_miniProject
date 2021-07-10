/** 
* @author Ankit Kumar(Ankitdkumar43@gmail.com)
* @file credetnialFunctions.c
* @brief Functions related to User Credential management
*
*/

/*************************** HEADER FILES ***************************/
#include "credentialFunctions.h"

/*********************** FUNCTION DEFINITIONS ***********************/

status addNewCredential(const char *organisationName, const char *username, const char *password)
{
    FILE *outfile; // to open file for writing
    credential new_credential, credential;

    //check for NULL pointer
    if (organisationName == NULL ||
        username == NULL ||
        password == NULL ||
        strlen(organisationName) == 0 ||
        strlen(username) == 0 ||
        strlen(password) == 0)
        return NULL_PTR;

    if (credentialExist(organisationName, username))
    {
        printf("%s\n", "Organisation & Username combination already exist");
        return FAILURE;
    }

    strcpy(new_credential.organisationName, organisationName);
    strcpy(new_credential.username, username);
    strcpy(new_credential.password, password);

    // Check if credential file exist or not if not create it
    if (access(CREDENTIAL_FILE, F_OK) != 0)
    {
        outfile = fopen(CREDENTIAL_FILE, "w");

        if (outfile == NULL)
            return FAILURE;

        fclose(outfile);
    }

    // open CREDENTIAL_FILE to apend the credential
    outfile = fopen(CREDENTIAL_FILE, "a");
    if (outfile == NULL)
        return FAILURE;
    fwrite(&new_credential, sizeof(credential), 1, outfile);
    fclose(outfile);
    return SUCCESS;
}

status showAllCredentials()
{
    FILE *infile;
    credential credential;

    //*********open the credential file in read mode***********
    infile = fopen(CREDENTIAL_FILE, "r");
    if (infile == NULL)
    {
        printf("%s\n", "Show All Credential - Error opening file");
        return FAILURE;
    }

    //*********Checking if file is empty***************
    fseek(infile, 0, SEEK_END);
    int size = ftell(infile);
    if (0 == size)
    {
        printf("file is empty\n");
        fclose(infile);
        return FAILURE;
    }

    //**************Reading the file until EOF and printing credentials*******************
    int i = 1;
    printf("%s\n", "********************************************************************************************");
    while (fread(&credential, sizeof(credential), 1, infile))
    {

        printf("%d) Organisation = %s, Username = %s, Password = %s\n", i,
               credential.organisationName, credential.username, credential.password);

        printf("%s\n", "********************************************************************************************");
        i++;
    }
    fclose(infile);
    return SUCCESS;
}

status deleteAllCredentials()
{
    // checking of file exist
    if (access(CREDENTIAL_FILE, F_OK) == 0)
    {
        remove(CREDENTIAL_FILE);
        return SUCCESS;
    }
    return FAILURE; // file does not exist
}

status searchCredential(const char *organisationName, const char *username)
{
    credential credential;
    FILE *infile;

    //********checking if there is any NULL or size 0 string in the arguments********
    if (organisationName == NULL ||
        username == NULL ||
        strlen(organisationName) == 0 ||
        strlen(username) == 0)
        return NULL_PTR;

    //*********open the credential file in read mode***********
    infile = fopen(CREDENTIAL_FILE, "r");
    if (infile == NULL)
    {
        printf("%s\n", "Search Credential - Error opening file");
        return FAILURE;
    }

    //**************Reading the file until EOF credential is found*******************
    while (fread(&credential, sizeof(credential), 1, infile))
    {
        if (strcmp(credential.organisationName, organisationName) == 0 &&
            strcmp(credential.username, username) == 0)
        {
            printf(" Organisation = %s, Username = %s, Password = %s\n",
                   credential.organisationName, credential.username, credential.password);

            printf("%s\n", "********************************************************************************************");
            fclose(infile);
            return SUCCESS;
        }
    }
    fclose(infile);
    return FAILURE;
}

bool credentialExist(const char *organisationName, const char *username)
{

    credential credential;
    FILE *infile;

    //********checking if there is any NULL or size 0 string in the arguments********
    if (organisationName == NULL ||
        username == NULL ||
        strlen(organisationName) == 0 ||
        strlen(username) == 0)
    {
        printf("%s\n", "credential exist- Null pointer");
        return false;
    }

    //*********open the credential file in read mode***********
    infile = fopen(CREDENTIAL_FILE, "r");
    if (infile == NULL)
    {
        printf("%s\n", "Credential Search - Error opening file");
        return false;
    }

    // **************Reading the file until EOF or credential is found*******************
    while (fread(&credential, sizeof(credential), 1, infile))
    {
        if (strcmp(credential.organisationName, organisationName) == 0 &&
            strcmp(credential.username, username) == 0)
        {
            fclose(infile);
            return true;
        }
    }
    fclose(infile);
    return false; // NO such credential found
}