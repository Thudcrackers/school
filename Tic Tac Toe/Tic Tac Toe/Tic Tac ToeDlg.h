
// Tic Tac ToeDlg.h : header file
//

#pragma once


// CTicTacToeDlg dialog
class CTicTacToeDlg : public CDialogEx
{
// Construction
public:
	CTicTacToeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TICTACTOE_DIALOG };
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
	afx_msg void OnBnClickedTopleft();
	afx_msg void OnBnClickedReset();
	afx_msg void OnBnClickedTopmiddle();
	afx_msg void OnBnClickedTopright();
	afx_msg void OnBnClickedMiddleleft();
	afx_msg void OnBnClickedCenter();
	afx_msg void OnBnClickedMiddleright();
	afx_msg void OnBnClickedBottomleft();
	afx_msg void OnBnClickedBottommiddle();
	afx_msg void OnBnClickedBottomright();
};
