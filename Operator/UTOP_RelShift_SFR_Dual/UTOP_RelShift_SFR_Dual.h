// UTOP_RelShift_SFR_Dual.h : UTOP_RelShift_SFR_Dual DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_RelShift_SFR_DualApp
// �o�����O����@�аѾ\ UTOP_RelShift_SFR_Dual.cpp
//

class CUTOP_RelShift_SFR_DualApp : public CWinApp
{
public:
	CUTOP_RelShift_SFR_DualApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_RelShift_SFR_DualApp theApp;