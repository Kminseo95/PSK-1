#pragma once

#include "Interface_Code.h"

#include "CCommon_Error.h"
#include "CCommon_Def.h"


class CObj__TMP_IO : public __IOBJ__STD_TYPE
{
private:
	//-------------------------------------------------------------------------
	CString	sObject_Name;

	// ...
	SCX__USER_LOG_CTRL xI_LOG_CTRL;
	//

	//-------------------------------------------------------------------------
	// OBJ ...
	CX__VAR_STRING_CTRL   sCH__OBJ_MSG;
	CX__VAR_STRING_CTRL   sCH__OBJ_STATUS;

	// MON ...
	CX__VAR_STRING_CTRL   sCH__MON_COMM_STATE;
	CX__VAR_DIGITAL_CTRL  dCH__MON_PUMP_ON_SNS;
	CX__VAR_DIGITAL_CTRL  dCH__MON_ERROR_STATE;
	CX__VAR_STRING_CTRL   sCH__MON_PUMP_STATE;
	CX__VAR_ANALOG_CTRL   aCH__MON_PUMP_RPM_VALUE;

	// CFG ...
	CX__VAR_ANALOG_CTRL   aCH__CFG_STOP_ERR_DELAY;
	CX__VAR_ANALOG_CTRL   aCH__CFG_TURBO_EXHAUST_VALVE_CLOSE_DELAY;
	CX__VAR_ANALOG_CTRL   aCH__CFG_TURBO_N2_PURGE_CLOSE_DELAY;
	//
	
	//-------------------------------------------------------------------------
	// TMP.OBJ ...
	CII_EXT_OBJECT__CTRL  *pOBJ_CTRL__TMP;

	CString sTMP_MODE__START;
	CString sTMP_MODE__STOP;
	CString sTMP_MODE__STOP_NO_WAIT;

	// TMP.IO ...
	bool bActive__TMP_DI_COMM_STATE;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__TMP_DI_COMM_STATE;

	bool bActive__TMP_DI_PUMP_STATE;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__TMP_DI_PUMP_STATE;

	bool bActive__TMP_DI_ERROR_STATE;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__TMP_DI_ERROR_STATE;

	bool bActive__TMP_AI_ROT_RPM;
	CX__VAR_ANALOG_CTRL	  aEXT_CH__TMP_AI_ROT_RPM;

	// VAT ...
	CII_EXT_OBJECT__CTRL  *pOBJ_CTRL__VAT;

	// IO ...
	bool bActive__DI_FORELINE_VAC_SNS;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__DI_FORELINE_VAC_SNS;

	bool bActive__DI_DRY_PUMP_ON;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__DI_DRY_PUMP_ON;

	bool bActive__DO_TMP_EXHAUST_VALVE;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__DO_TMP_EXHAUST_VALVE;

	bool bActive__DO_TMP_N2_VALVE;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__DO_TMP_N2_VALVE;
	//

	//-------------------------------------------------------------------------
	CString sMODE__INIT;
	int Call__INIT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__FULL_CLOSE;
	int Call__FULL_CLOSE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__FULL_OPEN;
	int Call__FULL_OPEN(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__EXHAUST_OPEN;
	int Call__EXHAUST_OPEN(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__EXHAUST_CLOSE;
	int Call__EXHAUST_CLOSE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__ON;
	int Call__ON(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__OFF;
	CString sMODE__OFF_NO_WAIT;
	int Call__OFF(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm, const bool active__no_wait);
	//

	// ...
	int Mon__STATE_CHECK(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	//


public:
	CObj__TMP_IO();
	~CObj__TMP_IO();

	//-------------------------------------------------------------------------
	int __DEFINE__CONTROL_MODE(obj,l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);
	int __DEFINE__ALARM(p_alarm);

	//-------------------------------------------------------------------------
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);

	//-------------------------------------------------------------------------
	int __CALL__CONTROL_MODE(mode,p_debug,p_variable,p_alarm);
	int __CALL__MONITORING(id,p_variable,p_alarm);
};