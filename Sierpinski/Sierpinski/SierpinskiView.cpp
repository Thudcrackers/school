
// SierpinskiView.cpp : implementation of the CSierpinskiView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Sierpinski.h"
#endif

#include "SierpinskiDoc.h"
#include "SierpinskiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSierpinskiView

IMPLEMENT_DYNCREATE(CSierpinskiView, CView)

BEGIN_MESSAGE_MAP(CSierpinskiView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSierpinskiView construction/destruction

CSierpinskiView::CSierpinskiView()
{
	// TODO: add construction code here

}

CSierpinskiView::~CSierpinskiView()
{
}

BOOL CSierpinskiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

void frac(CPoint p1, CPoint p2, CPoint p3, int max, CDC* pDC)
{
	if (max > 1)
	{
		CPoint m1, m2, m3;
		m1.x = (p1.x + p2.x) / 2;
		m1.y = (p1.y + p2.y) / 2;

		m2.x = (p2.x + p3.x) / 2;
		m2.y = (p2.y + p3.y) / 2;

		m3.x = (p1.x + p3.x) / 2;
		m3.y = (p1.y + p3.y) / 2;
		CPoint triangle[] = { m1, m2, m3 };

		pDC->Polygon(triangle, 3);
		frac(p1, m1, m3, max - 1, pDC);
		frac(p2, m1, m2, max - 1, pDC);
		frac(m2, m3, p3, max - 1, pDC);
	}
}

// CSierpinskiTriangleView drawing

void CSierpinskiView::OnDraw(CDC* pDC)
{
	CSierpinskiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect rcClient;
	GetClientRect(&rcClient);
	int max_steps = 9;

	CPoint p1, p2, p3;
	p1.x = rcClient.Width() / 2;
	p1.y = 1;

	p2.x = 1;
	p2.y = rcClient.Height() + 1;

	p3.x = rcClient.Width() + 1;
	p3.y = rcClient.Height() + 1;

	CPoint t[] = { p1, p2, p3 };

	pDC->Polygon(t, 3);
	frac(p1, p2, p3, max_steps, pDC);

}


// CSierpinskiView printing

BOOL CSierpinskiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSierpinskiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSierpinskiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSierpinskiView diagnostics

#ifdef _DEBUG
void CSierpinskiView::AssertValid() const
{
	CView::AssertValid();
}

void CSierpinskiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSierpinskiDoc* CSierpinskiView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSierpinskiDoc)));
	return (CSierpinskiDoc*)m_pDocument;
}
#endif //_DEBUG


// CSierpinskiView message handlers
