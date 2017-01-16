
/* Simulator System Prototype Internals Header */

/* Display Entity Prototypes */

void adm_sim_display_entity_customer(
    void);

void adm_sim_display_entity_account(
    void);

void adm_sim_display_entity_bank_policy(
    void);


/* Acquire Identity Event Prototypes */

void adm_sim_acquire_identity_event_customer_last_account_closed(
    void);

void adm_sim_acquire_identity_event_customer_new_customer(
    void);

void adm_sim_acquire_identity_event_account_make_deposit(
    void);

void adm_sim_acquire_identity_event_account_account_ok(
    void);

void adm_sim_acquire_identity_event_account_withdrawal_submitted(
    void);

void adm_sim_acquire_identity_event_account_check_submitted(
    void);

void adm_sim_acquire_identity_event_account_overdrawn(
    void);

void adm_sim_acquire_identity_event_account_close_account(
    void);


/* Acquire Identifier Event Prototypes */


/* Display Event Prototypes */

void adm_sim_display_event_customer_last_account_closed(
    adm_ent_customer_typ * ent_customer,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_customer_new_customer(
    adm_str_name_typ * evd_full_name,
    adm_str_location_typ * evd_address,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_account_make_deposit(
    adm_ent_account_typ * ent_account,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_account_account_ok(
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_account_withdrawal_submitted(
    adm_ent_account_typ * ent_account,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_account_check_submitted(
    adm_ent_account_typ * ent_account,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_account_overdrawn(
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_account_close_account(
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);


/* Display State Prototypes */

void adm_sim_display_state_customer_accepting_new_customer(
    adm_pool_target_customer_typ * pool_target);

void adm_sim_display_state_customer_customer_vanishes(
    adm_pool_target_customer_typ * pool_target);

void adm_sim_display_state_account_taking_deposit(
    adm_pool_target_account_typ * pool_target);

void adm_sim_display_state_account_in_good_standing(
    adm_pool_target_account_typ * pool_target);

void adm_sim_display_state_account_considering_withdrawal(
    adm_pool_target_account_typ * pool_target);

void adm_sim_display_state_account_considering_check(
    adm_pool_target_account_typ * pool_target);

void adm_sim_display_state_account_overdrawn(
    adm_pool_target_account_typ * pool_target);

void adm_sim_display_state_account_closed(
    adm_pool_target_account_typ * pool_target);


/* Find Event Name Prototype */

adm_base_string_typ * adm_sim_find_event_name(
    adm_base_integer_typ entity_index,
    adm_base_integer_typ entity_event_index);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */