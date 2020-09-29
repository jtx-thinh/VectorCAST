#ifndef VCAST_NEVER_STUB_EXTERNS
/* Begin defined extern variables */
/* End defined extern variables */
/* Begin defined static member variables */
/* End defined static member variables */
#endif /*VCAST_NEVER_STUB_EXTERNS*/
/* BEGIN PROTOTYPE STUBS */
float P_10_1_1;
int R_10_1;
int log_tax_receipts(float this_tax_ttl)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_623825082
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_623825082
  if ( vcast_is_in_driver ) {
    P_10_1_1 = this_tax_ttl;
    vCAST_COMMON_STUB_PROC_9( 10, 1, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_623825082
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_623825082
  vCAST_USER_CODE_TIMER_START();
  return R_10_1;
}


unsigned short P_10_2_1;
struct table_data_type R_10_2;
struct table_data_type Get_Table_Record(table_index_type Table)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_840098395
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_840098395
  if ( vcast_is_in_driver ) {
    P_10_2_1 = Table;
    vCAST_COMMON_STUB_PROC_9( 10, 2, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_840098395
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_840098395
  vCAST_USER_CODE_TIMER_START();
  return R_10_2;
}


unsigned short P_10_3_1;
float P_10_3_2;
struct table_data_type P_10_3_3;
void Update_Table_Record(table_index_type Table, float check_total, struct table_data_type Data)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_4016985428
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_4016985428
  if ( vcast_is_in_driver ) {
    P_10_3_1 = Table;
    P_10_3_2 = check_total;
    P_10_3_3 = Data;
    vCAST_COMMON_STUB_PROC_9( 10, 3, 4, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_4016985428
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_4016985428
  vCAST_USER_CODE_TIMER_START();
  return;
}


/* END PROTOTYPE STUBS */
