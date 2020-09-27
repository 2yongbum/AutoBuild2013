
// AutoBuild2013.h : main header file for the AutoBuild2013 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CAutoBuild2013App:
// See AutoBuild2013.cpp for the implementation of this class
//

class CAutoBuild2013App : public CWinAppEx
{
public:
	CAutoBuild2013App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAutoBuild2013App theApp;
