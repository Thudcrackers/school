
// F to C ConverterDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CFtoCConverterDlg dialog
class CFtoCConverterDlg : public CDialogEx
{
// Construction
public:
	CFtoCConverterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FTOCCONVERTER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeFahrenheit();
	CEdit m_CelsiusEdit;
	CEdit m_FahrenheitEdit;
	afx_msg void OnEnChangeCelsius2();
	CEdit m_CelsiusInput;
	CEdit m_FahrenheitOutput;
};
