// PickUpDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Pip-Boy 3000.h"
#include "PickUpDialog.h"
#include "afxdialogex.h"


// CPickUpDialog dialog

IMPLEMENT_DYNAMIC(CPickUpDialog, CDialogEx)

CPickUpDialog::CPickUpDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_itemSelection(_T(""))
	, m_weaponsSelection(_T(""))
	, m_aidSelection(_T(""))
{

}

CPickUpDialog::~CPickUpDialog()
{
}

void CPickUpDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ITEMS, m_itemList);
	DDX_LBString(pDX, IDC_LIST_ITEMS, m_itemSelection);
	DDX_Control(pDX, IDC_LIST_WEAPONS, m_weaponsList);
	DDX_LBString(pDX, IDC_LIST_WEAPONS, m_weaponsSelection);
	DDX_Control(pDX, IDC_LIST3, m_aidList);
	DDX_LBString(pDX, IDC_LIST3, m_aidSelection);
}


BEGIN_MESSAGE_MAP(CPickUpDialog, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST_ITEMS, &CPickUpDialog::OnLbnSelchangeListItems)
	ON_LBN_SELCHANGE(IDC_LIST_WEAPONS, &CPickUpDialog::OnLbnSelchangeListWeapons)
	ON_LBN_SELCHANGE(IDC_LIST3, &CPickUpDialog::OnLbnSelchangeList3)
END_MESSAGE_MAP()


// CPickUpDialog message handlers


BOOL CPickUpDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_itemList.AddString(CString("Bathrobe"));
	m_itemList.AddString(CString("Black vest and slacks"));
	m_itemList.AddString(CString("Bomber jacket"));
	m_itemList.AddString(CString("Casual outfit"));
	m_itemList.AddString(CString("Clean black suit"));
	m_itemList.AddString(CString("Postman uniform"));
	m_itemList.AddString(CString("Red dress"));
	m_itemList.AddString(CString("Vault-Tec lab coat"));

	m_weaponsList.AddString(CString(".44 pistol"));
	m_weaponsList.AddString(CString("10mm pistol"));
	m_weaponsList.AddString(CString("Pipe pistol"));
	m_weaponsList.AddString(CString("Laser pistol"));
	m_weaponsList.AddString(CString("Plasma pistol"));
	m_weaponsList.AddString(CString("Assault rifle"));
	m_weaponsList.AddString(CString("Combat rifle"));
	m_weaponsList.AddString(CString("Hunting rifle"));
	m_weaponsList.AddString(CString("Spray n' Pray"));
	m_weaponsList.AddString(CString("Shotgun"));
	m_weaponsList.AddString(CString("Fat Man"));
	m_weaponsList.AddString(CString("Minigun"));
	m_weaponsList.AddString(CString("Gauss rifle"));

	m_aidList.AddString(CString("Carrot"));
	m_aidList.AddString(CString("Corn"));
	m_aidList.AddString(CString("Deathclaw steak"));
	m_aidList.AddString(CString("Gourd"));
	m_aidList.AddString(CString("Beer"));
	m_aidList.AddString(CString("Rum"));
	m_aidList.AddString(CString("Nuka Cola"));
	m_aidList.AddString(CString("Nuka Cola Quantum"));
	m_aidList.AddString(CString("Nuka Cherry"));
	m_aidList.AddString(CString("Stimpack"));
	m_aidList.AddString(CString("Stealth Boy"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CPickUpDialog::OnLbnSelchangeListItems()
{
	// TODO: Add your control notification handler code here
	m_weaponsList.SetCurSel(-1);
	m_aidList.SetCurSel(-1);
}


void CPickUpDialog::OnLbnSelchangeListWeapons()
{
	// TODO: Add your control notification handler code here
	m_itemList.SetCurSel(-1);
	m_aidList.SetCurSel(-1);
}


void CPickUpDialog::OnLbnSelchangeList3()
{
	// TODO: Add your control notification handler code here
	m_itemList.SetCurSel(-1);
	m_weaponsList.SetCurSel(-1);
}
