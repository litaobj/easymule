#pragma once
#include "afxwin.h"


// CAffirmDeleteDlg �Ի���

class CAffirmDeleteDlg : public CDialog
{
	DECLARE_DYNAMIC(CAffirmDeleteDlg)

public:
	CAffirmDeleteDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAffirmDeleteDlg();
    virtual BOOL OnInitDialog();
// �Ի�������
	enum { IDD = IDD_AFFIRMDELETE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CButton IsChecked;
	bool bIsDeleteFile;
};
