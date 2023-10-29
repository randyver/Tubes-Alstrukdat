#ifndef USER_H
#define USER_H

#include "boolean.h"
#include "../ADT/Matrix.h"
#include "../ADT/PriorityQueueFriendRequest.h"
#include "../ADT/DynamicList.h"
#include "../ADT/StackDraft.h"

typedef struct User {
    char *name;
    char *password;

    boolean is_public;
    char *bio;
    char *phone;
    char *weton;
    Matrix profile_picture;

    int total_friends;
    PriorityQueueFriendRequest friend_requests;

    DynamicList tweets;
    
    StackDraft drafts;
} User;

void set_user_name(User *s, char *name);

void set_user_password(User *s, char *password);

void set_user_bio(User *s, char *bio);

void set_user_phone(User *s, char *phone);

void set_user_weton(User *s, char *weton);

#endif