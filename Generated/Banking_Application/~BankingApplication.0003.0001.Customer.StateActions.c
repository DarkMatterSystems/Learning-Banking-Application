
#include "~BankingApplication.0000.0000.Header.h"


/* Customer State Actions */

void adm_state_action_customer_accepting_new_customer(
    adm_ent_customer_typ * ent_customer,
    adm_dst_customer_accept_typ * dst_accept)
{
    /* Entity Objects */
    adm_ent_account_typ * ent_account_0000000001;
    adm_ent_bank_policy_typ * ent_bank_policy_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_customer_accepting_new_customer");
    #endif

    /* Assignment - Set */

    if (strlen(dst_accept->full_name) > ADM_TYPE_SIZE_NAME) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            1, 58, 45,
            "Customer",
            ent_customer->identity,
            "Full_name",
            dst_accept->full_name);
    }

    strcpy_s(
        ent_customer->atb_full_name, 
        ADM_TYPE_SIZE_NAME, 
        dst_accept->full_name);

    /* Assignment - Set */

    if (strlen(dst_accept->address) > ADM_TYPE_SIZE_LOCATION) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            1, 59, 45,
            "Customer",
            ent_customer->identity,
            "Address",
            dst_accept->address);
    }

    strcpy_s(
        ent_customer->atb_address, 
        ADM_TYPE_SIZE_LOCATION, 
        dst_accept->address);

    /* Template */

    adm_write_newline();
    adm_write_str("    Customer Registered");
    adm_write_newline();
    adm_write_str("        Full Name: ");
    adm_write_str(ent_customer->atb_full_name);
    adm_write_newline();
    adm_write_str("        Address:   ");
    adm_write_str(ent_customer->atb_address);
    adm_write_newline();

    /* Create */

    ent_account_0000000001 = adm_make_object_account(
        ADM_STATUS_ACCOUNT_CREATING_ACCOUNT);

    /* Relate */

    adm_link_relation_account_owned_by_customer(
        ent_account_0000000001,
        ent_customer,
        1, 67, 45);

    /* Relate */

    adm_link_relation_customer_owns_account(
        ent_customer,
        ent_account_0000000001,
        1, 68, 45);

    /* Assignment - Set */

    if (
        0.0 < ADM_TYPE_MINIMUM_MONEY ||
        0.0 > ADM_TYPE_MAXIMUM_MONEY) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            1, 71, 49,
            "Account",
            ent_account_0000000001->identity,
            "Balance",
            "0.0");
    }

    ent_account_0000000001->atb_balance = 0.0;

    /* EntitySelection - Selection */

    ent_bank_policy_0000000002 = adm_entity_system.ent_bank_policy.live_list_head;

    while (ent_bank_policy_0000000002 != NULL) {

        /* Relate */

        adm_link_relation_customer_governed_by_bank_policy(
            ent_customer,
            ent_bank_policy_0000000002,
            1, 75, 53);

        /* Assignment - Set */

        if (
            ent_bank_policy_0000000002->atb_next_account_number < ADM_TYPE_MINIMUM_ACCOUNT_NUMBER ||
            ent_bank_policy_0000000002->atb_next_account_number > ADM_TYPE_MAXIMUM_ACCOUNT_NUMBER) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                1, 78, 57,
                "Account",
                ent_account_0000000001->identity,
                "Number",
                adm_sim_lib_itoa(ent_bank_policy_0000000002->atb_next_account_number));
        }

        ent_account_0000000001->atb_number = +ent_bank_policy_0000000002->atb_next_account_number;

        /* Assignment - Evaluation */

        ent_bank_policy_0000000002->atb_next_account_number =
            +(
                +(
                    +ent_bank_policy_0000000002->atb_next_account_number
                    +
                    1
                )
            );

        if (
            ent_bank_policy_0000000002->atb_next_account_number < ADM_TYPE_MINIMUM_ACCOUNT_NUMBER ||
            ent_bank_policy_0000000002->atb_next_account_number > ADM_TYPE_MAXIMUM_ACCOUNT_NUMBER) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                1, 79, 64,
                "Bank_Policy",
                ent_bank_policy_0000000002->identity,
                "Next_account_number",
                adm_sim_lib_itoa(ent_bank_policy_0000000002->atb_next_account_number));
        }

        /* GenerateEvent */

        adm_send_event_account_make_deposit(
            ent_customer,
            ent_account_0000000001,
            dst_accept->amount,
            1, 84, 67);

        ent_bank_policy_0000000002 = ent_bank_policy_0000000002->next;
    }

    /* Template */

    adm_write_newline();
    adm_write_str("    Account Opened");
    adm_write_newline();
    adm_write_str("        Account Number: ");
    adm_write_int(ent_account_0000000001->atb_number);
    adm_write_newline();
    adm_write_str("        New Balance:    $");
    adm_write_fxd(ent_account_0000000001->atb_balance);
    adm_write_newline();

    adm_bind_object_account(
        ent_account_0000000001,
        1, 65, 50);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_customer_accepting_new_customer");
    #endif
}

void adm_state_action_customer_customer_vanishes(
    adm_ent_customer_typ * ent_customer)
{
    /* Entity Objects */
    adm_ent_account_typ * ent_account_0000000001;
    adm_ent_bank_policy_typ * ent_bank_policy_0000000002;

    /* Relationship Relations */
    adm_rel_customer_owns_account_typ * rel_customer_owns_account_0000000001;
    adm_rel_customer_owns_account_typ * nxt_customer_owns_account_0000000001;
    adm_rel_customer_governed_by_bank_policy_typ * rel_customer_governed_by_bank_policy_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_customer_customer_vanishes");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_customer(
        ent_customer,
        1, 101, 45);

    rel_customer_owns_account_0000000001 = ent_customer->rel_owns_account_head;

    while (rel_customer_owns_account_0000000001 != NULL) {

        nxt_customer_owns_account_0000000001 = rel_customer_owns_account_0000000001->next;

        ent_account_0000000001 = rel_customer_owns_account_0000000001->ent_account;

        /* Unrelate */

        adm_kill_relation_customer_owns_account(
            ent_customer,
            rel_customer_owns_account_0000000001,
            1, 104, 49);

        rel_customer_owns_account_0000000001 = nxt_customer_owns_account_0000000001;
    }

    /* Traverse - TraverseSelection */

    adm_object_existent_customer(
        ent_customer,
        1, 107, 45);

    rel_customer_governed_by_bank_policy_0000000002 = ent_customer->rel_governed_by_bank_policy_head;

    ent_bank_policy_0000000002 = rel_customer_governed_by_bank_policy_0000000002->ent_bank_policy;

    /* Unrelate */

    adm_kill_relation_customer_governed_by_bank_policy(
        ent_customer,
        rel_customer_governed_by_bank_policy_0000000002,
        1, 110, 49);

    /* Template */

    adm_write_newline();
    adm_write_str("    Customer Leaves");
    adm_write_newline();
    adm_write_str("        Full Name: ");
    adm_write_str(ent_customer->atb_full_name);
    adm_write_newline();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_customer_customer_vanishes");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */