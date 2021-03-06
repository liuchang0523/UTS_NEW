#pragma once
#include "UTSDefine.h"
#include "Algorithm.h"
#include "BaseOperator.h"
#include "otpdb.h"
#include "CommonFunc.h"

#pragma comment(lib, "ddm.lib")
#pragma comment(lib, "CommonFunc.lib")

using namespace UTS::Algorithm;
using namespace UTS::Algorithm::Image;



#ifdef OPERATOR_EXPORTS
#define OPERATOR_API __declspec(dllexport)
#else
#define OPERATOR_API __declspec(dllimport)
#endif

namespace UTS
{
    typedef struct _operator_param_
    {
        CString DBName;

    } OPERATOR_PARAM;

    typedef struct _operator_result_
    {
        int m_Bank;
    } OPERATOR_RESULT;

    class ImplOperator : public BaseOperator
    {
    public:
        ImplOperator(void);
        ~ImplOperator(void);

        virtual BOOL OnReadSpec();
        virtual BOOL OnTest(BOOL *pbIsRunning, int *pnErrorCode);
        virtual void OnGetErrorReturnValueList(vector<int> &vecReturnValue);
        virtual void OnGetRegisterList(vector<CString> &vecRegister);

    protected:
        virtual void GetDataContent(LPCTSTR lpTime, CString &strHeader, CString &strData, CString &strSFCFilter);
        //------------------------------------------------------------------------------
        // ����
        OPERATOR_PARAM m_param;
        //------------------------------------------------------------------------------
        // ���
        OPERATOR_RESULT m_result;
        //------------------------------------------------------------------------------
    };

    extern "C"
    {
        OPERATOR_API BaseOperator* GetOperator(void);
    }
}

