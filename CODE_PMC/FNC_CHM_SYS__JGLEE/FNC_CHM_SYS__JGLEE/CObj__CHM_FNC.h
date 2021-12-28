#pragma once

#include "Interface_Code.h"

#include "CCommon_Error.h"
#include "CCommon_Def.h"


#define  LEAK_CHECK__ITEM_SIZE						7


class CObj__CHM_FNC : public __IOBJ__STD_TYPE
{
private:
	//------------------------------------------------------------
	CString sObject_Name;

	CCommon_Error__USER_FNC mERROR__USER_FNC;

	SCX__USER_LOG_CTRL xLOG_CTRL;
	SCX__TIMER_CTRL	   xI_TIMER;

	int iActive__SIM_MODE;
	//


	//------------------------------------------------------------
	// INTERNAL PROPERTY

	// OBJECT PARAMETER
	CX__VAR_STRING_CTRL	 sCH__OBJ_STATUS;
	CX__VAR_STRING_CTRL	 sCH__OBJ_MSG;
	CX__VAR_STRING_CTRL  sCH__TIMER_COUNT;

	//
	CX__VAR_STRING_CTRL  sCH__CHM_PRESS_STS;
	CX__VAR_STRING_CTRL  sCH__TRANSFER_BALLAST_FLAG;

	CX__VAR_STRING_CTRL  sCH__PARA_XFER_BALLAST_WAIT_SKIP_FLAG;

	//
	CX__VAR_STRING_CTRL  sCH__ACTIVE_VENTING_STATE;

	// PRESSURE PARAMETER
	CX__VAR_DIGITAL_CTRL dCH__CFG_ATM_VENTING_MODE;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_ATM_PRESSURE;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_ATM_VENTING_TIME;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_ATM_VENT_HOLD_DELAY;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_SOFT_VENT_PRESSURE;

	CX__VAR_ANALOG_CTRL	 aCH__CFG_SOFT_PUMP_PRESSURE;
	CX__VAR_DIGITAL_CTRL dCH__CFG_SOFT_PUMP_MODE;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_SOFT_PUMP_DELAY;

	CX__VAR_ANALOG_CTRL	 aCH__CFG_PUMPING_PRESSURE;
	CX__VAR_DIGITAL_CTRL dCH__CFG_SR_OPT_AFTER_SOFT_PUMP;

	CX__VAR_ANALOG_CTRL  aCH__CFG_FORELINE_PUMP_TIMEOUT;

	// PURGE
	CX__VAR_ANALOG_CTRL  aCFG_CH__PURGE_CYCLE_COUNT;
	CX__VAR_ANALOG_CTRL  aCH__PURGE_CURRENT_COUNT;
	CX__VAR_ANALOG_CTRL  aCH__PURGE_UP_PRESSURE;
	CX__VAR_ANALOG_CTRL  aCH__PURGE_DOWN_PRESSURE;

	// LEAK
	CX__VAR_ANALOG_CTRL  aCH__LEAK_CHECK__TIME_MIN;

	CX__VAR_ANALOG_CTRL  aCH__LEAK_CHECK__TIME_COUNT;
	CX__VAR_ANALOG_CTRL  aCH__LEAK_CHECK__OVER_PUMPING_TIME;
	CX__VAR_ANALOG_CTRL  aCH__LEAK_CHECK__STABLE_TIME;

	CX__VAR_DIGITAL_CTRL dCH__LEAK_CHECK__VAT_VLV_POS_MOVING;

	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__DATE_FDC_MONTH;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__START_TIME;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__END_TIME;

	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__BASE_PRESSURE_mTORR;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__START_PRESSURE_mTORR;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__PRESSUREx_mTORR[LEAK_CHECK__ITEM_SIZE];
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__RATEx_mTORR_Per_MIN[LEAK_CHECK__ITEM_SIZE];
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__RESULT_mTORR_Per_MIN;

	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__VAT_MOVE__START_PRESSURE_mTORR;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__VAT_MOVE__RESULT_PRESSURE_mTORR;

	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__LOG_MESSAGE;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__LOG_START_PRESSURE_mTORR;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__LOG_PRESSURE_mTORR;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__LOG_RATE_mTORR_Per_MIN;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__LOG_RESULT_mTORR_Per_MIN;

	CX__VAR_ANALOG_CTRL  aCH__LEAK_CHECK__MAX_PRESSURE_mTORR;
	CX__VAR_ANALOG_CTRL  aCH__LEAK_CHECK__CFG_RESULT_POSTING;

	// TIME-OUT PARAMETER
	CX__VAR_ANALOG_CTRL  aCH__CFG_ATM_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_SOFT_VENT_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_SOFT_PUMP_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_PUMPING_TIMEOUT;

	//
	CX__VAR_ANALOG_CTRL  aCFG_VENT_VAC_SNS_OFF_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_VENT_TO_ATM_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_VENT_TIMEOUT_SOFT_VENT_TO_FAST_VENT;

	//
	CX__VAR_DIGITAL_CTRL dCH__CFG_CHAMBER_BALLAST_ENABLED;

	//
	CX__VAR_ANALOG_CTRL	 aCH__CFG_ADD_PUMP_TIME_SECONDS_FOR_PP;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_ADD_PURGE_TIME_SECONDS_FOR_PP;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_OVER_VENT_TIME;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_PROCESS_MANOMETER_ZERO_OFFSET_LIMIT;

	CX__VAR_ANALOG_CTRL  aCH__CFG_BEFORE_AUTO_LEARNING_DELAY_TIME;

	// CFG : TMP ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_BEFORE_VENT_TURBO_PUMP_OFF;
	CX__VAR_ANALOG_CTRL  aCH__CFG_PUMP_TURBO_STABLE_TIME;
	//


	//------------------------------------------------------------
	// EXTERNAL PROPERTY

	// OBJ - DB_INF ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__SYSTEM_TRANSFER_MODE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__PMC_SLIT_VLV_STS;

	CX__VAR_ANALOG_CTRL  aEXT_CH__CHM_PRESSURE_TORR;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CHM_PRESSURE_mTORR;

	CX__VAR_ANALOG_CTRL  aEXT_CH__PMP_PRESSURE_TORR;
	CX__VAR_STRING_CTRL  sEXT_CH__PMP_PRESSURE_STATE;
	CX__VAR_STRING_CTRL  sEXT_CH__PMP_VAC_SNS;

	// OBJ - DB_SYS ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__CTC_LEAK_CHECK_USE_FLAG;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CTC_LEAK_CHECK_OVER_PUMPING_TIME;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CTC_LEAK_CHECK_STABLE_TIME;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CTC_LEAK_CHECK_TIME_MIN;

	CX__VAR_STRING_CTRL  sEXT_CH__SYSTEM_INTERLOCK_FLAG;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_PMC_ATM_MAINT_FLAG;

	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_CHM_MANOMETER_PRESS_SW1_SETTING;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_CHM_MANOMETER_PRESS_SW2_SETTING;


	// OBJ : PMC LOG ...
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__PMC_LOG;

	CX__VAR_STRING_CTRL  xEXT_CH__PMC_LOG__SUB_DIR;
	CX__VAR_STRING_CTRL  xEXT_CH__PMC_LOG__FILE_NAME;
	CX__VAR_ANALOG_CTRL  xEXT_CH__PMC_LOG__SAMPLING_PERIOD;

	// GAS & VAC VLV ...
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__VAC_VALVE;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__GAS_VALVE;

	// OBJ : ESC
	bool bActive__ESC_OBJ;

	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__ESC;

	// OBJ : TURBO_PUMP
	bool bActive__OBJ_CTRL__TURBO_PUMP;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__TURBO_PUMP;

	CX__VAR_DIGITAL_CTRL dEXT_CH__TURBO_PUMP__POWER_SNS;

	// OBJ : DRY_PUMP
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__DRY_PUMP;

	CX__VAR_DIGITAL_CTRL dEXT_CH__DRY_PUMP__POWER_SNS;

	// Channel Link ...
	bool bActive__CHM_SHUTTER_STATE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CHM_SHUTTER_STATE;

	CX__VAR_DIGITAL_CTRL dEXT_CH__CHM_VAC_SNS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CHM_ATM_SNS;
	//


	//------------------------------------------------------------
	// ...
	CString sMODE__INIT;
	int Call__INIT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	int Fnc__INIT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__ALL_GAS_LINE_CLOSE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__ALL_VAC_LINE_CLOSE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__MAINT;
	int Call__MAINTMODE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__PUMPING;
	CString sMODE__LOW_VAC_PUMP;
	CString sMODE__HIGH_VAC_PUMP;
	int Call__LOW_VAC_PUMP(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__LOW_VAC_PUMP(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm,
		                  const int high_vac_flag,const int purge_flag);

	int Seq__SOFT_LOW_VAC(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm,const int purge_flag);

	//
	CString sMODE__CLOSE_VAC_LINE;
	int Call__CLOSE_VAC_LINE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__VENT;
	int Call__VENT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__VENT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm,const int purge_flag);

	int Seq__SOFT_VENT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm,const int purge_flag);
	int Seq__FAST_VENT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm,const int purge_flag);

	//
	CString sMODE__LEAK_CHECK;
	int Call__LEAK_CHECK(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__LEAK_CHECK(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__LEAK_CHECK__VAT_VLV_POS_MOVE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__PURGE;
	int Call__PURGE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__PURGE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	int Seq__PURGE_VENT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int Seq__PURGE_PUMP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm,const int cycle_count);

	// 
	CString sMODE__CHM_BALLAST_START;
	int Call__CHM_BALLAST_START(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__CHM_BALLAST_START(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__TRANS_BALLAST_START;
	int Call__TRANS_BALLAST_START(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__TRANS_BALLAST_START(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);	

	CString sMODE__BALLAST_END;
	int Call__BALLAST_END(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__BALLAST_END(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	int Fnc__BALLAST_POSITION(CII_OBJECT__VARIABLE *p_variable);
	int Fnc__BALLAST_PRESSURE(CII_OBJECT__VARIABLE *p_variable);

	CString sMODE__APC_AUTO_LEARN;
	int Call__APC_AUTO_LEARN(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__APC_AUTO_LEARN(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);


	// Sub Function .....
	int Fnc__TURBO_PUMP_ON(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	int Fnc__DRY_PUMP_ON(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	int Fnc__PUMP_CTRL(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm,const int mode);

	// Additional Sub Function
	int Seq__LINE_PUMP(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	int Fnc__VENT_COMPLETE(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);


	// MON Function .....
	void Mon__PRESSURE_STATUS(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	//


public:
	CObj__CHM_FNC();
	~CObj__CHM_FNC();

	//-------------------------------------------------------------------------
	int __DEFINE__CONTROL_MODE(obj,l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);
	int __DEFINE__ALARM(p_alarm);

	int __Define__USER_FUNCTION(CII_DEFINE__FUNCTION *p_fnc_ctrl);

	//-------------------------------------------------------------------------
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);

	//------------------------------------------------------------
	int __CALL__CONTROL_MODE(mode,p_debug,p_variable,p_alarm);
	int __CALL__MONITORING(id,p_variable,p_alarm);
};