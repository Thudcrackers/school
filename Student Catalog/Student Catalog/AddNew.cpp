// AddNew.cpp : implementation file
//

#include "stdafx.h"
#include "Student Catalog.h"
#include "AddNew.h"
#include "afxdialogex.h"


// CAddNew dialog

IMPLEMENT_DYNAMIC(CAddNew, CDialog)

CAddNew::CAddNew(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_newStudentName(_T(""))
	, m_newStudentMajor(_T(""))
	, m_newStudentYear(_T(""))
{

}

CAddNew::~CAddNew()
{
}

void CAddNew::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_newStudentName);
	DDX_Text(pDX, IDC_EDIT_MAJOR, m_newStudentMajor);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_newStudentYear);
}


BEGIN_MESSAGE_MAP(CAddNew, CDialog)
END_MESSAGE_MAP()


// CAddNew message handlers
