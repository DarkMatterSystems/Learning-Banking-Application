
#include "~BankingApplication.0000.0000.Header.h"


/* Simulator Account Display State */

void adm_sim_display_state_account_taking_deposit(
    adm_pool_target_account_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_account_taking_deposit");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:144:46) - Account[");
        printf("%d", (pool_target->ent_account)->identity);
        printf("] ");
        printf("Taking_Deposit");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_ACCOUNT, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_account[(pool_target->ent_account)->status]);
        printf("} (");
        printf("Amount:");
        printf("%f", (pool_target->dataset.transaction)->amount);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_account_taking_deposit");
    #endif
}

void adm_sim_display_state_account_in_good_standing(
    adm_pool_target_account_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_account_in_good_standing");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:178:42) - Account[");
        printf("%d", (pool_target->ent_account)->identity);
        printf("] ");
        printf("In_Good_Standing");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_ACCOUNT, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_account[(pool_target->ent_account)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_account_in_good_standing");
    #endif
}

void adm_sim_display_state_account_considering_withdrawal(
    adm_pool_target_account_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_account_considering_withdrawal");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:189:46) - Account[");
        printf("%d", (pool_target->ent_account)->identity);
        printf("] ");
        printf("Considering_Withdrawal");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_ACCOUNT, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_account[(pool_target->ent_account)->status]);
        printf("} (");
        printf("Amount:");
        printf("%f", (pool_target->dataset.transaction)->amount);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_account_considering_withdrawal");
    #endif
}

void adm_sim_display_state_account_considering_check(
    adm_pool_target_account_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_account_considering_check");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:226:46) - Account[");
        printf("%d", (pool_target->ent_account)->identity);
        printf("] ");
        printf("Considering_Check");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_ACCOUNT, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_account[(pool_target->ent_account)->status]);
        printf("} (");
        printf("Amount:");
        printf("%f", (pool_target->dataset.transaction)->amount);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_account_considering_check");
    #endif
}

void adm_sim_display_state_account_overdrawn(
    adm_pool_target_account_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_account_overdrawn");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:285:42) - Account[");
        printf("%d", (pool_target->ent_account)->identity);
        printf("] ");
        printf("Overdrawn");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_ACCOUNT, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_account[(pool_target->ent_account)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_account_overdrawn");
    #endif
}

void adm_sim_display_state_account_closed(
    adm_pool_target_account_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_account_closed");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:297:43) - Account[");
        printf("%d", (pool_target->ent_account)->identity);
        printf("] ");
        printf("Closed");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_ACCOUNT, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_account[(pool_target->ent_account)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_account_closed");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */