
#include "~BankingApplication.0000.0000.Header.h"


/* Bank Policy Simulator Display Entity */

void adm_sim_display_entity_bank_policy(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_bank_policy_typ * ent_bank_policy;

    adm_sim_width_bank_policy_typ width_bank_policy;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_bank_policy");
    #endif

    width_bank_policy.identity = strlen("Identity");
    width_bank_policy.atb_next_account_number = strlen("Next_account_number");
    width_bank_policy.atb_bounced_check_fee = strlen("Bounced_check_fee");

    ent_bank_policy = adm_entity_system.ent_bank_policy.live_list_head;

    while (ent_bank_policy != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_bank_policy->identity);
        if (width > width_bank_policy.identity) width_bank_policy.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_bank_policy->atb_next_account_number);
        if (width > width_bank_policy.atb_next_account_number) width_bank_policy.atb_next_account_number = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%f", ent_bank_policy->atb_bounced_check_fee);
        if (width > width_bank_policy.atb_bounced_check_fee) width_bank_policy.atb_bounced_check_fee = width;

        ent_bank_policy = ent_bank_policy->next;
    }

    printf(NEWLINE);
    printf("Bank_Policy:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_bank_policy.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_bank_policy.atb_next_account_number, "Next_account_number");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_bank_policy.atb_bounced_check_fee, "Bounced_check_fee");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_bank_policy.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_bank_policy.atb_next_account_number);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_bank_policy.atb_bounced_check_fee);

    ent_bank_policy = adm_entity_system.ent_bank_policy.live_list_head;

    while (ent_bank_policy != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_bank_policy.identity, ent_bank_policy->identity);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_bank_policy.atb_next_account_number, ent_bank_policy->atb_next_account_number);
        printf(ADM_SIM_COLUMN_GAP);
        printf("%*f", width_bank_policy.atb_bounced_check_fee, ent_bank_policy->atb_bounced_check_fee);

        ent_bank_policy = ent_bank_policy->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_bank_policy");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */