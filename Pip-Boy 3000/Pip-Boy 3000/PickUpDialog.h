#pragma once
#include "afxwin.h"


// CPickUpDialog dialog

class CPickUpDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPickUpDialog)

public:
	CPickUpDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPickUpDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_itemList;
	CString m_itemSelection;
	virtual BOOL OnInitDialog();
	CListBox m_weaponsList;
	CString m_weaponsSelection;
	CListBox m_aidList;
	CString m_aidSelection;
	afx_msg void OnLbnSelchangeListItems();
	afx_msg void OnLbnSelchangeListWeapons();
	afx_msg void OnLbnSelchangeList3();
};
