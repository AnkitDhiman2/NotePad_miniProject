/** 
* @author Ankit Kumar(Ankitdkumar43@gmail.com)
* @file credetnialFunctions.h
* @brief Define the API for User Credential management
*
*/

#ifndef __CREDENTIAL_FUNCTIONS_H__
#define __CREDENTIAL_FUNCTIONS_H__

/*************************** HEADER FILES ***************************/
#include "common.h"

/****************************** MACROS ******************************/
#define CredentialFile "credentialFile.dat"

/**************************** DATA TYPES ****************************/
typedef struct
{
    char organisationName[40];
    char username[15];
    char password[16];

} credential;

/*********************** FUNCTION DECLARATIONS **********************/

/**
* @brief To Add new user credentials
* @param[in] string organisation_name
* @param[in] string username
* @param[in] string password
* @return  SUCCESS if Master Username changed successfully otherwise FAILURE
*/
status addNewCredential(const char *organisationName, const char *username, const char *password);

/**
* @brief To Add new user credentials
* @param[in] string organisation_name
* @param[in] string username
* @return  SUCCESS if credentials are successfully deleted otherwise FAILURE
*/
status deleteCredential(const char organisationName, const char *username);

/**
* @brief To change Organisation name in  credential
* @param[in] credential pointer to credential data
* @param[in] string new_Organisation_name
* @return  SUCCESS if credentials arr found otherwise FAILURE
*/
status modifyCredentialOrganisation(credential *cred, char *new_Organisation_name);

/**
* @brief To change Username in credentials
* @param[in] credential pointer to credential data
* @param[in] string new_username
* @return  SUCCESS if credentials arr found otherwise FAILURE
*/
status modifyCredentialUsername(credential *cred, char *new_username);

/**
* @brief To password credentials
* @param[in] credential pointer to credential data
* @param[in] string new_password
* @return  SUCCESS if credentials arr found otherwise FAILURE
*/
status modifyCredentialPassword(credential *cred, char *new_password);

/**
* @brief To search credentials
* @param[in] string organisation_name
* @param[in] string username
* @return  SUCCESS if credentials arr found otherwise FAILURE
*/
credential *searchCredential(const char organisationName, const char *username);

/**
* @brief To print all saved credentials 
* @return  Print all the credentials
*/
void showAllCredentials();

#endif