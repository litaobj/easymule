#pragma once
#include "afxcmn.h"


// CShareFileSelect �Ի���

class CShareFileSelect : public CDialog
{
	DECLARE_DYNAMIC(CShareFileSelect)

public:
	CShareFileSelect(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CShareFileSelect();

// �Ի�������
	enum { IDD = IDD_DIALOG_SHAREFILE };

	void ShowFile(CString strDir);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
    virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ShareFileList;

private:
	CString m_strDir; // The Directory of the Share Files
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnNcDestroy();
};
