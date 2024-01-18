
// Biliardo_TeodoriPaoloView.h: interfaccia della classe CBiliardoTeodoriPaoloView
//

#pragma once


class CBiliardoTeodoriPaoloView : public CView
{
	float posx{ 300 };
	float posy{ 300 };
	int x{ 0 };
	int y{ 0 };
	float velx{ 0 };
	float vely{ 0 };
	POINT curs{ 0,0 };
	POINT upleft{ 50,50 };
	POINT downright{ 1200,600 };
	float molt{4};
	int sattr1 = 80000;
	int sattr2 = 5000;
	int r = 30;
	int k1 = 20;
	int k2 = 75;
	int fps = 60;
	bool linea = true;


protected: // creare solo da serializzazione.
	CBiliardoTeodoriPaoloView() noexcept;
	DECLARE_DYNCREATE(CBiliardoTeodoriPaoloView)

// Attributi
public:
	CBiliardoTeodoriPaoloDoc* GetDocument() const;

// Operazioni
public:

// Sostituzioni
public:
	virtual void OnDraw(CDC* pDC);  // sottoposto a override per creare questa visualizzazione
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementazione
public:
	virtual ~CBiliardoTeodoriPaoloView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funzioni generate per la mappa dei messaggi
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // versione di debug in Biliardo_TeodoriPaoloView.cpp
inline CBiliardoTeodoriPaoloDoc* CBiliardoTeodoriPaoloView::GetDocument() const
   { return reinterpret_cast<CBiliardoTeodoriPaoloDoc*>(m_pDocument); }
#endif

