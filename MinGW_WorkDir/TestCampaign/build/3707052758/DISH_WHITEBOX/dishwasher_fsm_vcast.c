/*

 *  This module simulates the control of a simple dishwasher appliacance, by using

 *  a Finite State Machine (FSM).  The states are pretty simple, going from IDLE through

 *  the normal WASH-RINSE-DRY cycles.  These states are defined in the enumerator

 *  "t_machine_state".  The events that can occur are defined below by "t_event".

 *

 */
enum eventValues {
    EVENT_START_WASH,
    EVENT_START_RINSE,
    EVENT_START_DRY,
    EVENT_STOP,
};
typedef enum eventValues t_event;
enum stateValues {
    STATE_IDLE,
    STATE_WASHING,
    STATE_RINSING,
    STATE_DRYING,
} ;
typedef enum stateValues t_machine_state;
//
//  Error Status Codes
//
enum e_status {
    STS_ALL_GOOD,
    STS_NO_POWER,
    STS_UNEXPECTED_EVENT,
    STS_NO_HEAT,
    STS_GENERAL_ERROR
    };
typedef enum e_status t_status;
// Module Level Global Data:
static t_machine_state currentState = STATE_IDLE;
static int powerOn = 0;
//
//  Not implemented yet.  Return All Good for now.
//
static t_status checkHeatingElement( void )
{/*vcast_internal_start*/
extern enum e_status R_9_1;
extern unsigned char SBF_9_1;
if(SBF_9_1) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_94123813
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_94123813
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 9, 1, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_94123813
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_94123813
  vCAST_USER_CODE_TIMER_START();
  return R_9_1;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
    return( STS_ALL_GOOD );
/*vcast_internal_start*/}/*vcast_internal_end*/
}
/*

 *  Process events while in the IDLE State/Cycle

 */
static t_status processIdleState (t_event event) {/*vcast_internal_start*/
extern enum eventValues P_9_2_1;
extern enum e_status R_9_2;
extern unsigned char SBF_9_2;
if(SBF_9_2) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_2834802376
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_2834802376
  if ( vcast_is_in_driver ) {
    P_9_2_1 = event;
    vCAST_COMMON_STUB_PROC_9( 9, 2, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_2834802376
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_2834802376
  vCAST_USER_CODE_TIMER_START();
  return R_9_2;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
    t_status sts;
    switch (event)
    {
        case EVENT_START_WASH:
            if (powerOn)
            {
                sts = STS_ALL_GOOD;
                currentState = STATE_WASHING; // Go to Wash Cycle
            }
            else
                sts = STS_NO_POWER;
            break;
        case EVENT_STOP:
            sts = STS_ALL_GOOD; // Stopping while Idle is okay.  Just stay in Idle state.
            break;
        default: //  Anything else that comes in is invalid.
            sts = STS_UNEXPECTED_EVENT;
            break;
    }
   return sts;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
/*

 *  Process events while during the WASH Cycle.

 */
static t_status processWashCycle (t_event event)
{/*vcast_internal_start*/
extern enum eventValues P_9_3_1;
extern enum e_status R_9_3;
extern unsigned char SBF_9_3;
if(SBF_9_3) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_3121139166
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_3121139166
  if ( vcast_is_in_driver ) {
    P_9_3_1 = event;
    vCAST_COMMON_STUB_PROC_9( 9, 3, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_3121139166
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_3121139166
  vCAST_USER_CODE_TIMER_START();
  return R_9_3;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
    t_status sts;
    switch (event)
    {
        case EVENT_START_RINSE:
            if (powerOn)
            {
                sts = STS_ALL_GOOD;
                currentState = STATE_RINSING; // Go to Rinse Cycle
            }
            else
                sts = STS_NO_POWER;
            break;
        case EVENT_STOP:
            sts = STS_ALL_GOOD;
            currentState = STATE_IDLE; // Go back to the Idle State
            break;
        default: //  Anything else that comes in is invalid.
            sts = STS_UNEXPECTED_EVENT;
            break;
    }
   return sts;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
static t_status processRinseCycle (t_event event)
{/*vcast_internal_start*/
extern enum eventValues P_9_4_1;
extern enum e_status R_9_4;
extern unsigned char SBF_9_4;
if(SBF_9_4) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_2395145557
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_2395145557
  if ( vcast_is_in_driver ) {
    P_9_4_1 = event;
    vCAST_COMMON_STUB_PROC_9( 9, 4, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_2395145557
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_2395145557
  vCAST_USER_CODE_TIMER_START();
  return R_9_4;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
    t_status sts;
    switch (event)
    {
        case EVENT_START_DRY:
            if (powerOn)
            {
                sts = checkHeatingElement();
                if (sts == STS_ALL_GOOD)
                    currentState = STATE_DRYING;
                else
                    currentState = STATE_IDLE; // Go back to the Idle State
            }
            else
                sts = STS_NO_POWER;
            break;
        case EVENT_STOP:
            sts = STS_ALL_GOOD;
            currentState = STATE_IDLE; // Go back to the Idle State
            break;
        default: //  Anything else that comes in is invalid.
            sts = STS_UNEXPECTED_EVENT;
            break;
    }
   return sts;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
static t_status processDryCycle (t_event event) {/*vcast_internal_start*/
extern enum eventValues P_9_5_1;
extern enum e_status R_9_5;
extern unsigned char SBF_9_5;
if(SBF_9_5) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_343587927
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_343587927
  if ( vcast_is_in_driver ) {
    P_9_5_1 = event;
    vCAST_COMMON_STUB_PROC_9( 9, 5, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_343587927
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_343587927
  vCAST_USER_CODE_TIMER_START();
  return R_9_5;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
    t_status sts;
    switch (event)
    {
        case EVENT_STOP:
            sts = STS_ALL_GOOD;
            currentState = STATE_IDLE; // Go back to the Idle State
            break;
        default: //  Anything else that comes in is invalid.
            sts = STS_UNEXPECTED_EVENT;
            break;
    }
   return sts;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
//  These functions will be called to bring the dishwasher in and out of low-power mode.
//  None of the Dishwasher cycles should be performed until power is applied.
t_status applyPower ()
{/*vcast_internal_start*/
extern enum e_status R_9_6;
extern unsigned char SBF_9_6;
if(SBF_9_6) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_1292826204
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_1292826204
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 9, 6, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_1292826204
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_1292826204
  vCAST_USER_CODE_TIMER_START();
  return R_9_6;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
   if (currentState == STATE_IDLE)
   {
      powerOn = 1;
      return (STS_ALL_GOOD);
   }
   else
   {
      return (STS_GENERAL_ERROR);
   }
/*vcast_internal_start*/}/*vcast_internal_end*/
}
t_status turnOffPower ()
{/*vcast_internal_start*/
extern enum e_status R_9_7;
extern unsigned char SBF_9_7;
if(SBF_9_7) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_3756921254
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_3756921254
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 9, 7, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_3756921254
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_3756921254
  vCAST_USER_CODE_TIMER_START();
  return R_9_7;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
   if (currentState == STATE_IDLE)
   {
      powerOn = 0;
      return (STS_ALL_GOOD);
   }
   else
   {
      return (STS_GENERAL_ERROR);
   }
/*vcast_internal_start*/}/*vcast_internal_end*/
}
//
//  This function is the main entry point into the Dishwasher Finite State Machine.  This function will pass the incoming event
//  to the corresponding handler routine based on the current state of the machine.
//
t_status EventHandler (t_event event) {/*vcast_internal_start*/
extern enum eventValues P_9_8_1;
extern enum e_status R_9_8;
extern unsigned char SBF_9_8;
if(SBF_9_8) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_2410768248
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_2410768248
  if ( vcast_is_in_driver ) {
    P_9_8_1 = event;
    vCAST_COMMON_STUB_PROC_9( 9, 8, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_2410768248
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_2410768248
  vCAST_USER_CODE_TIMER_START();
  return R_9_8;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
   t_status ret_sts;
    switch (currentState)
    {
        case STATE_IDLE :
            ret_sts = processIdleState (event);
            break;
        case STATE_WASHING :
            ret_sts = processWashCycle (event);
            break;
        case STATE_RINSING :
            ret_sts = processRinseCycle (event);
            break;
        case STATE_DRYING :
            ret_sts = processDryCycle (event);
            break;
        default :
            ret_sts = STS_GENERAL_ERROR; // Invalid State.  Should never happen.
            break;
    }
   return ret_sts;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
/*vcast_internal_start*/
enum e_status R_9_1;
unsigned char SBF_9_1 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/
enum eventValues P_9_2_1;
enum e_status R_9_2;
unsigned char SBF_9_2 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/
enum eventValues P_9_3_1;
enum e_status R_9_3;
unsigned char SBF_9_3 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/
enum eventValues P_9_4_1;
enum e_status R_9_4;
unsigned char SBF_9_4 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/
enum eventValues P_9_5_1;
enum e_status R_9_5;
unsigned char SBF_9_5 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/
enum e_status R_9_6;
unsigned char SBF_9_6 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/
enum e_status R_9_7;
unsigned char SBF_9_7 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/
enum eventValues P_9_8_1;
enum e_status R_9_8;
unsigned char SBF_9_8 = 0;
/*vcast_internal_end*/
