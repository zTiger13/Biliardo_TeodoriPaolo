
// Biliardo_TeodoriPaoloDoc.cpp: implementazione della classe CBiliardoTeodoriPaoloDoc
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS può essere definito in un'anteprima di implementazione del progetto ATL, nei gestori di anteprime
// e della ricerca e consente di condividere il codice dei documenti con il progetto in questione.
#ifndef SHARED_HANDLERS
#include "Biliardo_TeodoriPaolo.h"
#endif

#include "Biliardo_TeodoriPaoloDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CBiliardoTeodoriPaoloDoc

IMPLEMENT_DYNCREATE(CBiliardoTeodoriPaoloDoc, CDocument)

BEGIN_MESSAGE_MAP(CBiliardoTeodoriPaoloDoc, CDocument)
END_MESSAGE_MAP()


// Costruzione/distruzione di CBiliardoTeodoriPaoloDoc

CBiliardoTeodoriPaoloDoc::CBiliardoTeodoriPaoloDoc() noexcept
{
	// TODO: aggiungere qui il codice di costruzione unico

}

CBiliardoTeodoriPaoloDoc::~CBiliardoTeodoriPaoloDoc()
{
}

BOOL CBiliardoTeodoriPaoloDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: aggiungere qui il codice di reinizializzazione
	// (nei documenti SDI verrà riutilizzato questo documento).

	return TRUE;
}




// Serializzazione di CBiliardoTeodoriPaoloDoc

void CBiliardoTeodoriPaoloDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: aggiungere qui il codice di archiviazione.
	}
	else
	{
		// TODO: aggiungere qui il codice di caricamento.
	}
}

#ifdef SHARED_HANDLERS

// Supporto per anteprime
void CBiliardoTeodoriPaoloDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modificare il codice per creare i dati del documento
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Supporto per gestori di ricerca
void CBiliardoTeodoriPaoloDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Consente di impostare i contenuti di ricerca dai dati del documento.
	// Le parti di contenuto devono essere separata da ";"

	// Ad esempio:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CBiliardoTeodoriPaoloDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Diagnostica di CBiliardoTeodoriPaoloDoc

#ifdef _DEBUG
void CBiliardoTeodoriPaoloDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBiliardoTeodoriPaoloDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Comandi di CBiliardoTeodoriPaoloDoc
