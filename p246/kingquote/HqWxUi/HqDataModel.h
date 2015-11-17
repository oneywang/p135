#pragma once
#include "MyVListCtrl.h"
#include "../HqStorage/HqFile.h"

enum HqField
{
	Fld_Code = 0,
	Fld_Name,
	FLd_LastMin,//��������
	Fld_LastTime,//���ʱ��
	Fld_Zdz,//�ǵ�ֵ
	Fld_Zdf,//�ǵ���
	Fld_Preclose,
	Fld_Openpx,
	Fld_Highpx,
	Fld_Lowpx,
	Fld_Newpx,
	Fld_Vol,
	Fld_Money,
	Fld_Position,
	Fld_Max,
};

class HqDataModel : public MyListCtrlDataProvider
{
public:
	HqDataModel();
	~HqDataModel();

public:
	void sethq(HqFile *hf)
	{
		m_hq = hf;
	}



	HqFile *gethq()
	{
		return m_hq;
	}

	void InitLc(MyVListCtrl *mlc);

	//��Ҫ��Ҫ�������������
	virtual wxString OnGetItemText(long item, long column) const;

	virtual int OnGetItemCount();


	virtual wxListItemAttr *OnGetItemColumnAttr(long item, long WXUNUSED(column))
	{
		if (item % 2)
		{
			return &m_attrForOddRows;
		}
		else
		{
			return &m_defaultCellAttr;
		}
	}

protected:
	HqFile* m_hq;
	wxArrayString     m_colLabels;
	wxListItemAttr m_attrForOddRows;
	wxListItemAttr m_defaultCellAttr;
};

