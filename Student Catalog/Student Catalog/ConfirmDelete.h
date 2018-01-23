#pragma once


// CConfirmDelete dialog

class CConfirmDelete : public CDialog
{
	DECLARE_DYNAMIC(CConfirmDelete)

public:
	CConfirmDelete(CWnd* pParent = NULL);   // standard constructor
	virtual ~CConfirmDelete();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
