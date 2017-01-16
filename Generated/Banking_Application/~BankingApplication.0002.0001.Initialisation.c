
#include "~BankingApplication.0000.0000.Header.h"


/* Domain - Initialisation */

void adm_initialisation_banking_application(
    void)
{
    /* Declare Objects */

    /* Customer */
    adm_ent_customer_typ * ent_customer_0000000001;

    /* Account */
    adm_ent_account_typ * ent_account_0000000002;
    adm_ent_account_typ * ent_account_0000000003;
    adm_ent_account_typ * ent_account_0000000004;

    /* Bank Policy */
    adm_ent_bank_policy_typ * ent_bank_policy_0000000005;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation_banking_application");
    #endif

    /* Entity System */

    adm_entity_system.ent_customer.tote = 0;
    adm_entity_system.ent_account.tote = 0;
    adm_entity_system.ent_bank_policy.tote = 0;

    adm_entity_system.ent_customer.live_list_head = NULL;
    adm_entity_system.ent_account.live_list_head = NULL;
    adm_entity_system.ent_bank_policy.live_list_head = NULL;

    adm_entity_system.ent_customer.live_list_tail = NULL;
    adm_entity_system.ent_account.live_list_tail = NULL;
    adm_entity_system.ent_bank_policy.live_list_tail = NULL;

    adm_entity_system.ent_customer.dead_list_head = NULL;
    adm_entity_system.ent_account.dead_list_head = NULL;
    adm_entity_system.ent_bank_policy.dead_list_head = NULL;

    adm_entity_system.ent_customer.dead_list_tail = NULL;
    adm_entity_system.ent_account.dead_list_tail = NULL;
    adm_entity_system.ent_bank_policy.dead_list_tail = NULL;

    adm_entity_system.ent_customer.home_pool_head = NULL;
    adm_entity_system.ent_account.home_pool_head = NULL;

    adm_entity_system.ent_customer.home_pool_tail = NULL;
    adm_entity_system.ent_account.home_pool_tail = NULL;

    adm_entity_system.ent_customer.away_pool_head = NULL;
    adm_entity_system.ent_account.away_pool_head = NULL;

    adm_entity_system.ent_customer.away_pool_tail = NULL;
    adm_entity_system.ent_account.away_pool_tail = NULL;


    /* Make Objects */

    /* Customer */
    ent_customer_0000000001 = adm_make_object_customer(ADM_STATUS_CUSTOMER_ACCEPTING_NEW_CUSTOMER);

    /* Account */
    ent_account_0000000002 = adm_make_object_account(ADM_STATUS_ACCOUNT_IN_GOOD_STANDING);
    ent_account_0000000003 = adm_make_object_account(ADM_STATUS_ACCOUNT_IN_GOOD_STANDING);
    ent_account_0000000004 = adm_make_object_account(ADM_STATUS_ACCOUNT_IN_GOOD_STANDING);

    /* Bank Policy */
    ent_bank_policy_0000000005 = adm_make_object_bank_policy();


    /* Object Fact Assignments */

    /* Customer */

    strcpy_s(ent_customer_0000000001->atb_full_name, ADM_TYPE_SIZE_NAME+1,(adm_str_name_typ*)&"Mike");
    strcpy_s(ent_customer_0000000001->atb_address, ADM_TYPE_SIZE_LOCATION+1,(adm_str_location_typ*)&"London");

    /* Account */

    ent_account_0000000002->atb_number = 10000000;
    ent_account_0000000002->atb_balance = 5.00;

    ent_account_0000000003->atb_number = 10000001;
    ent_account_0000000003->atb_balance = 10.00;

    ent_account_0000000004->atb_number = 10000002;
    ent_account_0000000004->atb_balance = 15.00;

    /* Bank Policy */

    ent_bank_policy_0000000005->atb_next_account_number = 10000003;
    ent_bank_policy_0000000005->atb_bounced_check_fee = 75.00;


    /* Bind Objects */

    /* Customer */
    adm_bind_object_customer(
        ent_customer_0000000001,
        1, 341, 29);

    /* Account */
    adm_bind_object_account(
        ent_account_0000000002,
        1, 352, 29);
    adm_bind_object_account(
        ent_account_0000000003,
        1, 353, 29);
    adm_bind_object_account(
        ent_account_0000000004,
        1, 354, 29);

    /* Bank Policy */
    adm_bind_object_bank_policy(
        ent_bank_policy_0000000005,
        1, 364, 29);


    /* Link Relations */

    /* Customer */

    adm_link_relation_customer_owns_account(
        ent_customer_0000000001,
        ent_account_0000000002,
        1, 347, 29);

    adm_link_relation_customer_governed_by_bank_policy(
        ent_customer_0000000001,
        ent_bank_policy_0000000005,
        1, 344, 29);

    /* Account */

    adm_link_relation_account_owned_by_customer(
        ent_account_0000000002,
        ent_customer_0000000001,
        1, 357, 29);

    adm_link_relation_account_owned_by_customer(
        ent_account_0000000003,
        ent_customer_0000000001,
        1, 358, 29);

    adm_link_relation_account_owned_by_customer(
        ent_account_0000000004,
        ent_customer_0000000001,
        1, 359, 29);


    /* Integrity Check */
    adm_integrity_check();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation_banking_application");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */