/*
 * Copyright (C) 2012 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _CHG_DRVAPI_H_
#define _CHG_DRVAPI_H_

#include <linux/types.h>
#include <linux/hrtimer.h>
#include <linux/wakelock.h>
#include <linux/power_supply.h>
#include <mach/adc.h>
#include <linux/semaphore.h>
/* When the battery volume is lower than this value and the charger is still
 * plugged in, we will restart the charge process.
 */
#define PREVRECHARGE		4100
#define CHGMNG_ULTRA_VOLTAGE	(4550)
#define CHGMNG_OVER_CHARGE	(4330)
/* When the battery voltage is higher than this value, we will stop charging. */
#define PREVCHGEND			(4210)

#define CHGMNG_DEFAULT_SWITPOINT CHG_SWITPOINT_18
#define CHGMNG_STOP_VPROG		80	/* Isense stop point */
#define CHGMNG_SWITCH_CV_VPROG	300	/* Isense stop point */
#define CHGMNG_PLUSE_TIMES		3
#define CHARGE_BEFORE_STOP		(1500)
#define CHARGE_OVER_TIME		21600	/* set for charge over time, 6 hours */

#define VBAT_CAPACITY_BUFF_CNT	(240/CONFIG_AVERAGE_CNT)

#ifdef CONFIG_ARCH_SC7710
/*charge current type*/
#define SPRD_CHG_CUR_300MA	300
#define SPRD_CHG_CUR_350MA	350
#define SPRD_CHG_CUR_400MA	400
#define SPRD_CHG_CUR_450MA	450
#define SPRD_CHG_CUR_500MA	500
#define SPRD_CHG_CUR_550MA	550
#define SPRD_CHG_CUR_600MA	600
#define SPRD_CHG_CUR_650MA	650
#define SPRD_CHG_CUR_700MA	700
#define SPRD_CHG_CUR_750MA	750
#define SPRD_CHG_CUR_800MA	800
#define SPRD_CHG_CUR_850MA	850
#define SPRD_CHG_CUR_900MA	900
#define SPRD_CHG_CUR_950MA	950
#define SPRD_CHG_CUR_1000MA	1000
#define SPRD_CHG_CUR_1050MA	1050
#define SPRD_CHG_CUR_MAX	1050

#define SPRD_USB_CHG_CUR	SPRD_CHG_CUR_500MA
#define SPRD_AC_CHG_CUR		SPRD_CHG_CUR_800MA

#else
/*charge current type*/
#define SPRD_CHG_CUR_300MA	300
#define SPRD_CHG_CUR_400MA	400
#define SPRD_CHG_CUR_500MA	500
#define SPRD_CHG_CUR_600MA	600
#define SPRD_CHG_CUR_700MA	700
#define SPRD_CHG_CUR_800MA	800
#define SPRD_CHG_CUR_900MA	900
#define SPRD_CHG_CUR_1000MA	1000
#define SPRD_CHG_CUR_1100MA	1100
#define SPRD_CHG_CUR_1200MA	1200
#define SPRD_CHG_CUR_1300MA	1300
#define SPRD_CHG_CUR_1400MA	1400
#define SPRD_CHG_CUR_1500MA	1500
#define SPRD_CHG_CUR_1600MA	1600
#define SPRD_CHG_CUR_1700MA	1700
#define SPRD_CHG_CUR_1800MA	1800
#define SPRD_CHG_CUR_MAX	1800

#define SPRD_USB_CHG_CUR	SPRD_CHG_CUR_500MA
#define SPRD_AC_CHG_CUR		SPRD_CHG_CUR_600MA

#endif


/*
 battery status define
*/

#define CHARGE_OVER_CURRENT 200

#define VOL_TO_CUR_PARAM (576)

#define CV_STOP_CURRENT		225
#define CC_CV_SWITCH_POINT	200

#define OVP_VOL_VALUE		6500
#define OVP_VOL_RECV_VALUE	5800
#define ADC_CHANNEL_VCHG ADC_CHANNEL_VCHGSEN

#define ADC_CHANNEL_TEMP ADC_CHANNEL_1
#define OTP_OVER_HIGH   600
#define OTP_OVER_LOW    (-50)
#define OTP_RESUME_HIGH 550
#define OTP_RESUME_LOW  0

#define _VCHG_BUF_SIZE  3

#define ADC_CAL_TYPE_NO         0
#define ADC_CAL_TYPE_NV         1
#define ADC_CAL_TYPE_EFUSE      2

#ifdef CONFIG_ARCH_SC7710
#define ANA_REG_BASE    (SPRD_MISC_BASE + 0x800)

#define ANA_CHGR_CTRL0  (ANA_REG_BASE + 0X8C)
#define ANA_CHGR_CTRL1  (ANA_REG_BASE + 0X90)

/* ANA_CHGR_CTL0 */
#define CHGR_CC_EN_BIT  BIT(0)
#define CHGR_CC_EN_RST_BIT  BIT(1)
#define CHGR_CHG_CUR_SHIFT  (2)
#define CHGR_CHG_CUR_MSK    (0XF << CHGR_CHG_CUR_SHIFT)
#define CHGR_PD_BIT         BIT(6)
#define CHGR_CURVE_SHARP_BIT    BIT(7)
#define CHGR_PWM_EN_BIT     BIT(10)
#define CHGR_PWM_EN_RST_BIT BIT(11)
#define CHGR_RECHG_BIT      BIT(12)

/* ANA_CHGR_CTL1 */
#define CHGR_SW_POINT_SHIFT 0
#define CHGR_SW_POINT_MSK   (0X1F << CHGR_SW_POINT_SHIFT)

#define SPRD_TIMER0_BASE    (SPRD_TIMER_BASE)
#define SPRD_TIMER0_LOAD    (SPRD_TIMER0_BASE + 0x0000)
#define SPRD_TIMER0_VALUE   (SPRD_TIMER0_BASE + 0x0004)
#define SPRD_TIMER0_CTL     (SPRD_TIMER0_BASE + 0x0008)
#define SPRD_TIMER0_INT     (SPRD_TIMER0_BASE + 0x000C)

#define SPRD_INTC_ADDR      (SPRD_INTCV_BASE)
#define SPRD_INTC_MSK_STS   (SPRD_INTC_ADDR + 0x0000)
#define SPRD_INTC_RAW_STS   (SPRD_INTC_ADDR + 0x0004)
#define SPRD_INTC_EN_STS    (SPRD_INTC_ADDR + 0x0008)
#define SPRD_INTC_DISEN_STS (SPRD_INTC_ADDR + 0x000C)

#define SPRD_INTC_TIMER0_BIT    BIT(5)

/* SPRD_TIEMR0_INT */
#define SPRD_TIMER0_INT_EN  (BIT(0))
#define SPRD_TIMER0_INT_RAW (BIT(1))
#define SPRD_TIMER0_INT_MSK (BIT(2))
#define SPRD_TIMER0_INT_CLR (BIT(3))
#define SPRD_TIMER0_LD_BUSY (BIT(4))

#define SPRD_TIMER0_RUN     (BIT(7))	/* 0: stop, 1: run */
#define SPRD_TIMER0_MODE    (BIT(6))	/* 0: one-time, 1: period */

#define SPRD_CHG_WAKEUP_SLEEP_CNT (32768)
#define SPRD_DISCHG_WAKEUP_SLEEP_CNT  (32678 * 30)

#define CHGR_SW_POINT_SHIFT_METAL   (1)
#define CHGR_SW_POINT_MSK_METAL (0x1F << CHGR_SW_POINT_SHIFT_METAL)

#else
/* control register definition */
#define ANA_REG_BASE	(SPRD_MISC_BASE + 0x600)	/*  0x82000600 */

#define ANA_CHGR_CTRL0	(ANA_REG_BASE + 0X68)
#define ANA_CHGR_CTRL1	(ANA_REG_BASE + 0X6C)

/* ANA_CHGR_CTL0 */
#define CHGR_CC_EN_BIT			BIT(0)
#define CHGR_CC_EN_RST_BIT		BIT(1)
#define CHGR_PWM_EN_BIT			BIT(10)
#define CHGR_PWM_EN_RST_BIT		BIT(11)
#define CHGR_RECHG_BIT                  BIT(12)

/* ANA_CHGR_CTL1*/

#define CHGR_SW_POINT_SHIFT		0
#define CHGR_SW_POINT_MSK		(0x1F << CHGR_SW_POINT_SHIFT)
#define CHGR_CHG_CUR_SHIFT		8
#define CHGR_CHG_CUR_MSK		(0xF << CHGR_CHG_CUR_SHIFT)
#define CHGR_PD_BIT			BIT(12)
#define CHGR_CURVE_SHARP_BIT		BIT(13)
#endif

#define CHGR_CAPACITY_SHOW_STEADY 1
/*
 * This enum defines the lowest switchover point between constant-current and
 * constant-volatage.
*/
enum {
	CHG_SWITPOINT_LOWEST = 0x0F,
	CHG_SWITPOINT_1 = 0x0E,
	CHG_SWITPOINT_2 = 0x0D,
	CHG_SWITPOINT_3 = 0x0C,
	CHG_SWITPOINT_4 = 0x0B,
	CHG_SWITPOINT_5 = 0x0A,
	CHG_SWITPOINT_6 = 0x09,
	CHG_SWITPOINT_7 = 0x08,
	CHG_SWITPOINT_8 = 0x07,
	CHG_SWITPOINT_9 = 0x06,
	CHG_SWITPOINT_10 = 0x05,
	CHG_SWITPOINT_11 = 0x04,
	CHG_SWITPOINT_12 = 0x03,
	CHG_SWITPOINT_13 = 0x02,
	CHG_SWITPOINT_14 = 0x01,
	CHG_SWITPOINT_15 = 0x00,
	CHG_SWITPOINT_16 = 0x10,
	CHG_SWITPOINT_17 = 0x11,
	CHG_SWITPOINT_18 = 0x12,
	CHG_SWITPOINT_19 = 0x13,
	CHG_SWITPOINT_20 = 0x14,
	CHG_SWITPOINT_21 = 0x15,
	CHG_SWITPOINT_22 = 0x16,
	CHG_SWITPOINT_23 = 0x17,
	CHG_SWITPOINT_24 = 0x18,
	CHG_SWITPOINT_25 = 0x19,
	CHG_SWITPOINT_26 = 0x1A,
	CHG_SWITPOINT_27 = 0x1B,
	CHG_SWITPOINT_28 = 0x1C,
	CHG_SWITPOINT_29 = 0x1D,
	CHG_SWITPOINT_30 = 0x1E,
	CHG_SWITPOINT_HIGHEST = 0x1F
};

struct sprd_battery_data {
	uint32_t reg_base;
	uint32_t gpio;
	uint32_t irq;
	spinlock_t lock;

	struct timer_list battery_timer;
	int timer_freq;
	int in_precharge;
	int adc_cal_updated;

	uint32_t capacity;
	uint32_t voltage;
#ifdef CONFIG_BATTERY_TEMP_DECT
	int temp;
#endif
	uint32_t charging;
	uint32_t ac_online;
	uint32_t usb_online;

	uint32_t precharge_start;
	uint32_t precharge_end;
	uint32_t over_voltage;
	uint32_t over_voltage_recovery;
	uint32_t over_voltage_flag;
	uint32_t over_temp_flag;
	uint32_t over_current;
	uint32_t charge_stop_point;
	uint32_t cur_type;
	uint32_t hw_switch_point;
	uint64_t charge_start_jiffies;
#ifdef CHGR_CAPACITY_SHOW_STEADY
	uint16_t capcity_reference;
	uint16_t read;
	struct semaphore capacity_sema;
#endif
	struct power_supply battery;
	struct power_supply ac;
	struct power_supply usb;
	struct wake_lock charger_plug_out_lock;
};

uint16_t sprd_bat_adc_to_vol(struct sprd_battery_data *data, uint16_t adcvalue);
uint16_t sprd_charger_adc_to_vol(struct sprd_battery_data *data,
				 uint16_t adcvalue);
void sprd_stop_charge(struct sprd_battery_data *data);
void sprd_start_charge(struct sprd_battery_data *data);
void sprd_set_recharge(struct sprd_battery_data *data);
void sprd_stop_recharge(struct sprd_battery_data *data);
uint32_t sprd_get_sw(struct sprd_battery_data *data);
uint32_t sprd_adjust_sw(struct sprd_battery_data *data, bool up_or_down);
int sprd_adc_to_temp(struct sprd_battery_data *data, uint16_t adcvalue);
uint32_t sprd_adc_to_cur(struct sprd_battery_data *data, uint16_t voltage);
int sprd_charger_is_adapter(struct sprd_battery_data *data);
int32_t sprd_get_vprog(struct sprd_battery_data *data);
void sprd_set_sw(struct sprd_battery_data *data, int eswitchpoint);
void sprd_set_chg_cur(uint32_t chg_current);
void sprd_chg_init(void);
uint32_t sprd_vol_to_percent(struct sprd_battery_data *data, uint32_t voltage,
			     int update);
void put_temp_value(struct sprd_battery_data *data, uint32_t temp);
uint32_t get_temp_value(struct sprd_battery_data *data);
void put_vprog_value(struct sprd_battery_data *data, uint32_t vprog);
uint32_t get_vprog_value(struct sprd_battery_data *data);
void update_vprog_value(struct sprd_battery_data *data, uint32_t vprog);
void put_vbat_value(struct sprd_battery_data *data, uint32_t vbat);
uint32_t get_vbat_value(struct sprd_battery_data *data);
void update_vbat_value(struct sprd_battery_data *data, uint32_t vbat);
void put_vbat_capacity_value(uint32_t vbat);
uint32_t get_vbat_capacity_value(void);
void put_vchg_value(uint32_t vchg);
uint32_t get_vchg_value(void);
int32_t sprd_get_chg_current(struct sprd_battery_data *data);

#ifdef CONFIG_ARCH_SC7710
void stop_chg_timer_work(void);
void clear_chg_timer_int(void);
void clear_chg_timer_in_intc(void);
uint32_t sprd_dump_chg_reg(void);

#endif

#endif /* _CHG_DRVAPI_H_ */
