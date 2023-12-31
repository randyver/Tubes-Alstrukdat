#ifndef Static_List_H
#define Static_List_H

#include "boolean.h"
#include "../database/database.h"

#define CAPACITY 1000
#define IDX_MIN 0
#define IDX_UNDEF -1
#define STATIC_LIST_MARK -99999

// With struct

typedef struct {
   int contents[CAPACITY];
} StaticList;

#define elmt_static_list(l, i) (l).contents[(i)]

void create_static_list(StaticList *l);
int static_list_length(StaticList l);

boolean is_static_list_empty(StaticList l);
boolean is_static_list_full(StaticList l);

void print_static_list(StaticList l);

void insert_first_static_list(StaticList *l, int val);
void insert_at_static_list(StaticList *l, int val, int idx);
void insert_last_static_list(StaticList *l, int val);

void delete_first_static_list(StaticList *l, int *val);
void delete_at_static_list(StaticList *l, int *val, int idx);
void delete_last_static_list(StaticList *l, int *val);


// No struct

typedef User StaticListUser[MAX_USER];
typedef Tweet StaticListTweet[MAX_TWEET];
typedef int StaticListReplyID[MAX_TWEET];
typedef ReplyTree StaticListReply[MAX_TWEET];

#endif