#pragma once

// CBufferMovieDlg �Ի���

class CBufferMovieDlg : public CDialog
{
	DECLARE_DYNAMIC(CBufferMovieDlg)

public:
	CBufferMovieDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBufferMovieDlg();

	void Localize(void);

// �Ի�������
	enum { IDD = IDD_DIALOG_BUFFERINGMOVIE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

private:
	afx_msg LRESULT OnUpdateGUIFileProgress(WPARAM wParam, LPARAM lParam);

protected:
	CWnd* m_Parent;
};
