
// Student CatalogSet.cpp : implementation of the CStudentCatalogSet class
//

#include "stdafx.h"
#include "Student Catalog.h"
#include "Student CatalogSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudentCatalogSet implementation

// code generated on Sunday, November 29, 2015, 10:17 PM

IMPLEMENT_DYNAMIC(CStudentCatalogSet, CRecordset)

CStudentCatalogSet::CStudentCatalogSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Id = 0;
	m_studentName = "";
	m_studentMajor = "";
	m_studentYear = "";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CStudentCatalogSet::GetDefaultConnect()
{
	return _T("DRIVER={SQL Server Native Client 11.0};SERVER=tcp:kdbtapfk3t.database.windows.net,1433;DATABASE=MortDB;UID=login@kdbtapfk3t;PWD=Loladog1;");
	//return _T("DSN=MortDB;UID=login;PWD=Loladog1;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=TECHNOLOG;DATABASE=MortDB;");
}

CString CStudentCatalogSet::GetDefaultSQL()
{
	return _T("[dbo].[studentCatalog]");
}

void CStudentCatalogSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[Id]"), m_Id);
	RFX_Text(pFX, _T("[studentName]"), m_studentName);
	RFX_Text(pFX, _T("[studentMajor]"), m_studentMajor);
	RFX_Text(pFX, _T("[studentYear]"), m_studentYear);

}
/////////////////////////////////////////////////////////////////////////////
// CStudentCatalogSet diagnostics

#ifdef _DEBUG
void CStudentCatalogSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStudentCatalogSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

