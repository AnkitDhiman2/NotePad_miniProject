

/*************************** HEADER FILES ***************************/
#include "masterAccountFunctions.h"
#include "common.h"
#include "credentialFunctions.h"
#include "passwordUsernameFormatChecker.h"

/****************************** MACROS ******************************/
#ifdef _WIN32
#define CLEAR "clr"
#else
#define CLEAR "clear"
#endif

#define TEST

#define BUFFER_SIZE 100

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
                char *username; // for user input
                char *password; // for user input

                printf("%s\n", "Enter Master Username");
                fgets(username, BUFFER_SIZE, stdin);
                printf("%s\n", "Enter Master Username");
                fgets(password, BUFFER_SIZE, stdin);

                if (verifyMasterUserAccount(username, password))
                {
                    break;
                }
                system(CLEAR);
                printf("%s\n", "Master Username or Master  Password is incorrect");
            }
        }
        else // Create new Master Account
        {
            char *username; // for new username
            char *password; // for new password
            printf("%s\n", "Master Acount Does Not exist");

            while (true) // Until Username format is not correct
            {

                printf("%s\n", "Please Enter New Username");
                fgets(username, BUFFER_SIZE, stdin);
                username[strcspn(username, "\n")] = 0;

                system(CLEAR);
                usernameFormatCheck(username);
                //if format is correct exit the loop
                if (usernameFormatCheck(username))
                {
                    break;
                }
                printf("%s\n", "Please Try Again");
            }

            system(CLEAR);

            while (true) // Until Password format is not correct
            {
                printf("%s\n", "Please Enter New password");
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
    addNewCredential("facebook", "Ankit", "ankit123");
    addNewCredential("twitter", "Ankit", "ankit123");

    //showAllCredentials();
    searchCredential("facebook", "Ankit");

    if (credentialExist("twitter", "Ankit"))
        printf("%s\n", "Exist");
    else
        printf("%s\n", "not Exist");

    deleteAllCredentials();
}

#endif
