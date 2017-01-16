
#include "~BankingApplication.0000.0000.Header.h"


/* Simulator Customer Display State */

void adm_sim_display_state_customer_accepting_new_customer(
    adm_pool_target_customer_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_customer_accepting_new_customer");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:54:47) - Customer[");
        printf("%d", (pool_target->ent_customer)->identity);
        printf("] ");
        printf("Accepting_New_Customer");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_CUSTOMER, pool_target->evente));
        printf("} (");
        printf("Full_name:");
        printf("\"%s\"", (pool_target->dataset.accept)->full_name);
        printf(", ");
        printf("Address:");
        printf("\"%s\"", (pool_target->dataset.accept)->address);
        printf(", ");
        printf("Amount:");
        printf("%f", (pool_target->dataset.accept)->amount);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_customer_accepting_new_customer");
    #endif
}

void adm_sim_display_state_customer_customer_vanishes(
    adm_pool_target_customer_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_customer_customer_vanishes");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:97:43) - Customer[");
        printf("%d", (pool_target->ent_customer)->identity);
        printf("] ");
        printf("Customer_Vanishes");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_BANKING_APPLICATION_CUSTOMER, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_customer[(pool_target->ent_customer)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_customer_customer_vanishes");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */