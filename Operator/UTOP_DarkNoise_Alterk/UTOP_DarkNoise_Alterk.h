// UTOP_DarkNoise_Alterk.h : UTOP_DarkNoise_Alterk DLL 的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"		// 主要符號


// CUTOP_DarkNoise_AlterkApp
// 這個類別的實作請參閱 UTOP_DarkNoise_Alterk.cpp
//

class CUTOP_DarkNoise_AlterkApp : public CWinApp
{
public:
	CUTOP_DarkNoise_AlterkApp();

// 覆寫
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_DarkNoise_AlterkApp theApp;