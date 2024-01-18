
// Biliardo_TeodoriPaoloView.cpp: implementazione della classe CBiliardoTeodoriPaoloView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS può essere definito in un'anteprima di implementazione del progetto ATL, nei gestori di anteprime
// e della ricerca e consente di condividere il codice dei documenti con il progetto in questione.
#ifndef SHARED_HANDLERS
#include "Biliardo_TeodoriPaolo.h"
#endif

#include "Biliardo_TeodoriPaoloDoc.h"
#include "Biliardo_TeodoriPaoloView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBiliardoTeodoriPaoloView

IMPLEMENT_DYNCREATE(CBiliardoTeodoriPaoloView, CView)

BEGIN_MESSAGE_MAP(CBiliardoTeodoriPaoloView, CView)
	// Comandi di stampa standard
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBiliardoTeodoriPaoloView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Costruzione/distruzione di CBiliardoTeodoriPaoloView

CBiliardoTeodoriPaoloView::CBiliardoTeodoriPaoloView() noexcept
{
	// TODO: aggiungere qui il codice di costruzione.

}

CBiliardoTeodoriPaoloView::~CBiliardoTeodoriPaoloView()
{
}

BOOL CBiliardoTeodoriPaoloView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modificare la classe o gli stili Window modificando
	//  la struttura CREATESTRUCT

	return CView::PreCreateWindow(cs);
}

// Disegno di CBiliardoTeodoriPaoloView

void CBiliardoTeodoriPaoloView::OnDraw(CDC* pDC)
{
	CBiliardoTeodoriPaoloDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: aggiungere qui il codice di disegno per i dati nativi.

	//campo
	pDC->FillSolidRect(upleft.x,upleft.y,downright.x-upleft.x,downright.y-upleft.y,RGB(21,88,67));


	x = (int)posx;
	y = (int)posy;

	//linea tra il cursore e la palla
	if (linea) {
		GetCursorPos(&curs);
		ScreenToClient(&curs);
		pDC->MoveTo(curs.x,curs.y);
		pDC->LineTo(x, y);
	}

	//palla
	pDC->Ellipse(x - r, y - r, x + r, y + r);
}


// Stampa di CBiliardoTeodoriPaoloView


void CBiliardoTeodoriPaoloView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBiliardoTeodoriPaoloView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// preparazione predefinita
	return DoPreparePrinting(pInfo);
}

void CBiliardoTeodoriPaoloView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: inserire un'ulteriore inizializzazione prima della stampa.
}

void CBiliardoTeodoriPaoloView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: aggiungere pulizia dopo la stampa.
}

void CBiliardoTeodoriPaoloView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBiliardoTeodoriPaoloView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Diagnostica di CBiliardoTeodoriPaoloView

#ifdef _DEBUG
void CBiliardoTeodoriPaoloView::AssertValid() const
{
	CView::AssertValid();
}

void CBiliardoTeodoriPaoloView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBiliardoTeodoriPaoloDoc* CBiliardoTeodoriPaoloView::GetDocument() const // la versione non debug è inline.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBiliardoTeodoriPaoloDoc)));
	return (CBiliardoTeodoriPaoloDoc*)m_pDocument;
}
#endif //_DEBUG


// Gestori di messaggi di CBiliardoTeodoriPaoloView


void CBiliardoTeodoriPaoloView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: aggiungere qui il codice del gestore di messaggi e/o chiamare il codice predefinito

	//lancio della palla
	if ((velx == 0) && (vely == 0)) {
		linea = false;
		GetCursorPos(&curs);
		ScreenToClient(&curs);
		velx = molt*(-curs.x+posx);
		vely = molt*(-curs.y+posy);
		SetTimer(1, round((float)1000/fps), NULL);
	}

	CView::OnLButtonUp(nFlags, point);
}


void CBiliardoTeodoriPaoloView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: aggiungere qui il codice del gestore di messaggi e/o chiamare il codice predefinito

	//serve per ridisegnare la linea tra il cursore e la palla
	if ((velx == 0) && (vely == 0)) {
		Invalidate();
		UpdateWindow();
	}

	CView::OnMouseMove(nFlags, point);
}

	
void CBiliardoTeodoriPaoloView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: aggiungere qui il codice del gestore di messaggi e/o chiamare il codice predefinito

	//update posizione
	posx += velx / fps;
	posy += vely / fps;

	//controllo eventuale rimbalzo

	if (((posx >= downright.x - r) && (velx > 0))) {
		posx = 2 * (downright.x - r) - posx;
		velx = -velx;
	}
	else if ((posx <= upleft.x + r) && (velx < 0)) {
		posx = 2 * (upleft.x + r) - posx;
		velx = -velx;
	}

	if (((posy >= downright.y - r) && (vely > 0))) {
		posy = 2 * (downright.y - r) - posy;
		vely = -vely;
	}
	else if ((posy <= upleft.y + r) && (vely < 0)) {
		posy = 2 * (upleft.y + r) - posy;
		vely = -vely;
	}

	//attrito dinamico
	if (velx != 0) velx -= k1 * velx / 1000;
	if (vely != 0) vely -= k1 * vely / 1000;

	//ulteriore attrito quando la palla sta per fermarsi
	if (velx*velx + vely*vely <= sattr1) {
		velx -= k2 * velx / 1000;
		vely -= k2 * vely / 1000;
	}

	//quando la velocità è molto piccola, viene messa a 0
	if (velx * velx + vely * vely <= sattr2) {
		velx = 0;
		vely = 0;
		linea = true;
		KillTimer(1);
	}
	
	Invalidate();
	UpdateWindow();

	CView::OnTimer(nIDEvent);
}
