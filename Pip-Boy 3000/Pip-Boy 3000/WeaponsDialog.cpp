// WeaponsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Pip-Boy 3000.h"
#include "WeaponsDialog.h"
#include "afxdialogex.h"


// CWeaponsDialog dialog

IMPLEMENT_DYNAMIC(CWeaponsDialog, CDialogEx)

CWeaponsDialog::CWeaponsDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_WEAPONS, pParent)
{

}

CWeaponsDialog::~CWeaponsDialog()
{
}

void CWeaponsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWeaponsDialog, CDialogEx)
END_MESSAGE_MAP()


// CWeaponsDialog message handlers
