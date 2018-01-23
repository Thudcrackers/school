
// Pip-Boy 3000Set.h: interface of the CPipBoy3000Set class
//


#pragma once

// code generated on Tuesday, December 08, 2015, 6:09 PM

class CPipBoy3000Set : public CRecordset
{
public:
	CPipBoy3000Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPipBoy3000Set)

// Field/Param Data

// The string types below (if present) reflect the actual data type of the
// database field - CStringA for ANSI datatypes and CStringW for Unicode
// datatypes. This is to prevent the ODBC driver from performing potentially
// unnecessary conversions.  If you wish, you may change these members to
// CString types and the ODBC driver will perform all necessary conversions.
// (Note: You must use an ODBC driver version that is version 3.5 or greater
// to support both Unicode and these conversions).

	long	m_Id;
	CStringA	m_category;
	CStringA	m_itemName;
	float	m_weight;
	long m_quantity;

// Overrides
	// Wizard generated virtual function overrides
	public:
	virtual CString GetDefaultConnect();	// Default connection string

	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

