
/* System Prototypes Header */

/* Main Prototype */

int main(
    int,
    char * []);


/* System Library */

void * adm_allocate_memory(
    adm_base_integer_typ amount);

void adm_deallocate_memory(
    void * memory);

void adm_open_test_result_file  (void);
void adm_close_test_result_file (void);

void adm_open_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_close_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_write_int(
    adm_base_integer_typ number);

void adm_write_bln(
    adm_base_boolean_typ value);

void adm_write_fxd(
    adm_base_fixed_typ number);

void adm_write_flt(
    adm_base_float_typ number);

void adm_write_str(
    adm_base_string_typ * string);

void adm_write_newline(void);

void adm_template_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_template_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_display_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_display_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_convert_string_upper_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_lower_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_sentence_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_capital_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_remove_spaces(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_convert_underlines(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_integrity_check(void);


#if ADM_PROBE

void adm_probe_enter(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name);

void adm_probe_leave(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name);

void adm_add_spaces(
    adm_base_string_typ  * space_string,
    adm_base_integer_typ   space_number);

#endif


/* System Error Handler */

void adm_error_report(
    adm_err_number_typ     error,
    adm_err_file_typ       file,
    adm_err_line_typ       line,
    adm_err_rank_typ       rank,
    adm_err_problem_typ  * source,
    adm_base_integer_typ   identity,
    adm_err_problem_typ  * relation,
    adm_err_problem_typ  * target);


/* Initialisation Prototype */

void adm_initialisation(void);


/* Domain Initialisation Prototypes */

void adm_initialisation_banking_application(void);


/* System Scheduler Prototypes */

void adm_scheduler(void);

void adm_scheduler_dom_banking_application(void);


/* System Initialisation Scheduler Prototypes */

void adm_scheduler_initialisation(void);

void adm_scheduler_initialisation_banking_application(void);


/* System Determine Termination Scheduler Prototypes */

adm_base_boolean_typ adm_scheduler_determine_termination(void);

adm_base_boolean_typ adm_scheduler_determine_termination_dom_banking_application(void);


/* Data Access Prototypes */

adm_ent_customer_typ * adm_make_object_customer(
    adm_sta_customer_typ status);

adm_ent_account_typ * adm_make_object_account(
    adm_sta_account_typ status);

adm_ent_bank_policy_typ * adm_make_object_bank_policy(void);

void adm_bind_object_customer(
    adm_ent_customer_typ * ent_customer,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_account(
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_bank_policy(
    adm_ent_bank_policy_typ * ent_bank_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_customer(
    void * source_object,
    adm_ent_customer_typ * ent_customer,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_account(
    void * source_object,
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_bank_policy(
    void * source_object,
    adm_ent_bank_policy_typ * ent_bank_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_customer_owns_account(
    adm_ent_customer_typ * ent_source_customer,
    adm_ent_account_typ * ent_target_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_customer_governed_by_bank_policy(
    adm_ent_customer_typ * ent_source_customer,
    adm_ent_bank_policy_typ * ent_target_bank_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_account_owned_by_customer(
    adm_ent_account_typ * ent_source_account,
    adm_ent_customer_typ * ent_target_customer,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_customer_owns_account(
    adm_ent_customer_typ * ent_customer,
    adm_rel_customer_owns_account_typ * rel_customer_owns_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_customer_governed_by_bank_policy(
    adm_ent_customer_typ * ent_customer,
    adm_rel_customer_governed_by_bank_policy_typ * rel_customer_governed_by_bank_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_account_owned_by_customer(
    adm_ent_account_typ * ent_account,
    adm_rel_account_owned_by_customer_typ * rel_account_owned_by_customer,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_customer(
    adm_ent_customer_typ * ent_customer,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_account(
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_bank_policy(
    adm_ent_bank_policy_typ * ent_bank_policy,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);


/* Event Sender Prototypes */

void adm_send_event_customer_last_account_closed(
    void * source_object,
    adm_ent_customer_typ * ent_customer,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_customer_new_customer(
    adm_str_name_typ * evd_full_name,
    adm_str_location_typ * evd_address,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_account_make_deposit(
    void * source_object,
    adm_ent_account_typ * ent_account,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_account_account_ok(
    void * source_object,
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_account_withdrawal_submitted(
    void * source_object,
    adm_ent_account_typ * ent_account,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_account_check_submitted(
    void * source_object,
    adm_ent_account_typ * ent_account,
    adm_fxd_money_typ evd_amount,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_account_overdrawn(
    void * source_object,
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_account_close_account(
    void * source_object,
    adm_ent_account_typ * ent_account,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);


/* Dispatcher Prototypes */

void adm_dispatcher_customer         (void);
void adm_dispatch_home_pool_customer (void);

adm_pool_target_customer_typ * adm_find_home_target_event_customer (void);
adm_pool_target_customer_typ * adm_find_away_target_event_customer (void);

void adm_dispatch_state_action_customer(
    adm_pool_target_customer_typ * pool_target_customer);

void adm_dispatcher_account         (void);
void adm_dispatch_home_pool_account (void);

adm_pool_target_account_typ * adm_find_home_target_event_account (void);
adm_pool_target_account_typ * adm_find_away_target_event_account (void);

void adm_dispatch_state_action_account(
    adm_pool_target_account_typ * pool_target_account);


/* State Action Prototypes */

void adm_state_action_customer_accepting_new_customer(
    adm_ent_customer_typ * ent_customer,
    adm_dst_customer_accept_typ * dst_accept);

void adm_state_action_customer_customer_vanishes(
    adm_ent_customer_typ * ent_customer);

void adm_state_action_account_taking_deposit(
    adm_ent_account_typ * ent_account,
    adm_dst_account_transaction_typ * dst_transaction);

void adm_state_action_account_considering_withdrawal(
    adm_ent_account_typ * ent_account,
    adm_dst_account_transaction_typ * dst_transaction);

void adm_state_action_account_considering_check(
    adm_ent_account_typ * ent_account,
    adm_dst_account_transaction_typ * dst_transaction);

void adm_state_action_account_closed(
    adm_ent_account_typ * ent_account);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */