
#include "~BankingApplication.0000.0000.Header.h"


/* Simulator Customer Display Event */

void adm_sim_display_event_customer_last_account_closed(
    adm_ent_customer_typ * ent_customer,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_customer_last_account_closed");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);
        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Customer[");
        printf("%d", ent_customer->identity);
        printf("] Last_account_closed (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_customer_last_account_closed");
    #endif
}

void adm_sim_display_event_customer_new_customer(
    adm_str_name_typ * evd_full_name,
    adm_str_location_typ * evd_address,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_customer_new_customer");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);
        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Customer[");
        printf("] New_customer (");
        printf("Full_name:\"%s\"", evd_full_name);
        printf(", ");
        printf("Address:\"%s\"", evd_address);
        printf(", ");
        printf("Amount:%f", evd_amount);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_customer_new_customer");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */