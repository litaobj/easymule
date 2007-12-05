#pragma once
// CDlgMainTabShare �Ի���
#include "resource.h"
#include "TabWnd.h"
#include "TbcShare.h"

class CDlgMainTabShare : public CDialog
{
	DECLARE_DYNAMIC(CDlgMainTabShare)

public:
	CDlgMainTabShare(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgMainTabShare();

// �Ի�������
	enum { IDD = IDD_MAINTAB_SHARE };

	void	SetShareText(LPCTSTR lpszText);
protected:
	CTabWnd			m_tabWnd;
	CTbcShare		m_toolbar;

	POSITION		m_posShare;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};