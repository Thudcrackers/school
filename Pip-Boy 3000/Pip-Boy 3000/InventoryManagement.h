#pragma once
#include "afxwin.h"


// CInventoryManagement dialog

class CInventoryManagement : public CDialogEx
{
	DECLARE_DYNAMIC(CInventoryManagement)

public:
	CInventoryManagement(CWnd* pParent = NULL);   // standard constructor
	virtual ~CInventoryManagement();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGBAR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_itemList;
	CButton m_pickUpButton;
	afx_msg void OnBnClickedButtonPickup();
	virtual BOOL OnInitDialog();
	CString m_itemSelection;
	CButton m_dropButton;
};
