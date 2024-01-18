
// Biliardo_TeodoriPaolo.h: file di intestazione principale per l'applicazione Biliardo_TeodoriPaolo
//
#pragma once

#ifndef __AFXWIN_H__
	#error "includere 'pch.h' prima di includere questo file per PCH"
#endif

#include "resource.h"       // simboli principali


// CBiliardoTeodoriPaoloApp:
// Per l'implementazione di questa classe, vedere Biliardo_TeodoriPaolo.cpp
//

class CBiliardoTeodoriPaoloApp : public CWinAppEx
{
public:
	CBiliardoTeodoriPaoloApp() noexcept;


// Override
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementazione
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBiliardoTeodoriPaoloApp theApp;
