
// Pip-Boy 3000.h : main header file for the Pip-Boy 3000 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPipBoy3000App:
// See Pip-Boy 3000.cpp for the implementation of this class
//

class CPipBoy3000App : public CWinAppEx
{
public:
	CPipBoy3000App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPipBoy3000App theApp;
