
// Pip-Boy 3000Doc.h : interface of the CPipBoy3000Doc class
//


#pragma once
#include "Pip-Boy 3000Set.h"
#include "WeaponsSet.h"

class CPipBoy3000Doc : public CDocument
{
protected: // create from serialization only
	CPipBoy3000Doc();
	DECLARE_DYNCREATE(CPipBoy3000Doc)

// Attributes
public:
	CPipBoy3000Set m_PipBoy3000Set;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CPipBoy3000Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	CWeaponsSet m_weaponSet;
};
