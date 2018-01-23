// DropItemDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Pip-Boy 3000.h"
#include "DropItemDialog.h"
#include "afxdialogex.h"


// CDropItemDialog dialog

IMPLEMENT_DYNAMIC(CDropItemDialog, CDialogEx)

CDropItemDialog::CDropItemDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_DROP, pParent)
	, m_itemSelection(_T(""))
	, m_pSet(NULL)
	, category(NULL)
{

}

CDropItemDialog::~CDropItemDialog()
{
}

void CDropItemDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_itemList);
	DDX_LBString(pDX, IDC_LIST1, m_itemSelection);
}


BEGIN_MESSAGE_MAP(CDropItemDialog, CDialogEx)
END_MESSAGE_MAP()


// CDropItemDialog message handlers


BOOL CDropItemDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	if (*category == "Apparel") {
		//CString str;
		m_pSet->MoveFirst();
		while (!m_pSet->IsEOF()) {
			if (m_pSet->m_category == *category) {
				CString name = CString(m_pSet->m_itemName);
				m_itemList.AddString(name);
			}
			m_pSet->MoveNext();
		}
	}
	else if (*category == "Weapons") {
		//CString str;
		m_pSet->MoveFirst();
		while (!m_pSet->IsEOF()) {
			if (m_pSet->m_category == *category) {
				CString name = CString(m_pSet->m_itemName);
				m_itemList.AddString(name);
			}
			m_pSet->MoveNext();
		}
	}
	else if (*category == "Aid") {
		//CString str;
		m_pSet->MoveFirst();
		while (!m_pSet->IsEOF()) {
			if (m_pSet->m_category == *category) {
				CString name = CString(m_pSet->m_itemName);
				m_itemList.AddString(name);
			}
			m_pSet->MoveNext();
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
