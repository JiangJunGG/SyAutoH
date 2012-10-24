
// VAMHSTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VAMHSTest.h"
#include "VAMHSTestDlg.h"
#include "afxdialogex.h"
#include "../VirtualAMHS/VirtualAMHS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CVirtualAMHS* pVirualAMHSDevice = NULL;
MAP_ItemOHT g_mapOHTs;
//zhang adds the code in 2012.10.24
MAP_ItemFoup g_mapFoups;

const int StockerID = 24;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CVAMHSTestDlg �Ի���



CVAMHSTestDlg::CVAMHSTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVAMHSTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVAMHSTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_OHT, m_listCtrlOHT);
	DDX_Control(pDX, IDC_LIST_FOUP, m_listCtrlFOUP);
}

BEGIN_MESSAGE_MAP(CVAMHSTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BN_AddOHT, &CVAMHSTestDlg::OnBnClickedBnOHTonline)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BN_AddSTK, &CVAMHSTestDlg::OnBnClickedBnAddstk)
	ON_BN_CLICKED(IDC_BN_STK_IN, &CVAMHSTestDlg::OnBnClickedBnStkIn)
	ON_BN_CLICKED(IDC_BN_STK_OUT, &CVAMHSTestDlg::OnBnClickedBnStkOut)
	ON_BN_CLICKED(IDC_BN_OHT_Add, &CVAMHSTestDlg::OnBnClickedBnOhtAdd)
	ON_BN_CLICKED(IDC_BN_SetHand, &CVAMHSTestDlg::OnBnClickedBnSethand)
	ON_BN_CLICKED(IDC_BN_SetPos, &CVAMHSTestDlg::OnBnClickedBnSetpos)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CVAMHSTestDlg ��Ϣ�������

BOOL CVAMHSTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	InitListCtrlOHT();
	InitListCtrlFOUP();
	AllocConsole();                     // �򿪿���̨��Դ
	FILE* file;
	freopen_s( &file, "CONOUT$", "w+t", stdout);// ����д
	pVirualAMHSDevice = new CVirtualAMHS();
	SetTimer(100, 500, NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CVAMHSTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CVAMHSTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CVAMHSTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// the button of OHTonline
void CVAMHSTestDlg::OnBnClickedBnOHTonline()
{
	int nItem = m_listCtrlOHT.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	int nOHT_ID = m_listCtrlOHT.GetItemData(nItem);
	int nAdd = pVirualAMHSDevice->OHT_Auth(nOHT_ID);
}


void CVAMHSTestDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	if (pVirualAMHSDevice != NULL)
	{
		delete pVirualAMHSDevice;
		pVirualAMHSDevice = NULL;
	}
	FreeConsole();                      // �ͷſ���̨��Դ

	MAP_ItemOHT::iterator it;
	it = g_mapOHTs.begin();
	while(it != g_mapOHTs.end())
	{
		delete it->second;
		++it;
	}
	g_mapOHTs.clear();
}

//add the Stock?
void CVAMHSTestDlg::OnBnClickedBnAddstk()
{
	pVirualAMHSDevice->Stocker_Auth(StockerID, "192.168.55.10");
}

//the button of input
void CVAMHSTestDlg::OnBnClickedBnStkIn()
{
	CString strFoup;
	GetDlgItemText(IDC_EDIT_STK_FOUP, strFoup);
	pVirualAMHSDevice->Stocker_ManualInputFoup(StockerID, strFoup);
	//zhang adds the code in 2012.10.24
	int nFoup_ID = GetDlgItemInt(IDC_EDIT_STK_FOUP); 
	if(nFoup_ID >= 0 && nFoup_ID <= 254)
	{
		MAP_ItemFoup::iterator it = g_mapFoups.find(nFoup_ID);
		MAP_ItemFoup::iterator itEnd = g_mapFoups.end();
		if(it != itEnd)
		{
			MessageBox(_T("Foup�Ѵ��ڣ�"));
		}
		else
		{
			ItemFoup* pFoup = new ItemFoup;
			g_mapFoups.insert(std::make_pair(nFoup_ID,pFoup));
			pFoup->FoupID[0] = nFoup_ID;
			pFoup->nProcessStatus = 0;
			CString str;
			m_listCtrlFOUP.InsertItem(0,str);
			SetFOUPListItemData(pFoup,0);
		}

	}
	else
	{
		MessageBox(_T("FoupID ������Χ,Ӧ��0����254֮�䣡"));
	}
}

// the button of output 
void CVAMHSTestDlg::OnBnClickedBnStkOut()
{
	CString strFoup;
	GetDlgItemText(IDC_EDIT_STK_FOUP, strFoup);
	pVirualAMHSDevice->Stocker_ManualOutputFoup(StockerID, strFoup);
	//zhang add the code in 2012.10.24
	int nFoup_ID = GetDlgItemInt(IDC_EDIT_STK_FOUP);
	if(nFoup_ID <= 254 && nFoup_ID >= 0)
	{
		MAP_ItemFoup::iterator it = g_mapFoups.begin();
		while(it->second->FoupID[0] != nFoup_ID)
		{
			it++;
		}
		MAP_ItemFoup::iterator itEnd = g_mapFoups.end();
		if(it != itEnd)
		{
			g_mapFoups.erase(it);
			DeleteFOUPListItemData(nFoup_ID);
		}
		else
		{
			MessageBox(_T("�б��в�������Ҫɾ����FOUP��������ѡ��"));
		}
	}
	else
	{
		MessageBox(_T("FOUPID ������Χ��Ӧ��0����254֮�䣡"));
	}

}

// the button function of addOHT
void CVAMHSTestDlg::OnBnClickedBnOhtAdd()                             
{
	int nOHT_ID = GetDlgItemInt(IDC_EDIT_OHTID);
	if (nOHT_ID >= 0 && nOHT_ID < 254)
	{
		MAP_ItemOHT::iterator it = g_mapOHTs.find(nOHT_ID);
		MAP_ItemOHT::iterator itEnd = g_mapOHTs.end();
		if (it != g_mapOHTs.end())
		{
			MessageBox(_T("OHT������!"));
		}
		else
		{
			// add
			ItemOHT* pOht = new ItemOHT;
			g_mapOHTs.insert(std::make_pair(nOHT_ID, pOht));
			pOht->nID = nOHT_ID;
			pOht->nPosition = 0;
			pOht->nHandStatus = 0;

			CString str;
			m_listCtrlOHT.InsertItem(0, str);
			SetOHTListItemData(pOht, 0);
		}
	}
	else
	{
		MessageBox(_T("�������OHT IDֵ, Ӧ��0��253֮��."));
	}
}

//the button of Sethand
void CVAMHSTestDlg::OnBnClickedBnSethand()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//the button of Setpos
void CVAMHSTestDlg::OnBnClickedBnSetpos()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//used for initialising the OHT list?
void CVAMHSTestDlg::InitListCtrlOHT(void)
{
	DWORD dwStyle;
	dwStyle = m_listCtrlOHT.GetStyle();  //ȡ����ʽ
	dwStyle =    LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT ;   //�����ʽ
	m_listCtrlOHT.SetExtendedStyle(dwStyle);     //��������

	m_listCtrlOHT.InsertColumn(0, _T("ID"), LVCFMT_CENTER, 30);            //������
	m_listCtrlOHT.InsertColumn(1, _T("POS"), LVCFMT_CENTER, 80);
	m_listCtrlOHT.InsertColumn(2, _T("HAND"), LVCFMT_CENTER, 50);
	m_listCtrlOHT.InsertColumn(3, _T("Status"), LVCFMT_CENTER, 50);
	m_listCtrlOHT.InsertColumn(4, _T("Online"), LVCFMT_CENTER, 50);
}

//used for initialising the FOUP list 
void CVAMHSTestDlg::InitListCtrlFOUP(void)
{
	DWORD dwStyle;
	dwStyle = m_listCtrlFOUP.GetStyle();  //ȡ����ʽ
	dwStyle =    LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT ;   //�����ʽ��ȫ��ѡ����դ����
	m_listCtrlFOUP.SetExtendedStyle(dwStyle);     //��������

	m_listCtrlFOUP.InsertColumn(0, _T("ID"), LVCFMT_CENTER, 100);
	m_listCtrlFOUP.InsertColumn(1, _T("Location"), LVCFMT_CENTER, 80);
	m_listCtrlFOUP.InsertColumn(2, _T("Status"), LVCFMT_CENTER, 50);
	
}

//timer event
void CVAMHSTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	LIST_OHT ohts = pVirualAMHSDevice->OHT_GetStatus();
	LIST_FOUP foups = pVirualAMHSDevice->Stocker_GetFoupsStatus(StockerID);

	LIST_OHT::iterator itOht = ohts.begin();
	while(itOht != ohts.end())
	{
		MAP_ItemOHT::iterator itMap = g_mapOHTs.find(itOht->nID);
		if (itMap != g_mapOHTs.end())
		{
			itMap->second->nHandStatus = itOht->nHandStatus;
			itMap->second->nPosition = itOht->nPosition;
			itMap->second->nOnline = itOht->nOnline;
		}
		++itOht;
	}

	int nCount = m_listCtrlOHT.GetItemCount();
	for (int i=0; i<nCount; i++)
	{
		int nOht = m_listCtrlOHT.GetItemData(i);
		MAP_ItemOHT::iterator it = g_mapOHTs.find(nOht);
		if (it != g_mapOHTs.end())
		{
			ItemOHT* pOht = it->second;
			SetOHTListItemData(pOht, i);
		}
	}

	//zhang added the code in 2012.10.24
	LIST_FOUP::iterator itFoup = foups.begin();
	while(itFoup != foups.end())
	{
		MAP_ItemFoup::iterator itMap = g_mapFoups.find(itFoup->FoupID[0]);
		if(itMap != g_mapFoups.end())
		{
			itMap->second->FoupID[0] = itFoup->FoupID[0];
			itMap->second->nProcessStatus = itFoup->nProcessStatus;
		}
		++itFoup;
	}
	int nCount_Foup = m_listCtrlFOUP.GetItemCount();
	for (int i=0; i<nCount_Foup; i++)
	{
		int nFoup = m_listCtrlFOUP.GetItemData(i);
		MAP_ItemFoup::iterator it = g_mapFoups.find(nFoup);
		if (it != g_mapFoups.end())
		{
			ItemFoup* pFoup = it->second;
			SetFOUPListItemData(pFoup, i);
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}

//used for displaying the data in the list?
void CVAMHSTestDlg::SetOHTListItemData(ItemOHT* pOHT, int nListIndex)
{
	CString str;
	str.Format(_T("%d"), pOHT->nID);
	m_listCtrlOHT.SetItemText(nListIndex, 0, str);
	str.Format(_T("%d"), pOHT->nPosition);
	m_listCtrlOHT.SetItemText(nListIndex, 1, str);
	str.Format(_T("%d"), pOHT->nHandStatus);
	m_listCtrlOHT.SetItemText(nListIndex, 2, str);
	m_listCtrlOHT.SetItemText(nListIndex, 3, _T("Idle"));
	if (pOHT->nOnline > 0)
	{
		str = _T("On");
	}
	else
	{
		str = _T("Off");
	}
	m_listCtrlOHT.SetItemText(nListIndex, 4, str);
	m_listCtrlOHT.SetItemData(nListIndex, pOHT->nID);
}

//zhang add the code in 2012.10.24
void CVAMHSTestDlg::SetFOUPListItemData(ItemFoup* pFOUP, int nListIndex)
{
	CString str;
	str.Format(_T("%d"),pFOUP->FoupID[0]);
	m_listCtrlFOUP.SetItemText(nListIndex,0,str);
	str.Format(_T("%d"),pFOUP->nProcessStatus);
	m_listCtrlFOUP.SetItemText(nListIndex,1,str);
	m_listCtrlFOUP.SetItemText(nListIndex,2,_T("Idle"));
}
void CVAMHSTestDlg::DeleteFOUPListItemData(int FoupID)
{
	int ncount = m_listCtrlFOUP.GetItemCount();
	int nlistindex = 0;
	for(; nlistindex <= ncount;)
	{
		CString strText = m_listCtrlFOUP.GetItemText(nlistindex,0);
		CString strNum;
		strNum.Format(_T("%d"),FoupID);
		if(strNum == strText)
			break;
		else
			nlistindex++;
	}
	m_listCtrlFOUP.DeleteItem(nlistindex);
}