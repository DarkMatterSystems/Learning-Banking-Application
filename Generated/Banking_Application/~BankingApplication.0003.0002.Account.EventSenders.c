
#include "~BankingApplication.0000.0000.Header.h"


/* Account Event Senders */

void adm_send_event_account_make_deposit(
    void * source_object,
    adm_ent_account_typ * ent_account,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_account_typ * pool_target;
    adm_pool_target_account_typ * home_pool_target;

    adm_dst_account_transaction_typ * dst_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_account_make_deposit");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_account_make_deposit(
            ent_account,
            evd_amount,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_account(
            ent_account,
            error_file,
            error_line,
            error_rank);

        if (
            evd_amount < ADM_TYPE_MINIMUM_MONEY ||
            evd_amount > ADM_TYPE_MAXIMUM_MONEY) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Account",
                ent_account->identity,
                "amount",
                adm_sim_lib_fxtoa(evd_amount));
        }

        dst_transaction = (adm_dst_account_transaction_typ*)
            adm_allocate_memory(sizeof(adm_dst_account_transaction_typ));

        dst_transaction->amount = evd_amount;

        pool_target = (adm_pool_target_account_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_account_typ));

        pool_target->evente = ADM_EVENT_ACCOUNT_MAKE_DEPOSIT;
        pool_target->ent_account = ent_account;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;
        pool_target->dataset.transaction = dst_transaction;

        if (source_object == ent_account) {

            if (adm_entity_system.ent_account.home_pool_head == NULL) {

                adm_entity_system.ent_account.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_account.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_account == ent_account) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Account",
                            ent_account->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_account.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_account.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_account.away_pool_head == NULL) {

                adm_entity_system.ent_account.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_account.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_account.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_account_make_deposit");
    #endif
}

void adm_send_event_account_account_ok(
    void * source_object,
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_account_typ * pool_target;
    adm_pool_target_account_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_account_account_ok");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_account_account_ok(
            ent_account,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_account(
            ent_account,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_account_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_account_typ));

        pool_target->evente = ADM_EVENT_ACCOUNT_ACCOUNT_OK;
        pool_target->ent_account = ent_account;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_account) {

            if (adm_entity_system.ent_account.home_pool_head == NULL) {

                adm_entity_system.ent_account.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_account.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_account == ent_account) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Account",
                            ent_account->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_account.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_account.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_account.away_pool_head == NULL) {

                adm_entity_system.ent_account.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_account.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_account.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_account_account_ok");
    #endif
}

void adm_send_event_account_withdrawal_submitted(
    void * source_object,
    adm_ent_account_typ * ent_account,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_account_typ * pool_target;
    adm_pool_target_account_typ * home_pool_target;

    adm_dst_account_transaction_typ * dst_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_account_withdrawal_submitted");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_account_withdrawal_submitted(
            ent_account,
            evd_amount,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_account(
            ent_account,
            error_file,
            error_line,
            error_rank);

        if (
            evd_amount < ADM_TYPE_MINIMUM_MONEY ||
            evd_amount > ADM_TYPE_MAXIMUM_MONEY) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Account",
                ent_account->identity,
                "amount",
                adm_sim_lib_fxtoa(evd_amount));
        }

        dst_transaction = (adm_dst_account_transaction_typ*)
            adm_allocate_memory(sizeof(adm_dst_account_transaction_typ));

        dst_transaction->amount = evd_amount;

        pool_target = (adm_pool_target_account_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_account_typ));

        pool_target->evente = ADM_EVENT_ACCOUNT_WITHDRAWAL_SUBMITTED;
        pool_target->ent_account = ent_account;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;
        pool_target->dataset.transaction = dst_transaction;

        if (source_object == ent_account) {

            if (adm_entity_system.ent_account.home_pool_head == NULL) {

                adm_entity_system.ent_account.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_account.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_account == ent_account) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Account",
                            ent_account->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_account.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_account.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_account.away_pool_head == NULL) {

                adm_entity_system.ent_account.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_account.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_account.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_account_withdrawal_submitted");
    #endif
}

void adm_send_event_account_check_submitted(
    void * source_object,
    adm_ent_account_typ * ent_account,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_account_typ * pool_target;
    adm_pool_target_account_typ * home_pool_target;

    adm_dst_account_transaction_typ * dst_transaction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_account_check_submitted");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_account_check_submitted(
            ent_account,
            evd_amount,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_account(
            ent_account,
            error_file,
            error_line,
            error_rank);

        if (
            evd_amount < ADM_TYPE_MINIMUM_MONEY ||
            evd_amount > ADM_TYPE_MAXIMUM_MONEY) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Account",
                ent_account->identity,
                "amount",
                adm_sim_lib_fxtoa(evd_amount));
        }

        dst_transaction = (adm_dst_account_transaction_typ*)
            adm_allocate_memory(sizeof(adm_dst_account_transaction_typ));

        dst_transaction->amount = evd_amount;

        pool_target = (adm_pool_target_account_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_account_typ));

        pool_target->evente = ADM_EVENT_ACCOUNT_CHECK_SUBMITTED;
        pool_target->ent_account = ent_account;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;
        pool_target->dataset.transaction = dst_transaction;

        if (source_object == ent_account) {

            if (adm_entity_system.ent_account.home_pool_head == NULL) {

                adm_entity_system.ent_account.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_account.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_account == ent_account) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Account",
                            ent_account->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_account.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_account.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_account.away_pool_head == NULL) {

                adm_entity_system.ent_account.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_account.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_account.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_account_check_submitted");
    #endif
}

void adm_send_event_account_overdrawn(
    void * source_object,
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_account_typ * pool_target;
    adm_pool_target_account_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_account_overdrawn");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_account_overdrawn(
            ent_account,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_account(
            ent_account,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_account_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_account_typ));

        pool_target->evente = ADM_EVENT_ACCOUNT_OVERDRAWN;
        pool_target->ent_account = ent_account;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_account) {

            if (adm_entity_system.ent_account.home_pool_head == NULL) {

                adm_entity_system.ent_account.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_account.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_account == ent_account) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Account",
                            ent_account->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_account.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_account.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_account.away_pool_head == NULL) {

                adm_entity_system.ent_account.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_account.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_account.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_account_overdrawn");
    #endif
}

void adm_send_event_account_close_account(
    void * source_object,
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_account_typ * pool_target;
    adm_pool_target_account_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_account_close_account");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_account_close_account(
            ent_account,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_account(
            ent_account,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_account_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_account_typ));

        pool_target->evente = ADM_EVENT_ACCOUNT_CLOSE_ACCOUNT;
        pool_target->ent_account = ent_account;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_account) {

            if (adm_entity_system.ent_account.home_pool_head == NULL) {

                adm_entity_system.ent_account.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_account.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_account == ent_account) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Account",
                            ent_account->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_account.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_account.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_account.away_pool_head == NULL) {

                adm_entity_system.ent_account.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_account.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_account.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_account_close_account");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */