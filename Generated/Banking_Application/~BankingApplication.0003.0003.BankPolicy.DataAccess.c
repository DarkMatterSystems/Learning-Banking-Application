
#include "~BankingApplication.0000.0000.Header.h"


/* Bank Policy Data Access */

/* Make Entity Object */

adm_ent_bank_policy_typ * adm_make_object_bank_policy(
    void)
{
    adm_ent_bank_policy_typ * ent_bank_policy;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_bank_policy");
    #endif

    if (adm_entity_system.ent_bank_policy.dead_list_head != NULL) {

        ent_bank_policy = adm_entity_system.ent_bank_policy.dead_list_head;

        if (adm_entity_system.ent_bank_policy.dead_list_head == ent_bank_policy) {

            adm_entity_system.ent_bank_policy.dead_list_head = ent_bank_policy->next;

        } else {

            (ent_bank_policy->back)->next = ent_bank_policy->next;
        }

        if (adm_entity_system.ent_bank_policy.dead_list_tail == ent_bank_policy) {

            adm_entity_system.ent_bank_policy.dead_list_tail = ent_bank_policy->back;

        } else {

            (ent_bank_policy->next)->back = ent_bank_policy->back;
        }

    } else {

        ent_bank_policy = (adm_ent_bank_policy_typ*)adm_allocate_memory(sizeof(adm_ent_bank_policy_typ));
    }

    ent_bank_policy->identity = ++adm_entity_system.ent_bank_policy.tote;

    ent_bank_policy->unique  = FALSE;
    ent_bank_policy->deleted = FALSE;
    ent_bank_policy->marked  = FALSE;
    ent_bank_policy->ignore  = null;

    ent_bank_policy->back = NULL;
    ent_bank_policy->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_bank_policy");
    #endif

    return (ent_bank_policy);
}


/* Bind Entity Object */

void adm_bind_object_bank_policy(
    adm_ent_bank_policy_typ * ent_bank_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_bank_policy");
    #endif

    adm_object_existent_bank_policy(
        ent_bank_policy,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_bank_policy.live_list_head == NULL) {

        ent_bank_policy->back = NULL;

        adm_entity_system.ent_bank_policy.live_list_head = ent_bank_policy;

    } else {

        ent_bank_policy->back = adm_entity_system.ent_bank_policy.live_list_tail;

        (adm_entity_system.ent_bank_policy.live_list_tail)->next = ent_bank_policy;
    }

    ent_bank_policy->next = NULL;

    adm_entity_system.ent_bank_policy.live_list_tail = ent_bank_policy;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_bank_policy");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_bank_policy(
    void * source_object,
    adm_ent_bank_policy_typ * ent_bank_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_bank_policy");
    #endif

    adm_object_existent_bank_policy(
        ent_bank_policy,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_bank_policy) {

        if (adm_entity_system.ent_bank_policy.live_list_head == ent_bank_policy) {

            adm_entity_system.ent_bank_policy.live_list_head = ent_bank_policy->next;

        } else {

            (ent_bank_policy->back)->next = ent_bank_policy->next;
        }

        if (adm_entity_system.ent_bank_policy.live_list_tail == ent_bank_policy) {

            adm_entity_system.ent_bank_policy.live_list_tail = ent_bank_policy->back;

        } else {

            (ent_bank_policy->next)->back = ent_bank_policy->back;
        }

        ent_bank_policy->deleted = TRUE;

        if (adm_entity_system.ent_bank_policy.dead_list_head == NULL) {

            ent_bank_policy->back = NULL;

            adm_entity_system.ent_bank_policy.dead_list_head = ent_bank_policy;

        } else {

            ent_bank_policy->back = adm_entity_system.ent_bank_policy.dead_list_tail;

            (adm_entity_system.ent_bank_policy.dead_list_tail)->next = ent_bank_policy;
        }

        ent_bank_policy->next = NULL;

        adm_entity_system.ent_bank_policy.dead_list_tail = ent_bank_policy;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Bank_Policy",
            ent_bank_policy->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_bank_policy");
    #endif
}


/* Object Existent */

void adm_object_existent_bank_policy(
    adm_ent_bank_policy_typ * ent_bank_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_bank_policy");
    #endif

    if (ent_bank_policy->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Bank_Policy",
            ent_bank_policy->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_bank_policy");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */