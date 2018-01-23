#pragma once
#include "afxwin.h"


// CEditRow dialog

class CEditRow : public CDialogEx
{
	DECLARE_DYNAMIC(CEditRow)

public:
	CEditRow(CWnd* pParent = NULL);   // standard constructor
	virtual ~CEditRow();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EDIT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_editName;
	CString m_editMajor;
	CString m_editYear;
	CEdit m_editNameControl;
	CEdit m_editMajorControl;
	CEdit m_editYearControl;
	virtual BOOL OnInitDialog();
};
