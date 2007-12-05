// DlgMainTabSidePanel.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "emule.h"
#include "emuleDlg.h"
#include "DlgMainTabSidePanel.h"
#include "CmdFuncs.h"
#include ".\dlgmaintabsidepanel.h"
#include "MainTabBkDraw.h"

extern CemuleApp theApp;
// CDlgMainTabSidePanel �Ի���

IMPLEMENT_DYNAMIC(CDlgMainTabSidePanel, CDialog)
CDlgMainTabSidePanel::CDlgMainTabSidePanel(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMainTabSidePanel::IDD, pParent)
{

}

CDlgMainTabSidePanel::~CDlgMainTabSidePanel()
{
}

void CDlgMainTabSidePanel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMainTabSidePanel, CDialog)
	//ON_WM_ERASEBKGND()
	ON_MESSAGE(WM_ERASEBKGND, OnEraseBkgndEx)
	ON_WM_SIZE()
ON_WM_PAINT()
END_MESSAGE_MAP()

//BEGIN_ANCHOR_MAP(CDlgMainTabSidePanel)
//	ANCHOR_MAP_ENTRY(*GetDlgItem(IDC_EDIT_KEYWORD), ANF_AUTOMATIC)
//	ANCHOR_MAP_ENTRY(*GetDlgItem(IDC_BN_SEARCH), ANF_AUTOMATIC)
//END_ANCHOR_MAP()

int CDlgMainTabSidePanel::GetDesireWidth()
{
	CRect	rtClient;
	if (NULL != GetSafeHwnd())
	{
		GetClientRect(&rtClient);
		return rtClient.Width();
	}
	else
		return 0;
}

void CDlgMainTabSidePanel::Resize()
{
	CRect rcClient;
	GetClientRect(rcClient);

	//������ť
	CRect rtButton;
	CSize sizeButton;

	m_SearchButton.GetDesireSize(sizeButton);

	rtButton.CopyRect(rcClient);
	rtButton.right = rcClient.right - 8;
	rtButton.left = rtButton.right - sizeButton.cx;
	rtButton.top = rcClient.top + (rcClient.Height() - sizeButton.cy) / 2;
	rtButton.bottom = rtButton.top + sizeButton.cy;

	if (NULL != m_SearchButton.GetSafeHwnd())
		m_SearchButton.MoveWindow(&rtButton, FALSE);


	//������
	CRect rtSearchBar( rcClient.left, rcClient.top + (rcClient.Height() - 23) / 2,
						rtButton.left - 8, rcClient.bottom - (rcClient.Height() - 23) / 2 );

	if (NULL != m_SearchBarCtrl.GetSafeHwnd())
		m_SearchBarCtrl.MoveWindow(&rtSearchBar, FALSE);
}
// CDlgMainTabSidePanel ��Ϣ�������

//BOOL CDlgMainTabSidePanel::OnEraseBkgnd(CDC* pDC)
//{
//	return CDialog::OnEraseBkgnd(pDC);
//}

LRESULT	CDlgMainTabSidePanel::OnEraseBkgndEx(WPARAM wParam, LPARAM lParam)
{
	if (1 == lParam)
	{
		::SendMessage( ::GetParent(GetSafeHwnd()), WM_ERASEBKGND, wParam, lParam);
		//CRect rtClient;
		//GetClientRect(rtClient);
		//CMainTabBkDraw	bkDraw;
		//bkDraw.Draw(&dc, rtClient);
	}

	return 1;
}

BOOL CDlgMainTabSidePanel::OnInitDialog()
{
	CDialog::OnInitDialog();

	if(!m_SearchButton.Create(this, CRect(0, 0, 0, 0)))
	{
		return FALSE;
	}

	if(!m_SearchBarCtrl.Create(this, CRect(0, 0, 0, 0)))
	{
		return FALSE;
	}



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgMainTabSidePanel::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	//CRect rcWnd;
	//GetWindowRect(&rcWnd);
	//HandleAnchors(&rcWnd); 
	//Invalidate(FALSE);
	Resize();
}

void CDlgMainTabSidePanel::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialog::OnCancel();
}

//void CDlgMainTabSidePanel::OnBnClickedSearchbutton()
//{
//	CString str;
//	m_CtrlSearchBar.GetEditor()->GetWindowText(str);
//
//	if(m_CtrlSearchBar.GetTipinfo() || str.IsEmpty())
//	{
//		return;
//	}
//	else
//	{
//		if (str.Left(13).CompareNoCase(_T("ed2k://|file|")) == 0)
//		{
//			CmdFuncs::AddEd2kLinksToDownload(str, 0);
//		}
//		else
//		{
//			theApp.emuledlg->m_mainTabWnd.m_dlgResource.OpenNewSearchResult(str);
//		}
//	}
//}

void CDlgMainTabSidePanel::OnOK()
{
	//Deleted by thilon on 2007.06.18
	//CString	str;

	//m_SearchBarCtrl.GetEditor()->GetWindowText(str);

	//// VC-SearchDream[2007-04-06]: Direct HTTP and FTP DownLoad
	//if ((str.Left(7).CompareNoCase(_T("http://")) == 0) || (str.Left(6).CompareNoCase(_T("ftp://")) == 0))
	//{
	//	CmdFuncs::AddUrlToDownload(str);

	//	return;
	//}

	//theApp.emuledlg->m_mainTabWnd.m_dlgResource.OpenNewSearchResult(str);
}

void CDlgMainTabSidePanel::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CClientRect	rtClient(this);
	CBufferDC	bufDC(dc.GetSafeHdc(), rtClient);

	SendMessage(WM_ERASEBKGND, (WPARAM) bufDC.GetSafeHdc(), 1);

}
