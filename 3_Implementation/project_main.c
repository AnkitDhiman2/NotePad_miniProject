

/*************************** HEADER FILES ***************************/
#include "masterAccountFunctions.h"
#include "common.h"
#include "credentialFunctions.h"
#include "passwordUsernameFormatChecker.h"
#include <stdlib.h>
/****************************** MACROS ******************************/
#ifdef _WIN32
#define CLEAR "clr"
#else
#define CLEAR "clear"
#endif

//#define TEST

#define BUFFER_SIZE (100) /*Common Buffer size for input*/

#ifndef TEST
/*********************** MAIN FUNCTION DEFINITIONS ***********************/
int main()
{
    printf("%s\n", "*********************************************** TextPad Password Maneger ***********************************************");
    while (true)
    {
        if (masterUserAccountExist())
        {
            while (true)
            {
                char username[BUFFER_SIZE]; // for user input
                char password[BUFFER_SIZE]; // for user input
                char input;

                printf("%s\n", "Enter Master Username");
                fflush(stdin);
                fgets(username, BUFFER_SIZE, stdin);
                fflush(stdin);

                printf("%s\n", "Enter Master password");
                fflush(stdin);
                fgets(password, BUFFER_SIZE, stdin);

                if (verifyMasterUserAccount(username, password))
                {
                    break;
                }
                system(CLEAR);
                printf("%s\n", "Master Username or Master  Password is incorrect.");
                printf("%s\n", ">Enter 1 to try again\n>Enter 0 to exit");

                fflush(stdin);
                scanf(" %c", &input);
                switch (input)
                {
                case '0':
                    printf("%s\n", "Exiting the program");
                    return 0;
                    break;
                default:
                    continue;
                    break;
                }
            }
            while (true)
            {
                /* code */

                printf("%s\n", "Enter the index for operation to perform");
                printf("%s\n", "Enter 1 to change Master Username");
                printf("%s\n", "Enter 2 to change Master Password");
                printf("%s\n", "Enter 3 to add New Credential");
                printf("%s\n", "Enter 4 to Search a Credential");
                printf("%s\n", "Enter 5 to Show All Credentials");
                printf("%s\n", "Enter 6 to EXIT");
                char input;
                fflush(stdin);
                scanf(" %c", &input);
                switch (input)
                {
                case '1':
                {
                    while (true)
                    {
                        system(CLEAR);
                        char new_username[BUFFER_SIZE];
                        char inside_input;
                        printf("%s\n", "Enter New Master Username");
                        fflush(stdin);
                        fgets(new_username, BUFFER_SIZE, stdin);

                        if (usernameFormatCheck(new_username))
                        {
                            modifyMasterUsername(new_username);
                            printf("%s\n", "Username Changed Successfully");
                            break;
                        }

                        printf("%s\n", ">Enter 1 to try again\n>Enter 0 to exit");

                        fflush(stdin);
                        scanf(" %c", &input);
                        switch (inside_input)
                        {
                        case '0':
                            printf("%s\n", "Exiting the program");
                            return 0;
                            break;
                        default:
                            continue;
                            break;
                        }
                    }
                    break;
                }

                case '2':
                {
                    while (true)
                    {
                        system(CLEAR);
                        char new_password[BUFFER_SIZE];
                        char inside_input;
                        printf("%s\n", "Enter New Master Password");
                        fflush(stdin);
                        fgets(new_password, BUFFER_SIZE, stdin);

                        if (passwordFormatCheck(new_password))
                        {
                            modifyMasterPassword(new_password);
                            printf("%s\n", " Password Changed Successfully");
                            break;
                        }

                        printf("%s\n", ">Enter 1 to try again\n>Enter 0 to exit");

                        fflush(stdin);
                        scanf(" %c", &inside_input);
                        switch (inside_input)
                        {
                        case '0':
                            printf("%s\n", "Exiting the program");
                            return 0;
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                }

                case '3':
                {
                    char new_organisation[BUFFER_SIZE];
                    char new_username[BUFFER_SIZE];
                    char new_password[BUFFER_SIZE];

                    printf("%s\n", "Enter Organisation Name");

                    fflush(stdin);
                    fgets(new_organisation, BUFFER_SIZE, stdin);
                    fflush(stdin);
                    fgets(new_organisation, BUFFER_SIZE, stdin);

                    printf("%s\n", "Enter Username");
                    fflush(stdin);
                    fgets(new_username, BUFFER_SIZE, stdin);

                    printf("%s\n", "Enter Password");
                    fflush(stdin);
                    fgets(new_password, BUFFER_SIZE, stdin);

                    addNewCredential(new_organisation, new_username, new_password);

                    break;
                }
                case '4':
                {
                    char organisation[BUFFER_SIZE];
                    char username[BUFFER_SIZE];
                    credential temp_credential;

                    printf("%s\n", "Enter Organisation Name to search");

                    fflush(stdin);
                    fgets(organisation, BUFFER_SIZE, stdin);
                    fflush(stdin);
                    fgets(organisation, BUFFER_SIZE, stdin);

                    printf("%s\n", "Enter Username to search");
                    fflush(stdin);
                    fgets(username, BUFFER_SIZE, stdin);

                    if (searchCredential(organisation, username, &temp_credential) == FAILURE)
                    {
                        printf("%s\n", "No Such Credential Found");
                        break;
                    }

                    while (true)
                    {
                        char inside_input;
                        printf("%s\n", "********************************************");
                        printf("Organisation -> %s\n", temp_credential.organisationName);
                        printf("Username -> %s\n", temp_credential.username);
                        printf("PASSWORD -> %s\n", temp_credential.password);
                        printf("%s\n", "********************************************");

                        printf("%s\n", "Press 1 to change the Organisation Name");
                        printf("%s\n", "Press 2 to change the Userame");
                        printf("%s\n", "Press 3 to change the Password");
                        printf("%s\n", "Press 0 to exit");

                        fflush(stdin);
                        scanf(" %c", &inside_input);
                        switch (inside_input)
                        {
                        case '0':
                            printf("%s\n", "Exiting the program");
                            return 0;
                            break;
                        case '1':
                        {
                            char new_organisation[BUFFER_SIZE];
                            printf("%s\n", "Enter new organisaion name");
                            fflush(stdin);
                            fgets(new_organisation, BUFFER_SIZE, stdin);
                            fgets(new_organisation, BUFFER_SIZE, stdin);

                            modifyCredentialOrganisation(temp_credential.organisationName, temp_credential.username, new_organisation);
                            break;
                        }

                        case '2':
                        {
                            char new_username[BUFFER_SIZE];
                            printf("%s\n", "Enter new username");
                            fflush(stdin);
                            fgets(new_username, BUFFER_SIZE, stdin);

                            modifyCredentialUsername(temp_credential.organisationName, temp_credential.username, new_username);
                            break;
                        }

                        case '3':
                        {
                            char new_password[BUFFER_SIZE];
                            printf("%s\n", "Enter new organisaion name");
                            fflush(stdin);
                            fgets(new_password, BUFFER_SIZE, stdin);
                            modifyCredentialPassword(temp_credential.organisationName, temp_credential.username, new_password);
                            break;
                        }

                        default:
                            printf("%s\n", "Invalid Option Please try again");
                            break;
                        }
                    }

                    break;
                }
                case '5':
                    system(CLEAR);
                    showAllCredentials();

                    break;
                case '6':
                    return 0;
                    break;

                default:
                    system(CLEAR);
                    printf("%s\n\n", "Invalid input, Please try Again");
                    break;
                }
            }
        }
        else // Create new Master Account
        {
            char username[BUFFER_SIZE]; // for new username
            char password[BUFFER_SIZE]; // for new password
            printf("%s\n", "Master Acount Does Not exist");

            while (true) // Until Username format is not correct
            {
                printf("%s\n", "Please Enter New Username");
                //fgets(username, BUFFER_SIZE, stdin);
                fflush(stdin);
                fgets(username, BUFFER_SIZE, stdin);

                usernameFormatCheck(username);
                //if format is correct exit the loop
                if (usernameFormatCheck(username))
                {
                    break;
                }
                printf("%s\n", "Please Try Again");
            }

            while (true) // Until Password format is not correct
            {

                printf("%s\n", "Please Enter New password");
                //fgets(password, BUFFER_SIZE, stdin);

                fflush(stdin);
                fgets(password, BUFFER_SIZE, stdin);

                system(CLEAR);
                passwordFormatCheck(password);
                //if format is correct exit the loop
                if (passwordFormatCheck(password))
                {
                    break;
                }
                printf("%s\n", "Please Try Again");
            }

            createMasterUserAccount(username, password);
        }
    }
}

#else
int main()
{
    credential temp_credential;
    addNewCredential("facebook", "Ankit", "ankit123");
    addNewCredential("twitter", "Ankit", "ankit123");
    addNewCredential("facebook1", "Ankit", "ankit123");
    addNewCredential("twitter2", "Ankit", "ankit123");
    addNewCredential("facebook3", "Ankit", "ankit123");
    addNewCredential("twitter4", "Ankit", "ankit123");
    addNewCredential("facebook5", "Ankit", "ankit123");
    addNewCredential("twitter6", "Ankit", "ankit123");
    addNewCredential("Random Organisation", "Ankit Kumar", "@nkit123");

    searchCredential("twitter", "Ankit", &temp_credential);
    printf("%s\n", temp_credential.organisationName);
    printf("%s\n", temp_credential.username);
    printf("%s\n", temp_credential.password);

    deleteAllCredentials();
}
#endif
