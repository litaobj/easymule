// ToolTipCtrlZ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ToolTipCtrlZ.h"
#include ".\tooltipctrlz.h"


// CToolTipCtrlZ

IMPLEMENT_DYNAMIC(CToolTipCtrlZ, CToolTipCtrl)
CToolTipCtrlZ::CToolTipCtrlZ()
{
}

CToolTipCtrlZ::~CToolTipCtrlZ()
{
}


BEGIN_MESSAGE_MAP(CToolTipCtrlZ, CToolTipCtrl)
	ON_WM_CREATE()
END_MESSAGE_MAP()



// CToolTipCtrlZ ��Ϣ�������


int CToolTipCtrlZ::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CToolTipCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	GetParent()->EnableToolTips();
	Activate(TRUE);
	SetMaxTipWidth(SHRT_MAX);
	SetMargin(CRect(4, 4, 4, 4));


	return 0;
}
