#pragma once
#include "afxwin.h"
#include "Pip-Boy 3000Set.h"

// CDropItemDialog dialog

class CDropItemDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CDropItemDialog)

public:
	CDropItemDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDropItemDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DROP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_itemList;
	CString m_itemSelection;
	virtual BOOL OnInitDialog();
	CPipBoy3000Set* m_pSet;
	CStringA* category;
};
