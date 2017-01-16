
#include "~BankingApplication.0000.0000.Header.h"


/* Account State Actions */

void adm_state_action_account_taking_deposit(
    adm_ent_account_typ * ent_account,
    adm_dst_account_transaction_typ * dst_transaction)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_account_taking_deposit");
    #endif

    /* Assignment - Evaluation */

    ent_account->atb_balance =
        +(
            +(
                +ent_account->atb_balance
                +
                +dst_transaction->amount
            )
        );

    if (
        ent_account->atb_balance < ADM_TYPE_MINIMUM_MONEY ||
        ent_account->atb_balance > ADM_TYPE_MAXIMUM_MONEY) {

        adm_error_report(
            ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
            1, 147, 52,
            "Account",
            ent_account->identity,
            "Balance",
            adm_sim_lib_fxtoa(ent_account->atb_balance));
    }

    /* Template */

    adm_write_newline();
    adm_write_str("    Deposit Taken");
    adm_write_newline();
    adm_write_str("        Amount:      $");
    adm_write_fxd(dst_transaction->amount);
    adm_write_newline();
    adm_write_str("        New Balance: $");
    adm_write_fxd(ent_account->atb_balance);
    adm_write_newline();

    /* CaseSelection */

    if (
        (
            (
                ent_account->atb_balance >= 0.0
            )
        )) {

        /* GenerateEvent */

        adm_send_event_account_account_ok(
            ent_account,
            ent_account,
            1, 164, 53);

    } else {

        /* GenerateEvent */

        adm_send_event_account_overdrawn(
            ent_account,
            ent_account,
            1, 167, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_account_taking_deposit");
    #endif
}

void adm_state_action_account_considering_withdrawal(
    adm_ent_account_typ * ent_account,
    adm_dst_account_transaction_typ * dst_transaction)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_account_considering_withdrawal");
    #endif

    /* CaseSelection */

    if (
        (
            (
                dst_transaction->amount <= ent_account->atb_balance
            )
        )) {

        /* Assignment - Evaluation */

        ent_account->atb_balance =
            +(
                +(
                    +ent_account->atb_balance
                    +
                    -dst_transaction->amount
                )
            );

        if (
            ent_account->atb_balance < ADM_TYPE_MINIMUM_MONEY ||
            ent_account->atb_balance > ADM_TYPE_MAXIMUM_MONEY) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                1, 198, 64,
                "Account",
                ent_account->identity,
                "Balance",
                adm_sim_lib_fxtoa(ent_account->atb_balance));
        }

        /* Template */

        adm_write_newline();
        adm_write_str("    Withdrawal Accepted");
        adm_write_newline();
        adm_write_str("        Amount:      $");
        adm_write_fxd(dst_transaction->amount);
        adm_write_newline();
        adm_write_str("        New Balance: $");
        adm_write_fxd(ent_account->atb_balance);
        adm_write_newline();

        /* GenerateEvent */

        adm_send_event_account_account_ok(
            ent_account,
            ent_account,
            1, 209, 53);

    } else {

        /* Template */

        adm_write_newline();
        adm_write_str("    Withdrawal Rejected");
        adm_write_newline();
        adm_write_str("        Amount:  $");
        adm_write_fxd(dst_transaction->amount);
        adm_write_newline();
        adm_write_str("        Balance: $");
        adm_write_fxd(ent_account->atb_balance);
        adm_write_newline();
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_account_considering_withdrawal");
    #endif
}

void adm_state_action_account_considering_check(
    adm_ent_account_typ * ent_account,
    adm_dst_account_transaction_typ * dst_transaction)
{
    /* Entity Objects */
    adm_ent_customer_typ * ent_customer_0000000001;
    adm_ent_bank_policy_typ * ent_bank_policy_0000000001;

    /* Relationship Relations */
    adm_rel_account_owned_by_customer_typ * rel_account_owned_by_customer_0000000001;
    adm_rel_customer_governed_by_bank_policy_typ * rel_customer_governed_by_bank_policy_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_account_considering_check");
    #endif

    /* CaseSelection */

    if (
        (
            (
                dst_transaction->amount > ent_account->atb_balance
            )
        )) {

        /* Traverse - TraverseSelection */

        adm_object_existent_account(
            ent_account,
            1, 236, 57);

        rel_account_owned_by_customer_0000000001 = ent_account->rel_owned_by_customer_head;

        ent_customer_0000000001 = rel_account_owned_by_customer_0000000001->ent_customer;

        rel_customer_governed_by_bank_policy_0000000001 = ent_customer_0000000001->rel_governed_by_bank_policy_head;

        ent_bank_policy_0000000001 = rel_customer_governed_by_bank_policy_0000000001->ent_bank_policy;

        /* Assignment - Evaluation */

        ent_account->atb_balance =
            +(
                +(
                    +ent_account->atb_balance
                    +
                    -ent_bank_policy_0000000001->atb_bounced_check_fee
                )
            );

        if (
            ent_account->atb_balance < ADM_TYPE_MINIMUM_MONEY ||
            ent_account->atb_balance > ADM_TYPE_MAXIMUM_MONEY) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                1, 240, 72,
                "Account",
                ent_account->identity,
                "Balance",
                adm_sim_lib_fxtoa(ent_account->atb_balance));
        }

        /* Template */

        adm_write_newline();
        adm_write_str("    Return Cheque");
        adm_write_newline();
        adm_write_str("        Amount:                    $");
        adm_write_fxd(dst_transaction->amount);
        adm_write_newline();
        adm_write_str("        Charged Bounced Check Fee: $");
        adm_write_fxd(ent_bank_policy_0000000001->atb_bounced_check_fee);
        adm_write_newline();
        adm_write_str("        New Balance:               $");
        adm_write_fxd(ent_account->atb_balance);
        adm_write_newline();

    } else {

        /* Assignment - Evaluation */

        ent_account->atb_balance =
            +(
                +(
                    +ent_account->atb_balance
                    +
                    -dst_transaction->amount
                )
            );

        if (
            ent_account->atb_balance < ADM_TYPE_MINIMUM_MONEY ||
            ent_account->atb_balance > ADM_TYPE_MAXIMUM_MONEY) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                1, 254, 60,
                "Account",
                ent_account->identity,
                "Balance",
                adm_sim_lib_fxtoa(ent_account->atb_balance));
        }

        /* Template */

        adm_write_newline();
        adm_write_str("    Pay Cheque");
        adm_write_newline();
        adm_write_str("        Amount:      $");
        adm_write_fxd(dst_transaction->amount);
        adm_write_newline();
        adm_write_str("        New Balance: $");
        adm_write_fxd(ent_account->atb_balance);
        adm_write_newline();
    }

    /* CaseSelection */

    if (
        (
            (
                ent_account->atb_balance >= 0.0
            )
        )) {

        /* GenerateEvent */

        adm_send_event_account_account_ok(
            ent_account,
            ent_account,
            1, 271, 53);

    } else {

        /* GenerateEvent */

        adm_send_event_account_overdrawn(
            ent_account,
            ent_account,
            1, 274, 49);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_account_considering_check");
    #endif
}

void adm_state_action_account_closed(
    adm_ent_account_typ * ent_account)
{
    /* Entity Objects */
    adm_ent_customer_typ * ent_customer_0000000001;
    adm_ent_account_typ * ent_account_0000000002;

    /* Relationship Relations */
    adm_rel_account_owned_by_customer_typ * rel_account_owned_by_customer_0000000001;
    adm_rel_customer_owns_account_typ * rel_customer_owns_account_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_account_closed");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_account(
        ent_account,
        1, 301, 45);

    rel_account_owned_by_customer_0000000001 = ent_account->rel_owned_by_customer_head;

    ent_customer_0000000001 = rel_account_owned_by_customer_0000000001->ent_customer;

    /* Unrelate */

    adm_kill_relation_account_owned_by_customer(
        ent_account,
        rel_account_owned_by_customer_0000000001,
        1, 304, 49);

    /* Traverse - TraverseSelection */

    adm_object_existent_customer(
        ent_customer_0000000001,
        1, 307, 53);

    rel_customer_owns_account_0000000002 = ent_customer_0000000001->rel_owns_account_head;

    while (rel_customer_owns_account_0000000002 != NULL) {

        ent_account_0000000002 = rel_customer_owns_account_0000000002->ent_account;

        /* SelectionHead */

        adm_object_existent_customer(
            ent_customer_0000000001,
            1, 307, 53);

        if (rel_customer_owns_account_0000000002 == ent_customer_0000000001->rel_owns_account_head) {

            /* SelectionLast */

            adm_object_existent_customer(
                ent_customer_0000000001,
                1, 307, 53);

            if (rel_customer_owns_account_0000000002 == ent_customer_0000000001->rel_owns_account_tail) {

                /* GenerateEvent */

                adm_send_event_customer_last_account_closed(
                    ent_account,
                    ent_customer_0000000001,
                    1, 312, 65);
            }
        }

        rel_customer_owns_account_0000000002 = rel_customer_owns_account_0000000002->next;
    }

    /* Template */

    adm_write_newline();
    adm_write_str("    Account Closed");
    adm_write_newline();
    adm_write_str("        Account Number: ");
    adm_write_int(ent_account->atb_number);
    adm_write_newline();
    adm_write_str("        Pay Out:        $");
    adm_write_fxd(ent_account->atb_balance);
    adm_write_newline();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_account_closed");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */