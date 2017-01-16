
#include "~BankingApplication.0000.0000.Header.h"


/* Simulator System Configuration */

/* Domain Map */

adm_sim_domain_typ adm_sim_domain[] = {
    {"Banking_Application"},
    {SNULL}
};

/* Entity Map */

adm_sim_entity_typ adm_sim_entity[] = {
    {ADM_SIM_INDEX_DOMAIN_BANKING_APPLICATION, "Customer", TRUE, adm_sim_display_entity_customer},
    {ADM_SIM_INDEX_DOMAIN_BANKING_APPLICATION, "Account", TRUE, adm_sim_display_entity_account},
    {ADM_SIM_INDEX_DOMAIN_BANKING_APPLICATION, "Bank_Policy", FALSE, adm_sim_display_entity_bank_policy},
    {null, SNULL, null, NULL}
};

/* Event Map */

adm_sim_event_typ adm_sim_event[] = {
    {
        ADM_SIM_INDEX_DOMAIN_BANKING_APPLICATION,
        ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_CUSTOMER,
        "Last_account_closed",
        FALSE,
        adm_sim_acquire_identity_event_customer_last_account_closed
    },
    {
        ADM_SIM_INDEX_DOMAIN_BANKING_APPLICATION,
        ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_CUSTOMER,
        "New_customer",
        TRUE,
        adm_sim_acquire_identity_event_customer_new_customer
    },
    {
        ADM_SIM_INDEX_DOMAIN_BANKING_APPLICATION,
        ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_ACCOUNT,
        "Make_deposit",
        FALSE,
        adm_sim_acquire_identity_event_account_make_deposit
    },
    {
        ADM_SIM_INDEX_DOMAIN_BANKING_APPLICATION,
        ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_ACCOUNT,
        "Account_ok",
        FALSE,
        adm_sim_acquire_identity_event_account_account_ok
    },
    {
        ADM_SIM_INDEX_DOMAIN_BANKING_APPLICATION,
        ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_ACCOUNT,
        "Withdrawal_submitted",
        FALSE,
        adm_sim_acquire_identity_event_account_withdrawal_submitted
    },
    {
        ADM_SIM_INDEX_DOMAIN_BANKING_APPLICATION,
        ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_ACCOUNT,
        "Check_submitted",
        FALSE,
        adm_sim_acquire_identity_event_account_check_submitted
    },
    {
        ADM_SIM_INDEX_DOMAIN_BANKING_APPLICATION,
        ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_ACCOUNT,
        "Overdrawn",
        FALSE,
        adm_sim_acquire_identity_event_account_overdrawn
    },
    {
        ADM_SIM_INDEX_DOMAIN_BANKING_APPLICATION,
        ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_ACCOUNT,
        "Close_account",
        FALSE,
        adm_sim_acquire_identity_event_account_close_account
    },
    {
        null,
        null,
        SNULL,
        null,
        NULL
    }
};

/* Identifier Map */

adm_sim_identifier_typ adm_sim_identifier[] = {
    {
        null,
        null,
        null,
        SNULL,
        NULL
    }
};


/* Find Event Name From Event Index */

adm_base_string_typ * adm_sim_find_event_name(
    adm_base_integer_typ entity_index,
    adm_base_integer_typ entity_event_index)
{
    adm_base_integer_typ index;

    adm_base_boolean_typ event_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_find_event_name");
    #endif

    index = 0;

    event_not_found = TRUE;

    while (event_not_found) {

        if (adm_sim_event[index].entity == entity_index) {

            index += entity_event_index;

            event_not_found = FALSE;

        } else {

            ++index;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_find_event_name");
    #endif

    return (adm_sim_event[index].name);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */