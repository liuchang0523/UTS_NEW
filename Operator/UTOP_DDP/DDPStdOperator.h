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
        double dDDMaxY;             // 黑板测试最大Y值
        int nReCapture;             // 0：不动作  1：进行更换序列、抓图片、保存的动作   
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
        // 参数
        DDP_OPERATOR_PARAM m_param;
        //------------------------------------------------------------------------------
        // 结果
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

