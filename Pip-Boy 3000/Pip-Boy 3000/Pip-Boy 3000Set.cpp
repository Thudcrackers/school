
// Pip-Boy 3000Set.cpp : implementation of the CPipBoy3000Set class
//

#include "stdafx.h"
#include "Pip-Boy 3000.h"
#include "Pip-Boy 3000Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPipBoy3000Set implementation

// code generated on Tuesday, December 08, 2015, 6:09 PM

IMPLEMENT_DYNAMIC(CPipBoy3000Set, CRecordset)

CPipBoy3000Set::CPipBoy3000Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Id = 0;
	m_category = "";
	m_itemName = "";
	m_weight = 0.0;
	m_quantity = 0;
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CPipBoy3000Set::GetDefaultConnect()
{
	return _T("Driver={SQL Server Native Client 11.0};Server=tcp:kdbtapfk3t.database.windows.net,1433;Database=MortDB;Uid=login@kdbtapfk3t;Pwd=Loladog1;Encrypt=yes;Connection Timeout=30;");
}

CString CPipBoy3000Set::GetDefaultSQL()
{
	return _T("[dbo].[Apparel]");
}

void CPipBoy3000Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[Id]"), m_Id);
	RFX_Text(pFX, _T("[itemName]"), m_itemName);
	RFX_Single(pFX, _T("[weight]"), m_weight);
	RFX_Text(pFX, _T("[category]"), m_category);
	RFX_Long(pFX, _T("[quantity]"), m_quantity);

}
/////////////////////////////////////////////////////////////////////////////
// CPipBoy3000Set diagnostics

#ifdef _DEBUG
void CPipBoy3000Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPipBoy3000Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

