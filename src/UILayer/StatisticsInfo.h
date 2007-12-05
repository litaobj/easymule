#pragma once

#include "resource.h"
#include "afxcmn.h"
// CStatisticsInfo �Ի���

#include "ProgressCtrlX.h"
#include "IconStatic.h"

#include "Localizee.h"
#include "ResizableLib\ResizableDialog.h"

class CStatisticsInfo : public CResizableDialog, public CLocalizee
{
	DECLARE_DYNAMIC(CStatisticsInfo)
	LOCALIZEE_WND_CANLOCALIZE();

public:
	CStatisticsInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStatisticsInfo();

// �Ի�������
	enum { IDD = IDD_DIALOG_STATISTICS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
    virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	
public:
	void SetRequest(int range, int pos);
	void SetAcceptUpload(int range, int pos);
	void SetTransfer(int range, uint64 pos);

	void SetAll(int request,  int accept, uint64 transfer);
	void SetNoFile();

	void SetStatisticsFrmText(CString str);

private:

	CProgressCtrlX pop_bar;
	CProgressCtrlX pop_baraccept;
	CProgressCtrlX pop_bartrans;
	CIconStatic m_ctrlStatisticsFrm;
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void Localize(void);
};
