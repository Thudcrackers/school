// ConfirmDelete.cpp : implementation file
//

#include "stdafx.h"
#include "Student Catalog.h"
#include "ConfirmDelete.h"
#include "afxdialogex.h"


// CConfirmDelete dialog

IMPLEMENT_DYNAMIC(CConfirmDelete, CDialog)

CConfirmDelete::CConfirmDelete(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_DELETE, pParent)
{

}

CConfirmDelete::~CConfirmDelete()
{
}

void CConfirmDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConfirmDelete, CDialog)
END_MESSAGE_MAP()


// CConfirmDelete message handlers
