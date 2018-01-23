// EditRow.cpp : implementation file
//

#include "stdafx.h"
#include "Student Catalog.h"
#include "EditRow.h"
#include "afxdialogex.h"


// CEditRow dialog

IMPLEMENT_DYNAMIC(CEditRow, CDialogEx)

CEditRow::CEditRow(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_EDIT, pParent)
	, m_editName(_T(""))
	, m_editMajor(_T(""))
	, m_editYear(_T(""))
{

}

CEditRow::~CEditRow()
{
}

void CEditRow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_editName);
	DDX_Text(pDX, IDC_EDIT2, m_editMajor);
	DDX_Text(pDX, IDC_EDIT3, m_editYear);
	DDX_Control(pDX, IDC_EDIT1, m_editNameControl);
	DDX_Control(pDX, IDC_EDIT2, m_editMajorControl);
	DDX_Control(pDX, IDC_EDIT3, m_editYearControl);
}


BEGIN_MESSAGE_MAP(CEditRow, CDialogEx)
END_MESSAGE_MAP()


// CEditRow message handlers


BOOL CEditRow::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
