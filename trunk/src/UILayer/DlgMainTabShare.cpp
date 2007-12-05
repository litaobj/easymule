// DlgMainTabShare.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DlgMainTabShare.h"
#include ".\dlgmaintabshare.h"
#include "TabItem_Normal.h"
#include "TabItem_Wnd.h"
#include "PageTabBkDraw.h"
#include "eMule.h"
#include "emuleDlg.h"
#include "SharedFilesWnd.h"


// CDlgMainTabShare �Ի���

IMPLEMENT_DYNAMIC(CDlgMainTabShare, CDialog)
CDlgMainTabShare::CDlgMainTabShare(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMainTabShare::IDD, pParent)
{
	m_posShare = NULL;
}

CDlgMainTabShare::~CDlgMainTabShare()
{
}

void CDlgMainTabShare::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMainTabShare, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()

void CDlgMainTabShare::SetShareText(LPCTSTR lpszText)
{
	if (NULL != m_posShare)
		m_tabWnd.SetTabText(m_posShare, lpszText);
}

// CDlgMainTabShare ��Ϣ�������

BOOL CDlgMainTabShare::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN)
	{
		// Don't handle Ctrl+Tab in this window. It will be handled by main window.
		if (pMsg->wParam == VK_TAB && GetAsyncKeyState(VK_CONTROL) < 0)
			return FALSE;

		if (VK_RETURN == pMsg->wParam || VK_ESCAPE == pMsg->wParam)
			return FALSE;
	}

	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CDlgMainTabShare::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	ModifyStyle(0, WS_CLIPCHILDREN, 0);

	m_tabWnd.Create(WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, CRect(0, 0, 0, 0), this, 0);
	m_tabWnd.SetBarBkDraw(new CPageTabBkDraw);


	//	add Toolbar	<begin>
	m_toolbar.Create(WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, AFX_IDW_TOOLBAR);
	m_toolbar.SetOwner(&theApp.emuledlg->sharedfileswnd->sharedfilesctrl);
	m_toolbar.SetIndent(8);
	m_toolbar.SetBkDraw(new CPageTabBkDraw);

	CTabItem_Wnd	*pTabItemWnd = new CTabItem_Wnd;
	pTabItemWnd->SetItemWnd(&m_toolbar, FALSE);
	pTabItemWnd->SetDynDesireLength(TRUE);
	m_tabWnd.AddTab(pTabItemWnd);
	pTabItemWnd = NULL;
	//	add Toolbar	<end>


	CTabItem_Normal	*pTI_Normal = new CTabItem_Normal;
	pTI_Normal->SetCaption(GetResString(IDS_SF_FILES));
	pTI_Normal->SetRelativeWnd(theApp.emuledlg->sharedfileswnd->GetSafeHwnd());
	//pTI_Normal->SetDesireLength(300);
	pTI_Normal->SetDynDesireLength(TRUE);
	m_posShare = m_tabWnd.AddTab(pTI_Normal, TRUE);
	pTI_Normal = NULL;

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgMainTabShare::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	if (NULL != m_tabWnd.GetSafeHwnd())
	{
		m_tabWnd.MoveWindow(0, 0, cx, cy, FALSE);
	}
}
