/****************************************************************************

    �ļ���: CIF.h

      ˵��: CIF����˼Ϊ:Color��Icon��Font�������ʵ���д,��Ŀ����ϣ���ܹ�ͳһ
	        ���������Ҫ�õ�����ɫ��ͼ�������
      
  ��Ҫ����:

      ��ʷ:

  ��ǰ�汾: Demo
  
  ȡ���汾:

																2006.1.27
															  Thilon��Ȩ����
****************************************************************************/

#pragma once

#define RGB_RED(rgb)	((BYTE)((rgb >> 0) & 0xff))
#define RGB_GREEN(rgb)	((BYTE)((rgb >> 8) & 0xff))
#define RGB_BLUE(rgb)	((BYTE)((rgb >> 16) & 0xff))

typedef struct
{
	WORD wVersion;
	WORD wWidth;
	WORD wHeight;
	WORD wItemCount;
	WORD* items() { return (WORD*)(this+1); }
} TOOLBAR_RES;

class CCIF
{

public:
	CCIF(void);
public:
	~CCIF(void);

//////////////////////////////////////////
//Color
//////////////////////////////////////////
public:
	BOOL		m_bCustom;
	COLORREF	m_crWindow;	//������ɫ
	COLORREF	m_crMidtone;
	COLORREF	m_crHighlight;
	COLORREF	m_crText;
	COLORREF	m_crHiText;
	COLORREF	m_crBackNormal;
	COLORREF	m_crBackSel;
	COLORREF	m_crBackCheck;
	COLORREF	m_crBackCheckSel;
	COLORREF	m_crMargin;
	COLORREF	m_crBorder;
	COLORREF	m_crShadow;
	COLORREF	m_crCmdText;
	COLORREF	m_crCmdTextSel;
	COLORREF	m_crDisabled;
	COLORREF	m_crNoFocusLine;

public:
	void					InitColor();
		   COLORREF			GetDialogBackColor();
	static COLORREF			CalculateColor(COLORREF crFore, COLORREF crBack, int nAlpha);

//////////////////////////////////////////
//Icon
//////////////////////////////////////////
public:
	CMapStringToPtr			m_pNameMap;
	CMapPtrToPtr			m_pImageMap;			//ָ��ͼƬ��ָ��
	CImageList				m_ImageList;			//��Ų˵�ͼ��

	CMapPtrToPtr			m_pGrayImageMap;		//ָ��Ҷ�ͼƬ��ָ��
	CImageList				m_GrayImageList;		//��ŻҶ�ͼƬ

protected:
	CSize					m_czBuffer;
	CDC						m_dcBuffer;
	CBitmap					m_bmBuffer;
	HBITMAP					m_bmOldBuffer;

public:
	BOOL					DrawWatermark(CDC* pDC, CRect* pRect, CBitmap* pMark, int nOffX = 0, int nOffY = 0);
	BOOL					ConfirmImageList();
	BOOL					ConfirmGrayImageList();

	void					NameCommand(UINT nID, LPCTSTR pszName);
	void					Clear();
	void					CopyIcon(UINT nFromID, UINT nToID);
	void					AddIcon(UINT nID, HICON hIcon, BOOL bGrayscale = FALSE);

	UINT					NameToID(LPCTSTR pszName);
	BOOL					AddImagesFromToolbar(UINT nIDToolBar, COLORREF crBack = RGB(0,255,0));
	CDC*					GetBuffer(CDC& dcScreen, const CSize& szItem);
	
	int						ImageForID(UINT nID);
	int						GrayImageForID(UINT nID);
	HICON					ExtractIcon(UINT nID);
	static HICON			CreateGrayscaleIcon(HICON hIcon);

//////////////////////////////////////////
//Icon
//////////////////////////////////////////
public:
		CFont		m_fntUP;
		CFont		m_fntBold;
		CFont		m_fntOver;
		CFont		m_fntDown;
public:
	void CreateFonts(LPCTSTR pszFace = NULL, int nSize = 0);
	void GradientFillEx(HDC hdc, long x1, long y1, long x2, long y2, COLORREF crFore, COLORREF crBack, bool bHorz = true);

	void Draw2GradLayerRect(HDC hdc, const CRect &rect, COLORREF crFore1, COLORREF crBack1, COLORREF crFore2, COLORREF crBack2, UINT nScale);
	void DrawRound(HDC hdc, const RECT& rect, int iStartPos = 0, int iRound = 3);
	void RemoveIcon(UINT nID, BOOL bGrayscale);

};

extern CCIF cif;