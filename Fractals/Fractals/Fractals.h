
// Fractals.h : main header file for the Fractals application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFractalsApp:
// See Fractals.cpp for the implementation of this class
//

class CFractalsApp : public CWinApp
{
public:
	CFractalsApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFractalsApp theApp;
