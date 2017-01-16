
#include "~BankingApplication.0000.0000.Header.h"


/* Account Data Access */

/* Make Entity Object */

adm_ent_account_typ * adm_make_object_account(
    adm_sta_account_typ status)
{
    adm_ent_account_typ * ent_account;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_account");
    #endif

    if (adm_entity_system.ent_account.dead_list_head != NULL) {

        ent_account = adm_entity_system.ent_account.dead_list_head;

        if (adm_entity_system.ent_account.dead_list_head == ent_account) {

            adm_entity_system.ent_account.dead_list_head = ent_account->next;

        } else {

            (ent_account->back)->next = ent_account->next;
        }

        if (adm_entity_system.ent_account.dead_list_tail == ent_account) {

            adm_entity_system.ent_account.dead_list_tail = ent_account->back;

        } else {

            (ent_account->next)->back = ent_account->back;
        }

    } else {

        ent_account = (adm_ent_account_typ*)adm_allocate_memory(sizeof(adm_ent_account_typ));
    }

    ent_account->identity = ++adm_entity_system.ent_account.tote;

    ent_account->unique  = FALSE;
    ent_account->deleted = FALSE;
    ent_account->marked  = FALSE;
    ent_account->status  = status;

    ent_account->rel_owned_by_customer_head = NULL;
    ent_account->rel_owned_by_customer_tail = NULL;

    ent_account->back = NULL;
    ent_account->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_account");
    #endif

    return (ent_account);
}


/* Bind Entity Object */

void adm_bind_object_account(
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_account");
    #endif

    adm_object_existent_account(
        ent_account,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_account.live_list_head == NULL) {

        ent_account->back = NULL;

        adm_entity_system.ent_account.live_list_head = ent_account;

    } else {

        ent_account->back = adm_entity_system.ent_account.live_list_tail;

        (adm_entity_system.ent_account.live_list_tail)->next = ent_account;
    }

    ent_account->next = NULL;

    adm_entity_system.ent_account.live_list_tail = ent_account;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_account");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_account(
    void * source_object,
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_account");
    #endif

    adm_object_existent_account(
        ent_account,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_account) {

        if (ent_account->rel_owned_by_customer_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Account",
                ent_account->identity,
                "Owned_by",
                "Customer");
        }

        if (adm_entity_system.ent_account.live_list_head == ent_account) {

            adm_entity_system.ent_account.live_list_head = ent_account->next;

        } else {

            (ent_account->back)->next = ent_account->next;
        }

        if (adm_entity_system.ent_account.live_list_tail == ent_account) {

            adm_entity_system.ent_account.live_list_tail = ent_account->back;

        } else {

            (ent_account->next)->back = ent_account->back;
        }

        ent_account->deleted = TRUE;

        if (adm_entity_system.ent_account.dead_list_head == NULL) {

            ent_account->back = NULL;

            adm_entity_system.ent_account.dead_list_head = ent_account;

        } else {

            ent_account->back = adm_entity_system.ent_account.dead_list_tail;

            (adm_entity_system.ent_account.dead_list_tail)->next = ent_account;
        }

        ent_account->next = NULL;

        adm_entity_system.ent_account.dead_list_tail = ent_account;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Account",
            ent_account->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_account");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_account_owned_by_customer(
    adm_ent_account_typ * ent_source_account,
    adm_ent_customer_typ * ent_target_customer,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_account_owned_by_customer_typ * rel_account_owned_by_customer;

    adm_base_boolean_typ customer_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_account_owned_by_customer");
    #endif

    adm_object_existent_account(
        ent_source_account,
        error_file,
        error_line,
        error_rank);

    customer_not_found = TRUE;

    rel_account_owned_by_customer = ent_source_account->rel_owned_by_customer_head;

    while (
        customer_not_found &&
        rel_account_owned_by_customer != NULL) {

        if (rel_account_owned_by_customer->ent_customer == ent_target_customer) {

            customer_not_found = FALSE;
        }

        rel_account_owned_by_customer = rel_account_owned_by_customer->next;
    }

    if (customer_not_found) {

        rel_account_owned_by_customer = (adm_rel_account_owned_by_customer_typ*)
            adm_allocate_memory(sizeof(adm_rel_account_owned_by_customer_typ));

        rel_account_owned_by_customer->ent_customer = ent_target_customer;

        if (ent_source_account->rel_owned_by_customer_head == NULL) {

            rel_account_owned_by_customer->back = NULL;

            ent_source_account->rel_owned_by_customer_head = rel_account_owned_by_customer;

        } else {

            rel_account_owned_by_customer->back = ent_source_account->rel_owned_by_customer_tail;

            (ent_source_account->rel_owned_by_customer_tail)->next = rel_account_owned_by_customer;
        }

        rel_account_owned_by_customer->next = NULL;

        ent_source_account->rel_owned_by_customer_tail = rel_account_owned_by_customer;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Account",
            ent_source_account->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_account_owned_by_customer");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_account_owned_by_customer(
    adm_ent_account_typ * ent_account,
    adm_rel_account_owned_by_customer_typ * rel_account_owned_by_customer,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_account_owned_by_customer");
    #endif

    adm_object_existent_account(
        ent_account,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_account_owned_by_customer->next !=
        (adm_base_integer_typ)rel_account_owned_by_customer->ent_customer) {

        if (ent_account->rel_owned_by_customer_head != NULL) {

            if (ent_account->rel_owned_by_customer_head == rel_account_owned_by_customer) {

                ent_account->rel_owned_by_customer_head = rel_account_owned_by_customer->next;

            } else {

                (rel_account_owned_by_customer->back)->next = rel_account_owned_by_customer->next;
            }

            if (ent_account->rel_owned_by_customer_tail == rel_account_owned_by_customer) {

                ent_account->rel_owned_by_customer_tail = rel_account_owned_by_customer->back;

            } else {

                (rel_account_owned_by_customer->next)->back = rel_account_owned_by_customer->back;
            }

            adm_deallocate_memory(rel_account_owned_by_customer);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Account",
                ent_account->identity,
                "Owned_by",
                "Customer");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Account",
            ent_account->identity,
            "Owned_by",
            "Customer");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_account_owned_by_customer");
    #endif
}


/* Object Existent */

void adm_object_existent_account(
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_account");
    #endif

    if (ent_account->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Account",
            ent_account->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_account");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */