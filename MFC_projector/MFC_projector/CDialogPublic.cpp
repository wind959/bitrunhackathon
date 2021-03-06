// CDialogPublic.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_projector.h"
#include "CDialogPublic.h"
#include "afxdialogex.h"


// CDialogPublic 对话框

IMPLEMENT_DYNAMIC(CDialogPublic, CDialog)

CDialogPublic::CDialogPublic(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOGpublic, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialogPublic::~CDialogPublic()
{
}

void CDialogPublic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_com);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT4, m_edit4);
	DDX_Control(pDX, IDC_EDIT6, m_edit5);
	DDX_Control(pDX, IDC_EDIT5, m_edit6);
}


BEGIN_MESSAGE_MAP(CDialogPublic, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialogPublic::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogPublic::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CDialogPublic::OnBnClickedButton3)
END_MESSAGE_MAP()


// CDialogPublic 消息处理程序


void CDialogPublic::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: Add your control notification handler code here   
	// 设置过滤器   
	TCHAR szFilter[] = _T("PDF件(*.pdf)|*.pdf|Word文件(*.doc)|*.doc|所有文件(*.*)|*.*||");
	// 构造保存文件对话框   
	//CFileDialog fileDlg(FALSE, _T("选择文件"), _T("选择白皮书"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	CFileDialog fileDlg(TRUE, _T("白皮书"), NULL, 0, szFilter, this);
	
	CString strFilePath;

	// 显示保存文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		m_edit5.SetWindowTextW(strFilePath);
		//SetDlgItemText(IDC_SAVE_EDIT, strFilePath);
	}
}


void CDialogPublic::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"递交成功", L"系统收到代币请求", 0);
}


void CDialogPublic::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit1.SetWindowTextW(L"");
	m_edit2.SetWindowTextW(L"");
	m_edit3.SetWindowTextW(L"");
	m_edit4.SetWindowTextW(L"");
	m_edit5.SetWindowTextW(L"");
	m_edit6.SetWindowTextW(L"");
	Sleep(3000);
	this->CloseWindow();
}


BOOL CDialogPublic::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_com.AddString(_T("Yincheng EOS"));
	m_com.AddString(_T("EOS"));
	// 为组合框控件的列表框添加列表项“百度”   
	m_com.AddString(_T("Ethereum"));

	// 默认选择第一项   
	m_com.SetCurSel(0);
	this->SetWindowTextW(L"业务发布");

	m_edit1.SetWindowTextW(L"1000000000");
	m_edit2.SetWindowTextW(L"1000");
	m_edit3.SetWindowTextW(L"1");
	m_edit4.SetWindowTextW(L"10000000");
	m_edit5.SetWindowTextW(L"");
	m_edit6.SetWindowTextW(L"源于EOS平台的二次发币 请求募资，欢迎韭菜升级股东与投资人监管我们干成大事");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
