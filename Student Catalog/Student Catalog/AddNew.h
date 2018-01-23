#pragma once


// CAddNew dialog

class CAddNew : public CDialog
{
	DECLARE_DYNAMIC(CAddNew)

public:
	CAddNew(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAddNew();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_newStudentName;
	CString m_newStudentMajor;
	CString m_newStudentYear;
};
