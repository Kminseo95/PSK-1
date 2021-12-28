#include "StdAfx.h"
#include "CObj__TMP_IO.h"
#include "CObj__TMP_IO__ALID.h"


// ...
int CObj__TMP_IO
::Mon__STATE_CHECK(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm)
{
	CString ch_data;

	// Init ...
	{
		sCH__MON_COMM_STATE->Set__DATA(STR__ONLINE);

		dCH__MON_PUMP_ON_SNS->Set__DATA(STR__OFF);
		dCH__MON_ERROR_STATE->Set__DATA(STR__OFF);

		aCH__MON_PUMP_RPM_VALUE->Set__DATA("0");
	}

	double loop_sec = 0.1;
	double cur__err_sec = 0;


	while(1)
	{
		p_variable->Wait__SINGLE_OBJECT(loop_sec);


		// UPDATE.IO ...
		{
			if(bActive__TMP_DI_COMM_STATE)
			{
				dEXT_CH__TMP_DI_COMM_STATE->Get__DATA(ch_data);
				sCH__MON_COMM_STATE->Set__DATA(ch_data);
			}

			if(bActive__TMP_DI_PUMP_STATE)
			{
				ch_data = dEXT_CH__TMP_DI_PUMP_STATE->Get__STRING();
				sCH__MON_PUMP_STATE->Set__DATA(ch_data);

				if((ch_data.CompareNoCase(STR__NORMAL)       == 0)
				|| (ch_data.CompareNoCase(STR__ON)           == 0)
				|| (ch_data.CompareNoCase(STR__ACCELERATION) == 0))
				{
					dCH__MON_PUMP_ON_SNS->Set__DATA(STR__ON);
				}
				else
				{
					dCH__MON_PUMP_ON_SNS->Set__DATA(STR__OFF);
				}
			}

			if(bActive__TMP_DI_ERROR_STATE)
			{
				dEXT_CH__TMP_DI_ERROR_STATE->Get__DATA(ch_data);
				dCH__MON_ERROR_STATE->Set__DATA(ch_data);
			}

			if(bActive__TMP_AI_ROT_RPM)
			{
				aEXT_CH__TMP_AI_ROT_RPM->Get__DATA(ch_data);
				aCH__MON_PUMP_RPM_VALUE->Set__DATA(ch_data);
			}				
		}

		// INTERLOCK.CHECK ...
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

			if(active__err_sns)
			{
				double cfg_sec = aCH__CFG_STOP_ERR_DELAY->Get__VALUE();

				cur__err_sec += loop_sec;
				if(cur__err_sec >= cfg_sec)
				{
					cur__err_sec = 0.0;

					if(dCH__MON_PUMP_ON_SNS->Check__DATA(STR__ON) > 0)
					{
						int alm_id = ALID__FORLINE_PRESSURE_UNSTABLE_ALARM;
						CString alm_msg;
						CString alm_bff;
						CString r_act;

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

						p_alarm->Check__ALARM(alm_id, r_act);
						p_alarm->Post__ALARM_With_MESSAGE(alm_id, alm_msg);

						Call__OFF(p_variable, p_alarm, false);
					}
				}
			}
			else
			{
				cur__err_sec = 0.0;
			}
		}
	}
}
