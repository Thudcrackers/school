#pragma once


// CWeaponsDialog dialog

class CWeaponsDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CWeaponsDialog)

public:
	CWeaponsDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CWeaponsDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_WEAPONS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
