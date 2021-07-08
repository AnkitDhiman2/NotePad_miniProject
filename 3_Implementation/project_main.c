

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

/*********************** MAIN FUNCTION DEFINITIONS ***********************/
int main()
{
    printf("%s\n", "*********************************************** TextPad Password Maneger ***********************************************");
    while (true)
    {
        if (masterUserAccountExist())
        {
        }
        else // Create new Master Account
        {
            char *username; // for new username
            char *password; // for new password
            printf("%s\n", "Master Acount Does Not exist");

            while (true) // Until Username format is not correct
            {

                printf("%s\n", "Please Enter New Username");
                fgets(username, 17, stdin);
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
                fgets(password, 17, stdin);

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