
// FractalsView.h : interface of the CFractalsView class
//

#pragma once


class CFractalsView : public CView
{
protected: // create from serialization only
	CFractalsView();
	DECLARE_DYNCREATE(CFractalsView)

// Attributes
public:
	CFractalsDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CFractalsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FractalsView.cpp
inline CFractalsDoc* CFractalsView::GetDocument() const
   { return reinterpret_cast<CFractalsDoc*>(m_pDocument); }
#endif

