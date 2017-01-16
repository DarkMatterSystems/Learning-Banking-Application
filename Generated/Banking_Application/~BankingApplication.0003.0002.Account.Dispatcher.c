
#include "~BankingApplication.0000.0000.Header.h"


/* Account Dispatcher */

/* Dispatcher */

void adm_dispatcher_account(
    void)
{
    adm_pool_target_account_typ * pool_target_account;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_account");
    #endif

    pool_target_account = adm_find_away_target_event_account();

    adm_dispatch_state_action_account(pool_target_account);

    adm_dispatch_home_pool_account();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_account");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_account(
    void)
{
    adm_pool_target_account_typ * pool_target_account;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_account");
    #endif

    while (adm_entity_system.ent_account.home_pool_head != NULL) {

        pool_target_account = adm_find_home_target_event_account();

        adm_dispatch_state_action_account(pool_target_account);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_account");
    #endif
}


/* Find Home Target Event */

adm_pool_target_account_typ * adm_find_home_target_event_account(
    void)
{
    adm_pool_target_account_typ * pool_target_account;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_account");
    #endif

    pool_target_account = adm_entity_system.ent_account.home_pool_head;

    adm_entity_system.ent_account.home_pool_head = pool_target_account->next;

    if (adm_entity_system.ent_account.home_pool_head == NULL) {

        adm_entity_system.ent_account.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_account");
    #endif

    return (pool_target_account);
}


/* Find Away Target Event */

adm_pool_target_account_typ * adm_find_away_target_event_account(
    void)
{
    adm_pool_target_account_typ * pool_target_account;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_account");
    #endif

    pool_target_account = adm_entity_system.ent_account.away_pool_head;

    adm_entity_system.ent_account.away_pool_head = pool_target_account->next;

    if (adm_entity_system.ent_account.away_pool_head == NULL) {

        adm_entity_system.ent_account.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_account");
    #endif

    return (pool_target_account);
}


/* Dispatch State Action */

void adm_dispatch_state_action_account(
    adm_pool_target_account_typ * pool_target)
{
    adm_dst_account_transaction_typ * dst_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_account");
    #endif

    if (pool_target->ent_account != NULL) {

        adm_object_existent_account(
            pool_target->ent_account,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_ACCOUNT_MAKE_DEPOSIT :

            switch ((pool_target->ent_account)->status) {

                case ADM_STATUS_ACCOUNT_CREATING_ACCOUNT :

                    dst_transaction = (adm_dst_account_transaction_typ*)pool_target->dataset.transaction;

                    adm_sim_display_state_account_taking_deposit(pool_target);

                    (pool_target->ent_account)->status = ADM_STATUS_ACCOUNT_TAKING_DEPOSIT;

                    adm_state_action_account_taking_deposit(
                        pool_target->ent_account,
                        dst_transaction);

                    adm_deallocate_memory(pool_target->dataset.transaction);

                break;

                case ADM_STATUS_ACCOUNT_TAKING_DEPOSIT :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Make_deposit",
                        "State:Taking_Deposit");

                break;

                case ADM_STATUS_ACCOUNT_IN_GOOD_STANDING :

                    dst_transaction = (adm_dst_account_transaction_typ*)pool_target->dataset.transaction;

                    adm_sim_display_state_account_taking_deposit(pool_target);

                    (pool_target->ent_account)->status = ADM_STATUS_ACCOUNT_TAKING_DEPOSIT;

                    adm_state_action_account_taking_deposit(
                        pool_target->ent_account,
                        dst_transaction);

                    adm_deallocate_memory(pool_target->dataset.transaction);

                break;

                case ADM_STATUS_ACCOUNT_CONSIDERING_WITHDRAWAL :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Make_deposit",
                        "State:Considering_Withdrawal");

                break;

                case ADM_STATUS_ACCOUNT_CONSIDERING_CHECK :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Make_deposit",
                        "State:Considering_Check");

                break;

                case ADM_STATUS_ACCOUNT_OVERDRAWN :

                    dst_transaction = (adm_dst_account_transaction_typ*)pool_target->dataset.transaction;

                    adm_sim_display_state_account_taking_deposit(pool_target);

                    (pool_target->ent_account)->status = ADM_STATUS_ACCOUNT_TAKING_DEPOSIT;

                    adm_state_action_account_taking_deposit(
                        pool_target->ent_account,
                        dst_transaction);

                    adm_deallocate_memory(pool_target->dataset.transaction);

                break;

                case ADM_STATUS_ACCOUNT_CLOSED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Make_deposit",
                        "State:Closed");

                break;
            }

        break;

        case ADM_EVENT_ACCOUNT_ACCOUNT_OK :

            switch ((pool_target->ent_account)->status) {

                case ADM_STATUS_ACCOUNT_CREATING_ACCOUNT :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Account_ok",
                        "State:Creating_Account");

                break;

                case ADM_STATUS_ACCOUNT_TAKING_DEPOSIT :

                    adm_sim_display_state_account_in_good_standing(pool_target);

                    (pool_target->ent_account)->status = ADM_STATUS_ACCOUNT_IN_GOOD_STANDING;

                break;

                case ADM_STATUS_ACCOUNT_IN_GOOD_STANDING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Account_ok",
                        "State:In_Good_Standing");

                break;

                case ADM_STATUS_ACCOUNT_CONSIDERING_WITHDRAWAL :

                    adm_sim_display_state_account_in_good_standing(pool_target);

                    (pool_target->ent_account)->status = ADM_STATUS_ACCOUNT_IN_GOOD_STANDING;

                break;

                case ADM_STATUS_ACCOUNT_CONSIDERING_CHECK :

                    adm_sim_display_state_account_in_good_standing(pool_target);

                    (pool_target->ent_account)->status = ADM_STATUS_ACCOUNT_IN_GOOD_STANDING;

                break;

                case ADM_STATUS_ACCOUNT_OVERDRAWN :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Account_ok",
                        "State:Overdrawn");

                break;

                case ADM_STATUS_ACCOUNT_CLOSED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Account_ok",
                        "State:Closed");

                break;
            }

        break;

        case ADM_EVENT_ACCOUNT_WITHDRAWAL_SUBMITTED :

            switch ((pool_target->ent_account)->status) {

                case ADM_STATUS_ACCOUNT_CREATING_ACCOUNT :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Withdrawal_submitted",
                        "State:Creating_Account");

                break;

                case ADM_STATUS_ACCOUNT_TAKING_DEPOSIT :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Withdrawal_submitted",
                        "State:Taking_Deposit");

                break;

                case ADM_STATUS_ACCOUNT_IN_GOOD_STANDING :

                    dst_transaction = (adm_dst_account_transaction_typ*)pool_target->dataset.transaction;

                    adm_sim_display_state_account_considering_withdrawal(pool_target);

                    (pool_target->ent_account)->status = ADM_STATUS_ACCOUNT_CONSIDERING_WITHDRAWAL;

                    adm_state_action_account_considering_withdrawal(
                        pool_target->ent_account,
                        dst_transaction);

                    adm_deallocate_memory(pool_target->dataset.transaction);

                break;

                case ADM_STATUS_ACCOUNT_CONSIDERING_WITHDRAWAL :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Withdrawal_submitted",
                        "State:Considering_Withdrawal");

                break;

                case ADM_STATUS_ACCOUNT_CONSIDERING_CHECK :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Withdrawal_submitted",
                        "State:Considering_Check");

                break;

                case ADM_STATUS_ACCOUNT_CLOSED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Withdrawal_submitted",
                        "State:Closed");

                break;
            }

        break;

        case ADM_EVENT_ACCOUNT_CHECK_SUBMITTED :

            switch ((pool_target->ent_account)->status) {

                case ADM_STATUS_ACCOUNT_CREATING_ACCOUNT :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Check_submitted",
                        "State:Creating_Account");

                break;

                case ADM_STATUS_ACCOUNT_TAKING_DEPOSIT :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Check_submitted",
                        "State:Taking_Deposit");

                break;

                case ADM_STATUS_ACCOUNT_IN_GOOD_STANDING :

                    dst_transaction = (adm_dst_account_transaction_typ*)pool_target->dataset.transaction;

                    adm_sim_display_state_account_considering_check(pool_target);

                    (pool_target->ent_account)->status = ADM_STATUS_ACCOUNT_CONSIDERING_CHECK;

                    adm_state_action_account_considering_check(
                        pool_target->ent_account,
                        dst_transaction);

                    adm_deallocate_memory(pool_target->dataset.transaction);

                break;

                case ADM_STATUS_ACCOUNT_CONSIDERING_WITHDRAWAL :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Check_submitted",
                        "State:Considering_Withdrawal");

                break;

                case ADM_STATUS_ACCOUNT_CONSIDERING_CHECK :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Check_submitted",
                        "State:Considering_Check");

                break;

                case ADM_STATUS_ACCOUNT_CLOSED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Check_submitted",
                        "State:Closed");

                break;
            }

        break;

        case ADM_EVENT_ACCOUNT_OVERDRAWN :

            switch ((pool_target->ent_account)->status) {

                case ADM_STATUS_ACCOUNT_CREATING_ACCOUNT :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Overdrawn",
                        "State:Creating_Account");

                break;

                case ADM_STATUS_ACCOUNT_TAKING_DEPOSIT :

                    adm_sim_display_state_account_overdrawn(pool_target);

                    (pool_target->ent_account)->status = ADM_STATUS_ACCOUNT_OVERDRAWN;

                break;

                case ADM_STATUS_ACCOUNT_IN_GOOD_STANDING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Overdrawn",
                        "State:In_Good_Standing");

                break;

                case ADM_STATUS_ACCOUNT_CONSIDERING_WITHDRAWAL :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Overdrawn",
                        "State:Considering_Withdrawal");

                break;

                case ADM_STATUS_ACCOUNT_CONSIDERING_CHECK :

                    adm_sim_display_state_account_overdrawn(pool_target);

                    (pool_target->ent_account)->status = ADM_STATUS_ACCOUNT_OVERDRAWN;

                break;

                case ADM_STATUS_ACCOUNT_OVERDRAWN :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Overdrawn",
                        "State:Overdrawn");

                break;

                case ADM_STATUS_ACCOUNT_CLOSED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Overdrawn",
                        "State:Closed");

                break;
            }

        break;

        /* Deletion Events */

        case ADM_EVENT_ACCOUNT_CLOSE_ACCOUNT :

            switch ((pool_target->ent_account)->status) {

                case ADM_STATUS_ACCOUNT_CREATING_ACCOUNT :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Close_account",
                        "State:Creating_Account");

                break;

                case ADM_STATUS_ACCOUNT_TAKING_DEPOSIT :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Close_account",
                        "State:Taking_Deposit");

                break;

                case ADM_STATUS_ACCOUNT_IN_GOOD_STANDING :

                    adm_sim_display_state_account_closed(pool_target);

                    adm_state_action_account_closed(
                        pool_target->ent_account);

                    adm_kill_object_account(
                        NULL,
                        pool_target->ent_account,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank);

                break;

                case ADM_STATUS_ACCOUNT_CONSIDERING_WITHDRAWAL :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Close_account",
                        "State:Considering_Withdrawal");

                break;

                case ADM_STATUS_ACCOUNT_CONSIDERING_CHECK :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Close_account",
                        "State:Considering_Check");

                break;

                case ADM_STATUS_ACCOUNT_CLOSED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Account",
                        (pool_target->ent_account)->identity,
                        "Event:Close_account",
                        "State:Closed");

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_account");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */