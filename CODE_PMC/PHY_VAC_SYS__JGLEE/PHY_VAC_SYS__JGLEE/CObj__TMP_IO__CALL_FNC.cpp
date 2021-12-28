#include "StdAfx.h"
#include "CObj__TMP_IO.h"
#include "CObj__TMP_IO__ALID.h"


// ...
#define CMMD__INIT				"INIT"
#define CMMD__ON				"ON"
#define CMMD__OFF				"OFF"

// ...
#define CMMD_VAT__CLOSE			"CLOSE"
#define CMMD_VAT__OPEN			"OPEN"


// ...
int CObj__TMP_IO
::Call__INIT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm)
{

	return 1;
}

int CObj__TMP_IO
::Call__FULL_CLOSE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm)
{
	if(pOBJ_CTRL__VAT->Call__OBJECT(CMMD_VAT__CLOSE) < 0)
	{
		return -1;
	}

	Sleep(990);

	if(bActive__DO_TMP_N2_VALVE)			dEXT_CH__DO_TMP_N2_VALVE->Set__DATA(STR__CLOSE);
	if(bActive__DO_TMP_EXHAUST_VALVE)		dEXT_CH__DO_TMP_EXHAUST_VALVE->Set__DATA(STR__CLOSE);

	return 1;
}
int CObj__TMP_IO
::Call__FULL_OPEN(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm)
{
	bool active__err_sns = false;

	if(bActive__DI_FORELINE_VAC_SNS)
	{
		if(dEXT_CH__DI_FORELINE_VAC_SNS->Check__DATA(STR__ON) < 0)			active__err_sns = true;
	}
	if(bActive__DI_DRY_PUMP_ON)
	{
		if(dEXT_CH__DI_DRY_PUMP_ON->Check__DATA(STR__ON) < 0)				active__err_sns = true;
	}

	if(dCH__MON_PUMP_ON_SNS->Check__DATA(STR__ON) < 0)
	{
		active__err_sns = true;
	}

	if(active__err_sns)
	{
		int alarm_id = ALID__PUMP_STATE_ERROR;
		CString alm_msg;
		CString alm_bff;
		CString r_act;

		// ...
		{
			alm_bff.Format(" * %s <- %s \n", 
							sCH__MON_PUMP_STATE->Get__CHANNEL_NAME(),
							sCH__MON_PUMP_STATE->Get__STRING());
			alm_msg += alm_bff;

			alm_bff.Format(" * %s <- %s \n", 
							dCH__MON_PUMP_ON_SNS->Get__CHANNEL_NAME(),
							dCH__MON_PUMP_ON_SNS->Get__STRING());
			alm_msg += alm_bff;
		}

		if(bActive__DI_FORELINE_VAC_SNS)
		{
			alm_bff.Format(" * %s <- %s \n", 
							dEXT_CH__DI_FORELINE_VAC_SNS->Get__CHANNEL_NAME(),
							dEXT_CH__DI_FORELINE_VAC_SNS->Get__STRING());
			alm_msg += alm_bff;
		}
		if(bActive__DI_DRY_PUMP_ON)
		{
			alm_bff.Format(" * %s <- %s \n", 
							dEXT_CH__DI_DRY_PUMP_ON->Get__CHANNEL_NAME(),
							dEXT_CH__DI_DRY_PUMP_ON->Get__STRING());
			alm_msg += alm_bff;
		}

		p_alarm->Check__ALARM(alarm_id, r_act);
		p_alarm->Post__ALARM(alarm_id);
		return -11;
	}

	// ...
	bool active__delay_check = false;

	if(dEXT_CH__DO_TMP_N2_VALVE->Check__DATA(STR__OPEN) < 0)
	{
		dEXT_CH__DO_TMP_N2_VALVE->Set__DATA(STR__OPEN);

		active__delay_check = true;
	}
	if(dEXT_CH__DO_TMP_EXHAUST_VALVE->Check__DATA(STR__OPEN) < 0)
	{
		dEXT_CH__DO_TMP_EXHAUST_VALVE->Set__DATA(STR__OPEN);

		active__delay_check = true;
	}

	if(active__delay_check)
	{
		Sleep(990);
	}

	if(pOBJ_CTRL__VAT->Call__OBJECT(CMMD_VAT__OPEN) < 0)
	{
		return -21;
	}
	return 1;
}

int CObj__TMP_IO
::Call__EXHAUST_CLOSE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm)
{
	if(bActive__DO_TMP_EXHAUST_VALVE)
		return dEXT_CH__DO_TMP_EXHAUST_VALVE->Set__DATA(STR__CLOSE);

	return 1;
}
int CObj__TMP_IO
::Call__EXHAUST_OPEN(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm)
{
	if(bActive__DO_TMP_N2_VALVE)
		dEXT_CH__DO_TMP_N2_VALVE->Set__DATA(STR__OPEN);

	if(bActive__DO_TMP_EXHAUST_VALVE)
		return dEXT_CH__DO_TMP_EXHAUST_VALVE->Set__DATA(STR__OPEN);

	return 1;
}

int CObj__TMP_IO
::Call__ON(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm)
{
	// Dry Pumps Check ...
	if(bActive__DI_DRY_PUMP_ON)
	{
		if(dEXT_CH__DI_DRY_PUMP_ON->Check__DATA(STR__ON) < 0)
		{
			// Alarm ...
			{
				int alm_id = ALID__TMP_ON_ERROR;
				CString alm_msg;
				CString r_act;

				alm_msg.Format(" * %s <- %s \n",
								dEXT_CH__DI_DRY_PUMP_ON->Get__CHANNEL_NAME(),
								dEXT_CH__DI_DRY_PUMP_ON->Get__STRING());

				p_alarm->Check__ALARM(alm_id, r_act);
				p_alarm->Post__ALARM_With_MESSAGE(alm_id, alm_msg);
			}
			return -11;
		}
	}

	// Foreline Pressure Check ...
	if(bActive__DI_FORELINE_VAC_SNS)
	{
		if(dEXT_CH__DI_FORELINE_VAC_SNS->Check__DATA(STR__ON) < 0)
		{
			// Alarm ...
			{
				int alm_id = ALID__TMP_ON_ERROR;
				CString alm_msg;
				CString r_act;

				alm_msg.Format(" * %s <- %s \n",
								dEXT_CH__DI_FORELINE_VAC_SNS->Get__CHANNEL_NAME(),
								dEXT_CH__DI_FORELINE_VAC_SNS->Get__STRING());

				p_alarm->Check__ALARM(alm_id, r_act);
				p_alarm->Post__ALARM_With_MESSAGE(alm_id, alm_msg);
			}
			return -21;
		}
	}

	if(pOBJ_CTRL__TMP->Call__OBJECT(sTMP_MODE__START) < 0)
	{
		return -1;
	}
	return 1;
}
int CObj__TMP_IO
::Call__OFF(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm, const bool active__no_wait)
{
	SCX__TIMER_CTRL x_timer;
	x_timer->REGISTER__ABORT_OBJECT(sObject_Name);

	// TMP N2 Purge Valve Close ...
	if(bActive__DO_TMP_N2_VALVE)
	{
		dEXT_CH__DO_TMP_N2_VALVE->Set__DATA(STR__CLOSE);

		double cfg_sec = aCH__CFG_TURBO_N2_PURGE_CLOSE_DELAY->Get__VALUE();
		if(x_timer->WAIT(cfg_sec) < 0)		return -11;
	}

	// TMP Exhaust Valve Close ...
	if(bActive__DO_TMP_EXHAUST_VALVE)
	{
		dEXT_CH__DO_TMP_EXHAUST_VALVE->Set__DATA(STR__CLOSE);

		double cfg_sec = aCH__CFG_TURBO_EXHAUST_VALVE_CLOSE_DELAY->Get__VALUE();
		if(x_timer->WAIT(cfg_sec) < 0)		return -21;
	}

	if(active__no_wait)
	{
		if(pOBJ_CTRL__TMP->Run__OBJECT(sTMP_MODE__STOP_NO_WAIT) < 0)
		{
			return -1;
		}
	}
	else
	{
		if(pOBJ_CTRL__TMP->Call__OBJECT(sTMP_MODE__STOP) < 0)
		{
			return -2;
		}
	}
	return 1;
}