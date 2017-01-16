
#include "~BankingApplication.0000.0000.Header.h"


/* Simulator Account Display Event */

void adm_sim_display_event_account_make_deposit(
    adm_ent_account_typ * ent_account,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_account_make_deposit");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);
        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Account[");
        printf("%d", ent_account->identity);
        printf("] Make_deposit (");
        printf("Amount:%f", evd_amount);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_account_make_deposit");
    #endif
}

void adm_sim_display_event_account_account_ok(
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_account_account_ok");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);
        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Account[");
        printf("%d", ent_account->identity);
        printf("] Account_ok (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_account_account_ok");
    #endif
}

void adm_sim_display_event_account_withdrawal_submitted(
    adm_ent_account_typ * ent_account,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_account_withdrawal_submitted");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);
        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Account[");
        printf("%d", ent_account->identity);
        printf("] Withdrawal_submitted (");
        printf("Amount:%f", evd_amount);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_account_withdrawal_submitted");
    #endif
}

void adm_sim_display_event_account_check_submitted(
    adm_ent_account_typ * ent_account,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_account_check_submitted");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);
        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Account[");
        printf("%d", ent_account->identity);
        printf("] Check_submitted (");
        printf("Amount:%f", evd_amount);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_account_check_submitted");
    #endif
}

void adm_sim_display_event_account_overdrawn(
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_account_overdrawn");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);
        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Account[");
        printf("%d", ent_account->identity);
        printf("] Overdrawn (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_account_overdrawn");
    #endif
}

void adm_sim_display_event_account_close_account(
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_account_close_account");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);
        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Account[");
        printf("%d", ent_account->identity);
        printf("] Close_account (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_account_close_account");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */