
// Student Catalog.h : main header file for the Student Catalog application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CStudentCatalogApp:
// See Student Catalog.cpp for the implementation of this class
//

class CStudentCatalogApp : public CWinApp
{
public:
	CStudentCatalogApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CStudentCatalogApp theApp;
