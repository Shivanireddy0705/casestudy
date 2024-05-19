#ifndef LOGIN_H
#define LOGIN_H
#include <stdbool.h>

void registerUser(const char *username, const char *password);
bool isUserRegistered(const char *username, const char *password);

#endif