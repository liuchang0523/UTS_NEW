#pragma once
#include "UTSDefine.h"
#include "Algorithm.h"
#include "BaseOperator.h"

using namespace UTS::Algorithm;
using namespace UTS::Algorithm::ColorShading;
using namespace UTS::Algorithm::ColorShading_NOKIA;

#pragma comment(lib, "UTSAlgorithm.lib")
#pragma comment(lib, "UTSFramework.lib")

#ifdef COLORSHADING_OPERATOR_EXPORTS
#define COLORSHADING_OPERATOR_API __declspec(dllexport)
#else
#define COLORSHADING_OPERATOR_API __declspec(dllimport)
#endif

namespace UTS
{
    typedef struct _colorshading_operator_param_
    {
        double dLTMinY;         // 白板测试最小Y值
        double dLTMaxY;         // 白板测试最大Y值
        int nReCapture;         // 0：不动作  1：进行更换序列、抓图片、保存的动作
		int nROIWidth;
		int nROIHeight;
		double dMeanA[5];
		double dMeanB[5];
		double dDeltaSpec;
    } COLORSHADING_OPERATOR_PARAM;

    class ColorShadingOperator : public BaseOperator
    {
    public:
        ColorShadingOperator(void);
        ~ColorShadingOperator(void);

        virtual BOOL OnReadSpec();
        virtual BOOL OnTest(BOOL *pbIsRunning, int *pnErrorCode);
        virtual void OnGetErrorReturnValueList(vector<int> &vecReturnValue);
        virtual void OnGetRegisterList(vector<CString> &vecRegister);

    protected:
        virtual void GetDataContent(LPCTSTR lpTime, CString &strHeader, CString &strData, CString &strSFCFilter);

    private:
        //------------------------------------------------------------------------------
        // 参数
        COLORSHADING_OPERATOR_PARAM m_param;
        //------------------------------------------------------------------------------
        // 结果
        CS_DELTA_NOKIA_RESULT m_result;
        double m_dYvalue;
    };

    extern "C"
    {
        COLORSHADING_OPERATOR_API BaseOperator* GetOperator(void);
    }
}
