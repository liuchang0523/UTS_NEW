#ifndef _SP2509V_H_
#define _SP2509V_H_

#include <stdint.h>
#include "../../SensorDriver.h"


class SP2509V : public SuperPixSensor
{
public:
	SP2509V();

    int do_prog_otp(int page, int addr, const void *data, int len);
    int do_read_otp(int page, int addr, void *data, int len);

	/*int set_exposure(int e);
	int get_exposure(void);
	int get_exposure_settings(int e, std::map<int, int> &regs);*/
};

#endif
