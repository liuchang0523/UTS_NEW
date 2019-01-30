#include "StdAfx.h"
#include "ImplOperator.h"
#include "UTOP_UVC_EraseEEProm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace UTS
{
	ImplOperator::ImplOperator(void)
	{
		OPERATOR_INIT;
	}

	ImplOperator::~ImplOperator(void)
	{
	}

	BOOL ImplOperator::OnReadSpec()
	{
		CString strSection = OSUtil::GetFileName(m_strModuleFile);
		
		
		return TRUE;
	}

	BOOL ImplOperator::OnTest(BOOL *pbIsRunning, int *pnErrorCode)
	{
		m_TimeCounter.SetStartTime();
		
		LPBYTE lpData = NULL;
		LPBYTE lpDumpData = NULL;
	
		int iResult = -1;
	
		int eepromsize = 8*1024;    //Here 5806 Download EEPROM size is 8*1024;
		int Dumpsize = 0;

		lpData = new BYTE[eepromsize];

		//Erase Eeprom
		memset(lpData, 0xFF, eepromsize);

		if (!m_pDevice->WriteValue(eDeviceWriteValueType::DWVT_LOADFW_EEPROM,
			lpData, eepromsize))
		{
			uts.log.Error(_T("Device WriteValue DWVT_LOADFW_EEPROM Error."));
			*pnErrorCode = uts.errorcode.E_Fail;
		}

		//Read Eeprom
		Dumpsize = 8*1024;
		lpDumpData = new BYTE[Dumpsize];
		memset(lpDumpData, 0x00, (Dumpsize));

		if (!m_pDevice->ReadValue(eDeviceReadValueType::DRVT_DUMPFW_EEPROM,
			lpDumpData, Dumpsize))
		{
			uts.log.Error(_T("Device WriteValue DWVT_LOADFW_EEPROM Error."));
			*pnErrorCode = uts.errorcode.E_Fail;
		}

		for(int i = 0; i< Dumpsize; i++)
		{
			if (lpDumpData[i] != 0xFF )
			{
				*pnErrorCode = uts.errorcode.E_NVMWrite;
			}
		}


		if(lpData)
		{
			delete lpData;
			lpData = NULL;
		}

		if(lpDumpData)
		{
			delete lpDumpData;
			lpDumpData = NULL;
		}

		//------------------------------------------------------------------------------

		// 根据Errorcode设置结果
		m_bResult = (*pnErrorCode == uts.errorcode.E_Pass);

		// 保存数据文件
		SaveData();

		return m_bResult;
	}

	void ImplOperator::OnGetErrorReturnValueList(vector<int> &vecReturnValue)
	{
		vecReturnValue.clear();
		vecReturnValue.push_back(uts.errorcode.E_Fail);
		vecReturnValue.push_back(uts.errorcode.E_NVMWrite);
	}

	void ImplOperator::OnGetRegisterList(vector<CString> &vecRegister)
	{
		vecRegister.clear();
		vecRegister.push_back(m_strOperatorName);
	}


	void ImplOperator::GetDataContent(LPCTSTR lpTime, CString &strHeader, CString &strData, CString &strSFCFilter)
	{
		CString strVersion;
		UTS::OSUtil::GetFileVersion(m_strModuleFile, strVersion);
		CString strResult = (m_bResult ? PASS_STR : FAIL_STR);

		strHeader = _T("Time,SN,TestTime(ms),_Result,")
			
			_T("Version,OP_SN\n");

		strData.Format(
			_T("%s,%s,%.1f,%s,")
	
			_T("%s,%s\n")
			, lpTime, uts.info.strSN, m_TimeCounter.GetPassTime(), strResult
			
			, strVersion, uts.info.strUserId);
	}
	//------------------------------------------------------------------------------
	BaseOperator* GetOperator(void)
	{
		return (new ImplOperator);
	}
	//------------------------------------------------------------------------------
}
