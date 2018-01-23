
// Student CatalogDoc.h : interface of the CStudentCatalogDoc class
//


#pragma once
#include "Student CatalogSet.h"


class CStudentCatalogDoc : public CDocument
{
protected: // create from serialization only
	CStudentCatalogDoc();
	DECLARE_DYNCREATE(CStudentCatalogDoc)

// Attributes
public:
	CStudentCatalogSet m_StudentCatalogSet;

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
	virtual ~CStudentCatalogDoc();
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
};
