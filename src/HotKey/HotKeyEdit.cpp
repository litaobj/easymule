/** @file HotKeyEdit.cpp @brief ���ļ��ļ�Ҫ˵����������Ч��
 <pre>
 *	Copyright (c) 2007��Emule
 *	All rights reserved.
 *
 *	��ǰ�汾��
 *	��    �ߣ�kernel
 *	������ڣ�2007-05-15
 *
 *	ȡ���汾��none
 *	��    �ߣ�none
 *	������ڣ�none
 </pre>*/

//

#include "stdafx.h"
#include "emule.h"
#include "HotKeyEdit.h"


// CHotKeyEdit

IMPLEMENT_DYNAMIC(CHotKeyEdit, CHotKeyCtrl)
CHotKeyEdit::CHotKeyEdit()
{
}

CHotKeyEdit::~CHotKeyEdit()
{
}


BEGIN_MESSAGE_MAP(CHotKeyEdit, CHotKeyCtrl)
	//ON_MESSAGE(WM_KEYDOWN,OnKeyDown)
	//ON_MESSAGE(WM_SYSKEYDOWN,OnKeyDown)
	//ON_KEYDOWN()
	ON_WM_KEYDOWN()
	ON_WM_SYSKEYDOWN()
END_MESSAGE_MAP()



// CHotKeyEdit ��Ϣ�������

void CHotKeyEdit::OnKeyDown(UINT nChar,UINT nRepCnt,UINT nFlags)
{
	GetParent()->PostMessage(WM_HK_CHANGE);
	CHotKeyCtrl::OnKeyDown(nChar,nRepCnt,nFlags);
}

void CHotKeyEdit::OnSysKeyDown(UINT nChar,UINT nRepCnt,UINT nFlags)
{
	GetParent()->PostMessage(WM_HK_CHANGE);
	CHotKeyCtrl::OnSysKeyDown(nChar,nRepCnt,nFlags);
}