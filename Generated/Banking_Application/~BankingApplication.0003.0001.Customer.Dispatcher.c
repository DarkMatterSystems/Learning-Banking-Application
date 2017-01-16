
#include "~BankingApplication.0000.0000.Header.h"


/* Customer Dispatcher */

/* Dispatcher */

void adm_dispatcher_customer(
    void)
{
    adm_pool_target_customer_typ * pool_target_customer;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_customer");
    #endif

    pool_target_customer = adm_find_away_target_event_customer();

    adm_dispatch_state_action_customer(pool_target_customer);

    adm_dispatch_home_pool_customer();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_customer");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_customer(
    void)
{
    adm_pool_target_customer_typ * pool_target_customer;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_customer");
    #endif

    while (adm_entity_system.ent_customer.home_pool_head != NULL) {

        pool_target_customer = adm_find_home_target_event_customer();

        adm_dispatch_state_action_customer(pool_target_customer);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_customer");
    #endif
}


/* Find Home Target Event */

adm_pool_target_customer_typ * adm_find_home_target_event_customer(
    void)
{
    adm_pool_target_customer_typ * pool_target_customer;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_customer");
    #endif

    pool_target_customer = adm_entity_system.ent_customer.home_pool_head;

    adm_entity_system.ent_customer.home_pool_head = pool_target_customer->next;

    if (adm_entity_system.ent_customer.home_pool_head == NULL) {

        adm_entity_system.ent_customer.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_customer");
    #endif

    return (pool_target_customer);
}


/* Find Away Target Event */

adm_pool_target_customer_typ * adm_find_away_target_event_customer(
    void)
{
    adm_pool_target_customer_typ * pool_target_customer;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_customer");
    #endif

    pool_target_customer = adm_entity_system.ent_customer.away_pool_head;

    adm_entity_system.ent_customer.away_pool_head = pool_target_customer->next;

    if (adm_entity_system.ent_customer.away_pool_head == NULL) {

        adm_entity_system.ent_customer.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_customer");
    #endif

    return (pool_target_customer);
}


/* Dispatch State Action */

void adm_dispatch_state_action_customer(
    adm_pool_target_customer_typ * pool_target)
{
    adm_dst_customer_accept_typ * dst_accept;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_customer");
    #endif

    if (pool_target->ent_customer != NULL) {

        adm_object_existent_customer(
            pool_target->ent_customer,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Creation Events */

        case ADM_EVENT_CUSTOMER_NEW_CUSTOMER :

            dst_accept = (adm_dst_customer_accept_typ*)pool_target->dataset.accept;

            pool_target->ent_customer = adm_make_object_customer(
                ADM_STATUS_CUSTOMER_ACCEPTING_NEW_CUSTOMER);

            adm_sim_display_state_customer_accepting_new_customer(pool_target);

            adm_state_action_customer_accepting_new_customer(
                pool_target->ent_customer,
                dst_accept);

            adm_deallocate_memory(dst_accept->full_name);
            adm_deallocate_memory(dst_accept->address);

            adm_deallocate_memory(pool_target->dataset.accept);

            adm_bind_object_customer(
                pool_target->ent_customer,
                1, 54, 47);

        break;

        /* Deletion Events */

        case ADM_EVENT_CUSTOMER_LAST_ACCOUNT_CLOSED :

            switch ((pool_target->ent_customer)->status) {

                case ADM_STATUS_CUSTOMER_ACCEPTING_NEW_CUSTOMER :

                    adm_sim_display_state_customer_customer_vanishes(pool_target);

                    adm_state_action_customer_customer_vanishes(
                        pool_target->ent_customer);

                    adm_kill_object_customer(
                        NULL,
                        pool_target->ent_customer,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank);

                break;

                case ADM_STATUS_CUSTOMER_CUSTOMER_VANISHES :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Customer",
                        (pool_target->ent_customer)->identity,
                        "Event:Last_account_closed",
                        "State:Customer_Vanishes");

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_customer");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */