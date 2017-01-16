
#include "~BankingApplication.0000.0000.Header.h"


/* Account Simulator Display Entity */

void adm_sim_display_entity_account(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_account_typ * ent_account;

    adm_sim_width_account_typ width_account;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_account");
    #endif

    width_account.identity = strlen("Identity");
    width_account.status = strlen("Status");
    width_account.atb_number = strlen("Number");
    width_account.atb_balance = strlen("Balance");

    ent_account = adm_entity_system.ent_account.live_list_head;

    while (ent_account != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_account->identity);
        if (width > width_account.identity) width_account.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_account[ent_account->status]);
        if (width > width_account.status) width_account.status = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_account->atb_number);
        if (width > width_account.atb_number) width_account.atb_number = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%f", ent_account->atb_balance);
        if (width > width_account.atb_balance) width_account.atb_balance = width;

        ent_account = ent_account->next;
    }

    printf(NEWLINE);
    printf("Account:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_account.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_account.status, "Status");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_account.atb_number, "Number");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_account.atb_balance, "Balance");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_account.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_account.status);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_account.atb_number);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_account.atb_balance);

    ent_account = adm_entity_system.ent_account.live_list_head;

    while (ent_account != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_account.identity, ent_account->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_account->status) {
            case ADM_STATUS_ACCOUNT_CREATING_ACCOUNT :
                printf("%-*s", width_account.status, "Creating_Account");
            break;
            case ADM_STATUS_ACCOUNT_TAKING_DEPOSIT :
                printf("%-*s", width_account.status, "Taking_Deposit");
            break;
            case ADM_STATUS_ACCOUNT_IN_GOOD_STANDING :
                printf("%-*s", width_account.status, "In_Good_Standing");
            break;
            case ADM_STATUS_ACCOUNT_CONSIDERING_WITHDRAWAL :
                printf("%-*s", width_account.status, "Considering_Withdrawal");
            break;
            case ADM_STATUS_ACCOUNT_CONSIDERING_CHECK :
                printf("%-*s", width_account.status, "Considering_Check");
            break;
            case ADM_STATUS_ACCOUNT_OVERDRAWN :
                printf("%-*s", width_account.status, "Overdrawn");
            break;
            case ADM_STATUS_ACCOUNT_CLOSED :
                printf("%-*s", width_account.status, "Closed");
            break;
            default :
                printf("%-*s", width_account.status, "ERROR");
            break;
        }

        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_account.atb_number, ent_account->atb_number);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*f", width_account.atb_balance, ent_account->atb_balance);

        ent_account = ent_account->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_account");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */