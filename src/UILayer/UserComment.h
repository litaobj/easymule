#pragma once

#include "resource.h"
// CUserComment �Ի���
#include "WebBrowserWnd.h"
#include "ResizableLib\ResizableDialog.h"

class CUserComment : public CResizableDialog
{
	DECLARE_DYNAMIC(CUserComment)

public:
	CUserComment(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserComment();

	void Refresh(CKnownFile * file);

// �Ի�������
	enum { IDD = IDD_DIALOG_COMMENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

	CHtmlCtrl * m_pwebUserComment;
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
