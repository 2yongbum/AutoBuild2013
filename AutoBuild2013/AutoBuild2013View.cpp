
// AutoBuild2013View.cpp : implementation of the CAutoBuild2013View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "AutoBuild2013.h"
#endif

#include "AutoBuild2013Doc.h"
#include "AutoBuild2013View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAutoBuild2013View

IMPLEMENT_DYNCREATE(CAutoBuild2013View, CView)

BEGIN_MESSAGE_MAP(CAutoBuild2013View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CAutoBuild2013View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CAutoBuild2013View construction/destruction

CAutoBuild2013View::CAutoBuild2013View()
{
	// TODO: add construction code here

}

CAutoBuild2013View::~CAutoBuild2013View()
{
}

BOOL CAutoBuild2013View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CAutoBuild2013View drawing

void CAutoBuild2013View::OnDraw(CDC* /*pDC*/)
{
	CAutoBuild2013Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CAutoBuild2013View printing


void CAutoBuild2013View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CAutoBuild2013View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAutoBuild2013View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAutoBuild2013View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CAutoBuild2013View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CAutoBuild2013View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CAutoBuild2013View diagnostics

#ifdef _DEBUG
void CAutoBuild2013View::AssertValid() const
{
	CView::AssertValid();
}

void CAutoBuild2013View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAutoBuild2013Doc* CAutoBuild2013View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAutoBuild2013Doc)));
	return (CAutoBuild2013Doc*)m_pDocument;
}
#endif //_DEBUG


// CAutoBuild2013View message handlers
