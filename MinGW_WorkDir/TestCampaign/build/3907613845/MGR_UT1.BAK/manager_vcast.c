/*vcast_header_expansion_start:C:/VCAST/Training/SourceFiles/ctypes.h*/
enum boolean { v_false, v_true };
enum soups { NO_SOUP, ONION, CHOWDER };
enum salads { NO_SALAD, CAESAR, GREEN };
enum entrees { NO_ENTREE, STEAK, CHICKEN, LOBSTER, PASTA };
enum desserts { NO_DESSERT, CAKE, PIE, FRUIT };
enum beverages { NO_BEVERAGE, WINE, BEER, MIXED_DRINK, SODA };
struct order_type
{
  enum soups Soup;
  enum salads Salad;
  enum entrees Entree;
  enum desserts Dessert;
  enum beverages Beverage;
};
typedef unsigned short seat_index_type;
typedef unsigned short table_index_type;
struct table_data_type
{
  enum boolean Is_Occupied;
  seat_index_type Number_In_Party;
  char Designator;
  char Wait_Person[10];
  struct order_type Order[4];
  float Check_Total;
};
typedef char name_type[32];
/*vcast_header_expansion_end*/
#include "c:/vcast/mingw/include/stdio.h"
/*vcast_header_expansion_start:C:/VCAST/Training/SourceFiles/database.h*/
extern int log_tax_receipts( float this_tax_ttl );
extern struct table_data_type Get_Table_Record(table_index_type Table);
extern void Update_Table_Record(table_index_type Table, float check_total, struct table_data_type Data);
/*vcast_header_expansion_end*/
/* Allow 10 Parties to wait */
static name_type WaitingList[10];
static unsigned int WaitingListSize = 0;
static unsigned int WaitingListIndex = 0;
const struct order_type NULL_ORDER =
      {NO_SOUP, NO_SALAD, NO_ENTREE, NO_DESSERT, NO_BEVERAGE};
/*

 *  This function adds in the tax & tip and returns a new check total

 *  It will either use the tax passed in as a user parameter, or it will

 *  use the global variable (default_tax) if it is non-zero.

 *

 */
static int log_err_cnt=0;
static float state_tax = .03;
static float default_tax = .05;
float Add_Tax_Tip( float check_total, float sales_tax, float tip )
{/*vcast_internal_start*/
extern float P_9_1_1;
extern float P_9_1_2;
extern float P_9_1_3;
extern float R_9_1;
extern unsigned char SBF_9_1;
if(SBF_9_1) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_3904200724
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_3904200724
  if ( vcast_is_in_driver ) {
    P_9_1_1 = check_total;
    P_9_1_2 = sales_tax;
    P_9_1_3 = tip;
    vCAST_COMMON_STUB_PROC_9( 9, 1, 4, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_3904200724
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_3904200724
  vCAST_USER_CODE_TIMER_START();
  return R_9_1;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
    float new_total, tax;
    int log_err;
    if (sales_tax > 0)
    {
        tax = sales_tax;
    }
    else if (sales_tax == 0)
    {
        tax = default_tax;
    }
    else
    {
        tax = 0;
    }
    log_err = log_tax_receipts( tax*check_total );
    if (log_err)
    {
        log_err_cnt++;
        printf("\nError in Logging Tax Receipts\n");
    }
    new_total = check_total * (1 + tax + tip);
    return( new_total );
/*vcast_internal_start*/}/*vcast_internal_end*/
}
/* This function will add a free dessert to specific orders based on the 

   entree, salad, and beverage choice. */
int Add_Included_Dessert(struct order_type* Order)
{/*vcast_internal_start*/
extern struct order_type *P_9_2_1;
extern int R_9_2;
extern unsigned char SBF_9_2;
if(SBF_9_2) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_1220426544
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_1220426544
  if ( vcast_is_in_driver ) {
    P_9_2_1 = Order;
    vCAST_COMMON_STUB_PROC_9( 9, 2, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_1220426544
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_1220426544
  vCAST_USER_CODE_TIMER_START();
  return R_9_2;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  int rc;
  rc = 0; //Neither
  if(Order->Entree == STEAK &&
     Order->Salad == CAESAR &&
     Order->Beverage == MIXED_DRINK)
  {
    rc = 1;
    Order->Dessert = PIE;
  }
  else if(Order->Entree == LOBSTER &&
          Order->Salad == GREEN &&
          Order->Beverage == WINE)
  {
    rc = 2;
    Order->Dessert = CAKE;
  }
  return(rc);
/*vcast_internal_start*/}/*vcast_internal_end*/
}
float Place_Order(table_index_type Table,
                seat_index_type Seat,
                struct order_type Order)
{/*vcast_internal_start*/
extern unsigned short P_9_3_1;
extern unsigned short P_9_3_2;
extern struct order_type P_9_3_3;
extern float R_9_3;
extern unsigned char SBF_9_3;
if(SBF_9_3) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_453126248
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_453126248
  if ( vcast_is_in_driver ) {
    P_9_3_1 = Table;
    P_9_3_2 = Seat;
    P_9_3_3 = Order;
    vCAST_COMMON_STUB_PROC_9( 9, 3, 4, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_453126248
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_453126248
  vCAST_USER_CODE_TIMER_START();
  return R_9_3;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  struct table_data_type Table_Data;
  struct table_data_type *Table_Bfr;
  Table_Data = Get_Table_Record(Table);
  Table_Data.Is_Occupied = v_true;
  Table_Data.Number_In_Party = Table_Data.Number_In_Party + 1;
  Table_Data.Order[Seat] = Order;
  /* Add a free dessert in some cases */
  Add_Included_Dessert(&Table_Data.Order[Seat]);
  switch(Order.Entree)
    {
    case NO_ENTREE :
       break;
    case STEAK :
       Table_Data.Check_Total = Table_Data.Check_Total + 14;
       break;
    case CHICKEN :
       Table_Data.Check_Total = Table_Data.Check_Total + 10;
       break;
    case LOBSTER :
       Table_Data.Check_Total = Table_Data.Check_Total + 18;
       break;
    case PASTA :
       Table_Data.Check_Total = Table_Data.Check_Total + 12;
       break;
    default:
       printf( "Invalid Entree: %d", Order.Entree);
       break;
    }
  Update_Table_Record(Table, Table_Data.Check_Total, Table_Data);
  return (Table_Data.Check_Total);
/*vcast_internal_start*/}/*vcast_internal_end*/
}
int Clear_Table(table_index_type Table)
{/*vcast_internal_start*/
extern unsigned short P_9_4_1;
extern int R_9_4;
extern unsigned char SBF_9_4;
if(SBF_9_4) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_2460377677
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_2460377677
  if ( vcast_is_in_driver ) {
    P_9_4_1 = Table;
    vCAST_COMMON_STUB_PROC_9( 9, 4, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_2460377677
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_2460377677
  vCAST_USER_CODE_TIMER_START();
  return R_9_4;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  struct table_data_type Table_Data;
  seat_index_type Seat;
  Table_Data = Get_Table_Record(Table);
  Table_Data.Is_Occupied = v_false;
  Table_Data.Number_In_Party = 1;
  printf("\nClear Table %d\n", Table);
  for (Seat=0; Seat < 4; Seat++)
    Table_Data.Order[Seat] = NULL_ORDER;
    Table_Data.Check_Total = 0;
  Update_Table_Record(Table, 0, Table_Data);
  return 0;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
float Get_Check_Total(table_index_type Table)
{/*vcast_internal_start*/
extern unsigned short P_9_5_1;
extern float R_9_5;
extern unsigned char SBF_9_5;
if(SBF_9_5) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_3462039048
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_3462039048
  if ( vcast_is_in_driver ) {
    P_9_5_1 = Table;
    vCAST_COMMON_STUB_PROC_9( 9, 5, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_3462039048
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_3462039048
  vCAST_USER_CODE_TIMER_START();
  return R_9_5;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  struct table_data_type Table_Data;
  Table_Data = Get_Table_Record(Table);
  return (Table_Data.Check_Total);
/*vcast_internal_start*/}/*vcast_internal_end*/
}
void Add_Party_To_Waiting_List(char* Name)
{/*vcast_internal_start*/
extern char *P_9_6_1;
extern unsigned char SBF_9_6;
if(SBF_9_6) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_1361818386
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_1361818386
  if ( vcast_is_in_driver ) {
    P_9_6_1 = Name;
    vCAST_COMMON_STUB_PROC_9( 9, 6, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_1361818386
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_1361818386
  vCAST_USER_CODE_TIMER_START();
  return;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  int i = 0;
  if(WaitingListSize > 9)
    WaitingListSize = 0;
  while(Name && *Name) {
    WaitingList[WaitingListSize][i++] = *Name;
    Name++;
  }
  WaitingList[WaitingListSize++][i] = 0;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
char* Get_Next_Party_To_Be_Seated(void)
{/*vcast_internal_start*/
extern char *R_9_7;
extern unsigned char SBF_9_7;
if(SBF_9_7) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_11444024
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_11444024
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 9, 7, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_11444024
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_11444024
  vCAST_USER_CODE_TIMER_START();
  return R_9_7;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  if(WaitingListIndex > 9)
    WaitingListIndex = 0;
  return WaitingList[WaitingListIndex++];
/*vcast_internal_start*/}/*vcast_internal_end*/
}
/*vcast_internal_start*/
float P_9_1_1;
float P_9_1_2;
float P_9_1_3;
float R_9_1;
unsigned char SBF_9_1 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/
struct order_type *P_9_2_1;
int R_9_2;
unsigned char SBF_9_2 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/
unsigned short P_9_3_1;
unsigned short P_9_3_2;
struct order_type P_9_3_3;
float R_9_3;
unsigned char SBF_9_3 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/
unsigned short P_9_4_1;
int R_9_4;
unsigned char SBF_9_4 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/
unsigned short P_9_5_1;
float R_9_5;
unsigned char SBF_9_5 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/
char *P_9_6_1;
unsigned char SBF_9_6 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/
char *R_9_7;
unsigned char SBF_9_7 = 0;
/*vcast_internal_end*/
