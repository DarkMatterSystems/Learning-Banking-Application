
#include "~BankingApplication.0000.0000.Header.h"


/* Simulator Customer Acquire Identity Event */

void adm_sim_acquire_identity_event_customer_last_account_closed(
    void)
{
    adm_ent_customer_typ * ent_customer;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_customer_last_account_closed");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_customer = adm_entity_system.ent_customer.live_list_head;

    while (
        entity_not_found &&
        ent_customer != NULL) {

        if (ent_customer->identity == identity) {

            adm_send_event_customer_last_account_closed(
                NULL,
                ent_customer,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_customer = ent_customer->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_customer_last_account_closed");
    #endif
}

void adm_sim_acquire_identity_event_customer_new_customer(
    void)
{
    adm_base_string_typ evd_nme_full_name [ADM_TYPE_SIZE_NAME+1];
    adm_base_string_typ evd_nme_address [ADM_TYPE_SIZE_LOCATION+1];
    adm_base_float_typ evd_num_amount;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_customer_new_customer");
    #endif

    /* Fetch Event Data */

    adm_sim_str_fetch(
        evd_nme_full_name,
        ADM_TYPE_SIZE_NAME+1);

    adm_sim_str_fetch(
        evd_nme_address,
        ADM_TYPE_SIZE_LOCATION+1);

    evd_num_amount = adm_sim_fxd_fetch();

    /* Check Event Data Type Ranges */

    if (
        evd_num_amount < ADM_TYPE_MINIMUM_MONEY ||
        evd_num_amount > ADM_TYPE_MAXIMUM_MONEY) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_FIXED,
            adm_sim_lib_fxtoa(evd_num_amount));
    }

    /* Generate Event */

    adm_send_event_customer_new_customer(
        evd_nme_full_name,
        evd_nme_address,
        (adm_base_fixed_typ)evd_num_amount,
        0, 0, 0);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_customer_new_customer");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */