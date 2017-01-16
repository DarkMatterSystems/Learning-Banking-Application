
#include "~BankingApplication.0000.0000.Header.h"


/* Domain Scheduler Initialisation */

void adm_scheduler_initialisation_banking_application(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation_banking_application");
    #endif

    adm_dispatch_home_pool_customer();
    adm_dispatch_home_pool_account();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation_banking_application");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */