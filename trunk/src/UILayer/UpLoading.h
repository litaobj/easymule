#pragma once

#include "resource.h"
// CUpLoading �Ի���
#include "UploadListCtrl.h"
#include "ResizableLib\ResizableDialog.h"

class CUpLoading : public CResizableDialog
{
	DECLARE_DYNAMIC(CUpLoading)

public:
	CUpLoading(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUpLoading();

// �Ի�������
	enum { IDD = IDD_DIALOG_UPLOADING };
	CUploadListCtrl			uploadlistctrl;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
