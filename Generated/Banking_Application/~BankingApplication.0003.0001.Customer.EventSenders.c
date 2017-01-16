
#include "~BankingApplication.0000.0000.Header.h"


/* Customer Event Senders */

void adm_send_event_customer_last_account_closed(
    void * source_object,
    adm_ent_customer_typ * ent_customer,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_customer_typ * pool_target;
    adm_pool_target_customer_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_customer_last_account_closed");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_customer_last_account_closed(
            ent_customer,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_customer(
            ent_customer,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_customer_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_customer_typ));

        pool_target->evente = ADM_EVENT_CUSTOMER_LAST_ACCOUNT_CLOSED;
        pool_target->ent_customer = ent_customer;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_customer) {

            if (adm_entity_system.ent_customer.home_pool_head == NULL) {

                adm_entity_system.ent_customer.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_customer.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_customer == ent_customer) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Customer",
                            ent_customer->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_customer.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_customer.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_customer.away_pool_head == NULL) {

                adm_entity_system.ent_customer.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_customer.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_customer.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_customer_last_account_closed");
    #endif
}

void adm_send_event_customer_new_customer(
    adm_str_name_typ * evd_full_name,
    adm_str_location_typ * evd_address,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_customer_typ * pool_target;

    adm_dst_customer_accept_typ * dst_accept;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_customer_new_customer");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_customer_new_customer(
            evd_full_name,
            evd_address,
            evd_amount,
            error_file,
            error_line,
            error_rank);

        if (strlen(evd_full_name) > ADM_TYPE_SIZE_NAME) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Customer",
                null,
                "full_name",
                evd_full_name);
        }

        if (strlen(evd_address) > ADM_TYPE_SIZE_LOCATION) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Customer",
                null,
                "address",
                evd_address);
        }

        if (
            evd_amount < ADM_TYPE_MINIMUM_MONEY ||
            evd_amount > ADM_TYPE_MAXIMUM_MONEY) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Customer",
                null,
                "amount",
                adm_sim_lib_fxtoa(evd_amount));
        }

        dst_accept = (adm_dst_customer_accept_typ*)
            adm_allocate_memory(sizeof(adm_dst_customer_accept_typ));

        dst_accept->full_name = (adm_str_name_typ*)adm_allocate_memory(ADM_TYPE_SIZE_NAME+1);
        dst_accept->address = (adm_str_location_typ*)adm_allocate_memory(ADM_TYPE_SIZE_LOCATION+1);
        dst_accept->amount = evd_amount;

        strcpy_s(dst_accept->full_name, ADM_TYPE_SIZE_NAME+1, evd_full_name);
        strcpy_s(dst_accept->address, ADM_TYPE_SIZE_LOCATION+1, evd_address);

        pool_target = (adm_pool_target_customer_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_customer_typ));

        pool_target->evente = ADM_EVENT_CUSTOMER_NEW_CUSTOMER;
        pool_target->ent_customer = NULL;
        pool_target->next = NULL;
        pool_target->dataset.accept = dst_accept;

        if (adm_entity_system.ent_customer.away_pool_head == NULL) {

            adm_entity_system.ent_customer.away_pool_head = pool_target;

        } else {

            (adm_entity_system.ent_customer.away_pool_tail)->next = pool_target;
        }

        adm_entity_system.ent_customer.away_pool_tail = pool_target;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_customer_new_customer");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */