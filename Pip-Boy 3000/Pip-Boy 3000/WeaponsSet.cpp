// WeaponsSet.h : Implementation of the CWeaponsSet class



// CWeaponsSet implementation

// code generated on Tuesday, December 08, 2015, 6:13 PM

#include "stdafx.h"
#include "WeaponsSet.h"
IMPLEMENT_DYNAMIC(CWeaponsSet, CRecordset)

CWeaponsSet::CWeaponsSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Id = 0;
	m_itemName = "";
	m_weight = 0.0;
	m_nFields = 3;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CWeaponsSet::GetDefaultConnect()
{
	return _T("DSN=MortDB;UID=login;PWD=Loladog1;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=TECHNOLOG;DATABASE=MortDB;");
}

CString CWeaponsSet::GetDefaultSQL()
{
	return _T("[dbo].[Weapons]");
}

void CWeaponsSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[Id]"), m_Id);
	RFX_Text(pFX, _T("[itemName]"), m_itemName);
	RFX_Single(pFX, _T("[weight]"), m_weight);

}
/////////////////////////////////////////////////////////////////////////////
// CWeaponsSet diagnostics

#ifdef _DEBUG
void CWeaponsSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CWeaponsSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


