// DlgMainTabAdvance.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DlgMainTabAdvance.h"
#include ".\dlgmaintabadvance.h"
// CDlgMainTabAdvance �Ի���

IMPLEMENT_DYNAMIC(CDlgMainTabAdvance, CDialog)
CDlgMainTabAdvance::CDlgMainTabAdvance(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMainTabAdvance::IDD, pParent)
{
}

CDlgMainTabAdvance::~CDlgMainTabAdvance()
{
}

void CDlgMainTabAdvance::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMainTabAdvance, CDialog)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CDlgMainTabAdvance ��Ϣ�������

int CDlgMainTabAdvance::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	ModifyStyle(0, WS_CLIPCHILDREN);

	// TODO:  �ڴ������ר�õĴ�������
	m_tbwAdvance.Create(WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this);

	return 0;
}

void CDlgMainTabAdvance::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	m_tbwAdvance.MoveWindow(0, 0, cx, cy, FALSE);
}

BOOL CDlgMainTabAdvance::OnEraseBkgnd(CDC* /*pDC*/)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return TRUE;
	//return CDialog::OnEraseBkgnd(pDC);
}

void CDlgMainTabAdvance::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialog::OnCancel();
}

void CDlgMainTabAdvance::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialog::OnOK();
}
