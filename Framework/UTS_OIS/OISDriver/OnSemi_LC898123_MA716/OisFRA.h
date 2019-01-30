/**
 * @brief		FRA measurement header for LC898123 F40
 * 				API List for customers
 *
 * @author		Copyright (C) 2016, ON Semiconductor, all right reserved.
 *
 * @file		OisAPI.h
 * @date		svn:$Date:: 2016-04-28 14:30:21 +0900#$
 * @version		svn:$Revision: 43 $
 * @attention
 **/
#ifndef OISFRA_H_
#define OISFRA_H_

//****************************************************
//	extern selector for API
//****************************************************
#ifdef	__OISFRA__
	#define	__OIS_FRA_HEADER__
#else
	#define	__OIS_FRA_HEADER__		extern
#endif






typedef struct  {
	INT_32	a1 ;
	INT_32	b1 ;
	INT_32	c1 ;
	INT_32	a2 ;
	INT_32	b2 ;
	INT_32	c2 ;
} StMesFCoeff_t ;


__OIS_FRA_HEADER__	void	MesStart_FRA_Single( UINT_8, UINT_8 ) ;
__OIS_FRA_HEADER__	void	MesStart_FRA_Continue( void ) ;
__OIS_FRA_HEADER__	void	MesEnd_FRA_Sweep( void ) ;

#endif	// OISFRA_H_
