
#include "~BankingApplication.0000.0000.Header.h"


/* Simulator Account Acquire Identity Event */

void adm_sim_acquire_identity_event_account_make_deposit(
    void)
{
    adm_ent_account_typ * ent_account;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;
    adm_base_float_typ evd_num_amount;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_account_make_deposit");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Fetch Event Data */

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

    entity_not_found = TRUE;

    ent_account = adm_entity_system.ent_account.live_list_head;

    while (
        entity_not_found &&
        ent_account != NULL) {

        if (ent_account->identity == identity) {

            adm_send_event_account_make_deposit(
                NULL,
                ent_account,
                (adm_base_fixed_typ)evd_num_amount,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_account = ent_account->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_account_make_deposit");
    #endif
}

void adm_sim_acquire_identity_event_account_account_ok(
    void)
{
    adm_ent_account_typ * ent_account;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_account_account_ok");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_account = adm_entity_system.ent_account.live_list_head;

    while (
        entity_not_found &&
        ent_account != NULL) {

        if (ent_account->identity == identity) {

            adm_send_event_account_account_ok(
                NULL,
                ent_account,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_account = ent_account->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_account_account_ok");
    #endif
}

void adm_sim_acquire_identity_event_account_withdrawal_submitted(
    void)
{
    adm_ent_account_typ * ent_account;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;
    adm_base_float_typ evd_num_amount;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_account_withdrawal_submitted");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Fetch Event Data */

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

    entity_not_found = TRUE;

    ent_account = adm_entity_system.ent_account.live_list_head;

    while (
        entity_not_found &&
        ent_account != NULL) {

        if (ent_account->identity == identity) {

            adm_send_event_account_withdrawal_submitted(
                NULL,
                ent_account,
                (adm_base_fixed_typ)evd_num_amount,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_account = ent_account->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_account_withdrawal_submitted");
    #endif
}

void adm_sim_acquire_identity_event_account_check_submitted(
    void)
{
    adm_ent_account_typ * ent_account;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;
    adm_base_float_typ evd_num_amount;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_account_check_submitted");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Fetch Event Data */

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

    entity_not_found = TRUE;

    ent_account = adm_entity_system.ent_account.live_list_head;

    while (
        entity_not_found &&
        ent_account != NULL) {

        if (ent_account->identity == identity) {

            adm_send_event_account_check_submitted(
                NULL,
                ent_account,
                (adm_base_fixed_typ)evd_num_amount,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_account = ent_account->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_account_check_submitted");
    #endif
}

void adm_sim_acquire_identity_event_account_overdrawn(
    void)
{
    adm_ent_account_typ * ent_account;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_account_overdrawn");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_account = adm_entity_system.ent_account.live_list_head;

    while (
        entity_not_found &&
        ent_account != NULL) {

        if (ent_account->identity == identity) {

            adm_send_event_account_overdrawn(
                NULL,
                ent_account,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_account = ent_account->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_account_overdrawn");
    #endif
}

void adm_sim_acquire_identity_event_account_close_account(
    void)
{
    adm_ent_account_typ * ent_account;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_account_close_account");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_account = adm_entity_system.ent_account.live_list_head;

    while (
        entity_not_found &&
        ent_account != NULL) {

        if (ent_account->identity == identity) {

            adm_send_event_account_close_account(
                NULL,
                ent_account,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_account = ent_account->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_account_close_account");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */