// UpLoading.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "emule.h"
#include "UpLoading.h"


// CUpLoading �Ի���

IMPLEMENT_DYNAMIC(CUpLoading, CDialog)
CUpLoading::CUpLoading(CWnd* pParent /*=NULL*/)
	: CResizableDialog(CUpLoading::IDD, pParent)
{
}

CUpLoading::~CUpLoading()
{
}

void CUpLoading::DoDataExchange(CDataExchange* pDX)
{
	CResizableDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_UPLOADING, uploadlistctrl);
}


BEGIN_MESSAGE_MAP(CUpLoading, CResizableDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CUpLoading ��Ϣ�������
BOOL CUpLoading::OnInitDialog()
{
	CResizableDialog::OnInitDialog();
	uploadlistctrl.Init();

	AddAnchor(uploadlistctrl.m_hWnd,TOP_LEFT, BOTTOM_RIGHT);

	return TRUE;
}
void CUpLoading::OnSize(UINT nType, int cx, int cy)
{
	CResizableDialog::OnSize(nType, cx, cy);
	Invalidate(FALSE);
}
