// InventoryManagement.cpp : implementation file
//

#include "stdafx.h"
#include "Pip-Boy 3000.h"
#include "InventoryManagement.h"
#include "afxdialogex.h"


// CInventoryManagement dialog

IMPLEMENT_DYNAMIC(CInventoryManagement, CDialogEx)

CInventoryManagement::CInventoryManagement(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGBAR, pParent)
	, m_itemSelection(_T(""))
{
}

CInventoryManagement::~CInventoryManagement()
{
}

void CInventoryManagement::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ITEMS, m_itemList);
	DDX_Control(pDX, IDC_BUTTON_PICKUP, m_pickUpButton);
	DDX_LBString(pDX, IDC_LIST_ITEMS, m_itemSelection);
	DDX_Control(pDX, IDC_BUTTON_DROP, m_dropButton);
}


BEGIN_MESSAGE_MAP(CInventoryManagement, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_PICKUP, &CInventoryManagement::OnBnClickedButtonPickup)
END_MESSAGE_MAP()


// CInventoryManagement message handlers

//IGNORE
void CInventoryManagement::OnBnClickedButtonPickup()
{
	// TODO: Add your control notification handler code here
}


BOOL CInventoryManagement::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_itemList.AddString(CString("Buttslol"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
