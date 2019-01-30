#pragma once
#include "UTSDefine.h"
#include "Algorithm.h"
#include "BaseOperator.h"

using namespace UTS::Algorithm;
using namespace UTS::Algorithm::DefectPixel::DefectPixelStd;

#ifdef DDP_STD_OPERATOR_EXPORTS
#define DDP_STD_OPERATOR_API __declspec(dllexport)
#else
#define DDP_STD_OPERATOR_API __declspec(dllimport)
#endif

namespace UTS
{
    typedef struct _ddp_operator_param_
    {
        double dDDMaxY;             // �ڰ�������Yֵ
        int nReCapture;             // 0��������  1�����и������С�ץͼƬ������Ķ���   
        double dThreshold;
        SIZE sizeROI;
        int nSingleSpec;
        int nDoubleSpec;
        int nMultipleSpec;
        int nDefectPixel3ChannelEn;
    } DDP_OPERATOR_PARAM;

    class DDPStdOperator : public BaseOperator
    {
    public:
        DDPStdOperator(void);
        ~DDPStdOperator(void);

        virtual BOOL OnReadSpec();
        virtual BOOL OnTest(BOOL *pbIsRunning, int *pnErrorCode);
        virtual void OnGetErrorReturnValueList(vector<int> &vecReturnValue);
        virtual void OnGetRegisterList(vector<CString> &vecRegister);

    protected:
        virtual void GetDataContent(LPCTSTR lpTime, CString &strHeader, CString &strData, CString &strSFCFilter);

    private:
        //------------------------------------------------------------------------------
        // ����
        DDP_OPERATOR_PARAM m_param;
        //------------------------------------------------------------------------------
        // ���
        H4ISPDefectInfo m_defectInfo;
        AA_TwoDPoint m_DefPointTable[DEFECT_COUNT_MAX];
        double m_dYvalue;
        //------------------------------------------------------------------------------
        void SaveLocationData(LPCTSTR lpOperatorName);
    };

    extern "C"
    {
        DDP_STD_OPERATOR_API BaseOperator* GetOperator(void);
    }
}
