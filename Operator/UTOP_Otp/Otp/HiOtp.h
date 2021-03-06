#pragma once

#include "baseotp.h"

class HiOtp:public BaseOtp
{
public:
	HiOtp(BaseDevice *dev);
	~HiOtp(void);

protected:
	 int get_wb_gain(WB_RATIO *ratio, WB_RATIO *ratio_target, WB_GAIN *gain);
	 int get_wb_cali_data(WB_GAIN *gain, void *out);
};

