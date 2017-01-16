
/* Simulator System Entity Type Defines Header */

/* Domain Enumerations */

typedef enum {
    ADM_SIM_INDEX_DOMAIN_BANKING_APPLICATION
} adm_sim_index_domain_typ;

/* Entity Enumerations */

typedef enum {
    ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_CUSTOMER,
    ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_ACCOUNT,
    ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_BANK_POLICY
} adm_sim_index_entity_typ;

/* Event Enumerations */

typedef enum {
    ADM_SIM_INDEX_EVENT_BANKING_APPLICATION_CUSTOMER_LAST_ACCOUNT_CLOSED,
    ADM_SIM_INDEX_EVENT_BANKING_APPLICATION_CUSTOMER_NEW_CUSTOMER,
    ADM_SIM_INDEX_EVENT_BANKING_APPLICATION_ACCOUNT_MAKE_DEPOSIT,
    ADM_SIM_INDEX_EVENT_BANKING_APPLICATION_ACCOUNT_ACCOUNT_OK,
    ADM_SIM_INDEX_EVENT_BANKING_APPLICATION_ACCOUNT_WITHDRAWAL_SUBMITTED,
    ADM_SIM_INDEX_EVENT_BANKING_APPLICATION_ACCOUNT_CHECK_SUBMITTED,
    ADM_SIM_INDEX_EVENT_BANKING_APPLICATION_ACCOUNT_OVERDRAWN,
    ADM_SIM_INDEX_EVENT_BANKING_APPLICATION_ACCOUNT_CLOSE_ACCOUNT
} adm_sim_index_event_typ;

/* Entity Display Widths */

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
    adm_base_integer_typ atb_full_name;
    adm_base_integer_typ atb_address;
} adm_sim_width_customer_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
    adm_base_integer_typ atb_number;
    adm_base_integer_typ atb_balance;
} adm_sim_width_account_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_next_account_number;
    adm_base_integer_typ atb_bounced_check_fee;
} adm_sim_width_bank_policy_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */