-- VectorCAST 19.sp4 (01/07/20)
-- Test Case Script
-- 
-- Environment    : MATH
-- Unit(s) Under Test: math
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

-- Unit: math

-- Subprogram: Divide

-- Test Case: Divide.001
TEST.UNIT:math
TEST.SUBPROGRAM:Divide
TEST.NEW
TEST.NAME:Divide.001
TEST.FLOATING_POINT_TOLERANCE:0.0405%
TEST.VALUE:math.Divide.x:22.0
TEST.VALUE:math.Divide.y:7.0
TEST.EXPECTED:math.<<GLOBAL>>.g_result:3.14+/-.01
TEST.EXPECTED:math.Divide.return:Pi
TEST.END
