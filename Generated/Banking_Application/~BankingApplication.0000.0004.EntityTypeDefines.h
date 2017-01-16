
/* Entity Type Defines Header */

/* Entity Status Type Defines */

typedef enum {
    ADM_STATUS_CUSTOMER_ACCEPTING_NEW_CUSTOMER,
    ADM_STATUS_CUSTOMER_CUSTOMER_VANISHES
} adm_sta_customer_typ;

typedef enum {
    ADM_STATUS_ACCOUNT_CREATING_ACCOUNT,
    ADM_STATUS_ACCOUNT_TAKING_DEPOSIT,
    ADM_STATUS_ACCOUNT_IN_GOOD_STANDING,
    ADM_STATUS_ACCOUNT_CONSIDERING_WITHDRAWAL,
    ADM_STATUS_ACCOUNT_CONSIDERING_CHECK,
    ADM_STATUS_ACCOUNT_OVERDRAWN,
    ADM_STATUS_ACCOUNT_CLOSED
} adm_sta_account_typ;


/* Entity Event Type Defines */

typedef enum {
    ADM_EVENT_CUSTOMER_LAST_ACCOUNT_CLOSED,
    ADM_EVENT_CUSTOMER_NEW_CUSTOMER
} adm_evt_customer_typ;

typedef enum {
    ADM_EVENT_ACCOUNT_MAKE_DEPOSIT,
    ADM_EVENT_ACCOUNT_ACCOUNT_OK,
    ADM_EVENT_ACCOUNT_WITHDRAWAL_SUBMITTED,
    ADM_EVENT_ACCOUNT_CHECK_SUBMITTED,
    ADM_EVENT_ACCOUNT_OVERDRAWN,
    ADM_EVENT_ACCOUNT_CLOSE_ACCOUNT
} adm_evt_account_typ;


/* Entity Type Defines */

/* Customer */

typedef struct adm_ent_customer {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_customer_typ status;
    adm_str_name_typ * atb_full_name;
    adm_str_location_typ * atb_address;
    struct adm_rel_customer_owns_account * rel_owns_account_head;
    struct adm_rel_customer_owns_account * rel_owns_account_tail;
    struct adm_rel_customer_governed_by_bank_policy * rel_governed_by_bank_policy_head;
    struct adm_rel_customer_governed_by_bank_policy * rel_governed_by_bank_policy_tail;
    struct adm_ent_customer * back;
    struct adm_ent_customer * next;
} adm_ent_customer_typ;

/* Account */

typedef struct adm_ent_account {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_account_typ status;
    adm_int_account_number_typ atb_number;
    adm_fxd_money_typ atb_balance;
    struct adm_rel_account_owned_by_customer * rel_owned_by_customer_head;
    struct adm_rel_account_owned_by_customer * rel_owned_by_customer_tail;
    struct adm_ent_account * back;
    struct adm_ent_account * next;
} adm_ent_account_typ;

/* Bank Policy */

typedef struct adm_ent_bank_policy {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_int_account_number_typ atb_next_account_number;
    adm_fxd_money_typ atb_bounced_check_fee;
    struct adm_ent_bank_policy * back;
    struct adm_ent_bank_policy * next;
} adm_ent_bank_policy_typ;


/* Relationship Type Defines */

typedef struct adm_rel_customer_owns_account {
    adm_ent_account_typ * ent_account;
    struct adm_rel_customer_owns_account * back;
    struct adm_rel_customer_owns_account * next;
} adm_rel_customer_owns_account_typ;

typedef struct adm_rel_customer_governed_by_bank_policy {
    adm_ent_bank_policy_typ * ent_bank_policy;
    struct adm_rel_customer_governed_by_bank_policy * back;
    struct adm_rel_customer_governed_by_bank_policy * next;
} adm_rel_customer_governed_by_bank_policy_typ;

typedef struct adm_rel_account_owned_by_customer {
    adm_ent_customer_typ * ent_customer;
    struct adm_rel_account_owned_by_customer * back;
    struct adm_rel_account_owned_by_customer * next;
} adm_rel_account_owned_by_customer_typ;


/* Entity Dataset Type Defines */

typedef struct {
    adm_str_name_typ * full_name;
    adm_str_location_typ * address;
    adm_fxd_money_typ amount;
} adm_dst_customer_accept_typ;

typedef struct {
    adm_fxd_money_typ amount;
} adm_dst_account_transaction_typ;


/* Error Location Type Define */

typedef struct {
    adm_base_integer_typ file;
    adm_base_integer_typ line;
    adm_base_integer_typ rank;
} adm_error_location_typ;


/* Entity Event Pool Target Type Defines */

typedef struct adm_pool_target_customer {
    adm_evt_customer_typ evente;
    adm_ent_customer_typ * ent_customer;
    adm_error_location_typ error_location;
    struct adm_pool_target_customer * next;
    union {
        adm_dst_customer_accept_typ * accept;
    } dataset;
} adm_pool_target_customer_typ;

typedef struct adm_pool_target_account {
    adm_evt_account_typ evente;
    adm_ent_account_typ * ent_account;
    adm_error_location_typ error_location;
    struct adm_pool_target_account * next;
    union {
        adm_dst_account_transaction_typ * transaction;
    } dataset;
} adm_pool_target_account_typ;


/* Entity System - Entity Type Defines */

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_customer_typ * live_list_head;
    adm_ent_customer_typ * live_list_tail;
    adm_ent_customer_typ * dead_list_head;
    adm_ent_customer_typ * dead_list_tail;
    adm_pool_target_customer_typ * home_pool_head;
    adm_pool_target_customer_typ * home_pool_tail;
    adm_pool_target_customer_typ * away_pool_head;
    adm_pool_target_customer_typ * away_pool_tail;
} adm_entity_system_customer_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_account_typ * live_list_head;
    adm_ent_account_typ * live_list_tail;
    adm_ent_account_typ * dead_list_head;
    adm_ent_account_typ * dead_list_tail;
    adm_pool_target_account_typ * home_pool_head;
    adm_pool_target_account_typ * home_pool_tail;
    adm_pool_target_account_typ * away_pool_head;
    adm_pool_target_account_typ * away_pool_tail;
} adm_entity_system_account_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_bank_policy_typ * live_list_head;
    adm_ent_bank_policy_typ * live_list_tail;
    adm_ent_bank_policy_typ * dead_list_head;
    adm_ent_bank_policy_typ * dead_list_tail;
} adm_entity_system_bank_policy_typ;


/* Entity System - System Type Define */

typedef struct {
    adm_entity_system_customer_typ ent_customer;
    adm_entity_system_account_typ ent_account;
    adm_entity_system_bank_policy_typ ent_bank_policy;
} adm_entity_system_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */