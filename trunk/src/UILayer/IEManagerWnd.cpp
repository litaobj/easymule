// IEManagerWnd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "emule.h"
#include "IEManagerWnd.h"
#include ".\iemanagerwnd.h"


// CIEManagerWnd

IMPLEMENT_DYNAMIC(CIEManagerWnd, CWnd)
CIEManagerWnd::CIEManagerWnd()
{
}

CIEManagerWnd::~CIEManagerWnd()
{
}


BEGIN_MESSAGE_MAP(CIEManagerWnd, CWnd)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CIEManagerWnd ��Ϣ�������


BOOL CIEManagerWnd::OnEraseBkgnd(CDC* /*pDC*/)
{
	return TRUE;
}
