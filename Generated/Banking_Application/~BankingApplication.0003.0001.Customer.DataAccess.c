
#include "~BankingApplication.0000.0000.Header.h"


/* Customer Data Access */

/* Make Entity Object */

adm_ent_customer_typ * adm_make_object_customer(
    adm_sta_customer_typ status)
{
    adm_ent_customer_typ * ent_customer;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_customer");
    #endif

    if (adm_entity_system.ent_customer.dead_list_head != NULL) {

        ent_customer = adm_entity_system.ent_customer.dead_list_head;

        if (adm_entity_system.ent_customer.dead_list_head == ent_customer) {

            adm_entity_system.ent_customer.dead_list_head = ent_customer->next;

        } else {

            (ent_customer->back)->next = ent_customer->next;
        }

        if (adm_entity_system.ent_customer.dead_list_tail == ent_customer) {

            adm_entity_system.ent_customer.dead_list_tail = ent_customer->back;

        } else {

            (ent_customer->next)->back = ent_customer->back;
        }

    } else {

        ent_customer = (adm_ent_customer_typ*)adm_allocate_memory(sizeof(adm_ent_customer_typ));
    }

    ent_customer->identity = ++adm_entity_system.ent_customer.tote;

    ent_customer->unique  = FALSE;
    ent_customer->deleted = FALSE;
    ent_customer->marked  = FALSE;
    ent_customer->status  = status;

    ent_customer->atb_full_name = (adm_str_name_typ*)adm_allocate_memory(ADM_TYPE_SIZE_NAME+1);
    ent_customer->atb_address = (adm_str_location_typ*)adm_allocate_memory(ADM_TYPE_SIZE_LOCATION+1);

    ent_customer->rel_owns_account_head = NULL;
    ent_customer->rel_owns_account_tail = NULL;

    ent_customer->rel_governed_by_bank_policy_head = NULL;
    ent_customer->rel_governed_by_bank_policy_tail = NULL;

    ent_customer->back = NULL;
    ent_customer->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_customer");
    #endif

    return (ent_customer);
}


/* Bind Entity Object */

void adm_bind_object_customer(
    adm_ent_customer_typ * ent_customer,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_customer");
    #endif

    adm_object_existent_customer(
        ent_customer,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_customer.live_list_head == NULL) {

        ent_customer->back = NULL;

        adm_entity_system.ent_customer.live_list_head = ent_customer;

    } else {

        ent_customer->back = adm_entity_system.ent_customer.live_list_tail;

        (adm_entity_system.ent_customer.live_list_tail)->next = ent_customer;
    }

    ent_customer->next = NULL;

    adm_entity_system.ent_customer.live_list_tail = ent_customer;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_customer");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_customer(
    void * source_object,
    adm_ent_customer_typ * ent_customer,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_customer");
    #endif

    adm_object_existent_customer(
        ent_customer,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_customer) {

        if (ent_customer->rel_owns_account_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Customer",
                ent_customer->identity,
                "Owns",
                "Account");
        }

        if (ent_customer->rel_governed_by_bank_policy_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Customer",
                ent_customer->identity,
                "Governed_by",
                "Bank_Policy");
        }

        if (adm_entity_system.ent_customer.live_list_head == ent_customer) {

            adm_entity_system.ent_customer.live_list_head = ent_customer->next;

        } else {

            (ent_customer->back)->next = ent_customer->next;
        }

        if (adm_entity_system.ent_customer.live_list_tail == ent_customer) {

            adm_entity_system.ent_customer.live_list_tail = ent_customer->back;

        } else {

            (ent_customer->next)->back = ent_customer->back;
        }

        adm_deallocate_memory(ent_customer->atb_full_name);
        adm_deallocate_memory(ent_customer->atb_address);

        ent_customer->deleted = TRUE;

        if (adm_entity_system.ent_customer.dead_list_head == NULL) {

            ent_customer->back = NULL;

            adm_entity_system.ent_customer.dead_list_head = ent_customer;

        } else {

            ent_customer->back = adm_entity_system.ent_customer.dead_list_tail;

            (adm_entity_system.ent_customer.dead_list_tail)->next = ent_customer;
        }

        ent_customer->next = NULL;

        adm_entity_system.ent_customer.dead_list_tail = ent_customer;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Customer",
            ent_customer->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_customer");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_customer_owns_account(
    adm_ent_customer_typ * ent_source_customer,
    adm_ent_account_typ * ent_target_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_customer_owns_account_typ * rel_customer_owns_account;

    adm_base_boolean_typ account_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_customer_owns_account");
    #endif

    adm_object_existent_customer(
        ent_source_customer,
        error_file,
        error_line,
        error_rank);

    account_not_found = TRUE;

    rel_customer_owns_account = ent_source_customer->rel_owns_account_head;

    while (
        account_not_found &&
        rel_customer_owns_account != NULL) {

        if (rel_customer_owns_account->ent_account == ent_target_account) {

            account_not_found = FALSE;
        }

        rel_customer_owns_account = rel_customer_owns_account->next;
    }

    if (account_not_found) {

        rel_customer_owns_account = (adm_rel_customer_owns_account_typ*)
            adm_allocate_memory(sizeof(adm_rel_customer_owns_account_typ));

        rel_customer_owns_account->ent_account = ent_target_account;

        if (ent_source_customer->rel_owns_account_head == NULL) {

            rel_customer_owns_account->back = NULL;

            ent_source_customer->rel_owns_account_head = rel_customer_owns_account;

        } else {

            rel_customer_owns_account->back = ent_source_customer->rel_owns_account_tail;

            (ent_source_customer->rel_owns_account_tail)->next = rel_customer_owns_account;
        }

        rel_customer_owns_account->next = NULL;

        ent_source_customer->rel_owns_account_tail = rel_customer_owns_account;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Customer",
            ent_source_customer->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_customer_owns_account");
    #endif
}

void adm_link_relation_customer_governed_by_bank_policy(
    adm_ent_customer_typ * ent_source_customer,
    adm_ent_bank_policy_typ * ent_target_bank_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_customer_governed_by_bank_policy_typ * rel_customer_governed_by_bank_policy;

    adm_base_boolean_typ bank_policy_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_customer_governed_by_bank_policy");
    #endif

    adm_object_existent_customer(
        ent_source_customer,
        error_file,
        error_line,
        error_rank);

    bank_policy_not_found = TRUE;

    rel_customer_governed_by_bank_policy = ent_source_customer->rel_governed_by_bank_policy_head;

    while (
        bank_policy_not_found &&
        rel_customer_governed_by_bank_policy != NULL) {

        if (rel_customer_governed_by_bank_policy->ent_bank_policy == ent_target_bank_policy) {

            bank_policy_not_found = FALSE;
        }

        rel_customer_governed_by_bank_policy = rel_customer_governed_by_bank_policy->next;
    }

    if (bank_policy_not_found) {

        rel_customer_governed_by_bank_policy = (adm_rel_customer_governed_by_bank_policy_typ*)
            adm_allocate_memory(sizeof(adm_rel_customer_governed_by_bank_policy_typ));

        rel_customer_governed_by_bank_policy->ent_bank_policy = ent_target_bank_policy;

        if (ent_source_customer->rel_governed_by_bank_policy_head == NULL) {

            rel_customer_governed_by_bank_policy->back = NULL;

            ent_source_customer->rel_governed_by_bank_policy_head = rel_customer_governed_by_bank_policy;

        } else {

            rel_customer_governed_by_bank_policy->back = ent_source_customer->rel_governed_by_bank_policy_tail;

            (ent_source_customer->rel_governed_by_bank_policy_tail)->next = rel_customer_governed_by_bank_policy;
        }

        rel_customer_governed_by_bank_policy->next = NULL;

        ent_source_customer->rel_governed_by_bank_policy_tail = rel_customer_governed_by_bank_policy;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Customer",
            ent_source_customer->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_customer_governed_by_bank_policy");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_customer_owns_account(
    adm_ent_customer_typ * ent_customer,
    adm_rel_customer_owns_account_typ * rel_customer_owns_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_customer_owns_account");
    #endif

    adm_object_existent_customer(
        ent_customer,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_customer_owns_account->next !=
        (adm_base_integer_typ)rel_customer_owns_account->ent_account) {

        if (ent_customer->rel_owns_account_head != NULL) {

            if (ent_customer->rel_owns_account_head == rel_customer_owns_account) {

                ent_customer->rel_owns_account_head = rel_customer_owns_account->next;

            } else {

                (rel_customer_owns_account->back)->next = rel_customer_owns_account->next;
            }

            if (ent_customer->rel_owns_account_tail == rel_customer_owns_account) {

                ent_customer->rel_owns_account_tail = rel_customer_owns_account->back;

            } else {

                (rel_customer_owns_account->next)->back = rel_customer_owns_account->back;
            }

            adm_deallocate_memory(rel_customer_owns_account);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Customer",
                ent_customer->identity,
                "Owns",
                "Account");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Customer",
            ent_customer->identity,
            "Owns",
            "Account");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_customer_owns_account");
    #endif
}

void adm_kill_relation_customer_governed_by_bank_policy(
    adm_ent_customer_typ * ent_customer,
    adm_rel_customer_governed_by_bank_policy_typ * rel_customer_governed_by_bank_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_customer_governed_by_bank_policy");
    #endif

    adm_object_existent_customer(
        ent_customer,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_customer_governed_by_bank_policy->next !=
        (adm_base_integer_typ)rel_customer_governed_by_bank_policy->ent_bank_policy) {

        if (ent_customer->rel_governed_by_bank_policy_head != NULL) {

            if (ent_customer->rel_governed_by_bank_policy_head == rel_customer_governed_by_bank_policy) {

                ent_customer->rel_governed_by_bank_policy_head = rel_customer_governed_by_bank_policy->next;

            } else {

                (rel_customer_governed_by_bank_policy->back)->next = rel_customer_governed_by_bank_policy->next;
            }

            if (ent_customer->rel_governed_by_bank_policy_tail == rel_customer_governed_by_bank_policy) {

                ent_customer->rel_governed_by_bank_policy_tail = rel_customer_governed_by_bank_policy->back;

            } else {

                (rel_customer_governed_by_bank_policy->next)->back = rel_customer_governed_by_bank_policy->back;
            }

            adm_deallocate_memory(rel_customer_governed_by_bank_policy);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Customer",
                ent_customer->identity,
                "Governed_by",
                "Bank_Policy");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Customer",
            ent_customer->identity,
            "Governed_by",
            "Bank_Policy");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_customer_governed_by_bank_policy");
    #endif
}


/* Object Existent */

void adm_object_existent_customer(
    adm_ent_customer_typ * ent_customer,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_customer");
    #endif

    if (ent_customer->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Customer",
            ent_customer->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_customer");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */