#pragma once
#include "ResizableLib\ResizableDialog.h"
#include "LogListCtrl.h"
#include "resource.h"

#include "HttpClient.h"
// CPeerLog �Ի���

class CPeerLog : public CResizableDialog
{
	DECLARE_DYNAMIC(CPeerLog)

public:
	CPeerLog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPeerLog();

// �Ի�������
	enum { IDD = IDD_DIALOG_PEERLOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CLogListCtrl m_LogListCtrl;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCopySelected();
	afx_msg void OnCutSelected();
	afx_msg void OnSelectAll();
	afx_msg void OnSaveAs();

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);

protected:
	CMenuXP*		m_pMenuXP;
	CUpDownClient*  m_pClient;
	CPartFile*		m_pPartFile;
public:
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
};
