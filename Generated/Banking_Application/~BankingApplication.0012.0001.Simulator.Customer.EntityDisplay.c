
#include "~BankingApplication.0000.0000.Header.h"


/* Customer Simulator Display Entity */

void adm_sim_display_entity_customer(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_customer_typ * ent_customer;

    adm_sim_width_customer_typ width_customer;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_customer");
    #endif

    width_customer.identity = strlen("Identity");
    width_customer.status = strlen("Status");
    width_customer.atb_full_name = strlen("Full_name");
    width_customer.atb_address = strlen("Address");

    ent_customer = adm_entity_system.ent_customer.live_list_head;

    while (ent_customer != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_customer->identity);
        if (width > width_customer.identity) width_customer.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_customer[ent_customer->status]);
        if (width > width_customer.status) width_customer.status = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_customer->atb_full_name);
        if (width > width_customer.atb_full_name) width_customer.atb_full_name = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_customer->atb_address);
        if (width > width_customer.atb_address) width_customer.atb_address = width;

        ent_customer = ent_customer->next;
    }

    printf(NEWLINE);
    printf("Customer:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_customer.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_customer.status, "Status");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_customer.atb_full_name, "Full_name");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_customer.atb_address, "Address");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_customer.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_customer.status);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_customer.atb_full_name);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_customer.atb_address);

    ent_customer = adm_entity_system.ent_customer.live_list_head;

    while (ent_customer != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_customer.identity, ent_customer->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_customer->status) {
            case ADM_STATUS_CUSTOMER_ACCEPTING_NEW_CUSTOMER :
                printf("%-*s", width_customer.status, "Accepting_New_Customer");
            break;
            case ADM_STATUS_CUSTOMER_CUSTOMER_VANISHES :
                printf("%-*s", width_customer.status, "Customer_Vanishes");
            break;
            default :
                printf("%-*s", width_customer.status, "ERROR");
            break;
        }

        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_customer->atb_full_name);
        printf("%-*s", width_customer.atb_full_name, buffer);
        printf(ADM_SIM_COLUMN_GAP);
        sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "\"%s\"", ent_customer->atb_address);
        printf("%-*s", width_customer.atb_address, buffer);

        ent_customer = ent_customer->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_customer");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */