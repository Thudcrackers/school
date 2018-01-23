
// Sierpinski.h : main header file for the Sierpinski application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSierpinskiApp:
// See Sierpinski.cpp for the implementation of this class
//

class CSierpinskiApp : public CWinApp
{
public:
	CSierpinskiApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSierpinskiApp theApp;
