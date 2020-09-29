-- VectorCAST 19.sp4 (01/07/20)
-- Test Case Script
-- 
-- Environment    : MGR_UT1
-- Unit(s) Under Test: manager
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STANDARD_SPACING_R2
TEST.SCRIPT_FEATURE:OVERLOADED_CONST_SUPPORT
TEST.SCRIPT_FEATURE:UNDERSCORE_NULLPTR
TEST.SCRIPT_FEATURE:FULL_PARAMETER_TYPES
TEST.SCRIPT_FEATURE:STRUCT_DTOR_ADDS_POINTER
TEST.SCRIPT_FEATURE:STRUCT_FIELD_CTOR_ADDS_POINTER
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
TEST.SCRIPT_FEATURE:VCAST_MAIN_NOT_RENAMED
--

-- Unit: manager

-- Subprogram: Add_Included_Dessert

-- Test Case: PIE_ORDER
TEST.UNIT:manager
TEST.SUBPROGRAM:Add_Included_Dessert
TEST.NEW
TEST.NAME:PIE_ORDER
TEST.VALUE:manager.Add_Included_Dessert.Order:<<malloc 1>>
TEST.VALUE:manager.Add_Included_Dessert.Order[0].Salad:CAESAR
TEST.VALUE:manager.Add_Included_Dessert.Order[0].Entree:STEAK
TEST.VALUE:manager.Add_Included_Dessert.Order[0].Dessert:CAKE
TEST.VALUE:manager.Add_Included_Dessert.Order[0].Beverage:MIXED_DRINK
TEST.EXPECTED:manager.Add_Included_Dessert.Order[0].Dessert:PIE
TEST.EXPECTED:manager.Add_Included_Dessert.return:1
TEST.END

-- Subprogram: Add_Party_To_Waiting_List

-- Test Case: Add_Party_To_Waiting_List.001
TEST.UNIT:manager
TEST.SUBPROGRAM:Add_Party_To_Waiting_List
TEST.NEW
TEST.NAME:Add_Party_To_Waiting_List.001
TEST.VALUE:manager.Add_Party_To_Waiting_List.Name:<<malloc 4>>
TEST.VALUE:manager.Add_Party_To_Waiting_List.Name:"Tom"
TEST.EXPECTED:manager.<<GLOBAL>>.WaitingList[0]:"Tom"
TEST.END

-- Test Case: Add_Party_To_Waiting_List.002
TEST.UNIT:manager
TEST.SUBPROGRAM:Add_Party_To_Waiting_List
TEST.NEW
TEST.NAME:Add_Party_To_Waiting_List.002
TEST.VALUE:manager.Add_Party_To_Waiting_List.Name:<<malloc 4>>
TEST.VALUE:manager.Add_Party_To_Waiting_List.Name[0]:'T'
TEST.VALUE:manager.Add_Party_To_Waiting_List.Name[1]:'i'
TEST.VALUE:manager.Add_Party_To_Waiting_List.Name[2]:'m'
TEST.VALUE:manager.Add_Party_To_Waiting_List.Name[3]:8#0#
TEST.EXPECTED:manager.<<GLOBAL>>.WaitingList[0]:"Tim"
TEST.END

-- Test Case: Add_Party_To_Waiting_List.003
TEST.UNIT:manager
TEST.SUBPROGRAM:Add_Party_To_Waiting_List
TEST.NEW
TEST.NAME:Add_Party_To_Waiting_List.003
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[0]:<<malloc 5>>
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[0]:"John"
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[1]:<<malloc 5>>
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[1]:"John"
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[2]:<<malloc 5>>
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[2]:"John"
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[3]:<<malloc 5>>
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[3]:"John"
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[4]:<<malloc 5>>
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[4]:"John"
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[5]:<<malloc 5>>
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[5]:"John"
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[6]:<<malloc 5>>
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[6]:"John"
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[7]:<<malloc 5>>
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[7]:"John"
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[8]:<<malloc 5>>
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[8]:"John"
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[9]:<<malloc 5>>
TEST.VALUE:manager.<<GLOBAL>>.WaitingList[9]:"John"
TEST.VALUE:manager.Add_Party_To_Waiting_List.Name:<<malloc 4>>
TEST.VALUE:manager.Add_Party_To_Waiting_List.Name[0]:'T'
TEST.VALUE:manager.Add_Party_To_Waiting_List.Name[1]:'i'
TEST.VALUE:manager.Add_Party_To_Waiting_List.Name[2]:'m'
TEST.VALUE:manager.Add_Party_To_Waiting_List.Name[3]:8#0#
TEST.END

-- Subprogram: Add_Tax_Tip

-- Test Case: Normal
TEST.UNIT:manager
TEST.SUBPROGRAM:Add_Tax_Tip
TEST.NEW
TEST.NAME:Normal
TEST.VALUE:manager.Add_Tax_Tip.check_total:10.0
TEST.VALUE:manager.Add_Tax_Tip.sales_tax:0.05
TEST.VALUE:manager.Add_Tax_Tip.tip:0.15
TEST.EXPECTED:manager.Add_Tax_Tip.return:12.0
TEST.END

-- Test Case: TenPercentTax
TEST.UNIT:manager
TEST.SUBPROGRAM:Add_Tax_Tip
TEST.NEW
TEST.NAME:TenPercentTax
TEST.VALUE:manager.<<GLOBAL>>.default_tax:0.10
TEST.VALUE:manager.Add_Tax_Tip.check_total:10.0
TEST.VALUE:manager.Add_Tax_Tip.sales_tax:0.0
TEST.VALUE:manager.Add_Tax_Tip.tip:0.0
TEST.EXPECTED:manager.<<GLOBAL>>.log_err_cnt:0
TEST.EXPECTED:manager.<<GLOBAL>>.default_tax:0.10
TEST.EXPECTED:manager.Add_Tax_Tip.return:11.0
TEST.END

-- Subprogram: Place_Order

-- Test Case: TEST3
TEST.UNIT:manager
TEST.SUBPROGRAM:Place_Order
TEST.NEW
TEST.NAME:TEST3
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:TRUE
TEST.VALUE:<<OPTIONS>>.EVENT_LIMIT:10
TEST.VALUE:manager.Place_Order.Table:VARY FROM:0 TO:5 BY: 1
TEST.VALUE:manager.Place_Order.Seat:VARY FROM:0 TO:3 BY: 1
TEST.VALUE:manager.Place_Order.Order.Entree:CHICKEN
TEST.END

-- Test Case: TEST4
TEST.UNIT:manager
TEST.SUBPROGRAM:Place_Order
TEST.NEW
TEST.NAME:TEST4
TEST.VALUE:<<OPTIONS>>.GLOBAL_DATA_DISPLAY:EACH_EVENT
TEST.VALUE:manager.<<GLOBAL>>.WaitingListSize:1
TEST.VALUE:manager.Place_Order.Table:1
TEST.VALUE:manager.Place_Order.Seat:2
TEST.EXPECTED:manager.<<GLOBAL>>.WaitingListSize:1
TEST.END
